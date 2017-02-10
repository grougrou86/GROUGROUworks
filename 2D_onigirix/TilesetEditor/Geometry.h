#pragma once
#include<array>
#include<vector>
#include"texture.h"

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
/*

Geometry class for display :

	- as an inner implementation for the software display 
	- DataPerPixel is to set to 3 in normal case and to 4 if there is an alpha 
	- DataPerPixel if it is negative -> for hardware implementation off the rendering --> remove calculate :
		- 0 --> opengl 

*/
namespace ONIGIRIX_GUI {
	
	namespace GEOMETRY2D {

		//constant definition 

#define GEOMETRY2D_DEFAULT_THICKNESS 2.0;

		/*
		For performance there is a lot of return by reference
		*/

		//forward declarations

		template<class Unit, class ImageType, int DataPerPixel> class Rectangle;
		template<class Unit, class ImageType, int DataPerPixel> class Point;
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
		// class about drawing 
		// data per pixel is the number of ImageType representing each pixels 



		template<class ImageType, int DataPerPixel > using Color = ImageType[DataPerPixel];
		/*
		- set pixel --> modify the pixel 
		- add pixel --> add pixel supposing the last is the alpha 
		- get pixel --> return the pixel 
		*/
		// get them by entering the pixel position
		template<class ImageType, int DataPerPixel > void set_pixel(ImageType* first, const unsigned int position, const Color<ImageType, DataPerPixel>* color);
		template<class ImageType, int DataPerPixel > void add_pixel(ImageType* first, const unsigned int position, const Color<ImageType, DataPerPixel>* color);
		template<class ImageType, int DataPerPixel > const Color<ImageType, DataPerPixel> & get_pixel(const ImageType* first, const unsigned int position);
		// get them by entering the pointer  (pointer = DataPerPixel * position)
		template<class ImageType, int DataPerPixel > void set_pixel_exacte(ImageType* first, const unsigned int pointer, const Color<ImageType, DataPerPixel>* color);
		template<class ImageType, int DataPerPixel > void add_pixel_exacte(ImageType* first, const unsigned int pointer, const Color<ImageType, DataPerPixel>* color);
		template<class ImageType, int DataPerPixel > const Color<ImageType, DataPerPixel> & get_pixel_exacte(const ImageType* first, const unsigned int pointer);

		template<class Unit , class ImageType, int DataPerPixel > class Drawable {
			virtual void Draw(SDL_S_texture* first, const Rectangle<Unit, ImageType, DataPerPixel> & DrawRectangle );
		};
		// general class
		template<class Unit, class ImageType, int DataPerPixel> class Bounded {
		public:
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const = 0;
		};
		template<class Unit, class ImageType, int DataPerPixel> class Curve:public virtual Drawable<Unit,ImageType,DataPerPixel> {
		public:
			virtual bool  is_near(const Point<Unit, ImageType, DataPerPixel> &) const = 0;
			virtual void set_thickness(Unit thickness);
			virtual const Unit& get_thickness() const;
		private:
			Unit _thickness = GEOMETRY2D_DEFAULT_THICKNESS;
		};
		template<class Unit, class ImageType, int DataPerPixel> class Bounded_Curve:public virtual Bounded<Unit,ImageType,DataPerPixel>, virtual Curve<Unit,ImageType,DataPerPixel> {
		public:
			// the outer rectangle with the thickness of the line 
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const = 0;
		};
		template<class Unit, class ImageType, int DataPerPixel> class Shape :public  virtual Drawable<Unit,ImageType,DataPerPixel> {
		public:
			virtual bool is_in(const Point<Unit, ImageType, DataPerPixel> &) const = 0;
		};
		// actual geometries
		template<class Unit, class ImageType, int DataPerPixel> class Point : public virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {
		public:
			Point(const Unit& x, const Unit&  y);
			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;
			inline const Unit& get_x() const;
			inline const Unit& get_y() const;
			void set_x(Unit);
			void set_y(Unit);
			void set_x_y(Unit, Unit);

		private:
			Unit _x;
			Unit _y;
			Rectangle<Unit, ImageType, DataPerPixel> _outer_rectangle;
			Rectangle<Unit, ImageType, DataPerPixel> _outer_rectangle_thick;
		};

		// a Vector is same as a point  

		template<typename Unit, class ImageType, int DataPerPixel> class Vector : public Point<Unit,ImageType, DataPerPixel> {
		public:
			Vector(const Point<Unit, ImageType, DataPerPixel>&);
			Vector(const Point<Unit, ImageType, DataPerPixel>& p1,const Point<Unit, ImageType, DataPerPixel>& p2);//vector between p1->p2
			Vector(Unit x, Unit  y);
			//get vector norme / square norme
			Unit square_norme() const;
			Unit norme() const;
			//normalise the vector
			void normalise();
			//get normal vector of same norm
			Vector<Unit, ImageType, DataPerPixel> normal();
			// classical addition and multiplication
			Vector<Unit, ImageType, DataPerPixel> operator+(const Vector<Unit, ImageType, DataPerPixel> &);
			Vector<Unit, ImageType, DataPerPixel> operator-(const Vector<Unit, ImageType, DataPerPixel> &);
			//produit scallaire
			Unit operator*(const Vector<Unit, ImageType, DataPerPixel> &);

		};

		template<class Unit, class ImageType, int DataPerPixel> Vector<Unit, ImageType, DataPerPixel> operator*(const Vector<Unit, ImageType, DataPerPixel> &,const Unit &);
		template<class Unit, class ImageType, int DataPerPixel> Vector<Unit, ImageType, DataPerPixel> operator/(const Vector<Unit, ImageType, DataPerPixel> &,const Unit &);
		template<class Unit, class ImageType, int DataPerPixel> Vector<Unit, ImageType, DataPerPixel> operator*(const Unit &,const Vector<Unit, ImageType, DataPerPixel> &);
		template<class Unit, class ImageType, int DataPerPixel> Vector<Unit, ImageType, DataPerPixel> operator/(const Unit &,const Vector<Unit, ImageType, DataPerPixel> &);
		//template<class Unit> Radiant angle(const Vector<Unit> &, const Vector<Unit> &);

		template<class Unit, class ImageType, int DataPerPixel> class Line : public virtual Curve<Unit, ImageType, DataPerPixel> {
		public:
			Line(const Point<Unit, ImageType, DataPerPixel>& p1,const Point<Unit, ImageType, DataPerPixel>& p2);
			Line(const Point<Unit, ImageType, DataPerPixel>& p1,const Vector<Unit, ImageType, DataPerPixel>& v);

			const Vector<Unit, ImageType, DataPerPixel>& get_v_director() const;
			const Point<Unit, ImageType, DataPerPixel>& get_origine() const;
			void set_v_director(const Vector<Unit, ImageType, DataPerPixel>&);
			void set_origine(const Point<Unit, ImageType, DataPerPixel>&);

			virtual Unit Distance_Point(const Point<Unit, ImageType, DataPerPixel> &) const;

			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;

		protected:

			Vector<Unit, ImageType, DataPerPixel> _v_director;
			Point<Unit, ImageType, DataPerPixel> _origine;

			//Some value to compute distance at more speed

			// cf allgorithm distance 2 points wikipedia : https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line#Line_defined_by_two_points
			Unit v1,v2,v3;// (y2-y1)/sqrt((x1-x2)^2+(y1-y1)^2) // (x2-x1)/sqrt((x1-x2)^2+(y1-y1)^2) // (x2y1-y2x1)/sqrt((x1-x2)^2+(y1-y1)^2) 
			//ATTENTION FUNCTION TO BE CALLED AT EACH TIME LINE IS MODIFIED
			void _Update_OtherValue(); // update the top values

		};
		template<class Unit, class ImageType, int DataPerPixel> class HalfLine : public Line<Unit, ImageType, DataPerPixel> {
		public:
			HalfLine(const Point<Unit, ImageType, DataPerPixel>& p1, const Point<Unit, ImageType, DataPerPixel>& p2);
			HalfLine(const Point<Unit, ImageType, DataPerPixel>& p1, const Vector<Unit, ImageType, DataPerPixel>& v);

			virtual Unit Distance_Point(const Point<Unit, ImageType, DataPerPixel> &) const;

			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;

		private:
		};
		template<class Unit, class ImageType, int DataPerPixel> class Segment : public Line<Unit, ImageType, DataPerPixel>, virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {
		public:
			Segment(const Point<Unit, ImageType, DataPerPixel>& p1, const Point<Unit, ImageType, DataPerPixel>& p2);
			Segment(const Point<Unit, ImageType, DataPerPixel>& p1, const Vector<Unit, ImageType, DataPerPixel>& v);

			virtual Unit Distance_Point(const Point<Unit, ImageType, DataPerPixel> &);

			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;
			//same but faster no calculation of the distance to the two boundary point  so no rounding
			virtual bool is_near_fast(const Point<Unit, ImageType, DataPerPixel> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;
			const Point<Unit, ImageType, DataPerPixel>& get_p1() const;
			const Point<Unit, ImageType, DataPerPixel>& get_p2() const;
			void set_p1(const Point<Unit, ImageType, DataPerPixel>&);
			void set_p2(const Point<Unit, ImageType, DataPerPixel>&);

		private:
		};
		/*
		
		in the rectangle :
			- the fontion called with x and y keep h and w const 
			- the fontion called with x1 and y1 keep x2 and y2 const 
		
		*/
		template<class Unit, class ImageType, int DataPerPixel> class Rectangle : public virtual Bounded_Curve<Unit, ImageType, DataPerPixel>, virtual Shape<Unit, ImageType, DataPerPixel> {
		public:
			Rectangle(Unit x, Unit y, Unit w, Unit h);
			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual bool is_in(const Point<Unit, ImageType, DataPerPixel> & p) const;
			//same as is_in but with an offset 
			virtual Rectangle<Unit, ImageType, DataPerPixel> get_offseted(Unit offset) const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;
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
		template<class Unit, unsigned int _size, class ImageType, int DataPerPixel> class Polygone : public virtual Bounded_Curve<Unit, ImageType, DataPerPixel>, virtual Shape<Unit, ImageType, DataPerPixel> {
		public:
			Polygone(std::array<Point<Unit, ImageType, DataPerPixel>, _size>);
			virtual const std::array<Point<Unit, ImageType, DataPerPixel>, _size>& get_summet();
			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel>&) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;

			unsigned constexpr int size();
		private:
			//the summet of the plygone
			std::array<Point<Unit, ImageType, DataPerPixel>, _size> _summet;
			//for is_in 
			std::array<Unit, _size> _constant;
			std::array<Unit, _size> _multiple;
			//for is_near or other uses the side of the polygone 
			std::array<Segment<Unit, ImageType, DataPerPixel>, _size> _side;
		};
		//specifate for 3 corner and 4 corner
		template<class Unit, class ImageType, int DataPerPixel> class Triangle : public Polygone<Unit, 3, ImageType, DataPerPixel> {
		};
		template<class Unit, class ImageType, int DataPerPixel> class Quadrilater : public Polygone<Unit, 4, ImageType, DataPerPixel> {
			Quadrilater(Rectangle<Unit, ImageType, DataPerPixel>);
		};
		template<class Unit, unsigned int _size, class ImageType, int DataPerPixel> class Polyline : public virtual Bounded_Curve<Unit, ImageType, DataPerPixel>, virtual Shape<Unit, ImageType, DataPerPixel> {
		public:
			Polyline(std::array<Point<Unit, ImageType, DataPerPixel>, _size>);
			virtual const std::array<Point<Unit, ImageType, DataPerPixel>, _size>& get_summet();
			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;

			unsigned constexpr int size();
		private:
			//the summet of the polyline
			std::array<Point<Unit, ImageType, DataPerPixel>, _size> _summet;
			//for is_near or other uses the side of the polyline 
			std::array<Segment<Unit, ImageType, DataPerPixel>, (_size - 1)> _side;
		};
		//dynamic equivalent of polygone and polyline so that they can hav free value of n 
		/*
		more free can be use for getting the result of an intersection or union of polygones etc...
		*/
		template<class Unit, class ImageType, int DataPerPixel> class DynamicPolygone : public  virtual Shape<Unit, ImageType, DataPerPixel>, virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {
		public:
			DynamicPolygone(std::vector<Point<Unit, ImageType, DataPerPixel>>);
			template<unsigned int n>DynamicPolygone(Polygone<Unit, n, ImageType, DataPerPixel>);
			virtual const std::vector<Point<Unit, ImageType, DataPerPixel>>& get_summet() const;
			virtual bool is_in(const Point<Unit, ImageType, DataPerPixel> & p) const;
			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;

			unsigned int size();
		private:
			//the summet of the plygone
			std::vector<Point<Unit, ImageType, DataPerPixel>> _summet;
			//for is_in 
			std::vector<Unit> _constant;
			std::vector<Unit> _multiple;
			//for is_near or other uses the side of the polygone 
			std::vector<Segment<Unit, ImageType, DataPerPixel>> _side;
		};
		template<class Unit, class ImageType, int DataPerPixel> class DynamicPolyline : public virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {
		public:
			DynamicPolyline(std::vector<Point<Unit, ImageType, DataPerPixel>>);
			template<unsigned int n> DynamicPolyline(Polyline<Unit, n, ImageType, DataPerPixel>);
			virtual const std::vector<Point<Unit, ImageType, DataPerPixel>>& get_summet();
			virtual bool is_near(const Point<Unit, ImageType, DataPerPixel> &) const;
			virtual void set_thickness(Unit min_distance);
			virtual const Unit& get_thickness() const;

			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle() const;
			virtual const Rectangle<Unit, ImageType, DataPerPixel>& get_outer_rectangle_thick() const;

			unsigned int size();
		private:
			//the summet of the polyline
			std::vector<Point<Unit, ImageType, DataPerPixel>> _summet;
			//for is_near or other uses the side of the polyline 
			std::vector<Segment<Unit, ImageType, DataPerPixel>> _side;
		};
		template<class Unit, class ImageType, int DataPerPixel> class BesierCurve : public  virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {

		};
		template<class Unit, class ImageType, int DataPerPixel> class Circle : public virtual Shape<Unit, ImageType, DataPerPixel>, virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {

		};
		template<class Unit, class ImageType, int DataPerPixel>class CircleArc : public virtual Shape<Unit, ImageType, DataPerPixel>, virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {

		};
		template<class Unit, class ImageType, int DataPerPixel> class Elipse : public virtual Shape<Unit, ImageType, DataPerPixel>, virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {

		};
		template<class Unit, class ImageType, int DataPerPixel> class ElipseArc : public virtual Shape<Unit, ImageType, DataPerPixel>, virtual Bounded_Curve<Unit, ImageType, DataPerPixel> {

		};

	}
		
}