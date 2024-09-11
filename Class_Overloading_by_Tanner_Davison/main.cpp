#include <utility>

#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"

template<typename T>

T returnSmallest(const T& x,const T& y)
{
	return x <= y ? x : y;
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
void printAll(const X& x, const Y& y, const Z&z)
{
	std::cout << x << " " << y << " " << z << endl;
}
template <typename C>
void print(const C& c)
{
	std::cout << c << endl;
}
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
	constexpr Example one{100};
	constexpr Example two{200};
	const auto three = returnSmallest<Example>(one, two);
	print(three);

cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}