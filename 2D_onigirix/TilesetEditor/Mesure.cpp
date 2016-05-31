
#include "Mesure.h"
namespace ONIGIRIX_GUI {
	Mesure& Mesure::operator+=(Mesure const& M2) {
		px += M2.px;
		pc += M2.pc;
		return *this;
	}
	Mesure& Mesure::operator-=(Mesure const& M2) {
		px -= M2.px;
		pc -= M2.pc;
		return *this;
	}
	Mesure operator+(Mesure M1, Mesure const& M2) {
		M1 += M2;
		return M1;
	}
	Mesure operator-(Mesure M1, Mesure const& M2) {
		M1 -= M2;
		return M1;
	}
	const bool operator!=(Mesure M1, Mesure const& M2) {
		return !(M1.pc == M2.pc&&M1.px == M2.px);
	}
	const bool operator==(Mesure const& M1, Mesure const& M2) {
		return (M1.pc == M2.pc&&M1.px == M2.px);
	}
	Mesure operator*(double const& M1, Mesure M2) {
		M2.pc *= M1;
		M2.px *= M1;

		return M2;
	}
}