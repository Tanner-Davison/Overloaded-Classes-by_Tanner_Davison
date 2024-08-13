#include "Entity.h"
#include <iostream>
#include <cstring>

using namespace std;

int Entity::count = 0;

Entity::Entity(int pAge, int pMainMember, double pPtr, Vector2D vec)
	: age(pAge), mainMember(pMainMember), instance(++count), entityPtr(new double(pPtr)), location(vec) {
	cout << "Constructor invoked #:  " << this->instance << "\n";
}

Entity::Entity(const Entity& other)
	: mainMember(other.mainMember), age(other.age), instance(++count), entityPtr(new double(*other.entityPtr)), location(other.location) {
	cout << "Copy Constructor Invoked #: " << count << "\n";
}

Entity::Entity(Entity&& other) noexcept
	: age(other.age), mainMember(other.mainMember), instance(other.instance), entityPtr(other.entityPtr), location(other.location) {
	cout << "Move Constructor Invoked\n";
	other.entityPtr = nullptr;
}

Entity::~Entity() {
	if (this->entityPtr != nullptr) {
		delete entityPtr;
		this->entityPtr = nullptr;
		count--;
	}
}

Entity& Entity::operator++() {
	++age;
	++mainMember;
	++(*this->entityPtr);
	++location;
	return *this;
}

Entity Entity::operator++(int) {
	Entity temp = *this;
	++(*this);
	return temp;
}

Entity& Entity::operator--() {
	--age;
	--mainMember;
	--(*this->entityPtr);
	--location;
	return *this;
}

Entity Entity::operator--(int) {
	Entity temp = *this;
	--(*this);
	return temp;
}

Entity& Entity::operator=(const Entity& other) {
	if (this == &other) {
		return *this;
	}
	delete entityPtr;
	mainMember = other.mainMember;
	this->entityPtr = new double(*other.entityPtr);
	this->location = other.location;
	this->age = other.age;
	cout << "copy assignment overload invoked #: " << count << "\n";
	return *this;
}

Entity& Entity::operator=(Entity&& other) noexcept {
	if (this != &other) {
		delete entityPtr;
		age = other.age;
		mainMember = other.mainMember;
		instance = other.instance;
		entityPtr = other.entityPtr;
		location = other.location;
		other.entityPtr = nullptr;
		cout << "move assignment = operator invoked\n";
	}
	return *this;
}

Entity Entity::operator+(const Entity& other) const {
	return Entity(this->age + other.age, this->mainMember + other.mainMember, *this->entityPtr + *other.entityPtr, location + other.location);
}

Entity Entity::add(const Entity& other) {
	return Entity(this->age += other.age, mainMember += other.mainMember, *entityPtr += *other.entityPtr, location + other.location);
}

bool Entity::operator==(const Entity& other) const {
	return ((mainMember == other.mainMember) && (age == other.age));
}

Entity Entity::operator*(const Entity& other) const {
	return Entity(this->age, this->mainMember * other.mainMember);
}

Entity Entity::multiply(const Entity& other) const {
	return Entity(this->age, this->mainMember * other.mainMember);
}

int Entity::getAge() const {
	return this->age;
}

double Entity::getPointer() const {
	return *entityPtr;
}

int Entity::getAccess() const {
	return this->mainMember;
}

void Entity::getEnemy(const Enemies& enemyP) const {
	cout << "Enemies member is: " << enemyP.member << "\n";
}

Vector2D Entity::getLocation() const {
	return this->location;
}

bool Entity::isEqual(const Entity& other) const {
	return (this->mainMember == other.mainMember);
}

void Entity::setMainMember(int pAccess) {
	this->mainMember = pAccess;
}

void Entity::setAge(int pAge) {
	this->age = pAge;
}
void howOld(Entity& entityP) {
	cout << "The entity is " << entityP.getAge() << " years old." << endl;
}
void Entity::toString() const {
	cout << "Entity # " << this->instance << " "
		<< "\nage: " << this->age << " "
		<< "mainMember: " << this->mainMember
		<< " entityPtr: " << *this->entityPtr
		<< " location x: " << this->location.x << " "
		<< "location y: " << this->location.y << "\n";
}

void Entity::setLocation(Vector2D vec) {
	location = vec;
}




class ArrayList {
public:
	// Constructor
	ArrayList(int lengthP = 1) : length(lengthP) {
		list = new char[length];
		memset(list, 0, length);
	}

	// Destructor
	~ArrayList() {
		delete[] list;
	}

	// Copy Assignment Operator
	ArrayList& operator=(const ArrayList& other) {
		if (this != &other) {
			delete[] list;
			length = other.length;
			list = new char[length];
			std::memcpy(list, other.list, length);
		}
		return *this;
	}

	// Copy Constructor
	ArrayList(const ArrayList& other) : length(other.length), list(new char[length]) {
		memcpy(list, other.list, length);
	}

	// Method to print the list
	void printList() const {
		for (int i = 0; i < length; ++i) {
			cout << list[i];
		}
		cout << endl;
	}

private:
	char* list;
	int length;
};

