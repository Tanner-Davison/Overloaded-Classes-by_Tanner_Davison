#include "stdafx.h"


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

//static void modifyPointerAddress(int* ptrP, int* addressToAssaign) {
//	ptrP = addressToAssaign;
//}
static void modifyPointerAddress(int** ptrP, int* addressToAssaign) {
	*ptrP = addressToAssaign;
}
static void modifyPointerAddress(int*& ptrP, int* addressToAssaign) {
	ptrP = addressToAssaign;
}

int main() {


	int STUFF = 4;
	int MAX = 100;
	int* ptr = &STUFF;
	int varToAssaign{ 250 };
	std::cout << "BEFORE: " << *ptr << endl;

	int*& refToPointer = ptr;

	/*modifyPointerAddress(refToPointer, &varToAssaign);*/
	/*modifyPointerAddress(&ptr, &varToAssaign);*/
	modifyPointerAddress(&ptr, &varToAssaign);

	//"Ref to Pointer"
	//int*& refToPtr = ptr;
	//refToPtr = &varToAssaign;



	std::cout << "After: " << *ptr << std::endl;
	std::cout << "stuff: " << STUFF << " MAX: " << MAX;


	return 0;
}