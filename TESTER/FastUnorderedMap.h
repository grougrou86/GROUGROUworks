#pragma once
#include <algorithm>
#include <vector>

/*
T --> key type
I --> object type
*/
/*
FastMap is a faster map than std map for rarely uptaded and offen access throw the same id by the same instance the instance so keep the 
FastMapSearch passed to make a search and use it again at next search! and if no modification was don the element can be accessed directly

ATTENTION is working if the element are added less than : 2,147,483,647 times

else use int 64 bits

return a pointer so that it can notice for non found // do not delet it thanks 

// exemple of use cf the end of document  --> in exemple performance of fastmap are 5 times better than unordered map 

ADVICE OF USE 

For keeping performance only call one time and then use the pointer beeing carful not to delet an element in that while.

*/

template< class T , class I> class HolderValue{
	//for the map internal usage -> countainsthe value the key and the unique unsigned int replacing it for faster compareason
public:

	HolderValue(unsigned int h, T k, I v): _holder(h),_value(v),_key(k){}
	HolderValue( T k , I v) : _holder(0), _value(v),_key(k) {}
	unsigned int holder() {
		return _holder;
	}
	T& key() {
		return _key;
	}
	I& value() {
		return _value;
	}

private:
	unsigned int _holder;
	T _key;
	I _value;

};

template<class T> class FastMapSearch {
	template<class T, class I> friend class FastMap;
public:

	FastMapSearch( T val) :_key(val) {}
	FastMapSearch() {}
	void set_key(T val) {
		_guest_position = 0;
		_key_int = 0;
		_key = val;
	}
protected:
	unsigned int _guest_position = 0;//0->unset key and so it is the quest position - 1
	T _key;
	unsigned int _key_int = 0;//0-> unset or unfound
};

template<class T, class I> class FastMap {
public:
	I* operator[](FastMapSearch<T>& search) {
		if (search._guest_position != 0 && _value.size() >= search._guest_position&&search._key_int == _value[search._guest_position - 1].holder()) return &(_value[search._guest_position - 1].value());
		//map has been updated so the element has not been found at last position
		if (search._key_int != 0) {//if the object has been found in the past oine can use it's ID to make faster compareason
			for (size_t i = 0; i < _value.size(); i++) {
				if (_value[i].holder() == search._key_int) {
					search._guest_position = i + 1; // set the position for further speedy search
					return &(_value[i].value());
				}
			}
			return nullptr; // not found
		}
		for (size_t i = 0; i < _value.size(); i++) {
			if (_value[i].key() == search._key) {
				search._key_int = _value[i].holder();
				search._guest_position = i + 1;
				return &(_value[i].value());
			}
		}
		return nullptr; // not found
	}
	void Insert(FastMapSearch<T>& search, I element) {
		search._key_int = (curr_id++);
		(_value.push_back(HolderValue<T, I>(search._key_int, search._key, element)));
		search._guest_position = _value.size() + 1;// udate the first search position !!
	}
	void Remove(FastMapSearch<T>& search) {
		if ((*this)[search] != nullptr) {//if found
			//swap back delet is efficient delet and it only moves one element -> the other are still found thery easialy ! -> good performance
			std::swap(_value[search._guest_position-1], _value.back());
			_value.pop_back();
		}
	}
private:
	//each element is asociated to an int id for faster lookup !
	unsigned int curr_id = 0;//0 correspond to unknown id and thus will not be attributed to any thing.
	std::vector<HolderValue<T,I>> _value;
	};



/*

	==================
	||EXEMPLE OF USE||
	==================

FastMap< std::string, std::string> FastM;
std::unordered_map< std::string, std::string> M;

std::vector< std::string> noms;
std::vector<FastMapSearch< std::string>> searches;

Timer timer;

for (unsigned int i = 0; i < 200; i++) {
noms.push_back(std::to_string(i));
searches.push_back(FastMapSearch< std::string>(std::to_string(i+9999999999)));
}

timer.reset();

// case of FastMap

for (unsigned int j = 0; j < 1000000; j++) {
for (unsigned int i = 0; i < 200; i+=4) {
std::string* s = FastM[searches[i]];
if (s == nullptr) {
FastM.Insert(searches[i], noms[i]);
}
}
}
std::cout << timer.elapsed() << std::endl;

timer.reset();

//cas of unordered_map

for (unsigned int j = 0; j < 1000000; j++) {
for (unsigned int i = 0; i < 200; i+=4) {
std::unordered_map< std::string, std::string>::iterator it = M.find(noms[i]);
if (it == M.end()) {
M[noms[i]] = noms[i];
}
}
}
std::cout << timer.elapsed() << std::endl;
*/
