#pragma once


template <typename T>
class EntityEx;

template<typename T>
void toStrings(const EntityEx<T>& entityP);

template <typename T>
inline std::ostream& operator<<(std::ostream& output, const EntityEx<T>& entityP);

template<typename T>
class EntityEx {

	friend void toStrings<>(const EntityEx<T>& entityP);
	friend std::ostream& operator<< <>(std::ostream& output, const EntityEx<T>& entityP);
public:
	EntityEx(T memberP = 0);
private:
	T member;
};


template<typename T>
EntityEx<T>::EntityEx(T memberP) :member(memberP)
{
	std::cout << "EntityEx created" << endl;
}

template <typename T>
inline void toStrings(const EntityEx<T>& entityP)
{
	std::cout << entityP.member << endl;
};


template<>
inline void toStrings(const EntityEx<int*>& entityP)
{
	std::cout << *entityP.member << endl;
}
template <typename T>
inline std::ostream& operator<<(std::ostream& output, const EntityEx<T>& entityP) {
	output << entityP.member << "FROM <<()" << endl;
	return output;
}
template <>
inline std::ostream& operator<<(std::ostream& output, const EntityEx<int*>& entityP) {
	output << *entityP.member << " SPECIALIZED OVERRIDE___ <<()" << std::endl;
	return output;
}