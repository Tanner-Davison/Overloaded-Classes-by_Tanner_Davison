#include <iostream>
#include "Enemies.h"
#include "Entity.h"

using namespace std;

Enemies::Enemies(double memberP) : member(memberP) {}

void Enemies::getInstance(const Entity& entityE) const {
	cout << "Instance of Entity #: " << entityE.instance << "\n";
}