#pragma once

class Entity;

class Enemies {
public:
	Enemies(double memberP = 1);
	void getInstance(const Entity& entityP) const;

private:
	double member;

	// Friend declarations
	friend class Entity;

};