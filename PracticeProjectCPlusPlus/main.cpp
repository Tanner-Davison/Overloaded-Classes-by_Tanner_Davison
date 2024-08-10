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

	Vector2D loc{ 100.32, 100.33 };
	Vector2D loc2{ 23.33, 23.22 };
	Vector2D loc3 = loc + loc2 + loc2;

	Entity eOne{ 5, 50, 43.3, loc };
	Entity eTwo{ 2, 2, 3.33 , loc2 };

	eOne.setLocation(eOne.getLocation().addToSelf(loc2));
	eOne.getLocation().readLocation();
	loc3.readLocation();

	Entity totals = eOne = eTwo;

	eOne.toString();
	eTwo.toString();
	totals.toString();


	return 0;
}