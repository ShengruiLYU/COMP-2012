/*
 * Car.cpp
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: Shengrui
 */

#include "Car.h"
#include <iostream>
using namespace std;

Car::Car(int nc, Color color, int mileage): engine(nc),color(color),mileage(mileage){

}
Car::~Car(){
	cout<<"Calling Car's destructor on the following car:"<<endl;
	print();
}

Color Car::getColor() const{
	return color;
}

int Car::getMileage() const{
	return mileage;
}

int Car::getEngine() const{
	return engine.getNumCylinder();
}

void Car::start(){
	cout<<"Car with "<<getEngine()<<"-cylinder engine started"<<endl;
}

void Car::brake(int distance){
	mileage+=distance;
	cout<<"Car with "<<getEngine()<<"-cylinder engine stopped"<<endl;
	cout<<"Driving distance: "<<distance<<endl;
}
void Car::print() const{
	string wc[] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};

	cout<<"Engine: "<<getEngine()<<"   Color: "<<wc[color]<<"   Current Mileage: "<<mileage<<endl;
}





