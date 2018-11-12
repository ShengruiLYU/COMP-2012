// Submit this file.
// You must use this exact file name.

#include "Fighter.h"

Fighter::Fighter(){
	name = "None";
	str = 1;
	hp = 60;
	money = 1000;
	weapon.setFighterName(name);

}

Fighter::Fighter(string name,int str,int hp){
	money =1000;
	this->name = name;
	this->str = str;
	this->hp = hp;
	weapon.setFighterName(name);
}

string Fighter::getName() const{
	return name;
}

int Fighter::getStr() const{
	return str;
}

int Fighter::getHp() const {
	return hp;
}

int Fighter::getMoney() const{
	return money;
}

Weapon& Fighter::getWeapon(){
	return weapon;
}

bool Fighter::setWeapon(const Weapon& weapon){
	this->weapon = weapon;
	this->weapon.setFighterName(name);
	return true;
}

bool Fighter::removeWeapon(){
	if (weapon.getType()=="unarmed"){
		return false;
	}

	;
	weapon = Weapon();
	return true;
}

void Fighter::addMoney(int amount){
	money = money+amount;
}

bool Fighter::removeMoney(int amount){
	if (money<=0){
		return false;
	}
	else{
		money = money-amount;
	}
	return true;
}
