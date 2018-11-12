#include "Set.h"
using namespace std;

// Default constructor: Construct an empty set
Set::Set() {

}

// Other constructor: Initialize the data members with the given parameters 
Set::Set(const int elements[], int size)
{
	this->size = size;
	this->elements = new int[size];
	for (int i=0;i<size;i++){

		this->elements[i] =elements[i];
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
	if (elements !=NULL){
		delete[] elements;
	}

}

// Return the cardinality of the set, i.e., the size
int Set::cardinality() const
{
 return size;
}

// Return the element's index if it exists. Otherwise return -1
int Set::findElement(const int& element) const
{
for (int i=0;i<size;i++){
	if(elements[i]==element){
		return i;

	}
}

return -1;


}

// Return true if the element exists, otherwise return false
bool Set::isExist(const int& element) const
{
	for (int i=0;i<size;i++){
		if(elements[i]==element){
			return true;

		}
	}

	return false;
}

// Allocate a new array of size "size+1", copy all the existing elements over and
// add the new element to the last position of the new array
void Set::addElement(const int& element)
{

	if (isExist(element)){
		return;
	}
	int *temp  = elements;

	elements = new int [size+1];

	for (int i=0;i<size;i++){
		elements[i]=temp[i];
	}

	elements[size]=element;
	size++;

	if (temp!=NULL){
		delete []temp;
		temp = NULL;
	}



//	if(!isExist(element)){
//		int* tmp_elements = new int[size+1];
//		for(int i =0;i<size;i++){
//			tmp_elements[i] = elements[i];
//		}
//		tmp_elements[size] = element;
//		size ++;
//		delete[] elements;
//		elements = tmp_elements;}

}

// Check if the element is in the set.
// If it is in the set, allocate a new array and copy all the existing elements over except
// the element to be deleted.
// Return true if the element is found and deleted. Otherwise return false
bool Set::removeElement(const int& element)
{

	if (!isExist(element)){
	 return false;
      }

        int index = findElement(element);


        int * temp = elements;

         elements = new int[size-1];


         for (int i=0;i<index;i++){
        	 elements[i]= temp[i];


         }

         for (int i=index;i<size-1;i++){
        	 elements[i]= temp[i+1];
         }

         if (temp != NULL){
        	 delete[] temp;
        	 temp = NULL;
         }
         return true;

//	if(isExist(element)){
//			int* tmp_elements = new int[size-1];
//			for(int i=0,j=0;i<size;i++,j++){
//				if(i == findElement(element)){
//					i++;
//				}
//				tmp_elements[j] = elements[i];
//			}
//			delete[] elements;
//			elements = tmp_elements;
//			size--;
//			return true;
//		}
//		else
//			return false;

}

// Overload operator+ to support union operation of two set objects
// Note: Resulting set of A + B = { x : x in A or x in B }
Set Set::operator+(const Set& b)const{

	Set c (*this);

	for (int i=0;i<b.size;i++){
		if (!(this->isExist(b.elements[i])) ){

			int a = b.elements[i];
			c.addElement(a);

		}
	}

	return c;


}



// Overload operator- to support difference operation of two set objects
// Note: Resulting set of A - B = { x : x in A and x not in B }
Set Set::operator-(const Set& b)const{

	Set c(*this);
	for (int i=0;i<b.size;i++){
		if ((this->isExist(b.elements[i])) ){

			c.removeElement(b.elements[i]);
		}
	}

	return c;


}


// Overload assignment operator function
// Note: Deep copying is required

const Set& Set::operator=(const Set& b){
	if (this == &b){
		return *this;
	}

	if (this->elements != NULL){
		delete []elements;
	}
	this->size = b.size;
	elements =  new int [size];

	for (int i =0;i <size;i++){
		this->elements[i]= b.elements[i];
	}

	return *this;
}



// Overload equality operator function
bool Set::operator==(const Set& b)const{
	if (this->size!=b.size){
		return false;
	}

	for (int i=0;i<b.size;i++){
		if (!this->isExist(b.elements[i])){
			return false;
		}
	}

	return true;
}




// Overload operator<< to allow output of objects in Set type

ostream& operator<<(ostream& os, const Set&a){

	for (int i=0;i<a.size;i++){
		os<<a.elements[i]<<"  ";
	}
	return os;
}
