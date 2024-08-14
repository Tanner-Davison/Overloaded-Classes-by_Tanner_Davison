#pragma once
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class ArrayList {
public:
	ArrayList();
	~ArrayList();
	ArrayList& operator=(const ArrayList& other);
	ArrayList(const ArrayList& other);
	void printList() const;
private:
	char* list;
	int length;
};
