#include "stdafx.h"

int Entity::count = 0;

Entity::Entity(int pAge, int pMainMember, double pPtr, Vector2D vec, int sizeP)
	: age(pAge), mainMember(pMainMember), instance(++count), entityPtr(new double(pPtr)), location(vec), size(sizeP), elements(new int[sizeP]) {
	std::cout << "Constructor invoked #:  " << this->instance << "\n";
	for (int i = 0; i < size; i++) {
		elements[i] = 0;
	}
}
//copy constructor
Entity::Entity(const Entity& other)
	: mainMember(other.mainMember), age(other.age), instance(++count), entityPtr(new double(*other.entityPtr)), location(other.location), size(other.size), elements(new int[other.size]) {
	std::cout << "Copy Constructor Invoked #: " << count << "\n";
	for (int i = 0; i < other.size; i++) {
		elements[i] = other.elements[i];
	}
}
//move constructor
Entity::Entity(Entity&& other) noexcept
	: age(other.age), mainMember(other.mainMember), instance(other.instance), entityPtr(other.entityPtr), location(other.location), size(other.size), elements(other.elements) {
	std::cout << "Move Constructor Invoked\n";
	other.entityPtr = nullptr;
	other.size = 0;
	other.elements = nullptr;
}

Entity::~Entity() {
	if (this->entityPtr != nullptr) {
		delete entityPtr;
		this->entityPtr = nullptr;
		count--;
	}
	delete[] elements;
}
// overloading the Stream Insertion and Extractin Operators
std::ostream& operator<<(std::ostream& output, const Entity& entityP) {
	output << "\n***********\n";
	output << "instance # " << entityP.instance << "\n";
	output << "mainMember:  " << entityP.mainMember << "\n";
	output << "age: " << entityP.age << "\n";
	output << "Pointer: " << *entityP.entityPtr << "\n";
	output << "Location: " << "x:" << entityP.location.x << " y: " << entityP.location.y << "\n";
	output << "size: " << entityP.size << "\n";
	output << "elements: [ ";
	if (entityP.size > 0 && entityP.elements) {
		for (int i = 0; i < entityP.size; ++i) {
			output << entityP.elements[i];
			if (i < entityP.size - 1) {
				output << ", ";
			}
		}
	}
	else {
		output << "empty";
	}
	output << " ]\n";
	output << "***********\n";
	output << "\n";
	return output;
}
std::istream& operator>>(std::istream& input, Entity& entityP) {
	std::cout << "Main Member: ";
	input >> entityP.mainMember;
	std::cout << "\nage: ";
	input >> entityP.age;
	std::cout << "\nentity pointer: ";
	input >> *entityP.entityPtr;
	std::cout << "\nlocation x and y:  ";
	input >> entityP.location.x >> entityP.location.y;
	return input;
}

int& Entity::operator[](int subscript) {
	static int boundsError = -1;

	if (subscript >= 0 && subscript <= size - 1) {
		return elements[subscript];
	}
	else {
		std::cout << "\n Index is out of bounds!\n";
		return boundsError;
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
	std::cout << "copy assignment overload invoked #: " << count << "\n";
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
		std::cout << "move assignment = operator invoked\n";
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
	std::cout << "Enemies member is: " << enemyP.member << "\n";
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
	std::cout << "The entity is " << entityP.getAge() << " years old." << endl;
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




