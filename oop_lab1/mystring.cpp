#include "mystring.h"

MyString::MyString() {

}


MyString::MyString(const char* c) {
	unsigned int c_len = strlen(c);

	this->ReAllocate(c_len);
	memcpy(this->my_string, c, c_len);
	this->my_string[c_len] = 0;
}


MyString::MyString(const char* c, int lenght) {
	this->ReAllocate(lenght);

	memcpy(this->my_string, c, lenght);

	this->my_string[lenght] = 0;
}


MyString::MyString(int count, char symbol) {
	this->ReAllocate(count);

	for (int i = 0; i < count; ++i) {
		this->my_string[i] = symbol;
	}
	this->my_string[count] = 0;
}


/*	destructor of the class
*/
MyString::~MyString() {
	std::cout << "destruct" << std::endl;

	if (this->my_string != NULL) {
		free(my_string);
	}
}


void MyString::Allocate(unsigned int size) {
	this->my_string = (char*)malloc(sizeof(char) * size + 1);
	this->lenght_ = size;
	this->capacity_ = size + 1;
}


void MyString::ReAllocate(unsigned int new_size) {
	this->my_string = (char*)realloc(this->my_string, sizeof(char) * new_size + 1);
	this->lenght_ = new_size;
	this->capacity_ = new_size + 1;
}


unsigned int MyString::capacity() {
	return this->capacity_;
}


void MyString::operator+=(const char* c){
	unsigned int c_len = strlen(c);

	this->ReAllocate(this->lenght_ + c_len);

	memcpy(this->my_string + this->lenght_ - c_len , c, c_len);
	this->my_string[this->lenght_] = 0;
}


void MyString::operator=(char c) {

}


/*	this function returns the constant pointer to the string
*/
const char* MyString::c_str() {
	const char* c = this->my_string;
	return c;
}


/*	this function returns the %char at specified %index.
	
	should we throw an exception if the specified index 
	is out of range or not?
*/
char MyString::operator[](int index) {
	char c = (index == -1 ? this->my_string[this->lenght_ - 1] : this->my_string[index]);	
	return c;
}


/*	this function returns the lenght of the string buffer.
	
	to prevent calculating the lenght all the time it is specified 
	every time string is changing.
*/
unsigned int MyString::lenght() {
	return this->lenght_;
}