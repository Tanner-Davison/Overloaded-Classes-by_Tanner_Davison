#include "stdafx.h"


Enemies::Enemies(double memberP, double armorP, int enemyAgeP) : member(memberP), armor(armorP), enemyAge(enemyAgeP) {}

void Enemies::getInstanceOfEntity(const Entity& entityE) const {
	std::cout << "Instance of Entity #: " << entityE.instance << "\n";
}

void printEnemyMember(const Enemies& enemyP) { //global friend function
	std::cout << enemyP.member << "\n";
}
Enemies::operator int() {
	return enemyAge;
};