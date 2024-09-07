#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"

class Abstract
{
public:
	virtual void tostring()const=0;
	virtual ~Abstract()
	{
		std::cout << "Abstract Destructing..." << endl;
	};
};
class DerivedAb : public Abstract
{
public:
	void tostring() const override
	{
		std::cout << "overriding abstract" << endl;
	}
	virtual ~DerivedAb(){std::cout << "derivedAb destructor" << endl;};
};
int main()
{
string* mystrings[5];
	for(int x =0; x < 5; x++)
	{
		mystrings[x] = new std::string;
	}
	for(int x =0; x < 5; x++)
	{
		string temp;
		std::getline(std::cin, temp);
		*mystrings[x] = temp;

	}
	for(int x = 0; x < 5; x++)
	{
		std::cout << *mystrings[x] << endl;
	}
	for(int x = 0; x < 5; x++)
	{
		delete mystrings[x];
	}
cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}