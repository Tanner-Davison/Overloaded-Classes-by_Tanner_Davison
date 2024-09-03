#include "Vector2D.h"
#include "stdafx.h"
//constructor
Vector2D::Vector2D(double pX, double pY) : x(pX), y(pY) {}

// Assignment operator
Vector2D& Vector2D::operator=(const Vector2D& other) {
	if (this == &other) {
		return *this; // Self-assignment check
	}
	this->x = other.x;
	this->y = other.y;
	return *this;
}
Vector2D::Vector2D(const Vector3D& vec3P) {
	x = vec3P.x;
	y = vec3P.y;
}
Vector2D::operator Vector3D()const {
	std::cout << "Vector2D Conversion operator invoked\n";
	return { x, y, 0 };
}
Vector2D Vector2D::addToSelf(const Vector2D& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

// Addition operator
Vector2D Vector2D::operator+(const Vector2D& other) const {
	return Vector2D(this->x + other.x, this->y + other.y);
}


//Vector2D operator+(const Vector2D& lho, const Vector2D& rho) {
//	Vector2D temp;
//	temp.x = lho.x + rho.x;
//	temp.y = lho.y + rho.y;
//}


// Prefix decrement
Vector2D& Vector2D::operator--() {
	--this->x;
	--this->y;
	return *this;
}

// Postfix decrement
Vector2D Vector2D::operator--(int) {
	Vector2D temp = *this;
	--(*this);
	return temp;
}

// Prefix increment
Vector2D& Vector2D::operator++() {
	++this->x;
	++this->y;
	return *this;
}

// Postfix increment
Vector2D Vector2D::operator++(int) {
	Vector2D temp = *this;
	++(*this);
	return temp;
}

// Print the location
void Vector2D::readLocation() const {
	std::cout << "Location X: " << this->x << " Location Y: " << this->y << "\n";
}