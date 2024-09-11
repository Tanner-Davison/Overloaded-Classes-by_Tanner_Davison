#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"

struct Example
{
	int member;

	bool operator<=(const Example &rho)const
	{
		return this->member < rho.member;
	};
};
std::ostream& operator<<(std::ostream& output, const Example& exampleP)
{
	output << exampleP.member;
	return output;
}



int main()
{
	const ExampleTemplate example{100};
	std::cout << example.getMember() << endl;

cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}