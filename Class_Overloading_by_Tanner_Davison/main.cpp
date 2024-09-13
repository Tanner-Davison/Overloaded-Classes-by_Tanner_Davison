
#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"
#include "M_Temps.h"

int main() {

	Pairs<int, int> myPairs{ 100,200 };
	myPairs.vec1 = { 1,2,3,4,5,6 };
	myPairs.vec2 = { 5,3,2,1,5,5 };

	Pairs<int, int> myPairs2{ 100,244 };
	myPairs2.vec1 = { 1,2,3,4,5,6,7,8,9,10 };
	myPairs2.vec2 = { 3,4,5,6,7,6 };
	Pairs<int, int> vec3{ (myPairs + myPairs2) };
	Pairs<string, int> pair1{ "My", "pairs" };
	pair1.vec1 = { "Please", "Excuse" , "My", "Dear", "Aunt" ,"Sally" };
	pair1.vec2 = { 1,2,3,4,5,6,7 };
	Pairs<double, int> myguy{ 1.24, 1.55 };
	std::cout << pair1.vec1 << pair1.vec2;
	Pairs<double, int>* myPtr = &myguy;

	std::cout << smallestMembers(*myPtr) << endl;



	std::cout << "\n--------END OF PROGRAM--------" << endl;

	return 1;
}