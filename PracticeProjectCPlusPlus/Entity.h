#pragma once

struct Vector2D {
	Vector2D(double pX = 1, double pY = 1) :x{ pX }, y{ pY } {};

	double x;
	double y;
};

class Entity {
public:

	Entity(int pAge = 1, int pMainMember = 1, double pPtr = 0.0, Vector2D pVec = Vector2D());

	//copy constructor
	Entity(const Entity& other);

	~Entity();

	//overloaded operators
	Entity& operator++();
	Entity operator++(int);
	Entity& operator--();
	Entity operator--(int);
	Entity operator+(const Entity& other)const;
	Entity operator*(const Entity& other)const;
	bool operator==(const Entity& other)const;

	Entity multiply(const Entity& other) const;
	Entity add(const Entity& other)const;
	bool isEqual(const Entity& other)const;

	int getAge() const;
	int getAccess() const;
	double getPointer()const;
	Vector2D getLocation()const;

	void toString() const;
	void setAge(int pAge);
	void setMainMember(int pAccess);
	void setLocation(Vector2D vec);

private:
	int mainMember;
	double* entityPtr;
	Vector2D location;
	int age;
	static int count;
	int instance;
};