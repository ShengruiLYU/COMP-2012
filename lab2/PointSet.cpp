#include "PointSet.h"
#include <iostream>
using namespace std;


PointSet::PointSet()
{
   // This function is already completed.

   cout << "Initialized by PointSet's default constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   numPoints = 0;
}

PointSet::PointSet(const Point3D points_in[], int num_in)
{
   cout << "Initialized by PointSet's parameterized constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here

for (int i =0; i< num_in; i++){
	points[i]= points_in[i];
}

   numPoints = num_in;
}

PointSet::PointSet(const PointSet & s)
{
   cout << "Initialized by PointSet's copy constructor" << endl;
   // This cout statement is for learning purpose only, which shows when the constructor will be invoked

   // TODO: add your code here
   this->numPoints = s.numPoints;
  for (int i =0; i< s.numPoints;i++){
	  this->points[i] = s.points[i];
	 }
}


void PointSet::addPoint(const Point3D& p)
{
   // TODO: add your code here
	if (numPoints==MAX_NUM_POINTS){
		cout<<"Insufficient array space"<<endl;
		return;
	}
	else{
	points[numPoints]=p;
	numPoints++;
	}
   
}

void PointSet::removeFirstPoint()
{
	// TODO: add your code here
	if (numPoints==0){
			cout<<"No points"<<endl;
			return;
	}
	else{
		numPoints--;
	for(int i =0; i< numPoints;i++){
		points[i]=points[i+1];
	}
	}
}

bool PointSet::contains(const Point3D& p) const
{
	// TODO: add your code here
	bool result = false;
	for(int i=0;i<numPoints;i++){
		if(points[i].equal(p)){
			result = true;
			break;
		}
	}

   return result;
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

