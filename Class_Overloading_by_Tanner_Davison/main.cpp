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


	Entity* myArrPointers[ARRAY_SIZE]{};

	myArrPointers[0] = new Entity[2]{ Entity(3),Entity(5) };
	myArrPointers[1] = new Entity[3]{};


	myArrPointers[1][2].setLocation(Vector2D(200, 500));

	for (int i = 0; i < 2; i++) {

		myArrPointers[0][i].setAge(400);
		std::cout << myArrPointers[0][i] << "\n";

		if (i == 1) {
			for (int j = 0; j < 3; j++) {
				myArrPointers[1][j].setAge(j + 200);
				std::cout << myArrPointers[1][j] << "\n";
			}
		}

	}

	for (int i = 0; i < ARRAY_SIZE; i++) {
		delete[] myArrPointers[i];
		myArrPointers[i] = nullptr;
	}



	return 0;
}