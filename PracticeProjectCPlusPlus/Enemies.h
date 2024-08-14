#include "stdafx.h"
#pragma once


class Entity;

class Enemies {
public:
	Enemies(double memberP = 1, double armorP = 0);
	void getInstanceOfEntity(const Entity& entityP) const;
	friend void printEnemyMember(const Enemies& enemyP);

private:
	double member;
	double armor;

	// Friend declarations
	friend class Entity;

};

