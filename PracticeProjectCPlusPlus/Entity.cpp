#include <iostream>
#include "Entity.h"

using namespace std;

Entity::Entity() :accessToken(1), age(1), instance(count) {
	++count;
}

Entity::Entity(int Ppass) : age(Ppass), accessToken(1), instance(count) {
	++count;
} //randomize accessToken *******need to do.*****

Entity::Entity(int pAge, int pAccessToken) : age(pAge), accessToken(pAccessToken), instance(count) {
	++count;
}

//prefix increment;
Entity& Entity::operator++() {
	++accessToken;
	return *this;
}
Entity Entity::operator+ (const Entity& other) const {
	Entity result;
	result.setAccessToken(this->accessToken + other.accessToken);
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
	--accessToken;
	return *this;
}
//post fix decrement
Entity Entity::operator--(int) {
	Entity temp = *this;
	--(*this);
	return *this;
}
Entity Entity::add(const Entity& other) const {
	Entity temp;
	temp.setAccessToken(this->accessToken + other.accessToken);
	temp.setAge(this->age + other.age);
	return temp;
}
Entity Entity::multiply(const Entity& other) const {
	return Entity(this->age, this->accessToken * other.accessToken);
}
Entity Entity::operator*(const Entity& other) const {
	return Entity(this->age, this->accessToken * other.accessToken);
}
//member getter functions
int Entity::getAge() const {
	return this->age;
}
int Entity::getAccess() const {
	return this->accessToken;
}
// member setter functions
void Entity::setAccessToken(int pAccess) {
	this->accessToken = pAccess;
}

void Entity::setAge(int pAge) {
	this->age = pAge;
}
void Entity::toString() const {
	cout << "Entity # " << instance << " " << "age: " << this->age <<
		"\n accessToken: " << this->accessToken << endl;
}
//static member variables;
int Entity::count = 0;