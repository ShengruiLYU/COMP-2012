/*
 * PointSet.cpp
 * 
 */

#include "PointSet.h"
#include <iostream>
using namespace std;


PointSet::PointSet()
{
   // This function is already completed.

   cout << "Initialized by PointSet's default constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked
   numPoints = 0;
   points = NULL;
}

PointSet::PointSet(const Point3D points_in[], int num_in)
{
   cout << "Initialized by PointSet's other constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   numPoints = num_in;

   points = new Point3D [num_in];
   
   for (int i = 0;i<num_in;i++){

	   points[i]=points_in[i];
   }
}

PointSet::PointSet(const PointSet & s)
{
   cout << "Initialized by PointSet's copy constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   this->numPoints = s.numPoints;
   
   points = new Point3D[s.numPoints];

   for(int i =0; i< s.numPoints;i++){

	   this->points[i] = s.points[i];
   }

}

PointSet::~PointSet()
{
    cout<<"PointSet's destructor!" <<endl;
    // This cout statement is for learning purpose only, which shows when the desstructor will be invoked

     // TODO: add your code here
    if (points!=NULL){
    delete [] points;
    points = NULL;
    }
}


void PointSet::addPoint(const Point3D& p)
{
   // TODO: add your code here



	 Point3D* temp = new Point3D[numPoints+1];

	 for (int i =0; i< numPoints; i++){

		 temp[i] = points[i];
	 }

	 temp[numPoints]=p;

	 numPoints+=1;

	 if(points != NULL)
	 delete [] points;

	 points = temp;
	 temp = NULL;

	

}

bool PointSet::contains(const Point3D& p) const
{
   // TODO: add your code here
	
	for (int i =0; i<numPoints;i++){
		if(p.equal(points[i])){
			return true;
		}
	}

	return false;

}

void PointSet::removeFirstPoint()
{
   // TODO: add your code here
	if(numPoints ==0){
		cout<<"No points";
		return;
	}




	for (int i = 0;i< numPoints-1;i++){

		points[i]=points[i+1];
	}
    numPoints--;
}

void PointSet::print() const
{
  // This function is already completed.

   if (numPoints == 0) {
      cout << "The PointSet is empty!" << endl;
      return;
   }
   cout << "Number of points: " << numPoints << endl;;
   cout << "points: " << endl;

   for (int i = 0; i < numPoints; i++)
   {

      points[i].print();
      cout << endl;
   }
}

