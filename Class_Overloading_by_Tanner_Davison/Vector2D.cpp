#include "stdafx.h"

// Assignment operator
Vector2D Vector2D::operator=(const Vector2D& other) {
	if (this == &other) {
		return *this; // Self-assignment check
	}
	this->x = other.x;
	this->y = other.y;
	return *this;
}

// Add to self
Vector2D Vector2D::addToSelf(const Vector2D& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

// Addition operator
Vector2D Vector2D::operator+(const Vector2D& other) const {
	return Vector2D(this->x + other.x, this->y + other.y);
}

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