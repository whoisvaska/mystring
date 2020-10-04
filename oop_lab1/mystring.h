#ifndef _MYSTRING_H_
#define _MYSTRING_H_

#include <stdlib.h>
#include <string.h>

#include <iostream>

class MyString {
public:
	MyString();
	MyString(const char*);
	MyString(const char*, int);
	MyString(int count, char symbol);

	~MyString();
	
	const char* c_str();
	unsigned int lenght();
	unsigned int capacity();

	void operator+=(const char*);
	char operator[](int);
	void operator=(char);

private:
	char* my_string = 0;

	unsigned int lenght_ = 0;
	unsigned int capacity_ = 0;

	void Allocate(unsigned int);
	void ReAllocate(unsigned int);
	
	
};




#endif
