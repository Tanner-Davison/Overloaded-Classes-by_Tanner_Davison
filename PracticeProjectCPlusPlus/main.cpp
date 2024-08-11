#include <iostream>
#include "Entity.h"

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

	Entity e1{ 100, 200, 32.3, Vector2D(2.5, 3.5) }, e2(300, 400, 32.5, Vector2D(2.5, 6.6));

	e1 = e2--;

	e1.toString();

	string isEqual = e1.isEqual(e2) ? "They are the same" : "They are not equal";


	cout << isEqual << "\n";

	return 0;
}