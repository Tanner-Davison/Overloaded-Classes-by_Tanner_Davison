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
Entity createEntity() {
	return Entity();
}
int main() {

	Entity e1{};
	Entity e2 = createEntity();
	e1 = createEntity();
	e2.toString();

	e1.toString();



	return 0;
}