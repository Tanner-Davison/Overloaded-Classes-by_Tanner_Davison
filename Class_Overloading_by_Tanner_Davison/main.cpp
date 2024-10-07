
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


	int* x{}, y{};
	A entity{};
	A entity2{};

	const A* const ptr1{};

	A* const ptr2{};
	A* ptr3 = new A;
	std::cout << "Types..." << std::endl;

	std::cout << "x: " << typeid(x).name() << std::endl;
	std::cout << "y: " << typeid(y).name() << std::endl;
	std::cout << "A : " << typeid(entity).name() << std::endl;
	std::cout << "A : " << typeid(entity2).name() << std::endl;

	std::cout << "ptr1: " << typeid(ptr1).name() << std::endl;
	std::cout << "ptr2: " << typeid(ptr2).name() << std::endl;
	std::cout << "ptr3-> " << typeid(*ptr3).name() << std::endl;


	delete pD;
	std::cout << "\n ----END PROGRAM ------" << std::endl;

	return 0;

}




