#ifndef MESURE_H
#define MESURE_H

// permet de faire une mesure combinée de pourcent et de pixel ...

class Mesure{
public:
	Mesure(double x, double y){ px = x; pc = y; }
	double px = 0;
	double pc = 0;
	double totalPX(double Reference){
		return px + pc*Reference / 100.0;
	}
	Mesure(){}
	Mesure& operator+=(Mesure const&);
	Mesure& operator-=(Mesure const&);

};
const bool operator!=(Mesure M1, Mesure const& M2);
 Mesure operator+(Mesure M1, Mesure const& M2); 
 Mesure operator*(double const& M1, Mesure M2);
 Mesure operator-(Mesure M1, Mesure const& M2);
#endif