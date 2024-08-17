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

	Vector3D vec3(3, 5, 6);
	Vector2D vec2(5.5);
	vec3 = vec2;
	Entity entity1{ 20,40,4.4, Vector2D(2.3,4.3),6 };
	std::cout << entity1 << "\n";

	for (int i = 0; i < 10; i++) {
		std::cout << entity1[i] << ", ";
	}
	std::cout << "\n";

	return 0;
}