//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef ARRAYVECTOR_H_
#define ARRAYVECTOR_H_

#include "Pair.h"

//Vectors are sequence containers representing arrays that can change in size
//ArrayVector is backed by a dynamic array of pointers, each of which points to either NULL or a T object
template<typename T>
class ArrayVector
{
public:
	//constructor, you should initialize array to NULL and size to 0
	ArrayVector();

	//delete array but do NOT delete the elements array[i] as they are supposed to be allocated and also destructed outside
	//hint: use delete [] or delete ?
	~ArrayVector();

	//return the size of the underlying dynamic array
	int getSize() const;

	//you can assume the given n is always in the range of [0, 1023]
	//if n is larger than or equal to the member variable size, that means the size is not enough
	//in that case, you need to enlarge the array
	//the size of the array is always the smallest power of 2 that is not less than the required size
	//for example, let's say the size at the beginning is 0
	//if the user writes 65 to arrayVector[2] where arrayVector is a ArrayVector<int> (e.g. with statement "arrayVector[2] = new int(65);")
	//that means the required size is 3
	//and that would imply that the size of the array should be enlarged to 4 (that is the smallest power of 2 that is not less than 3)
	//therefore you will enlarge the array to be of size 4, and it would have the following content:
	//NULL, NULL, 65, NULL
	//(note that, you should fill all the empty array entries with NULL, even though the user haven't used them yet)
	//after that, if the user writes 999 to arrayVector[8] (e.g. with statement "arrayVector[8] = new int(999);")
	//that means the required size becomes 9
	//and that would imply that the size of the array should be enlarged to 16 (that is the smallest power of 2 that is not less than 9)
	//therefore you will enlarge the array to be of size 16, all existing content should be kept, and it would have the following content:
	//NULL, NULL, 65, NULL, NULL, NULL, NULL, NULL, 999, NULL, NULL, NULL, NULL, NULL, NULL, NULL
	//finally, no matter whether an array enlargement is needed, you should return the reference to array[n] at the end
	//as a result, the user can read/write from/to the underlying dynamic array using arrayVector[n] for any n in the range of [0, 1023]
	//notice that reading from the vector can also trigger a resize of the underlying array as long as n is larger than or equal to size
	//e.g. a value checking statement like "if(arrayVector[2] == NULL) return true;" can also trigger an array enlargement (to size 4) if the original array size is less than 4
	T*& operator[] (int n);

private:
	T** array; //the underlying dynamic array of pointers, each of which points to either NULL or a T object
	int size; //the size of the underlying dynamic array, this needs to be ALWAYS a power of 2 that is not bigger than 1024. Therefore: 0, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
};

#include "ArrayVector.tpp"

#endif /* ARRAYVECTOR_H_ */
