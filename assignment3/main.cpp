//*** DO NOT SUBMIT THIS FILE ***//

#include <iostream>
#include "ArrayVector.h"
#include "ListVector.h"
#include "BSTree.h"
#include "Utility.h"
#include "SSS.h"

using namespace std;

//template<typename Container, typename KeyType, typename ValueType>
//int BSTree<Container,KeyType,ValueType>::bstree_count =0;





int main()
{
    //hint: you can temporarily remove parts that you cannot finish at the moment, to test the remaining parts
    //hint: you should design your own test cases eventually

    cout << "System testing begins..." << endl;

    {
        cout << endl << "Testing ArrayVector..." << endl;
        ArrayVector<int> arrayVector;
        cout << "arrayVector.getSize() = " << arrayVector.getSize() << endl;
        cout << "arrayVector[2] = new int(65);..." << endl;
        arrayVector[2] = new int(65);
        cout << "arrayVector.getSize() = " << arrayVector.getSize() << endl;
        cout << "*arrayVector[2] = " << *arrayVector[2] << endl;
        cout << "arrayVector[0] = " << (arrayVector[0]==NULL?"NULL":"NOT NULL") << endl;
        cout << "Reading from arrayVector[7]..." << endl;
        cout << "arrayVector[7] = " << (arrayVector[7]==NULL?"NULL":"NOT NULL") << endl;
        cout << "arrayVector.getSize() = " << arrayVector.getSize() << endl;
        cout << "Reading from arrayVector[8]..." << endl;
        cout << "arrayVector[8] = " << (arrayVector[8]==NULL?"NULL":"NOT NULL") << endl;
        cout << "arrayVector.getSize() = " << arrayVector.getSize() << endl;
        delete arrayVector[2];
    }

    {
        cout << endl << "Testing ListVector..." << endl;
        ListVector<int> listVector;


        cout << "listVector.getSize() = " << listVector.getSize() << endl;
        cout << "listVector[2] = new int(65);..." << endl;
        listVector[2] = new int(65);
        cout << "listVector.getSize() = " << listVector.getSize() << endl;
        cout << "*listVector[2] = " << *listVector[2] << endl;
        cout << "listVector[0] = " << (listVector[0]==NULL?"NULL":"NOT NULL") << endl;
        cout << "Reading from listVector[7]..." << endl;
        cout << "listVector[7] = " << (listVector[7]==NULL?"NULL":"NOT NULL") << endl;
        cout << "listVector.getSize() = " << listVector.getSize() << endl;
        cout << "Reading from listVector[8]..." << endl;
        cout << "listVector[8] = " << (listVector[8]==NULL?"NULL":"NOT NULL") << endl;
        cout << "listVector.getSize() = " << listVector.getSize() << endl;

        delete listVector[2];

    }


    const string SAMPLE_TREE_STRING_ANSWER = "<20,A>,<10,C>,<40,D>,(NULL),(NULL),<30,B>,<50,E>,(NULL),(NULL),(NULL),(NULL),(NULL),(NULL),<45,F>";

    {
        cout << endl << "Testing BSTree<ArrayVector<ISPair>, int, string> ..." << endl;
        cout << "Adding 20, 40, 10, 30, 50, 45..." << endl;
        Tree<ArrayVector<ISPair>, int, string>* tree = new BSTree<ArrayVector<ISPair>, int, string> ;
        BSTree<ArrayVector<ISPair>, int, string>* bstree = dynamic_cast<BSTree< ArrayVector<ISPair>, int, string>*>(tree);
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(20, "A");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(40, "D");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(10, "C");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(30, "B");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(50, "E");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(45, "F");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);

        string s = treeToString(tree);
        cout << "treeToString(p) = " << endl << "[" << s << "]" << endl;
        if(s == SAMPLE_TREE_STRING_ANSWER) cout << "Good, it is exactly the same as the expected answer." << endl;
        else cout << "Oh no... it is wrong! The expected output is " << endl << "[" << SAMPLE_TREE_STRING_ANSWER << "]" << endl;
        BSTree< ArrayVector<ISPair>, int, string> *p = stringToIntStringBSTree< BSTree< ArrayVector<ISPair>, int, string> >(s);
        string ps = treeToString(p);
        cout << "treeToString -> stringToIntStringBSTree -> treeToString = " << endl << "[" << ps << "]" << endl;
        if(ps == SAMPLE_TREE_STRING_ANSWER) cout << "Good, it is exactly the same as the expected answer." << endl;
        else cout << "Oh no... it is wrong! The expected output is " << endl << "[" << SAMPLE_TREE_STRING_ANSWER << "]" << endl;
        delete p;

        cout << "Removing 50, 45, 50..." << endl;
        cout << "tree->remove(50) = " << tree->remove(50) << endl;
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        cout << "Removing 50, 45, 50..." << endl;
        cout << "tree->remove(45) = " << tree->remove(45) << endl;
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        cout << "Removing 50, 45, 50..." << endl;
        cout << "tree->remove(50) = " << tree->remove(50) << endl;
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);



        delete tree;


    }

    {
        cout << endl << "Testing BSTree<ListVector<ISPair>, int, string> ..." << endl;
        cout << "Adding 20, 40, 10, 30, 50, 45..." << endl;
        Tree<ListVector<ISPair>, int, string>* tree = new BSTree<ListVector<ISPair>, int, string> ;
        BSTree<ListVector<ISPair>, int, string>* bstree = dynamic_cast<BSTree< ListVector<ISPair>, int, string>*>(tree);
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(20, "A");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(40, "D");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(10, "C");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(30, "B");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(50, "E");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        tree->add(45, "F");
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;

        printTreeIllustration(bstree);

        string s = treeToString(tree);
        cout << "treeToString(p) = " << endl << "[" << s << "]" << endl;
        if(s == SAMPLE_TREE_STRING_ANSWER) cout << "Good, it is exactly the same as the expected answer." << endl;
        else cout << "Oh no... it is wrong! The expected output is " << endl << "[" << SAMPLE_TREE_STRING_ANSWER << "]" << endl;
        BSTree< ListVector<ISPair>, int, string> *p = stringToIntStringBSTree< BSTree< ListVector<ISPair>, int, string> >(s);
        string ps = treeToString(p);
        cout << "treeToString -> stringToIntStringBSTree -> treeToString = " << endl << "[" << ps << "]" << endl;
        if(ps == SAMPLE_TREE_STRING_ANSWER) cout << "Good, it is exactly the same as the expected answer." << endl;
        else cout << "Oh no... it is wrong! The expected output is " << endl << "[" << SAMPLE_TREE_STRING_ANSWER << "]" << endl;



        delete p;



        cout << "Removing 50, 45, 50..." << endl;
        cout << "tree->remove(50) = " << tree->remove(50) << endl;
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        cout << "Removing 50, 45, 50..." << endl;
        cout << "tree->remove(45) = " << tree->remove(45) << endl;
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);
        cout << "Removing 50, 45, 50..." << endl;
        cout << "tree->remove(50) = " << tree->remove(50) << endl;
        cout << "bstree->getHeight() = " << bstree->getHeight() << endl;
        printTreeIllustration(bstree);




        delete tree;






    }


    cout << endl << endl;



    cout << "Testing is done... booting up the super secret system..." << endl;
    cout << "Which data structure would you like to use?" << endl;
    cout << "1. ListVector - good for space efficiency in general" << endl;
    cout << "2. ArrayVector - good for computational speed in general" << endl;
    int choice;
    cin >> choice;
    cout << endl;

    if(choice == 1)
    {
        SSS< BSTree< ListVector<ISPair>, int, string> >  sss;
        sss.run();
    }
    else if(choice == 2)
    {
        SSS< BSTree< ArrayVector<ISPair>, int, string> >  sss;
        sss.run();
    }

    return 0;

}
