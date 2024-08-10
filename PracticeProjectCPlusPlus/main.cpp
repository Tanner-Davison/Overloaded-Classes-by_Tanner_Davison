#include <iostream>
#include "Entity.h"

using namespace std;

const string& getProgramName() {
	const static string programName{ "Hello world how are you?" };
	return programName;
}
void toString(Entity& other) {
	cout << "Pointer of classType Entity: " << other.getPointer() << "\n\n";
}
int main() {

	Entity eOne{ 5, 50, 43.3 }, eTwo{ 6 };

	Vector2D loc{ 200.32, 100.32 };

	eOne.setLocation(loc);
	cout << eOne.getLocation().x << " " << eOne.getLocation().y << "\n";

	Entity totals = eOne;
	cout << "TESTING: " << totals.getLocation().x << " " << totals.getLocation().y << "\n";

	return 0;
}