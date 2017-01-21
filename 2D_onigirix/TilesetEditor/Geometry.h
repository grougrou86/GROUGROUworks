#pragma once
#include<array>
#include<vector>

/*

TO DO :

- point mesurer distance que si out of the bound
- demi droite pas utiuliser directement la distance mais la fonction is near du point extremitee 

*/
/*

FUTURE OPTIMISATION POSIBLE :

	- not to put the test if in rectangle in the is near test because redoundant it may already be used by the draw function to only go throw a little image part
			- faire un version sans outerRectangle verifications

*/

namespace ONIGIRIX_GUI {
	
	namespace GEOMETRY2D {


		/*
		For performance there is a lot of return by reference
		*/

		//forward declarations

		template<class Unit> class Rectangle;
		template<class Unit> class Point;
		class Degree;

		//declarations

		class Angle {
		public:
			//give the value in radiant ensure possible calculation
			virtual inline double value_Radiant() const= 0;
		};
		class Radiant : public Angle  {
		public:
			Radiant(double);
			Radiant(Degree);
			virtual inline double value_Radiant() const;
		private:
			double _value;
		};
		class Degree :public Angle {
		public:
			Degree(double);
			Degree(Radiant);
			virtual inline double value_Radiant() const;
			virtual inline double value_Degree() const;
		private:
			double _value;
		};
		//absolute value template 
		template<class Unit> inline Unit abs(const Unit&) {return Unit>0 ? Unit : - Unit}
		// graneral class
		template<class Unit> class Bounded {
		public:
			virtual const Rectangle<Unit>& get_outer_rectangle() const = 0;
		};
		template<class Unit> class Curve {
		public:
			virtual bool  is_near(const Point<Unit> &) const = 0;
			virtual void set_thickness(Unit thickness);
			virtual const Unit& get_thickness() const;
		private:
			Unit _thickness;
		};
		template<class Unit> class Bounded_Curve:public virtual Bounded<Unit>, virtual Curve<Unit> {
		public:
			// the outer rectangle with the thickness of the line 
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const = 0;
		};
		template<class Unit> class Shape {
		public:
			virtual bool is_in(const Point<Unit> &) const = 0;
		};
		// actual geometries
		template<class Unit> class Point : public virtual Bounded_Curve<Unit> {
		public:
			Point(const Unit& x, const Unit&  y);
			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;
			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;
			virtual inline const Unit& get_x() const;
			virtual inline const Unit& get_y() const;
			void set_x(Unit);
			void set_y(Unit);

		private:
			Unit _x;
			Unit _y;
		};

		// a Vector is same as a point  

		template<typename Unit> class Vector : public Point<Unit> {
		public:
			Vector(const Point<Unit>&);
			Vector(const Point<Unit>& p1,const Point<Unit>& p2);//vector between p1->p2
			Vector(Unit x, Unit  y);
			//get vector norme / square norme
			Unit square_norme() const;
			Unit norme() const;
			//normalise the vector
			void normalise();
			//get normal vector of same norm
			Vector<Unit> normal();
			// classical addition and multiplication
			Vector<Unit> operator+(const Vector<Unit> &);
			Vector<Unit> operator-(const Vector<Unit> &);
			//produit scallaire
			Unit operator*(const Vector<Unit> &);

		};

		template<class Unit> Vector<Unit> operator*(const Vector<Unit> &,const Unit &);
		template<class Unit> Vector<Unit> operator/(const Vector<Unit> &,const Unit &);
		template<class Unit> Vector<Unit> operator*(const Unit &,const Vector<Unit> &);
		template<class Unit> Vector<Unit> operator/(const Unit &,const Vector<Unit> &);
		//template<class Unit> Radiant angle(const Vector<Unit> &, const Vector<Unit> &);

		template<class Unit> class Line : public virtual Curve<Unit> {
		public:
			Line(const Point<Unit>& p1,const Point<Unit>& p2);
			Line(const Point<Unit>& p1,const Vector<Unit>& v);

			const Vector<Unit>& get_v_director() const;
			const Point<Unit>& get_origine() const;
			void set_v_director(const Vector<Unit>&);
			void set_origine(const Point<Unit>&);

			virtual Unit Distance_Point(const Point<Unit> &) const;

			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

		protected:

			Vector<Unit> _v_director;
			Point<Unit> _origine;

			//Some value to compute distance at more speed

			// cf allgorithm distance 2 points wikipedia : https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line#Line_defined_by_two_points
			Unit v1,v2,v3;// (y2-y1)/sqrt((x1-x2)^2+(y1-y1)^2) // (x2-x1)/sqrt((x1-x2)^2+(y1-y1)^2) // (x2y1-y2x1)/sqrt((x1-x2)^2+(y1-y1)^2) 
			//ATTENTION FUNCTION TO BE CALLED AT EACH TIME LINE IS MODIFIED
			void _Update_OtherValue(); // update the top values

		};
		template<class Unit> class HalfLine : public Line<Unit> {
		public:
			HalfLine(const Point<Unit>& p1, const Point<Unit>& p2);
			HalfLine(const Point<Unit>& p1, const Vector<Unit>& v);

			virtual Unit Distance_Point(const Point<Unit> &) const;

			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

		private:
		};
		template<class Unit> class Segment : public Line<Unit>, virtual Bounded_Curve<Unit> {
		public:
			Segment(const Point<Unit>& p1, const Point<Unit>& p2);
			Segment(const Point<Unit>& p1, const Vector<Unit>& v);

			virtual Unit Distance_Point(const Point<Unit> &);

			virtual bool is_near(const Point<Unit> &) const;
			//same but faster no calculation of the distance to the two boundary point  so no rounding
			virtual bool is_near_fast(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;
			virtual const Point<Unit>& get_p1() const;
			virtual const Point<Unit>& get_p2() const;
			virtual const Point<Unit>& set_p1();
			virtual const Point<Unit>& set_p2();

		private:
		};
		/*
		
		in the rectangle :
			- the fontion called with x and y keep h and w const 
			- the fontion called with x1 and y1 keep x2 and y2 const 
		
		*/
		template<class Unit> class Rectangle : public virtual Bounded_Curve<Unit>, virtual Shape<Unit> {
		public:
			Rectangle(Unit x, Unit y, Unit w, Unit h);
			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual bool is_in(const Point<Unit> & p) const;
			//same as is_in but with an offset 
			virtual Rectangle<Unit> get_offseted(Unit offset) const;
			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;
			const Unit& get_x() const;
			const Unit& get_y() const;
			const Unit& get_x1() const;
			const Unit& get_y1() const;
			const Unit& get_x2() const;
			const Unit& get_y2() const;
			const Unit get_w() const;
			const Unit get_h() const;
			void set_x1(Unit);
			void set_y1(Unit);
			void set_x2(Unit);
			void set_y2(Unit);
			void set_x(Unit);
			void set_y(Unit);
			void set_w(Unit);
			void set_h(Unit);
		private:
			Unit _x1;
			Unit _y1;
			Unit _x2;
			Unit _y2;

		};
		template<class Unit, unsigned int _size> class Polygone : public virtual Bounded_Curve<Unit>, virtual Shape<Unit> {
		public:
			Polygone(std::array<Point<Unit>, _size>);
			virtual const std::array<Point<Unit>, _size>& get_summet();
			virtual bool is_near(const Point<Unit>&) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;

			unsigned constexpr int size();
		private:
			//the summet of the plygone
			std::array<Point<Unit>, _size> _summet;
			//for is_in 
			std::array<Unit, _size> _constant;
			std::array<Unit, _size> _multiple;
			//for is_near or other uses the side of the polygone 
			std::array<Segment<Unit>, _size> _side;
		};
		//specifate for 3 corner and 4 corner
		template<class Unit> class Triangle : public Polygone<Unit, 3> {
		};
		template<class Unit> class Quadrilater : public Polygone<Unit, 3> {
			Quadrilater(Rectangle<Unit>);
		};
		template<class Unit, unsigned int _size> class Polyline : public virtual Bounded_Curve<Unit>, virtual Shape<Unit> {
		public:
			Polyline(std::array<Point<Unit>, _size>);
			virtual const std::array<Point<Unit>, _size>& get_summet();
			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;

			unsigned constexpr int size();
		private:
			//the summet of the polyline
			std::array<Point<Unit>, _size> _summet;
			//for is_near or other uses the side of the polyline 
			std::array<Segment<Unit>, (_size - 1)> _side;
		};
		//dynamic equivalent of polygone and polyline so that they can hav free value of n 
		/*
		more free can be use for getting the result of an intersection or union of polygones etc...
		*/
		template<class Unit> class DynamicPolygone : public  virtual Shape<Unit>, virtual Bounded_Curve<Unit> {
		public:
			DynamicPolygone(std::vector<Point<Unit>>);
			template<unsigned int n>DynamicPolygone(Polygone<Unit, n>);
			virtual const std::vector<Point<Unit>>& get_summet() const;
			virtual bool is_in(const Point<Unit> & p) const;
			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;

			unsigned int size();
		private:
			//the summet of the plygone
			std::vector<Point<Unit>> _summet;
			//for is_in 
			std::vector<Unit> _constant;
			std::vector<Unit> _multiple;
			//for is_near or other uses the side of the polygone 
			std::vector<Segment<Unit>> _side;
		};
		template<class Unit> class DynamicPolyline : public virtual Bounded_Curve<Unit> {
		public:
			DynamicPolyline(std::vector<Point<Unit>>);
			template<unsigned int n> DynamicPolyline(Polyline<Unit, n>);
			virtual const std::vector<Point<Unit>>& get_summet();
			virtual bool is_near(const Point<Unit> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit>& get_outer_rectangle() const;
			virtual const Rectangle<Unit>& get_outer_rectangle_thick() const;

			unsigned int size();
		private:
			//the summet of the polyline
			std::vector<Point<Unit>> _summet;
			//for is_near or other uses the side of the polyline 
			std::vector<Segment<Unit>> _side;
		};
		template<class Unit> class BesierCurve : public Curve<Unit>, Shape<Unit>, Bounded<Unit> {

		};
		template<class Unit> class Circle : public Curve<Unit>, Shape<Unit>, Bounded<Unit> {

		};
		template<class Unit>class CircleArc : public Curve<Unit>, Shape<Unit>, Bounded<Unit> {

		};
		template<class Unit> class Elipse : public Curve<Unit>, Shape<Unit>, Bounded<Unit> {

		};
		template<class Unit> class ElipseArc : public Curve<Unit>, Shape<Unit>, Bounded<Unit> {

		};

	}
		
}