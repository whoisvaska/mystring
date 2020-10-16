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
	MyString(const MyString&);

	~MyString();
	
	const char* c_str();
	char* data();
	unsigned int lenght();
	unsigned int capacity();

	void shrink_to_fit();

	friend MyString operator+(const MyString&, const char*);
	friend MyString operator+(const char*, const MyString&);

	friend MyString operator+(const MyString&, const MyString&);

	MyString& operator=(const MyString&);

	friend std::ostream& operator<<(std::ostream&, const MyString&);
	friend std::istream& operator>>(std::istream&, MyString&);

	bool operator==(const MyString&);
	bool operator!=(const MyString&);
	void operator+=(const char*);
	bool operator>(const MyString&);
	bool operator>=(const MyString&);
	bool operator<(const MyString&);
	bool operator<=(const MyString&);

	char operator[](int);
	void operator=(char);
	void operator=(const char* string);

	void insert(unsigned int, unsigned int, char);
	void insert(unsigned int, const char*);
	void insert(unsigned int, const char*, unsigned int);

	void erase(unsigned int, unsigned int);

	void append(unsigned int, char);
	void append(const char*);
	void append(const char*, unsigned int, unsigned int);

	void replace(unsigned int, unsigned int, const char*);

	int find(const char*);
	int find(const char*, unsigned int);

	MyString substr(unsigned int);
	MyString substr(unsigned int, unsigned int);

private:
	char* my_string = 0;

	unsigned int lenght_ = 0;
	unsigned int capacity_ = 0;

	void Allocate(unsigned int);
	void ReAllocate(unsigned int);
	
	
};




#endif
