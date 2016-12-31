#include"ZIndex.h"
#include<algorithm>
namespace ONIGIRIX_GUI {
	bool  ZIndex::operator< (ZIndex index2) {
		size_t s1(this->indexes.size());
		size_t s2(index2.indexes.size());
		size_t smin(std::min(s1, s2));

		for (size_t i = 0; i < smin; i++)
		{
			if (this->indexes[i] < index2.indexes[i])return true;
			if (this->indexes[i] > index2.indexes[i])return false;
		}
		return s1<s2;
	}
	bool  ZIndex::operator> (ZIndex index2) {
		size_t s1(indexes.size());
		size_t s2(index2.indexes.size());
		size_t smin(std::min(s1, s2));

		for (size_t i = 0; i < smin; i++)
		{
			if (indexes[i] > index2.indexes[i])return true;
			if (indexes[i] < index2.indexes[i])return false;
		}
		return s1>s2;
	}
	void ZIndex::clear() {
		indexes.clear();
	}
	void ZIndex::update(std::initializer_list<int> list){
		for (auto& el : list) {
			indexes.push_back(el);
		}
	}
	void ZIndex::addMainIndex(int index) {
		indexes.push_front(index);
	}
	void ZIndex::addChildIndex(int index) {
		indexes.push_back(index);
	}
}