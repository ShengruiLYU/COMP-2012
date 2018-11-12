/*
 * Stack.h
 *
 *  Created on: Oct 21, 2017
 *      Author: lixua
 */

#ifndef STACK_H_
#define STACK_H_

const int MAX_SIZE = 1024;

//First-in-first-out
class Stack
{
private:
	int content[MAX_SIZE]; //stores the elements
	int n; //number of elements

public:
	Stack();
	void push(int a);
	int pop();
	int top() const;
	bool empty()const;

};



#endif /* STACK_H_ */
