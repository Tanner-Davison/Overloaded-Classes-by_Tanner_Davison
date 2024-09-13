
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


template<typename T=string, typename T1=double>
class Bank
{
public:
	explicit Bank(T nameP, T1 depositP=0):name(std::move(nameP))
	{
		deposit.insert(deposit.begin(), depositP);
		std::cout<< "Bank Created for: " << name << " Starting with: ";
		for(T1 num: deposit)
		{
			std::cout<< "$" << num << endl;
		}
	};

	// void make_deposit();
	// void read_deposits();
	// T get_total();

	// T total = get_total();
	std::vector<T1> deposit;
	T name;
};
template <typename T=double, typename T1=string>
inline std::ostream& operator<<(std::ostream& output, const Bank<T,T1>& bankP)
{
	output << bankP.name << " Total Worth: " << bankP.deposit[0]<<endl;
	return output;
}
int main() {

	std::cout << "MAX VALUE FOR INT: " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "MAX LIMIT OF INT: " << INT_MAX << std::endl;

	std::cout << std::boolalpha;
	std::cout << "Is INT signed? " << std::numeric_limits<int>::is_signed << std::endl;
	bool b1, b2;
	std::istringstream is("true false");
	is >> std::boolalpha >> b1 >> b2;
	std::cout << '"' << is.str() << "\" parsed as: "
		<< std::boolalpha << b1 << ' ' << b2 << '\n';
	std::cout << "\n--------END OF PROGRAM--------" << endl;

	const Bank<string, double> tanners{"Tanner",100.00};
	cout << tanners;
	return 1;
}




