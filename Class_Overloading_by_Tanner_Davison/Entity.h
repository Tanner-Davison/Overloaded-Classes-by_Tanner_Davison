#pragma once
#include "stdafx.h"

class Enemies;


class Entity {
public:
	Entity(int pAge = 0, int pMainMember = 0, double pPtr = 0.0, Vector2D pVec = Vector2D(), int sizeP = 1);
	// Copy constructor
	Entity(const Entity& other);
	// Move constructor
	Entity(Entity&& other) noexcept;
	Entity& operator=(Entity&& other) noexcept;
	~Entity();
	// Overloaded operators
	friend std::ostream& operator<<(std::ostream& output, const Entity& entityP);
	friend std::istream& operator>>(std::istream& input, Entity& entityP);
	//bounds array
	int& operator[](int subscript);
	Entity& operator++();
	Entity operator++(int);
	Entity& operator--();
	Entity operator--(int);
	Entity operator+(const Entity& other) const;
	Entity operator*(const Entity& other) const;
	Entity& operator=(const Entity& other);
	bool operator==(const Entity& other) const;
	Entity multiply(const Entity& other) const;
	Entity add(const Entity& other);
	bool isEqual(const Entity& other) const;

	int getAge() const;
	int getAccess() const;
	double getPointer() const;
	Vector2D getLocation() const;

	void toString() const;
	void setAge(int pAge);
	void setMainMember(int pAccess);
	void setLocation(Vector2D vec);

	// Friend declarations
	void getEnemy(const Enemies& enemyP) const;
	friend class Enemies; // Grant access to Enemies

private:
	friend void howOld(Entity& entityP);
	int mainMember;
	double* entityPtr;
	Vector2D location;
	int age;
	static int count;
	int instance;
	int size;
	int* elements;
};


