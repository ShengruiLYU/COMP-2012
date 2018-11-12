//
// Operations on Binary Tree
//

#ifndef LAB9_BTREEEXERCISES_H
#define LAB9_BTREEEXERCISES_H

#include <iostream>
#include <queue>
#include "BtreeNode.h"

template<class T>
int treeHeight(BtreeNode<T> *root){
	if(root == NULL){
		return -1;
	}
	else{
		int height = treeHeight(root->get_left())>treeHeight(root->get_right()) ? treeHeight(root->get_left()) : treeHeight(root->get_right());
		return 1+height;
	}
}

template<class T>
int countNodes(BtreeNode<T> *root){
	if(root == NULL){
		return 0;
	}
	else {
		return countNodes(root->get_left())+countNodes(root->get_right())+1;
	}
}

template<class T>
BtreeNode<T> *mirror(BtreeNode<T> *root){

	if(root == NULL){
		return NULL;
	}
	else{
		BtreeNode<T> *right =  mirror(root->get_left());
		BtreeNode<T> * left = mirror(root->get_right());
		BtreeNode<T> * new_root = new BtreeNode<T>(root->get_data(), left, right);
		return new_root;
	}
}

template<class T>
bool isComplete(BtreeNode<T> *root){
	if(root == NULL){
		return true;
	}
	int height = treeHeight(root);
	BtreeNode<T> *p = root->get_left();
	if(height == 0){
		return true;
	}
	if ( isComplete(root->get_left()) == false||isComplete(root->get_right())==false){
		return false;
	}
	else{
		int i =0;
		while(p!=NULL){
			p = p->get_right();
			i++;
		}
		if(i<height){
			return false;
		}
		else
			return true;
	}
}

#endif //LAB9_BTREEEXERCISES_H
