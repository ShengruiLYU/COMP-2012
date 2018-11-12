#include "Set.h"
using namespace std;

// Default constructor: Construct an empty set
Set::Set() {
	elements = NULL;
	size = 0;
}

// Other constructor: Initialize the data members with the given parameters 
Set::Set(const int elements[], int size)
{
	Set::elements  = new int[size];
	Set::size = size;
	for(int i =0;i<size;i++){
		Set::elements[i] = elements[i];
	}
}

// Copy constructor: Perform deep copying
// Hint: Make use of assignment operator function
Set::Set(const Set& s)
{
	*this = s;
}

// Destructor: De-allocate dynamic memory
Set::~Set()
{
	delete[] elements;
	elements = NULL;
}

// Return the cardinality of the set, i.e., the size
int Set::cardinality() const
{
	return size;
}

// Return the element's index if it exists. Otherwise return -1
int Set::findElement(const int& element) const
{
	for(int i =0;i<size;i++){
		if(elements[i] == element){
			return i;
		}
	}
	return -1;
}

// Return true if the element exists, otherwise return false
bool Set::isExist(const int& element) const
{
	for(int i =0;i<size;i++){
		if(elements[i] == element){
			return true;
		}
	}
	return false;
}

// Allocate a new array of size "size+1", copy all the existing elements over and
// add the new element to the last position of the new array
void Set::addElement(const int& element)
{
	if(!isExist(element)){
	int* tmp_elements = new int[size+1];
	for(int i =0;i<size;i++){
		tmp_elements[i] = elements[i];
	}
	tmp_elements[size] = element;
	size ++;
	delete[] elements;
	elements = tmp_elements;}

}

// Check if the element is in the set.
// If it is in the set, allocate a new array and copy all the existing elements over except
// the element to be deleted.
// Return true if the element is found and deleted. Otherwise return false
bool Set::removeElement(const int& element)
{
	if(isExist(element)){
		int* tmp_elements = new int[size-1];
		for(int i=0,j=0;i<size;i++,j++){
			if(i == findElement(element)){
				i++;
			}
			tmp_elements[j] = elements[i];
		}
		delete[] elements;
		elements = tmp_elements;
		size--;
		return true;
	}
	else
		return false;
}

// Overload operator+ to support union operation of two set objects
// Note: Resulting set of A + B = { x : x in A or x in B }
Set Set::operator+(const Set& B)const{
	Set sum = *this;
	for(int i = 0;i<B.cardinality();i++){
		sum.addElement(B.elements[i]);
	}
	return sum;
}



// Overload operator- to support difference operation of two set objects
// Note: Resulting set of A - B = { x : x in A and x not in B }
Set Set::operator-(const Set& B)const{
	Set dif = *this;
	for(int i = 0;i<B.cardinality();i++){
		dif.removeElement(B.elements[i]);
	}
	return dif;
}


// Overload assignment operator function
// Note: Deep copying is required
const Set& Set::operator=(const Set& B){
	if(this != &B){
	size = B.size;
	delete[] this->elements;
	this->elements = new int [size];
	for(int i =0;i<size;i++){
		this->elements[i] = B.elements[i];
	}
	return *this;}
	else
		return *this;

}


// Overload equality operator function
bool Set::operator==(const Set& B)const{
	if(size == B.size){
		for (int i = 0; i<size; i++){
			if(!isExist(B.elements[i])){
				return false;
			}
		}
		return true;
	}
	else
		return false;
}



// Overload operator<< to allow output of objects in Set type
ostream& operator<< (ostream& os, const Set& a){
	os << "{" ;
	for(int i =0;i<a.size-1;i++){
		os<< a.elements[i] << ", ";
	}
	os<< a.elements[a.size-1]<<"}";
	return os;
}

