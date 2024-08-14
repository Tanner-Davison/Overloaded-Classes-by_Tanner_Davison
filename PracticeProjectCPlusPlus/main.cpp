#include "stdafx.h"


const string& getProgramName() {
	const static string programName{ "Hello world how are you?" };
	return programName;
}
void static toString(Entity& other) {
	std::cout << "Pointer of classType Entity: " << other.getPointer() << "\n\n";
}

void test(const int& x) {
	std::cout << "L Value Reference" << endl;
}
void test(int&& x) {
	std::cout << "R Value Reference" << endl;
}

int main() {

	Entity e1{ 1, 10, 1.1, Vector2D(0.0,0.0) };
	Enemies enemy1;
	howOld(e1);

	enemy1.getInstanceOfEntity(e1);
	Entity e2{ 2,3,20.3, Vector2D(40,43) };
	std::cout << e1;

	printEnemyMember(enemy1);

	return 0;
}