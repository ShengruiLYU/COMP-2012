/*
 * Organism.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
 *      Author: Shengrui
 */

#ifndef ORGANISM_H_
#define ORGANISM_H_
#include <iostream>
using namespace std;
class Organism{
private:
	double price;
public:
	Organism(double p=0.0):price(p){}
	void setPrice(double p) {price =p;}
	double getPrice()const{return price;}
	virtual void calculatePrice() = 0;
};




#endif /* ORGANISM_H_ */
