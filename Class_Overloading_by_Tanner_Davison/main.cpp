#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"

void display(const Base& baseP) {
	baseP.toString();
}
int main()
{

	int tan = 10;
	string name = "tanner";

	cout << to_string(tan) <<endl;
	string* man = (string*)&name;

	cout << *man << endl;


	cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}