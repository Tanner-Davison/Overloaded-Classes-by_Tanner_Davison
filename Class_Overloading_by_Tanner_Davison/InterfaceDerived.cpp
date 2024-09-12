//
// Created by Tanner on 9/8/2024.
//
#include "stdafx.h"
#include "InterfaceDerived.h"

void InterfaceDerived::tostring(std::ostream& output) const
{
	output << "Printing From InterfaceDerived!" << std::endl;
}

InterfaceDerived::~InterfaceDerived()
{
	std::cout << "Deleting InterFaceDerived" << endl;
}
