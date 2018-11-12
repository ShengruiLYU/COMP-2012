//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

#ifndef SSS_H_
#define SSS_H_

#include <string>
#include "Utility.h"
using namespace std;

//the Super Secret System
//all its implementation is already given
template <typename Tree>
class SSS
{
public:
	SSS(); //constructor
	~SSS(); //destructor
	void run(); //run the system which offers a menu of options to the secret agent

private:
	bool addTerrorist(string name, int power); //add a terrorist to the tree with name (as the node's value) and power (as the node's key)
	bool removeTerrorist(int power); //remove a terrorist from the tree according to the power (i.e. the node's value)

	Tree* tree;
};

#include "SSS.tpp"

#endif /* SSS_H_ */
