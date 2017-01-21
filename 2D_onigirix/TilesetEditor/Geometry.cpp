#include"Geometry.h"
#include<cmath>
namespace ONIGIRIX_GUI {
	namespace GEOMETRY2D {
		Radiant::Radiant(double v):_value(v){
		}
		Radiant::Radiant(Degree d) : _value(d.value_Radiant()) {
		}
		double Radiant::value_Radiant() const{
			return _value;
		}
		Degree::Degree(double v) : _value(v) {
		}
		Degree::Degree(Radiant r) : _value(r.value_Radiant()*57.295779513082320876798154814105) {
		}
		double Degree::value_Radiant() const {
			return _value*0.01745329251994329576923690768489;
		}
		double Degree::value_Degree() const {
			return _value;
		}
	}
}