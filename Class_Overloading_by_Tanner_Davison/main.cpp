
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
	SomeBase(){};
	virtual ~SomeBase(){};

	virtual void toString()
	{
		std::cout << "Base::toString()."<< std::endl;
	}
};
class DerivedSome : public SomeBase
{
public:
	DerivedSome() = default;
	virtual ~DerivedSome(){};
	virtual void toString() const
	{
		std::cout << "Derived::toString()" << std::endl;
	}
	int getMember()
	{
		return member;
	}
private:
	int member{5};
};

void displayPtr(SomeBase* basePtr)
{
	DerivedSome* ptr = dynamic_cast<DerivedSome*>(basePtr);

	if(ptr)
	{
		std::cout << ptr->getMember() << std::endl;
	}else
	{
		std::cout << "nullptr" << std::endl;
	}
}
void displayRef(SomeBase& baseRef)
{
	DerivedSome& refBase = dynamic_cast<DerivedSome&>(baseRef);
	DerivedSome* refBasePtr = dynamic_cast<DerivedSome*>(&refBase);

	if(refBasePtr)
	{
		std::cout << "Derived Part of Base Member: " << refBasePtr->getMember() << std::endl;

	}else
	{
		std::cout << "Nullptr" << std::endl;
	}
}
int main() {

	SomeBase* basePtr = new DerivedSome;
	DerivedSome derivedRef{};
	DerivedSome& derivedRefPtr = derivedRef;

	displayPtr(basePtr);
	displayRef(derivedRefPtr);


	/*const vector<double> myvec{ 100.00, 200.00,500.00, 800.00 };

	Bank<string, double> tanners("Tanner", 100.00);

	tanners.make_multiple_deposits(myvec);

	std::cout << tanners;*/





}




