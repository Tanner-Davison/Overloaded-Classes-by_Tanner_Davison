#pragma once
#include "stdafx.h"

struct Vector3D {
	//initial Constructor
	Vector3D() : x(0.0), y(0.0), z(0.0) {};
	//overloaded constructor
	Vector3D(double xP, double yP, double zP);

	double x;
	double y;
	double z;
};