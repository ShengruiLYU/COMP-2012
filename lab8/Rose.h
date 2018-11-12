/*
 * Rose.h
 *
 *  Created on: 2017Äê11ÔÂ22ÈÕ
 *      Author: Shengrui
 */

#ifndef ROSE_H_
#define ROSE_H_
#include "Plant.h"
//#include <iostream>
//using namespace std;
class Rose: public Plant{
private:
	int type;
public:
	Rose(int t): type(t),Plant(){}
	void calculatePrice() {
		cout<<"Rose::calculatePrice() is called! "<<endl;
			switch(type) {
			case 0:
				setPrice(100.0);break;
			case 1:
			     setPrice(200.0);break;
			case 2:
				setPrice(300.0) ; break;
			case 3:
				setPrice(400.0); break;
			}

		}

};




#endif /* ROSE_H_ */
