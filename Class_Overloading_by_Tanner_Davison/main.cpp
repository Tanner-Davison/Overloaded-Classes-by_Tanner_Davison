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
static void SetupTableValues(int* rowsP, int* columnsP) {

	std::cout << "Enter how many Rows & Columns: ";
	std::cin >> *rowsP >> *columnsP;
}

static Entity** entityArrayFactory(int* rowsP, int* columnsP) {
	Entity** pp_Tables = new Entity * [*rowsP] {nullptr};

	for (int currentRow = 0; currentRow < *rowsP; currentRow++) {
		pp_Tables[currentRow] = new Entity[*columnsP];
	}
	return pp_Tables;
}

static void rowBuilder(Entity** p, int* rowsP, int* columnsP) {
	int tempNum;
	for (int i = 0; i < *rowsP; i++) {
		std::cout << "Assaign " << *columnsP << " Columns On row:" << i + 1 << "\n";
		for (int j = 0; j < *columnsP; j++) {
			std::cin >> tempNum;
			p[i][j].setAge(tempNum);
		}
	}
	std::cout << endl;
}

static void PrintTable(Entity** p, int* rowsP, int* columnsP, char* mathOperatorP) {
	std::cout << "\nEnter operater for total columns / rows? | + | - | * | / |";
	std::cin >> *mathOperatorP;
	std::cout << "\t- - -\tTable\t- - -\n";
	for (int i = 0; i < *rowsP; i++) {
		for (int j = 0; j < *columnsP; j++) {
			std::cout << "\t" << p[i][j].getAge() << "\t";
		}
		std::cout << endl;
	}
}
std::string CreateColumnGap(int columns, const std::string& gap) {
	std::string result;
	for (int i = 0; i < columns; ++i) {
		result += gap;
	}
	return result;
}
static void printTotalsByRow(Entity** p, int* rowsP, int* columnsP, bool rowOrColumn, char* mathOperator) {

	if (rowOrColumn == true) {
		for (int i = 0; i < *rowsP; i++) {

			int totalRows = 0;
			for (int j = 0; j < *columnsP; j++) {
				if (i == 0) {
					totalRows += p[i][j].getAge();
				}
				else {
					switch (*mathOperator) {
					case '+':
						totalRows += p[i][j].getAge();
						break;
					case '-':
						totalRows -= p[i][j].getAge();
						break;
					case '*':
						totalRows *= p[i][j].getAge();
						break;
					case '/':
						if (p[i][j].getAge() != 0) {
							if (totalRows == i) {
								totalRows = (totalRows / p[i][j].getAge()) * 100;
							}
							totalRows /= p[i][j].getAge();

						}
						else {
							cout << "Division by zero error at Row " << i + 1 << ", Column " << j + 1 << "\n";
						}
						break;
					default:
						cout << "Invalid operator\n";
						return;
					}
				}

			}
			std::cout << "\n\tRow " << *rowsP << " total = " << totalRows << "\n";
		}
	}
	else if (rowOrColumn == false) {
		string columnGap = "\t___\t    ";
		std::cout << CreateColumnGap(*columnsP, columnGap) << "\n";
		for (int i = 0; i < *columnsP; i++) {
			int totalColumns = 0;
			for (int j = 0; j < *rowsP; j++) {
				if (j == 0) {
					totalColumns += p[j][i].getAge();
				}
				else {
					switch (*mathOperator) {
					case '+':
						totalColumns += p[j][i].getAge();
						break;
					case '-':
						totalColumns -= p[j][i].getAge();
						break;
					case '*':
						totalColumns *= p[j][i].getAge();
						break;
					case '/':
						if (p[j][i].getAge() != 0) {
							totalColumns /= p[j][i].getAge();
						}
						else {
							cout << "Division by zero error at column " << i + 1 << ", row " << j + 1 << "\n";
						}
						break;
					default:
						cout << "Invalid operator\n";
						return;
					}
				}

			}
			std::cout << "\t" << totalColumns << "\t";
		}
	}

}

int main() {

	int* ROWS = new int;
	int* COLUMNS = new int;
	char* mathOperator = new char;
	SetupTableValues(ROWS, COLUMNS);
	Entity** pp_Tables = entityArrayFactory(ROWS, COLUMNS);
	rowBuilder(pp_Tables, ROWS, COLUMNS);
	PrintTable(pp_Tables, ROWS, COLUMNS, mathOperator);
	printTotalsByRow(pp_Tables, ROWS, COLUMNS, false, mathOperator);

	for (int i = 0; i < *ROWS; i++) {
		delete[] pp_Tables[i];
	}
	delete[]pp_Tables;
	delete ROWS;
	delete COLUMNS;










	//Entity** pp_Table = new Entity * [ROWS] {};

	//for (int currentRow = 0; currentRow < ROWS; currentRow++) {
	//	pp_Table[currentRow] = new Entity[COLUMNS];
	//}

	//for (int i = 0; i < ROWS; i++)
	//{
	//	for (int j = 0; j < COLUMNS; j++)
	//	{
	//		std::cout << pp_Table[i][j] << endl;
	//	}
	//}

	//for (int i = 0; i < ROWS; i++)
	//{
	//	delete[] pp_Table[i];
	//}
	//delete[] pp_Table;



















	//int const ARRAY_SIZE = 3;


	//Entity* myArrPointers[ARRAY_SIZE]{};

	//myArrPointers[0] = new Entity[2]{ Entity(3),Entity(5) };
	//myArrPointers[1] = new Entity[3]{};


	//myArrPointers[1][2].setLocation(Vector2D(200, 500));

	//for (int i = 0; i <= 1; i++) {

	//	myArrPointers[0][i].setAge(i + 400);
	//	std::cout << "Array [0] Index: " << i << " " << myArrPointers[0][i] << "\n";

	//	if (i == 1) {
	//		for (int j = 0; j < 3; j++) {
	//			myArrPointers[1][j].setAge(j + 200);
	//			std::cout << "Array [1] Index: " << j << " " << myArrPointers[1][j] << "\n";
	//		}
	//	}

	//}

	//for (int i = 0; i < ARRAY_SIZE; i++) {
	//	delete[] myArrPointers[i];
	//	myArrPointers[i] = nullptr;
	//}



	return 0;
}