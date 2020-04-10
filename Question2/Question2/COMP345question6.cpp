#include <iostream>
#include "COMP345question6.h"


MyArray::MyArray() {
	this->size = 0;  
	this->theArray = new int[0];
}

MyArray::~MyArray() {
	delete[] theArray;
	theArray = NULL;
}

//Copy ctor
MyArray::MyArray(const MyArray& arr) : size(arr.size), theArray(arr.size ? new int[arr.size] : nullptr) {
	if (theArray)
		std::copy(arr.theArray, arr.theArray + size, theArray);
}

//Assignment operator
MyArray& MyArray::operator=(const MyArray & arr)
{
	if (this == &arr)
		return *this;

	delete theArray;

	theArray = arr.theArray;
	size = arr.size;

	return *this;
}


MyArray::MyArray(int *arr, int size) {
	this->size = size;
	this->theArray = new int[size];

	for (int i = 0; i < size; i++) {
		if(!isInArray(arr[i]))
			this->theArray[i] = arr[i];
	}
}

void MyArray::print_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}
	std::cout << std::endl;
}

//IsInArray
bool MyArray::isInArray(int val) {
	bool duplicate = false;

	for (int i = 0; i < size; i++) {
		if (theArray[i] == val)
			return duplicate = true;
	}

	return duplicate;
}

/*
int main() {

	int someArray[5] = { 2, 12, 1, 4, 9 };
	return 0;
}*/