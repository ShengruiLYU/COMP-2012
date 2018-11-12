/*
 * PoliceCar.cpp
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: Shengrui
 */
#include "PoliceCar.h"
#include <iostream>
using namespace std;

PoliceCar::PoliceCar(int nc, Color c, int m, bool action):Car(nc,c,m),inAction(action){}
PoliceCar::~PoliceCar(){
	cout<<"Calling PoliceCar's destructor on the following police car:"<<endl;
	print();
}
bool PoliceCar::getInAction() const{
	return inAction;
}
void PoliceCar::setInAction(bool action){
	inAction = action;
}
void PoliceCar::print() const{
	string wc[] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
	cout<<"Information of the police car:"<<endl;
	cout<<"Engine: "<<getEngine()<<"   Color: "<<wc[getColor()]<<"   Current Mileage: "<<getMileage()<<endl;
	if(!inAction)
	cout<<"State: not in action"<<endl;
	else
	cout<<"State: in action"<<endl;
}
