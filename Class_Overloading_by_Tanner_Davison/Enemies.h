#pragma once
#include "stdafx.h"


class Entity;

class Enemies {
public:
	explicit Enemies(double memberP = 1, double armorP = 0, int enemyAgeP = 1);
	void getInstanceOfEntity(const Entity& entityP) const;
	friend void printEnemyMember(const Enemies& enemyP);

	explicit operator int();

private:
	double member;
	double armor;
	int enemyAge;
	// Friend declarations
	friend class Entity;

};

