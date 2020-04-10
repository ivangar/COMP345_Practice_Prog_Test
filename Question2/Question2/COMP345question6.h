
#ifndef COMP345_QUESTION6_H
#define COMP345_QUESTION6_H
#include<iostream>
using namespace std;

class MyArray {
public:

	MyArray();
	MyArray(int *arr, int size);
	MyArray(const MyArray& arr);
	~MyArray();
	MyArray& operator=(const MyArray & arr);
	void print_arr(int *arr, int size);
	int getSize() {
		return size;
	}
	int* getArray() {
		return theArray;
	}

	bool isInArray(int val);
private:
	int *theArray;
	int size;
};


#endif