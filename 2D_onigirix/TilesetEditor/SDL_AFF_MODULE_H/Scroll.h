#ifndef SCROLL_H
#define SCROLL_H

//il est intelligent de l'utiliser en alloc dinamic pour laisser la fenêtre gérer même la destruction du Scroll !

#include "G_inc.h" 
#include <string>
#include <vector> 
#include "Mesure.h"

class Scroll{
public:
	Scroll(Fenetre* f, Mesure h1, Mesure h2,  Mesure w, Mesure x, Mesure y,bool);

	Rectangle* support;
	Rectangle* boutton;
	
	Fenetre* fen;

	double value = 0;

	bool is_vertical;

	bool restrected=false;

	void update();

	double get_value();
	void set_value(double value);

	Mesure _x;
	Mesure _y;
	Mesure _w;
	Mesure _h1;
	Mesure _h2;

	Mesure get_x();
	void set_x(Mesure);
	Mesure get_y();
	void set_y(Mesure);
	Mesure get_w();
	void set_w(Mesure);
	Mesure get_h1();
	void set_h1(Mesure);
	Mesure get_h2();
	void set_h2(Mesure);

	void change();

	void add_on_change(call_funk);
	void remove_on_change();

	call_funk onchange;

	call_funk callback=NULL;

	Rectangle* operator[](int i) const;

	virtual ~Scroll(){
		//C'est la  fenêtre qui s'occupe de supp les rectangle... he wesh
	}

};


#endif