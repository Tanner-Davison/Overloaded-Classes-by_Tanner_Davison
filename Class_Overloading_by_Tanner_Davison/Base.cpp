//
// Created by Tanner on 8/31/2024.
//

#include "Base.h"
#include "stdafx.h"

Base::Base():x(1) {
	std::cout << "Base Constructed" << std::endl;
}

Base::Base(const int xP) : x(xP)
{
	std::cout << "Base Set to " << x << std::endl;
}
Base::~Base()
{
	std::cout << "Base Destroyed" << std::endl;
}

void Base::toString() const
{
	cout << "---Base---\n"<< "Base: x: "<< this->x << "\n" << endl;
}

