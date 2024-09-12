
#include "stdafx.h"
#include "Base.h"
#include "Derived.h"
#include "IBaseInterface.h"
#include "InterfaceDerived.h"
#include "ExampleTemplate.h"

template <typename T>
class CharClass {
public:
	explicit CharClass(T memberP = 0);
	~CharClass() = default;
	void setMember(const T& memberP);
	T getMember()const {
		return this->member;
	}
	bool operator<(const T& otherP)const {
		return(this->member < otherP);
	}
private:
	T member;
	T x;
	T y;
};
template<typename T>
CharClass<T>::CharClass(T memberP) : member(memberP)
{
	std::cout << "created Char Class Object;" << std::endl;
}
template <typename T>
void CharClass<T>::setMember(const T& memberP) {
	this->member = memberP;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& output, const CharClass<T>& charclass) {
	output << charclass.getMember();

	return output;
};

template<typename T1, typename T2>
struct Pair {
	T1 first;
	T2 second;
};

template <int size = 0, typename T = int>
struct ArrayStruct {
public:

	void toString()const {
		for (int i = 0; i < size; i++) {
			std::cout << m_array[i] << endl;
		}
	}
	T& operator[](T index) {
		return this->m_array[index];
	}
private:
	T m_array[size]{};
};
template <typename T>
class Names {
public:
	explicit Names(vector<T>& namesP = 1) : names(namesP) {
		std::cout << "names Created!" << endl;
	};
	~Names() = default;
	void toString() {
		for (int i = 1; i < names.size(); i++) {
			std::cout << names[i] << " ";
		}
		std::cout << std::endl;
	};
private:
	vector<T> names;
};

int main()
{
	std::vector<std::string> allnames{ "Tanner", "Lisa", "James", "Brandon", "Jackson" };

	std::vector<std::pair<int, std::string>> allpairs;


	allpairs.reserve(allnames.size());
for (int i = 0; i < allnames.size(); ++i) {
		allpairs.emplace_back(i, allnames[i]);
	}

	for (const auto& pair : allpairs) {
		std::cout << "Index: " << pair.first << ", Name: " << pair.second << std::endl;
	}



	std::cout << "--------END OF PROGRAM--------" << endl;
	return 1;
}