//============================================================================
// Name        : test'.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <typeinfo>
using namespace std;
 class A{
 public:

	int a;
	A(){}






 };


 class B : public A{

 public :
	B(){}



 };


//class C : public B{
//
//	 void haha(){
//		 cout<<"haha in C"<<endl;
//	 }
// };


int main() {

	A * a = new B;
	cout<< typeid(*a).name()<<endl;



}
