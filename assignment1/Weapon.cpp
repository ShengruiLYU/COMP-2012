// Submit this file.
// You must use this exact file name.

#include "Weapon.h"

Weapon::Weapon(){
	 name = "None";
	 power = 1;
	 fighterName = "None";
	 type = "unarmed";
}

Weapon::Weapon(string name,string type,int power,string fighterName){
	this->name = name;
	this->type = type;
	this->power =power;
	this->fighterName = fighterName;
}

Weapon::Weapon(string name){
	power = 1;
	fighterName = "None";
	type = "unarmed";
	this->name = name;
}

string Weapon::getName() const{
	return name;
}

string Weapon::getType() const{
	return type;
}

int Weapon::getPower() const{
	return power;
}

string Weapon::getFighterName() const{
	return fighterName;
}

void Weapon::setFighterName(string mfighterName){
	this->fighterName = mfighterName;
}












