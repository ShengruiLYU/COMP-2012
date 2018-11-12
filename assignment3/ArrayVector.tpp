//SUBMIT THIS FILE
//YOU CANNOT INCLUDE ANY ADDITIONAL LIBRARY

#include "ArrayVector.h"

template<typename T>
ArrayVector<T>::ArrayVector(){
	array=NULL;
	size =0;
}

template<typename T>
ArrayVector<T>::~ArrayVector(){
	delete[] array;
	array = NULL;

}

template<typename T>
int ArrayVector<T>::getSize() const{
	return size;
}

template<typename T>
T*& ArrayVector<T>::operator[] (int n){
	if(n>=size){
		int temp_size = size;

		if(temp_size==0){
			temp_size= 1;
		}
		while(n>=temp_size){
			temp_size= temp_size*2;
		}

		T**temp_a = new T*[temp_size];

		for(int i=0;i<size;i++){
			temp_a[i]=array[i];
		}
		for(int i =size;i<temp_size;i++){
			temp_a[i] = NULL;
		}
		delete[] array;
		array = temp_a;
		size = temp_size;



	}
	return array[n];
}
