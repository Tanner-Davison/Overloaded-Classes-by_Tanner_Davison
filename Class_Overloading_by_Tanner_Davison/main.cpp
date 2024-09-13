
#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"

template <typename T>

std::vector<T> addTwoArrays(const std::vector<T>& arrOne, const std::vector<T>& arrTwo) {
	size_t _SIZE = (arrOne.size() > arrTwo.size()) ? arrOne.size() : arrTwo.size();
	std::vector<T> temp(_SIZE);
	for (int i = 0; i < _SIZE; i++) {
		if (i >= arrOne.size()) {
			temp[i] = arrTwo[i];
		}
		else if (i >= arrTwo.size()) {
			temp[i] = arrOne[i];
		}
		else {
			temp[i] = (arrOne[i] + arrTwo[i]);
		}
	}
	return temp;
}
template <typename T = int, typename T1 = int>
struct Pairs {
	T first;
	T second;
	std::vector<T> vec1;
	std::vector<T1> vec2;
	~Pairs() = default;
	Pairs operator+(const Pairs<T>& other) const {
		std::vector<T> arrVecOne = addTwoArrays(this->vec1, other.vec1);
		vector<T1> arrVecTwo = addTwoArrays(this->vec2, other.vec2);

		return Pairs{ this->first + other.first, this->second + other.second, arrVecOne, arrVecTwo };
	}
};
template <typename T>
T addMembers(const Pairs<T>& pairsP) {
	return(pairsP.first + pairsP.second);
}
template <typename T>
std::ostream& operator<<(std::ostream& output, const std::vector<T> arr) {
	for (T val : arr) {
		output << val << ", ";
	}
	std::cout << "\n";
	return output;
}
std::ostream& operator<<(std::ostream& output, std::vector<std::string>& arr) {
	for (std::string val : arr) {
		output << "[ " << val << " ], ";
	}
	std::cout << "\n";
	return output;
}
template <typename T>
std::ostream& operator<<(std::ostream& output, Pairs<T> pairP) {
	output << "First: " << pairP.first << " Second: " << pairP.second << std::endl;
	return output;
}

template <typename T>
T smallestMembers(const Pairs<T>& pairP) {
	return(pairP.first < pairP.second ? pairP.first : pairP.second);
}
template <typename T>
T smallestMembers(const Pairs<T>* pairP) {
	return (pairP.first < pairP.second ? pairP.first : pairP.second);
}
int main() {

	Pairs<int, int> myPairs{ 100,200 };
	myPairs.vec1 = { 1,2,3,4,5,6 };
	myPairs.vec2 = { 5,3,2,1,5,5 };

	Pairs<int, int> myPairs2{ 100,244 };
	myPairs2.vec1 = { 1,2,3,4,5,6,7,8,9,10 };
	myPairs2.vec2 = { 3,4,5,6,7,6 };
	Pairs<int, int> vec3{ (myPairs + myPairs2) };
	Pairs<string, int> pair1{ "My", "pairs" };
	pair1.vec1 = { "Please", "Excuse" , "My", "Dear", "Aunt" ,"Sally" };
	pair1.vec2 = { 1,2,3,4,5,6,7 };
	Pairs<double, int> myguy{ 1.24, 1.55 };
	std::cout << pair1.vec1 << pair1.vec2;
	Pairs<double, int>* myPtr = &myguy;

	std::cout << smallestMembers(*myPtr) << endl;



	std::cout << "\n--------END OF PROGRAM--------" << endl;

	return 1;
}