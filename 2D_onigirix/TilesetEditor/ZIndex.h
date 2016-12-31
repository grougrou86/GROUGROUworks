#pragma once
#include<deque>
namespace ONIGIRIX_GUI {

	//Zindex is composed of the child index and then the parent index the parent indexes have greater importance than the child indexes 

	class ZIndex {
	public:
		ZIndex(std::initializer_list<int> list) {
			update(list);
		}
		ZIndex() {}

		void update(std::initializer_list<int> list);
		void clear();
		void addMainIndex(int);
		void addChildIndex(int);

		bool operator< (ZIndex index2);
		bool operator> (ZIndex index2);

	private:
		std::deque<int> indexes; // first element is the most far parent index 
	};

	
}