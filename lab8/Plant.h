/*
 * Plant.h
 *
 *  Created on: 2017��11��22��
 *      Author: Shengrui
 */

#ifndef PLANT_H_
#define PLANT_H_
#include "Organism.h"
using namespace std;
class Plant :public Organism{
public:
	Plant():Organism(){}
	virtual void calculatePrice() = 0;
};



#endif /* PLANT_H_ */
