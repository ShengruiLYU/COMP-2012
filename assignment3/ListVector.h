//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef LISTVECTOR_H_
#define LISTVECTOR_H_

#include "Pair.h"



//Vectors are sequence containers representing arrays that can change in size
//ListVector is backed by a singly linked list
template<typename T>
class ListVector
{

	//this is the Node struct used for representing a node in the linked list
	//this shall be used only in this class
	struct Node
	{
		T* data; //a pointer that points to the data which is of type T
		Node* next; //a pointer that points to the next node in the linked list
		            //it shall point to NULL if this node is the last node of the list
	};

public:


	//constructor, you should initialize head to NULL
	ListVector();

	//destructor, you should delete all the linked list nodes here
	//but do NOT delete the data pointed by the "data" pointer in the node as they are supposed to be allocated and also destructed outside
	~ListVector();

	//you can assume the given n is always in the range of [0, 1023]
	//if n is larger than or equal to the member variable size, that means the size is not enough
	//in that case, you need to expand the linked list by adding new nodes
	//for example, let's say the size at the beginning is 0
	//so the head basically points to NULL
	//if the user writes 65 to listVector[2] where listVector is a ListVector (e.g. with statement "listVector[2] = new int(65);")
	//that means the required size is 3
	//therefore you will enlarge the linked list to be of exactly size 3, and it would have the following content ( -> indicates what the next pointer points to ):
	//(empty node which is also the head node) -> (empty node) -> (node that has its data set to a new int of value 65) -> NULL
	//note that, empty nodes must be created to fill the void in the middle, and you should have every empty node's data points to NULL
	//after that, if the user writes 999 to arrayVector[8] (e.g. with statement "listVector[8] = new int(999);"), that means the required size becomes exactly 9
	//therefore you will expand the linked list to be of size 9, all existing content should be kept, and it would have the following content:
	//(empty node which is also the head node) -> (empty node) -> (node that has its data set to a new int of value 65) -> (empty node) -> (empty node) -> (empty node) -> (empty node) -> (empty node) -> (node that has its data set to a new int of value 999) -> NULL
	//finally, no matter whether a linked list enlargement was performed, you should return the reference to the (n+1)-th linked list node's data at the end
	//so basically listVector[2] returns the reference of the data of the 3rd linked list node
	//as a result, the user can read/write from/to the underlying linked list using listVector[n] for any n in the range of [0, 1023]
	//notice that reading from the vector can also trigger a resize of the underlying linked list as long as n is larger than or equal to size
	//e.g. a value checking statement like "if(listVector[2] == NULL) return true;" can also trigger an linked list enlargement (to size 3) if the original linked list size is less than 3
	T*& operator[] (int n);

	//return the total number of nodes in the linked list
	int getSize() const;

private:
	Node* head; //this is the head pointer of the linked list
};

#include "ListVector.tpp"

#endif /* LISTVECTOR_H_ */
