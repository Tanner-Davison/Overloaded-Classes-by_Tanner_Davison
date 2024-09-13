
#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"
#include "M_Temps.h"
#include "Friend_Class_Templates.h"


int main() {

	int x = 44;
	EntityEx<int*> entity{ &x };
	toStrings(entity);
	cout << entity;


	std::cout << "\n--------END OF PROGRAM--------" << endl;

	return 1;
}




