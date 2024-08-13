#pragma once

#include "Enemies.h"

struct Vector2D {
	double x;
	double y;
	Vector2D(double pX = 0.0, double pY = 0.0) : x{ pX }, y{ pY } {}
	Vector2D operator=(const Vector2D& other);
	Vector2D addToSelf(const Vector2D& other);
	Vector2D operator+(const Vector2D& other) const;
	Vector2D& operator--();
	Vector2D operator--(int);
	Vector2D& operator++();
	Vector2D operator++(int);
	void readLocation() const;
};

class ArrayList {
public:
	ArrayList(int lengthP = 1);
	~ArrayList();
	ArrayList& operator=(const ArrayList& other);
	ArrayList(const ArrayList& other);
	void printList() const;
private:
	char* list;
	int length;
};

class Enemies;

class Entity {
public:
	Entity(int pAge = 0, int pMainMember = 0, double pPtr = 0.0, Vector2D pVec = Vector2D());

	// Copy constructor
	Entity(const Entity& other);
	// Move constructor
	Entity(Entity&& other) noexcept;
	Entity& operator=(Entity&& other) noexcept;
	~Entity();

	// Overloaded operators
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
};


