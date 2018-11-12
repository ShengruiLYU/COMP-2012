//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Tree.h"
#include "Pair.h"
#include <typeinfo>
using namespace std;

//the Binary Search Tree class
//the keys have to be unique in the tree - you need to make sure of that when performing the insertion
template<typename Container, typename KeyType, typename ValueType>
class BSTree : public Tree<Container, KeyType, ValueType>
{
public:

//	static int bstree_count;


	//empty constructor, nothing needs to be done here
	BSTree(){};

	//destructor
	//you should delete all the "new Pair<KeyType, ValueType>" living objects that you have created in this class here
	~BSTree();

	//add a node to the tree, according to the given key and value
	//you have to use the exact algorithm described in the lecture notes
	//so that you will have the exact same result as our demo and sample output
	//it should do nothing to the tree and return false when there is already a node that has the same key
	//otherwise, it should add the node and return true
	//hint: you probably will have a statement to allocate the space for the new pair, like so: "new Pair<KeyType, ValueType>(key, value);"
	bool add(KeyType key, ValueType value);

	//remove a node from the tree, according to the given key
	//for simplicity, you only need to remove leaf nodes
	//it should do nothing to the tree and return false if the node with the given key is not a leaf
	//it should do nothing to the tree and return false if there is no node that has the given key
	//otherwise, it should remove the node and return true
	bool remove(KeyType key);

	//return the node's value given a key
	//if the key is not found in the tree, you should use the following code:
	//    if (typeid(data[index]->getValue()) == typeid(string))
	//        return "";
	//    else
	//        return 0;
	ValueType getValue(KeyType key);

	//return the height of the tree
	//tree height is defined in the lecture notes
	//also, height of an empty tree (i.e. no node at all) will be 0
	//and that of a single-node tree (i.e. only the root node exists) will be 0
	int getHeight();

	using Tree<Container, KeyType, ValueType>::data; //needed to allow the use of the parent template class's member variable "data" easily
};

#include "BSTree.tpp"

#endif /* BSTREE_H_ */
