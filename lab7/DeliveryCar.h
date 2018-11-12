/*
 * DeliveryCar.h
 *
 *  Created on: 2017Äê11ÔÂ12ÈÕ
 *      Author: Shengrui
 */

#ifndef DELIVERYCAR_H_
#define DELIVERYCAR_H_
#include "Vehicle.h"

class DeliveryCar : protected Vehicle{
private:
	 int chargePerMile;
public:
	DeliveryCar(int n, Color c, int m,int charge): Vehicle(n,c,m),chargePerMile(charge){}
	virtual ~DeliveryCar(){
    cout<<"Calling Vehicle's destructor on the following delivery car:"<<endl;
    print();
	}
	 void setChargePerMile(int c){
		 chargePerMile = c;
	 }

	 int getCharge(){
		 return chargePerMile;
	 }
	 void print() const{
		 string wc[] = {"Black", "White", "Sliver", "Grey", "Red", "Blue"};
		 cout<<"Information of the delivery car:"<<endl;
		 cout<<"Engine: "<<getEngine()<<"   Color: "<<wc[getColor()]<<"   Current Mileage: "<<getMileage()<<endl;
		 cout<<"Charges per mile: "<<chargePerMile<<endl;
		 cout<<"Calculated charges: "<<getMileage()*chargePerMile<<endl;
	 }
    using Vehicle::start;
    using Vehicle::brake;


};




#endif /* DELIVERYCAR_H_ */
