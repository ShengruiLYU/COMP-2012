/*
 * Plant.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
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
