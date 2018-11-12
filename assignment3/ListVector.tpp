//SUBMIT THIS FILE
//YOU CANNOT INCLUDE ANY ADDITIONAL LIBRARY

#include "ListVector.h"

template<typename T>
ListVector<T>::ListVector(){
	head = NULL;
}



template<typename T>
ListVector<T>::~ListVector(){
	Node* curr = head;

    Node* next_node = NULL;

	while (curr!= NULL){
		next_node = curr->next;
		delete curr;



		curr = next_node;
	}
	head = NULL;
}

template<typename T>
int ListVector<T>::getSize() const{
	int result =0;

	Node* curr = head;
	while(curr != NULL){
		++result;
		curr = curr->next;
	}
	return result;

}

template<typename T>
T*& ListVector<T>::operator[] (int n){


	if(n >= this->getSize()){

		if(head == NULL){




			head  = new Node;
			head->data = NULL;
			head->next = NULL;
		}

		int count = n+1-this->getSize();
		Node*p = head;

		while(p->next != NULL){
			p=p->next;
		}

		for(int i = 0;i<count;i++){
			p->next = new Node;





			p->next->data = NULL;
			p->next->next = NULL;

			p=p->next;

		}


	}
	Node* target = head;
	for(int i =0;i<n;i++){
		target = target->next;
	}


	return target->data;
}











