#include <limits>
#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"
#include "M_Temps.h"
#include "Friend_Class_Templates.h"
#include <sstream>
#include <utility>
#include <typeinfo>
#include <cstdio>

template <typename T>
T addArrayValues(const vector<T>& arrayP) {
	T temp = 0;
	for (int i = 0; i < arrayP.size(); i++) {
		temp += arrayP[i];
	}
	if (temp > 0) {
		return temp;
	}
	else {
		return 0;
	}
}
//change up
template<typename T = string, typename T1 = double >
class Bank
{
public:
	explicit Bank(T nameP, T1 depositP = 0) :name(std::move(nameP))
	{
		std::cout << "Bank Member: " << name << std::endl;
		this->make_single_deposit(depositP);
	};
	void make_single_deposit(T1 valueP) {

		deposit.insert(deposit.begin(), valueP);
		if (deposit.size() <= 1) {
			std::cout << "Initial Deposit: $" << valueP << "\n";
		}
		else {
			std::cout << "Deposited: $" << valueP << "\n";
		}
		this->total = addArrayValues<T1>(deposit);
	}

	void make_multiple_deposits(const vector<T1>& valueArrP) {
		for (int i = 0; i < valueArrP.size(); i++) {
			deposit.insert(deposit.begin(), valueArrP[i]);
		}
		T1 totalDeposits = addArrayValues<T1>(valueArrP);
		this->total = addArrayValues<T1>(deposit);
		std::cout << "Multiple Deposits Total: " << totalDeposits << "\n";
	}
	std::vector<T1> deposit;
	T1 total;
	T name;
};

template <typename T = double, typename T1 = string>
inline std::ostream& operator<<(std::ostream& output, const Bank<T, T1>& bankP)
{
	output << bankP.name << " Total Worth: $" << bankP.total << std::endl;
	return output;
}

class TestingBase {
public:
	virtual ~TestingBase() = default;
	virtual void toString() const {
		std::cout << "testing base " << std::endl;
	}
};
class TestingDerived final : public TestingBase {
public:
	~TestingDerived() override = default;
	void toString() const override {
		std::cout << "Printing from testing Base" << std::endl;
	}
};
template<typename T = int, int size = 1>
class MyContainer {
public:
	T& operator[](int index) {
		return m_Array[index];
	}
private:
	T m_Array[size]{};
};
template <typename T, int size>
class FixedArray
{
public:
	void print() const
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << data[i] << " " << std::endl;
		}
		std::cout << std::endl;
	}

	T data[size];
};

class SomeBase
{
public:
	SomeBase() {};
	virtual ~SomeBase() {};

	virtual void toString()
	{
		std::cout << "Base::toString()." << std::endl;
	}
};
class DerivedSome : public SomeBase
{
public:
	DerivedSome() = default;
	virtual ~DerivedSome() {};
	virtual void toString() const
	{
		std::cout << "Derived::toString()" << std::endl;
	}
	int getMember()
	{
		return member;
	}
private:
	int member{ 5 };
};

void displayPtr(SomeBase* basePtr)
{
	DerivedSome* ptr = dynamic_cast<DerivedSome*>(basePtr);

	if (ptr)
	{
		std::cout << ptr->getMember() << std::endl;
	}
	else
	{
		std::cout << "nullptr" << std::endl;
	}
}
void displayRef(SomeBase& baseRef)
{
	DerivedSome& refBase = dynamic_cast<DerivedSome&>(baseRef);
	DerivedSome* refBasePtr = dynamic_cast<DerivedSome*>(&refBase);

	if (refBasePtr)
	{
		std::cout << "Derived Part of Base Member: " << refBasePtr->getMember() << std::endl;

	}
	else
	{
		std::cout << "Nullptr" << std::endl;
	}
}
class A
{
public:
	virtual ~A() {};
	virtual void toString() const
	{
		std::cout << "Base::toString()" << std::endl;
	}
};
class B : public A {};
class C : public A {};
class D
{
public:
	D() = default;
	virtual ~D() {};
	virtual void toString()
	{
		std::cout << "::toString() from class D" << std::endl;
	}
};
class E : public B, public C, public D {};

// A function that takes in a constant reference and modifies it using const_cast
int constNum(const int& num) {
	// Remove const-ness from 'num' to allow modification
	int& modifiableNum = const_cast<int&>(num);
	modifiableNum = 1200; // Dangerous: Modifying a const variable
	std::cout << "Modified Value: " << modifiableNum << std::endl;
	return num; // This returns the (potentially unchanged) original value
}
//modifies the const out of a constant object ->
class ConstantClass {
public:
	ConstantClass(int memberP = 0) :member(memberP)
	{ }
	void ModifyMemberConst(const int intP) const {
		(const_cast<ConstantClass*>(this))->member = intP;
	}
	void toString()const {
		std::cout << this->member << std::endl;
	}

private:
	int member;
};

int& GetValue() {
	static int value = 100;
	return value;
}
template <typename T>
void howManyTilZero(const T& pVal) {
	T count = pVal;
	T steps = 0;
	while (count > 0) {
		std::cout << "Current Count" << count << std::endl;
		count--;
		steps++;
	}
	std::cout << "Completed in " << steps << " steps" << std::endl;
}
int main()
{
	D* pD = new E;

	A* pA = dynamic_cast<A*>(pD);

	if (pA == nullptr)
	{
		std::cout << "nullpointer" << std::endl;
	}
	else
	{
		std::cout << "not empty" << std::endl;
	}

	int myNum = GetValue() = 10;
	std::cout << "HERE" << myNum << std::endl;

	// downcast followed by upcasting;
	E* pE = dynamic_cast<E*>(pD);
	B* pB = dynamic_cast<B*>(pE);
	A* pA2 = dynamic_cast<A*>(pB);
	if (pA2 != nullptr)
	{
		pA2->toString();
		std::cout << "from pA2!" << std::endl;
	}
	// cross casting
	B* pB2 = dynamic_cast<B*>(pD);
	A* pA3 = dynamic_cast<A*> (pB2);
	if (pA3 != nullptr)
	{
		pA3->toString();
		std::cout << "from pA3!" << std::endl;
	}


	/*const char* tanner = "Tanner";*/
	char testing[8] = "Testing";
	char name[] = { 'T','A','N','N','E','R','\0' };
	printf("%s\n", testing);

	const int x = 100;
	int y = constNum(x);
	std::cout << "Return Value: " << y << std::endl;
	std::cout << "Original Value of x: " << x << std::endl;// x may or may not be changed depending on how it was declared
	const ConstantClass test{ 800 };
	test.toString();// prints 800
	test.ModifyMemberConst(100);
	test.toString(); // prints 100

	int xyz{ 250 };
	volatile int* vPtr{ &xyz };
	int* ptr = const_cast<int*>(vPtr);

	int temp = constNum(xyz);

	int numSteps = 45.99;
	howManyTilZero(numSteps);

	std::cout << typeid(vPtr).name() << std::endl;

	delete pD;
	std::cout << "\n ----END PROGRAM ------" << std::endl;

	return 0;

}



