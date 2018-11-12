//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef TREE_H_
#define TREE_H_

#include <string>
using namespace std;

//the Tree class
//this is an ABC
//it is possible to make as many Tree subclasses as you like
//but for simplicity, we only implement BSTree in this assignment
template<typename Container, typename KeyType, typename ValueType>
class Tree
{
public:
	virtual bool add(KeyType key, ValueType value) = 0; //pure virtual function here, description can be found in BSTree class
	virtual bool remove(KeyType key) = 0; //pure virtual function here, description can be found in BSTree class
	virtual ValueType getValue(KeyType key) = 0; //pure virtual function here, description can be found in BSTree class
	virtual ~Tree(){}; //an empty destructor

protected:
	Container data; //the data container (a vector, which is either a ListVector or ArrayVector in this assignment)
	                //that stores all the node data of the tree
					//how the node is stored in the data container is very specific
					//please refer to the webpage description for details

	//treeToString in Utility is this class's only friend... :(
	template<typename aContainer, typename aKeyType, typename aValueType>
	friend string treeToString(Tree<aContainer, aKeyType, aValueType>* tree);
};

#endif
