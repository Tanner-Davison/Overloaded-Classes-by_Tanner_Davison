#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"

int main()
{

   Base* basePtr = new Derived;
    basePtr->toString();
    delete basePtr;
    cout << "--------END OF PROGRAM----------" << endl;
    return 1;
}