/*
 * Animal.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
 *      Author: Shengrui
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include "Organism.h"
#include <string>
#include <iostream>
using namespace std;
class Animal:public Organism{
private:
string name;
public:
Animal(string n): name(n),Organism(){}
virtual void calculatePrice() = 0;
string getName() const{
	return name;
}

};




#endif /* ANIMAL_H_ */
