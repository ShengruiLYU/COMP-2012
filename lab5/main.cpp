#include "Queue.h"
#include "Stack.h" // TODO: implement a stack using  an array in Stack.h and Stack.cpp (to be created by yourself)
#include <iostream>
using namespace std;

// checkBox: Determine whether the switch box is routable
bool checkBox(Queue pins, int n)
{

	// TODO: Returen true if it is routable, false otherwise
	// Use Stack to implement this part
	Stack stack;
	for(int i = 0;i<n;i++){
		int out = pins.dequeue() ;
		if(out == stack.top())
			stack.pop();
		else
			stack.push(out);
	}
	if(stack.empty())
		return true;
	else
		return false;
}

int main()
{
	int n;
	Queue pins;

	cout << "** Assumption: The number of pins is even and it is greater than or equal to  2 **" << endl ;

	cout << "Type number of pins in switch box: " ;
	cin >> n ;

	cout << "Type numbers for pins 1 through " << n << ": " ;
	int k;
	for (int i=0;i<n;i++)
	{
		cin >> k;
		pins.enqueue(k);
	}

	bool result = checkBox(pins, n);
	if ( result ) {
		cout << "The switch box is routable" << endl ;
	} else {
		cout << "The switch box is NOT routable" << endl ;
	}

	return 0;
}
