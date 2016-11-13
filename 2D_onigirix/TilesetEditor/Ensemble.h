#pragma once
#include<vector>

namespace Ensemble {
	template<class I> class Randge {
	public:
		Randge(I min, I max);
		I min();
		I max();
		void set_max(I);
		void set_min(I);
		virtual bool is_in(const I&); // is virtual to alow Randge close or open on side 
	private:
		I _min;
		I _max;
	};
	template<class I> class Singlet {
	public:
		Singlet(I);
		I value();
		void set_value(I);
	private:
		I _value;
	};
	template<class I> class Ensemble {
	public:
		Ensemble() {}
		Ensemble(Randge<I>);
		Ensemble(Singlet<I>);

		bool is_in(const I&);

		void pack();//the ensemble should automaticaly pack itself ! to reduce it's memory usage
	private:
		std::vector<Singlet<I>> _Singlets;
		std::vector<Randge<I>> _Randges;
	};

	template<class I> Ensemble<I> Union(Ensemble<I>, Ensemble<I>, bool pack = true); // packing resudces memory but is a time consuming process !
	template<class I> Ensemble<I> Intersection(Ensemble<I>, Ensemble<I>, bool pack = true);
	template<class I> Ensemble<I> Substartion(Ensemble<I>, Ensemble<I>, bool pack = true);

}