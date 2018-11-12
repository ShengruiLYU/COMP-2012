/*
 * Stack.cpp

 *
 *  Created on: Oct 21, 2017
 *      Author: lixua
 */
#include "Stack.h"
#include <iostream>
Stack::Stack(){
	n=0;
}
void Stack::push(int a){
	if(n<MAX_SIZE){
		content[n] = a;
		n++;
	}

}
int Stack::pop(){
	if(!empty()){
		--n;
		return content[n];
	}

}
int Stack::top() const{
	if(!empty()){
		return content[n-1];
	}

}
bool Stack::empty()const{
	if(n<=0)
		return true;
	else
		return false;

}



