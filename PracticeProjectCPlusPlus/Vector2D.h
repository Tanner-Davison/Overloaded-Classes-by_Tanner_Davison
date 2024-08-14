#pragma once
#include "stdafx.h"

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
