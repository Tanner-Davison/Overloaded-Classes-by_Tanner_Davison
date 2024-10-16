//
// Created by Tanner on 8/31/2024.
//

#include "Base.h"
#include "stdafx.h"

Base::Base():x(1), privateMember(new int{1}) {
	std::cout << "Base Constructed" << std::endl;
}

Base::Base(const int xP, const int xPrivate) : x(xP), privateMember(new int(xPrivate))
{
	std::cout << "Base Set to " << x << std::endl;
}
Base::~Base()
{
	std::cout << "Base Destroyed" << std::endl;
	delete privateMember;
}

void Base::toString() const
{
	cout << "---Base---\n"<< "Base: x: "<< this->x << "\n" << endl;
}

void Base::printPrivateMember() const
{
	std::cout <<"Base Private Member " << *privateMember << endl;
}

