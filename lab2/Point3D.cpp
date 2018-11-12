/*
 * Point3D.cpp
 *
 */
 
#include <iostream>

#include "Point3D.h"


using namespace std;

// Default constructor. It creates a point (0,0,0)
Point3D::Point3D()
{
    x = 0;
    y = 0;
    z = 0;
}

//  Copy constructor
Point3D::Point3D(const Point3D& p)
{
    x = p.x;
    y = p.y;
    z = p.z;
}

//  Conversion constructor that can convert a double to a Point3D object
Point3D::Point3D(double x_in)
{
   x = x_in;
   y = 0;
   z = 0;
}

//  Construct a point with given coordinates
Point3D::Point3D(double x_in, double y_in, double z_in)
{
    x = x_in;
    y = y_in;
    z = z_in;
}

//Check whether two 3D points are the same
bool Point3D::equal(const Point3D& p) const
{
	double diffx = this->x - p.x;
	double diffy = this->y - p.y;
	double diffz = this->z - p.z;

	if (diffx<0){
		diffx = -diffx;
	}
	if (diffy<0){
		diffy = -diffy;
	}
	if (diffz<0){
		diffz = -diffz;
	}
    return ((diffx<0.01) && (diffy<0.01) && (diffz<0.01));
}

//  Print the 3D point
void Point3D::print() const
{
    cout << "(" << x << "," << y << "," << z << ")";
}



