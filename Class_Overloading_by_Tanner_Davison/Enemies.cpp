#include "stdafx.h"


Enemies::Enemies(double memberP, double armorP) : member(memberP), armor(armorP) {}

void Enemies::getInstanceOfEntity(const Entity& entityE) const {
	std::cout << "Instance of Entity #: " << entityE.instance << "\n";
}

void printEnemyMember(const Enemies& enemyP) { //global friend function
	std::cout << enemyP.member << "\n";
}