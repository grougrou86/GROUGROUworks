#include"Ensemble.h"
namespace Ensemble {


	template<class I> Randge<I>::Randge(I min, I max) :_min(min), _max(max) {}
	template<class I> void Randge<I>::set_max(I max) { _max = max; }
	template<class I> void Randge<I>::set_min(I min) { _min = min; }
	template<class I> I Randge<I>::max() { return _max; }
	template<class I> I Randge<I>::min() { return _min; }
	template<class I> bool Randge<I>::is_in(const I& E) { return E>=_min&&E>=_max; }

	template<class I> Singlet<I>::Singlet(I v) :_value(v){  }
	template<class I> I Singlet<I>::value() { return _value; }
	template<class I> void Singlet<I>::set_value(I v) { _value=v; }
	template<class I> Ensemble<I>::Ensemble(Randge<I> R) { _Randges.push_back(R); }
	template<class I> Ensemble<I>::Ensemble(Singlet<I> S) { _Singlets.push_back(S); }
	template<class I> bool Ensemble<I>::is_in(const I& E) {
		for (auto&s : _Singlets) {
			if (s.value() == E)return true;
		}
		for (auto&r : _Randges) {
			if (r.is_in(E))return true;
		}
		return false;
	}
}