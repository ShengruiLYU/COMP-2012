// Submit this file.
// You must use this exact file name.

#include "Arena.h"

Arena::Arena(){
	weaponCount=0;
	fighterCount=0;
	reward = 1000;
	weapons=NULL;
	fighters=NULL;
	mode = "armed";
}

Arena::Arena(const Arena&a){
	 fighterCount = a.fighterCount;
	 weaponCount = a.weaponCount;
	 reward = a.reward;
	 mode = a.mode;

	 fighters = new Fighter*[fighterCount];

	 for (int i=0;i<fighterCount;i++){
		 fighters[i]= new Fighter();
		 *fighters[i]=*a.fighters[i];
	 }


	 weapons = new Weapon*[weaponCount];

	 for (int i=0;i<weaponCount;i++){
	 	weapons[i]= new Weapon();
	 	*weapons[i]=*a.weapons[i];
	 }
}

Arena::~Arena(){
	for (int i=0;i<fighterCount;i++){
		if(fighters[i]!=NULL){
		delete fighters[i];
		 fighters[i]=NULL;
	     }
	}

	delete [] fighters;

	for(int i=0;i<weaponCount;i++){
		if(weapons[i]!=NULL){
			delete weapons[i];
			weapons[i]=NULL;
		}
	}
	delete [] weapons;
}

bool Arena::doesFighterExist(string name) const{

		for(int i =0;i<fighterCount;i++){
			if (fighters[i]->getName()==name){
				return true;
			}
		}

		return false;
}

bool Arena::addFighter(string name, int str, int hp){


	if(doesFighterExist(name)){
		return false;
	}

	fighterCount=fighterCount+1;
	Fighter** temp = new Fighter* [fighterCount];

	for (int i=0;i<fighterCount-1;i++){
			 temp[i]= fighters[i];
			 fighters[i]=NULL;
	}

	temp[fighterCount-1]= new Fighter(name,str,hp);



	delete [] fighters;

	fighters = temp;
	temp = NULL;

	return true;


}

bool Arena::doesWeaponExist(string name) const{
	for(int i =0;i<weaponCount;i++){
			if (weapons[i]->getName()==name){
					return true;
				}
	}

			return false;
}

bool Arena::addWeapon(string name, string type, int power){
	if ((type != "melee")&&(type != "ranged")&&(type != "magic")&&(type != "unarmed")){

		return false;
	}

	if (doesWeaponExist(name)){
		return false;
	}

	weaponCount=weaponCount+1;
		Weapon** temp = new Weapon* [weaponCount];

		for (int i=0;i<weaponCount-1;i++){
				 temp[i]= weapons[i];
				 weapons[i]=NULL;
		}

		temp[weaponCount-1]= new Weapon(name,type,power,"None");



		delete [] weapons;

		weapons = temp;
		temp = NULL;
		return true;
}

bool Arena::removeWeaponFromFighter(string fighterName){
	if (!doesFighterExist(fighterName)){
		return false;
	}

	Fighter* fptr =NULL;
	for (int i =0; i< fighterCount;i++){
		if(fighters[i]->getName()== fighterName){
			fptr = fighters[i];
			break;
		}
	}

	if ((fptr->getWeapon().getType() !="unarmed")&&(doesWeaponExist(fptr->getWeapon().getName()))){

		for(int i=0;i<weaponCount;i++){
			if(weapons[i]->getName()==fptr->getWeapon().getName()){
				weapons[i]->setFighterName("None");
			}
		}

	}

	return fptr->removeWeapon();



}

bool Arena::giveWeaponToFighter(string personName, string weaponName){

	if ((doesFighterExist(personName)==false)||(doesWeaponExist(weaponName)==false)){
		return false;
	}



	bool removeWeapon = removeWeaponFromFighter(personName);

	Fighter* fptr = NULL;
	for (int i =0; i< fighterCount;i++){
		if(fighters[i]->getName()==personName){

			fptr = fighters[i];
		}

	}

	if (weapons[findIndexOfWeapon(weaponName)]->getFighterName()!="None"){

		    	removeWeaponFromFighter(weapons[findIndexOfWeapon(weaponName)]->getFighterName());
		}


	for (int i = 0; i< weaponCount;i++){
		if (weapons[i]->getName()==weaponName){
			if(fptr->setWeapon(*weapons[i])){
				weapons[i]->setFighterName(personName);
			}
		}
	}

   return true;
}

bool Arena::removeFighter(string name){
	if (!doesFighterExist(name)){
		return false;
	}





	Fighter* fptr = NULL;
    int index =0;

	for (int i=0;i<fighterCount;i++){

     if(fighters[i]->getName()==name){
    	 fptr = fighters[i];
    	 index=i;
    	 break;
     }
	}

	if (doesWeaponExist(fptr->getWeapon().getName())){

		removeWeaponFromFighter(name);
	}

	delete fptr;
	fptr =NULL;

	for (int i =index;i< fighterCount-1;i++){
		fighters[i]= fighters[i+1];
	}

	fighters[fighterCount-1]=NULL;

	fighterCount = fighterCount-1;
	return true;
}


bool Arena::destroyWeapon(string weaponName){
	if (!doesWeaponExist(weaponName)){
		return false;
	}

	int index = 0;

	for(int i =0; i<weaponCount; i++){

		if (weapons[i]->getName()==weaponName){
			index = i;
			break;
		}

	}

	if((weapons[index]->getFighterName()!="None")&&(doesFighterExist(weapons[index]->getFighterName()))){

		removeWeaponFromFighter(weapons[index]->getFighterName());

	}

	delete weapons[index];
	weapons[index]=NULL;

	for (int i =index; i< weaponCount-1;i++){
		weapons[i]=weapons[i+1];
	}

	weapons[weaponCount-1]=NULL;

	weaponCount=weaponCount-1;



	return true;
}

bool Arena::setReward(int mReward){
	if(mReward<0){
		return false;
	}
	reward = mReward;
	return true;
}

bool Arena::setMode(string mMode){
	if((mMode != "armed")&&(mMode !="unarmed")){
		return false;
	}

	mode = mMode;
	return true;

}



int Arena::computeMultiplier(string type1, string type2) const{

	if(mode=="unarmed"){
		return 1;
	}


	if (((type1=="melee")&&(type2=="ranged"))||((type1 == "ranged")&&(type2=="magic"))||((type1=="magic")&&(type2=="melee"))){
		return 2;
	}

	if((type1!="unarmed")&&(type2=="unarmed")){
	return 2;
	}

	return 1;
}

int Arena::findIndexOfFighter(string name) const{

	for(int i =0; i< fighterCount;i++){
		if(name==fighters[i]->getName()){
			return i;
		}
	}

	return -1;
}

int Arena::findIndexOfWeapon(string name)const{
	for(int i =0; i< weaponCount;i++){
			if(name==weapons[i]->getName()){
				return i;
			}
		}

	return -1;

}


bool Arena::fight(string fighter1Name,string fighter2Name){
	if ((!doesFighterExist(fighter1Name))||(!doesFighterExist(fighter2Name))){
		return false;
	}

	int fighter1 = findIndexOfFighter(fighter1Name);
	int fighter2 = findIndexOfFighter(fighter2Name);

	int Handicap1 =computeMultiplier(fighters[fighter1]->getWeapon().getType(),fighters[fighter2]->getWeapon().getType());
	int Handicap2 = computeMultiplier(fighters[fighter2]->getWeapon().getType(),fighters[fighter1]->getWeapon().getType());

	int damage1 = (fighters[fighter1]->getStr() +fighters[fighter1]->getWeapon().getPower() ) * Handicap1;
	int damage2 = (fighters[fighter2]->getStr() +fighters[fighter2]->getWeapon().getPower() ) * Handicap2;

    int hp1 = fighters[fighter1]->getHp();
    int hp2 = fighters[fighter2]->getHp();

    cout<<"Fighter 1:"<<endl;
    cout<<fighter1Name<<" :"<<endl;
    cout<<"Str: "<<fighters[fighter1]->getStr()<<", Hp: "<<fighters[fighter1]->getHp()<<endl;
    cout<<"Weapon: "<<fighters[fighter1]->getWeapon().getName()<<"("<<fighters[fighter1]->getWeapon().getType()<<")"<<endl;
    cout<<"Money: "<<fighters[fighter1]->getMoney()<<endl;
    cout<<endl;

    cout<<fighter2Name<<" :"<<endl;
    cout<<"Str: "<<fighters[fighter2]->getStr()<<", Hp: "<<fighters[fighter2]->getHp()<<endl;
    cout<<"Weapon: "<<fighters[fighter2]->getWeapon().getName()<<"("<<fighters[fighter2]->getWeapon().getType()<<")"<<endl;
    cout<<"Money: "<<fighters[fighter2]->getMoney()<<endl;
    cout<<endl;

    bool killfirst = false;
    bool killsecond = false;
    for (int i = 0; i<5;i++){

    	cout<<fighter1Name<<" hits "<<fighter2Name<<" for "<<damage1<<" damage"<<endl;
    	hp2=hp2-damage1;
    	cout<<fighter2Name<<" remaining hp: "<<hp2<<endl;
    	cout<<endl;

    	cout<<fighter2Name<<" hits "<<fighter1Name<<" for "<<damage2<<" damage"<<endl;
    	hp1=hp1-damage2;
    	cout<<fighter1Name<<" remaining hp: "<<hp1<<endl;
    	cout<<endl;

    	if((hp1 <= 0)&&(hp2 > 0)){
    		killfirst = !(fighters[fighter1]->removeMoney(reward));
    		cout<<fighter2Name<<" wins"<<endl;
    		fighters[fighter2]->addMoney(reward);
    		break;
    	}

    	if((hp1 > 0)&&(hp2 <= 0)){
    		killsecond = !(fighters[fighter2]->removeMoney(reward));
    		cout<<fighter1Name<<" wins"<<endl;
    		fighters[fighter1]->addMoney(reward);
    		break;
    	}

    	if((hp1 <= 0)&&(hp2 <= 0)){
    		cout<<"fight is concluded in draw"<<endl;
    		break;
    	}

    	if (i==4){
    		cout<<"fight is concluded in draw"<<endl;
    		break;
    	}

    }

    if (killfirst){

    	string question = "My lord shall we kill this("+fighter1Name+") moneyless loser?(y/n) ";
    	string kill = getStringInput(question);
    	if (kill == "y"){
    		removeFighter(fighter1Name);
    	}
    }

    if (killsecond){
    	string question = "My lord shall we kill this("+fighter2Name+") moneyless loser?(y/n) ";
    	string kill = getStringInput(question);
    	if (kill == "y"){
    	    removeFighter(fighter2Name);
    	}
    }


	return true;
}












