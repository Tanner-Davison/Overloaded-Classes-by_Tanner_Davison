#include "stdafx.h"


const string& getProgramName() {
	const static string programName{ "Hello world how are you?" };
	return programName;
}
void static toString(Entity& other) {
	std::cout << "Pointer of classType Entity: " << other.getPointer() << "\n\n";
}

void test(const int& x) {
	std::cout << "L Value Reference" << std::endl;
}
void test(int&& x) {
	std::cout << "R Value Reference" << std::endl;
}

int main() {

	int const ARRAY_SIZE = 3;
	Entity entity1{ 5,10,20,Vector2D(10,20),ARRAY_SIZE };
	Entity entity2{ 10,20,40, Vector2D(20,40), ARRAY_SIZE };
	Entity entity3{ 20,40,80, Vector2D(40,80), ARRAY_SIZE };

	double arr[ARRAY_SIZE]{ 40,50,200 };
	double arr2[ARRAY_SIZE]{ 100,100,200 };
	double arr3[ARRAY_SIZE]{ 500,200,100 };

	entity3.setElements(arr3, ARRAY_SIZE);
	entity2.setElements(arr2, ARRAY_SIZE);
	entity1.setElements(arr, ARRAY_SIZE);

	Entity totals = entity1 + entity2 + entity3;

	std::cout << totals;



	return 0;
}