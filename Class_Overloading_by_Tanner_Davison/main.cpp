#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"

void display(const Base& baseP) {
	baseP.toString();
}
int main()
{
	Base * base = new Derived(100,50);
	Derived* derived;

	derived = static_cast<Derived*>(base);
	derived->specialFunc();

	cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}