#include <iostream>
#include "Entity.h"
#include "Enemies.h"

using namespace std;

const string& getProgramName() {
	const static string programName{ "Hello world how are you?" };
	return programName;
}
void static toString(Entity& other) {
	cout << "Pointer of classType Entity: " << other.getPointer() << "\n\n";
}

void test(const int& x) {
	cout << "L Value Reference" << endl;
}
void test(int&& x) {
	cout << "R Value Reference" << endl;
}

int main() {

	Entity e1{ 1, 10, 1.1, Vector2D(0.0,0.0) };
	Enemies enemy1;
	howOld(e1);

	enemy1.getInstance(e1);

	return 0;
}