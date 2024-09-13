
#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"
#include "M_Temps.h"
#include "Friend_Class_Templates.h"
#include <sstream>

int main() {

	std::cout << "MAX VALUE FOR INT: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "MAX LIMIT OF INT: " << INT_MAX << std::endl;

	std::cout << std::boolalpha;
	std::cout << "Is INT signed? " << std::numeric_limits<int>::is_signed << std::endl;
	bool b1, b2;
	std::istringstream is("true false");
	is >> std::boolalpha >> b1 >> b2;
	std::cout << '"' << is.str() << "\" parsed as: "
		<< std::boolalpha << b1 << ' ' << b2 << '\n';
	std::cout << "\n--------END OF PROGRAM--------" << endl;

	return 1;
}




