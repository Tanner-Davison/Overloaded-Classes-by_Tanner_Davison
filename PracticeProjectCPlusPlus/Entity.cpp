#include <iostream>
#include "Entity.h"

using namespace std;

Entity::Entity(int pAge, int pMainMember, double pPtr, Vector2D vec)
	: age(pAge), mainMember(pMainMember), instance(++count), entityPtr(new double(pPtr)), location(vec) {
	cout << "Constructor invoked\n Instance Count: " << count << "\n";
}

//copy Constructor
Entity::Entity(const Entity& other)
	: mainMember(other.mainMember), age(other.age), instance(++count), entityPtr(new double(*other.entityPtr)), location(other.location) {
	cout << "Copy Constructor Invoked \n";
}

//delete pointer
Entity::~Entity() {
	delete entityPtr;
}
//prefix increment;
Entity& Entity::operator++() {
	++mainMember;
	return *this;
}

Entity Entity::operator+ (const Entity& other) const {
	Entity result;
	result.setMainMember(this->mainMember + other.mainMember);
	result.setAge(this->age + other.age);
	return result;
}


//postfix increment;
Entity Entity::operator++(int) {
	Entity temp = *this;
	++(*this);
	return *this;
}


//preFix decrement;
Entity& Entity::operator--() {
	--mainMember;
	return *this;
}

//post fix decrement
Entity Entity::operator--(int) {
	Entity temp = *this;
	--(*this);
	return *this;
}

//addition overloaded operator
Entity Entity::add(const Entity& other) const {
	Entity temp;
	temp.setMainMember(this->mainMember + other.mainMember);
	temp.setAge(this->age + other.age);
	return temp;
}

//comparison overloaded operator
bool Entity::operator==(const Entity& other)const {
	return ((mainMember == other.mainMember) && (age == other.age));
}

//multiply overloaded operator
Entity Entity::multiply(const Entity& other) const {
	return Entity(this->age, this->mainMember * other.mainMember);
}

//* overloaded operator
Entity Entity::operator*(const Entity& other) const {
	return Entity(this->age, this->mainMember * other.mainMember);
}

//member getters
int Entity::getAge() const {
	return this->age;
}
double Entity::getPointer()const {
	return *entityPtr;
}
int Entity::getAccess() const {
	return this->mainMember;
}

Vector2D Entity::getLocation()const {
	return this->location;
}

bool Entity::isEqual(const Entity& other)const {
	if (this->mainMember == other.mainMember) {
		return true;
	}
	else {
		return false;
	}
}

// member Setters functions
void Entity::setMainMember(int pAccess) {
	this->mainMember = pAccess;
}

void Entity::setAge(int pAge) {
	this->age = pAge;
}
void Entity::toString() const {
	cout << "Entity # " << instance << " " << "age: " << this->age <<
		"\n Main Member: " << this->mainMember << endl;
}
void Entity::setLocation(Vector2D vec) {
	location = vec;
}
//static member variables;
int Entity::count = 0;