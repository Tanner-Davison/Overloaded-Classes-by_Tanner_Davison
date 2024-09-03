//
// Created by Tanner on 9/1/2024.
//

#include "Derived.h"
#include "stdafx.h"

Derived::Derived()
{
	std::cout << "Derived Class Constructed\n" << endl;
}

Derived::Derived(const int xP, const int yP): basePtr(new Base(xP)), y(yP)
{
	std::cout<< "Derived Class Constructed\n" << endl;
}

Derived::~Derived()
{
	std::cout << "Derived Class Destroyed" << endl;
	delete basePtr;
}

void Derived::toString() const
{
	std::cout << "---Derived---\n" << "Base x = " << this->x << " Derived y = "<< this->y << endl;
	cout << "basePtr ->";
	this->basePtr->toString();
	cout << "\n";
}

void Derived::specialFunc() const
{
	std::cout << "this is a special function" << endl;
}

