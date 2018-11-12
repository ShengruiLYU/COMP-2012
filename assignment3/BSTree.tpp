//SUBMIT THIS FILE
//YOU CANNOT INCLUDE ANY ADDITIONAL LIBRARY

#include "BSTree.h"

template<typename Container, typename KeyType, typename ValueType>
BSTree<Container,KeyType,ValueType>::~BSTree(){


	int size = data.getSize();

	if (size!=0){
	for (int i=0;i<size;i++){
		if(data[i]!=NULL){
			delete data[i];




			data[i] = NULL;
		}

	}
	}

}

template<typename Container, typename KeyType, typename ValueType>
bool BSTree<Container, KeyType,ValueType>::add(KeyType key, ValueType value){
	int curr =0;
	bool found =false;
	int size = data.getSize();

	while(!found && data[curr]!=NULL){
		if(key < data[curr]->getKey()){
			curr = 2*curr +1;
		}
		else if(key > data[curr]->getKey()){
			curr = 2*curr +2;
		}
		else{
			found = true;
		}

	}

	if(!found){




		data[curr] = new Pair<KeyType, ValueType>(key, value);


//		bstree_count ++;

		return true;

	}
	else{
		return false;
	}

}


template<typename Container, typename KeyType, typename ValueType>
bool BSTree<Container, KeyType, ValueType>::remove(KeyType key){
	int curr =0;
		bool found =false;
		int size = data.getSize();

		while(!found && data[curr]!=NULL){
			if(key < data[curr]->getKey()){
				curr = 2*curr +1;
			}
			else if(key > data[curr]->getKey()){
				curr = 2*curr +2;
			}
			else{
				found = true;
			}

		}

	bool isLeaf = 	(data[2*curr+1]==NULL)&&(data[2*curr+2]==NULL);

	if(found&&isLeaf){
		delete data[curr];

//		bstree_count--;

		data[curr] = NULL;

		return true;

	}

	return false;


}

template<typename Container, typename KeyType, typename ValueType>
ValueType BSTree<Container, KeyType, ValueType>::getValue(KeyType key){
	int curr =0;
			bool found =false;
			int size = data.getSize();

			while(!found && data[curr]!=NULL){
				if(key < data[curr]->getKey()){
					curr = 2*curr +1;
				}
				else if(key > data[curr]->getKey()){
					curr = 2*curr +2;
				}
				else{
					found = true;

					return data[curr]->getValue();
				}

			}

			if(!found){
				if (typeid(data[0]->getValue()) == typeid(string))
				{ return "";}
			    else{
				        return 0;}

			}




}

int pow2(int base, int exponent)
{
    int result = 1;
    while(exponent--) result*=base;
    return result;
}

template<typename Container, typename KeyType, typename ValueType>
int BSTree<Container,KeyType,  ValueType>::getHeight(){

	int size = data.getSize();

	if(size>0){
	while((size>0)&&data[size-1] == NULL){
		if(size>0){
		--size;
		}
	}
	}
	int ex = 1;
	while(pow2(2,ex)<=size){
		++ex;
	}

	return (ex-1);

}



