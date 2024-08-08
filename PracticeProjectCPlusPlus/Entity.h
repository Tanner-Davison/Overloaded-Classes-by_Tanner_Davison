#pragma once

class Entity {
public:
	Entity();
	Entity(int Ppass);
	Entity(int pAge, int pAccessToken);

	Entity& operator++();
	Entity operator++(int);
	Entity& operator--();
	Entity operator--(int);
	Entity operator+(const Entity& other)const;
	Entity operator*(const Entity& other)const;

	Entity multiply(const Entity& other) const;
	Entity add(const Entity& other)const;
	int getAge() const;
	int getAccess() const;

	void toString() const;
	void setAge(int pAge);
	void setAccessToken(int pAccess);



private:
	int accessToken;
	int age;
	static int count;
	int instance;
};