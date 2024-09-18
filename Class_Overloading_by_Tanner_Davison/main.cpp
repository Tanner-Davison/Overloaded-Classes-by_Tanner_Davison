
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


template<typename T = string, typename T1 = double >
class Bank
{
public:
	explicit Bank(T nameP, T1 depositP = 0) :name(std::move(nameP))
	{

		deposit.insert(deposit.begin(), depositP);
		std::cout << "Bank Created for: " << name << std::endl;
		std::cout << "Initial Deposit: $" << depositP << std::endl;
	};

public:
	void make_deposit(T1 valueP) {
		deposit.insert(deposit.begin(), valueP);
		std::cout << "Deposit Received: $" << valueP << "\n";
	};
	// void read_deposits();
	// T get_total();

	// T total = get_total();
	std::vector<T1> deposit;
	T name;
};
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
template <typename T = double, typename T1 = string>
inline std::ostream& operator<<(std::ostream& output, const Bank<T, T1>& bankP)
{
	output << bankP.name << " Total Worth: $" << addArrayValues<double>(bankP.deposit) << std::endl;
	return output;
}
int main() {


	const vector<double> myvec{ 100.00, 200.00,500.00, 800.00 };

	Bank<string, double> tanners("Tanner", 100.00);

	for (int i = 0; i < myvec.size(); i++) {

		tanners.make_deposit(myvec[i]);
	}
	std::cout << tanners;

	return 1;
}




