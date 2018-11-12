/*
 * Pig.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
 *      Author: Shengrui
 */

#ifndef PIG_H_
#define PIG_H_
#include <string>
#include "Animal.h"
//#include <iostream>
//using namespace std;
class Pig: public Animal{
private:
	double weight;
	double priceperweight;
public:
	Pig(double w, double p, string n): weight(w),priceperweight(p),Animal(n){}
	void calculatePrice(){
		cout<<"Pig::calculatePrice() is called! "<<endl;
		 setPrice(weight*priceperweight);
	}
};




#endif /* PIG_H_ */
