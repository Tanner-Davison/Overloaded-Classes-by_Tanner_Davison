#include "stdafx.h"


const string& getProgramName() {
	const static string programName{ "Hello world how are you?" };
	return programName;
}
void static toString(Entity& other) {
	std::cout << "Pointer of classType Entity: " << other.getPointer() << "\n\n";
}

void test(const int& x) {
	std::cout << "L Value Reference" << std::endl;
}
void test(int&& x) {
	std::cout << "R Value Reference" << std::endl;
}

class Test {

public:
	Test(int memberP = 0) : member(memberP), memberLong(0) {
		std::cout << "constructor Test was called: " << member << "\n";
	}

	// Constructor for long long
	Test(long long memberP) : member(0), memberLong(memberP) {
		std::cout << "overloaded constructor used for long long: " << memberLong << "\n";
	}
	~Test() {
		std::cout << "Deallocating memory for TEST: " << (memberLong > member ? memberLong : member) << "\n";
	}
	void toString()const {
		if (this->memberLong > this->member) {
			std::cout << this->memberLong << endl;
		}
		else {
			std::cout << this->member << endl;
		}
	}

private:

	int member;
	long long memberLong;
};


int main() {

	int const ARRAY_SIZE = 3;
	int* inputAge = new int;
	long long* inputNumber = new long long int;
	int* inputBirthday = new int;

	std::cout << "Enter Age: \n";
	if (!(std::cin >> *inputAge)) {
		std::cerr << "Invalid input for age!" << std::endl;
		return 1;
	}
	std::cout << "Enter Number: \n";
	if (!(std::cin >> *inputNumber)) {
		std::cerr << "Invalid input for number!" << std::endl;
		return 1;
	}
	std::cout << "Enter Birthday (mmDDYY)\n";
	if (!(std::cin >> *inputBirthday)) {
		std::cerr << "Invalid input for birthday!" << std::endl;
		return 1;
	}

	if (inputAge != nullptr && inputNumber != nullptr && inputBirthday != nullptr) {
		Test* ptr = new Test[ARRAY_SIZE]{ Test(*inputAge), Test(*inputNumber), Test(*inputBirthday) };
		for (int i = 0; i < 3; i++) {
			ptr[i].toString();
		}

		delete[]ptr;
		ptr = nullptr;
		delete inputAge;
		delete inputNumber;
		delete inputBirthday;
	}
	else {
		return 1;
	}





	return 0;
}