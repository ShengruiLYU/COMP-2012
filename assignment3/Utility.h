//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef UTILITY_H_
#define UTILITY_H_

#include <iostream>
#include <sstream>
#include <string>
#include "ListVector.h"
#include "BSTree.h"
#include "Pair.h"
using namespace std;

typedef Pair<int, string> ISPair;

//a helper function to calculate an integer power
//it assumes exponent is non-negative
int pow(int base, int exponent);

//a helper function that converts the value to a string using ostringstream
//it would work as long as the ValueType supports operator<<
//e.g. string and int both work
//you may use it to convert keyType and valueType to string
template<typename T>
string toString(T value);

//it prints the illustration of a tree which is described in the webpage
//it is given and should not be modified
template<typename Container, typename KeyType, typename ValueType>
void printTreeIllustration(Tree<Container, KeyType, ValueType>* tree);

//it generates a string that represents the tree
//the string format is very specific
//please refer to the webpage description
//you can assume that the given tree is always non-empty (i.e. has at least the root node)
//you need to implement it in Utility.tpp
template<typename Container, typename KeyType, typename ValueType>
string treeToString(Tree<Container, KeyType, ValueType>* tree);

//it generates a tree according to the given string which is the aforementioned format
//you should always insert the nodes according to their appearance order in the string
//e.g. if given <20,A>,<10,C>,<40,D>,(NULL),(NULL),<30,B>,<50,E>,(NULL),(NULL),(NULL),(NULL),(NULL),(NULL),<45,F>
//then you should insert the nodes of values 20, 10, 40, 30, 50, and then 45, in this order
//you need to implement it in Utility.tpp
template<typename Tree>
Tree* stringToIntStringBSTree(string s);

#include "Utility.tpp"

#endif /* UTILITY_H_ */
