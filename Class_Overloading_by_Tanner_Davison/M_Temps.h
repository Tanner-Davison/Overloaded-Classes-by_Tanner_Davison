#pragma once
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
template <typename B>
inline std::ostream& operator<<(std::ostream& output, const CharClass<B>& charclass) {
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

template <typename T>

std::vector<T> addTwoArrays(const std::vector<T>& arrOne, const std::vector<T>& arrTwo) {
	size_t SIZE = (arrOne.size() > arrTwo.size()) ? arrOne.size() : arrTwo.size();
	std::vector<T> temp(SIZE);
	for (int i = 0; i < SIZE; i++) {
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
static inline std::ostream& operator<<(std::ostream& output, const std::vector<std::string>& arr) {
	for (std::string val : arr) {
		output << "[ " << val << " ], ";
	}
	std::cout << "\n";
	return output;
}
template <typename T>
static inline std::ostream& operator<<(std::ostream& output, const Pairs<T> pairP) {
	output << "First: " << pairP.first << " Second: " << pairP.second << std::endl;
	return output;
}

template <typename T>
T smallestMembers(const Pairs<T>& pairP) {
	return(pairP.first < pairP.second ? pairP.first : pairP.second);
}
template <typename T>
T smallestMembers(const Pairs<T>* pairP) {
	return pairP->first < pairP->second ? pairP->first : pairP->second;
}
template <typename T, typename T1>
T smallest(T x, T1 y) {
	return(x < y ? x : y);
}

