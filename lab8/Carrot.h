/*
 * Carrot.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
 *      Author: Shengrui
 */

#ifndef CARROT_H_
#define CARROT_H_
#include "Plant.h"
//#include <iostream>
//using namespace std;
class Carrot: public Plant{
private:
	double weight;
	double priceperweight;
public:
	Carrot(double w, double p): weight(w),priceperweight(p),Plant(){}
	void calculatePrice(){
		cout<<"Carrot::calculatePrice() is called! "<<endl;
		setPrice(weight*priceperweight);
	}
};




#endif /* CARROT_H_ */
