#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"

template<typename T>

T returnSmallest(const T& x,const T& y)
{
	return x >= y ? y : x;
}
template<typename B>
void interchange(B& x, B&y) noexcept
{
	B temp;
	temp = x;
	x = y;
	y = temp;
}

template <typename X, typename Y, typename Z>
void print(const X& x, const Y& y, const Z&z)
{
	std::cout << x << " " << y << " " << z << endl;
}

int main()
{
	print<char, int, float>('X', 100, 52.5);
	print<>(200, 200, 150.5);

cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}