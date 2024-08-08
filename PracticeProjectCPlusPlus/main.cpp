#include <iostream>
#include "Entity.h"

using namespace std;

int main() {

	Entity eOne{ 25 }, eTwo{ 30 };
	eOne.setAccessToken(300);
	eTwo.setAccessToken(150);

	Entity total = eOne.add(eTwo.multiply(eOne));

	cout << total.getAge() << "HERE" << endl;

	total.toString();
	eOne.toString();




	return 0;
}