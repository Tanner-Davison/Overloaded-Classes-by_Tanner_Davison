#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"

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
	const IBaseInterface* myBase = new InterfaceDerived();

	cout << *myBase << endl;

cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}