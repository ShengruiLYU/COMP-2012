/*
 * Dog.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
 *      Author: Shengrui
 */

#ifndef DOG_H_
#define DOG_H_
#include "Animal.h"
//#include <iostream>
class Dog : public Animal{
private:
	int species;
public:
	Dog(int s, string n):Animal(n),species(s){}
	void calculatePrice() {
		cout<<"Dog::calculatePrice() is called! "<<endl;
		switch(species){
		case 0:
			setPrice(150.0);break;
		case 1:
		    setPrice(300.0);break;
		case 2:
			setPrice(450.0);break;

		}
	}
};




#endif /* DOG_H_ */
