/*
 * Vehicle.h
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: Shengrui
 */

#ifndef VEHICLE_H_
#define VEHICLE_H_

#include "Engine.h"
#include <iostream>
using namespace std;
class Vehicle : private Engine
{
public:
	Vehicle(int nc, Color color, int mileage):Engine(nc),color(color),mileage(mileage){} // Constructor
	Color getColor() const{
		return color;
	};
	int getMileage() const{
		return mileage;
	}
	int getEngine() const{
		return getNumCylinder();
	}
	virtual ~Vehicle(){
		cout<<"Calling Car's destructor on the following Vehicle:"<<endl;
		print();
	}

	// Start the engine and print the information.
	// Please refer to the sample I/O.
	void start(){
		cout<<"Vehicle with "<<getNumCylinder()<<"-cylinder engine started"<<endl;
	}

	// Stop the engine and update the data member "mileage" by adding the traveled distance to it.
	// Print the information.
	// Please refer to the sample I/O.
	void brake(int distance){
		mileage+=distance;
			cout<<"Vehicle with "<<getNumCylinder()<<"-cylinder engine stopped"<<endl;
			cout<<"Driving distance: "<<distance<<endl;

	}

	// Print the information of the car. (Please refer to the I/O sample)
	virtual void print() const{
		string wc[] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
		cout<<"Engine: "<<getNumCylinder()<<"   Color: "<<wc[color]<<"   Current Mileage: "<<mileage<<endl;

	}

private:

	Color color;	// Color of the car
	int mileage;	// Total mileage

};



#endif /* VEHICLE_H_ */
