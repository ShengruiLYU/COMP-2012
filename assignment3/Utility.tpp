//SUBMIT THIS FILE
//YOU CANNOT INCLUDE ANY ADDITIONAL LIBRARY

#include "Utility.h"

//a helper function to calculate an integer power
//it assumes exponent is non-negative
int pow(int base, int exponent)
{
    int result = 1;
    while(exponent--) result*=base;
    return result;
}

//a helper function that converts the value to a string using ostringstream
//it would work as long as the ValueType supports operator<<
//e.g. string and int both work
//you may use it to convert keyType and valueType to string
template<typename T>
string toString(T value)
{
    string s;
    ostringstream oss(s);
    oss << value;
    return oss.str();
}

//it prints the illustration of a tree which is described in the webpage
//it is given and should not be modified
template<typename Container, typename KeyType, typename ValueType>
void printTreeIllustration(BSTree<Container, KeyType, ValueType>* tree)
{
    Container& data = tree->data;
    int h = tree->getHeight();

    for(int i=0; i<=h; i++)
    {
        cout << "Depth " << i << ":\t";
        int startIndex = pow(2, i) - 1;
        int endIndex = pow(2, i+1) - 1;
        for(int j=startIndex; j<endIndex; j++) //print the nodes on the same height
        {
            if(data[j] != NULL)
                cout << "<" << toString(data[j]->getKey()) << "," << toString(data[j]->getValue()) << ">" << "\t";
            else
                cout << "(NULL)\t";
        }
        cout << endl;
    }
}

//NO MODIFICATION IS ALLOWED TO THE CODE ABOVE
//PLEASE ADD YOUR CODE BELOW

template<typename Container, typename KeyType, typename ValueType>
string treeToString(Tree<Container, KeyType, ValueType>* tree){
	 Container& data = tree->data;
	    int size = data.getSize();


	    if(size>0){
	    	while((size>0)&&data[size-1] == NULL){


	    		if(size>0){
	    		--size;}
	    	}
	    }


	    string result = "";


	    if(size == 0){
	    	result = "(NULL)";
	    	return result;
	    }

	    for(int i = 0;i<size;i++){
	    	 if(data[i] != NULL)
	    	     { result += "<" ;
	    	       result += toString(data[i]->getKey()) ;
	    	       result += ",";
	    	       result += toString(data[i]->getValue());
	    	       result += ">";
	    	     }
	    	     else
	    	      { result += "(NULL)";}
	    	 if(i+1 != size){
	    		 result += ",";
	    	 }
	    }

	    return result;

}

template<typename Tree>
Tree* stringToIntStringBSTree(string s){

	Tree* tree = new Tree;
	string input = s;
	std::istringstream ss(input);
	std::string token;
	int key = 0;
	string value = "";

	while(std::getline(ss, token, ',')) {

		if(token != "(NULL)"){
			if(token[0] == '<'){

                 stringstream convert (token.substr(1,token.length()-1));
                 convert>>key;
			}
			else if(token[token.length()-1] == '>'){
				value = token.substr(0,token.length()-1);
				tree->add(key,value);


			}

	    }
	}
	return tree;
}









