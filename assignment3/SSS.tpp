//*** DO NOT MODIFY OR SUBMIT THIS FILE ***//

template <typename Tree>
SSS<Tree>::SSS()
{
	tree = new Tree;
}

template <typename Tree>
SSS<Tree>::~SSS()
{
	delete tree;
}

template <typename Tree>
bool SSS<Tree>::addTerrorist(string name, int power)
{
	return tree->add(power, name);
}

template <typename Tree>
bool SSS<Tree>::removeTerrorist(int power)
{
	return tree->remove(power);
}

template <typename Tree>
void  SSS<Tree>::run()
{
	while(true)
	{
		cout << endl;
		cout << "Agent D.T., what do you want to do for our great country today?" << endl;
		cout << "1. Note down a terrorist." << endl;
		cout << "2. Eliminate a terrorist." << endl;
		cout << "3. Show the secret tree." << endl;
		cout << "4. Import a new tree from a secret tree code." << endl;
		cout << "5. Shutdown this system." << endl;
		int choice;
		cin >> choice;
		if(choice == 1)
		{
			string name;
			int power;
			cout << "OK. What is the terrorist name?" << endl;
			cin >> name;
			cout << "How powerful is him?" << endl;
			cin >> power;
			bool result = addTerrorist(name, power);
			if(!result)
				cout << "Request declined. Power must be unique." << endl;
			else
				cout << "Added successfully." << endl;
		}
		else if(choice == 2)
		{
			int power;
			cout << "OK. What is the target's power?" << endl;
			cin >> power;
			bool result = removeTerrorist(power);
			if(!result)
				cout << "Request declined. No terrorist has this power, or the terrorist is not located in a leaf node." << endl;
			else
				cout << "Eliminated successfully." << endl;
		}
		else if(choice == 3)
		{
			cout << endl;
			printTreeIllustration(tree);
			cout << endl;
			cout << "Secret tree code is given within the brackets [ ] below:" << endl;
			string stc = treeToString(tree);
			cout << "[" << stc << "]" << endl;
		}
		else if(choice == 4)
		{
			cout << "OK. What is secret tree code? (without the [ ] bracket please) Make sure it is valid..." << endl;
			string stc;
			cin >> stc;
			delete tree;

			tree = stringToIntStringBSTree<Tree>(stc);
			cout << "Done!" << endl;
		}
		else if(choice == 5)
		{
			cout << "OK, I (you the programmer) shall make sure there is no memory leak. Your secret data is safe with me. Farewell." << endl;
			break;
		}
	}
}
