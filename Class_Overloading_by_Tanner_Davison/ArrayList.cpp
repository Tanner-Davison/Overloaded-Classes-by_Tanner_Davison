#include "stdafx.h"

// Default Constructor
ArrayList::ArrayList() : list(nullptr), length(0) {
	length = 1;
	list = new char[length];
	std::memset(list, 0, length);
}

// Destructor
ArrayList::~ArrayList() {
	delete[] list;
}

// Copy Assignment Operator
ArrayList& ArrayList::operator=(const ArrayList& other) {
	if (this != &other) { // Check for self-assignment
		delete[] list; // Clean up current memory
		length = other.length; // Copy length
		list = new char[length]; // Allocate new memory
		std::memcpy(list, other.list, length); // Deep copy contents
	}
	return *this; // Return the current object
}

// Copy Constructor
ArrayList::ArrayList(const ArrayList& other) : length(other.length) {
	list = new char[length]; // Allocate new memory
	std::memcpy(list, other.list, length); // Deep copy contents
}

// Method to print the list
void ArrayList::printList() const {
	for (int i = 0; i < length; ++i) {
		std::cout << list[i];
	}
	std::cout << std::endl;
}
