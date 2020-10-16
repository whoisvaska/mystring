#include "mystring.h"

/*	default constructor
	
	should we allocate memory like the default size for the string?
*/
MyString::MyString() {
	this->Allocate(10);
}


MyString::MyString(const char* string) {
	unsigned int string_lenght = strlen(string);

	this->Allocate(string_lenght + 1);
	memcpy(this->my_string, string, string_lenght);

	this->lenght_ = string_lenght;
	this->my_string[string_lenght] = 0;
}


MyString::MyString(const char* string, int lenght) {
	this->Allocate(lenght + 1);

	memcpy(this->my_string, string, lenght);

	this->lenght_ = lenght;
	this->my_string[lenght] = 0;
}


void MyString::shrink_to_fit() {
	this->ReAllocate(this->lenght_ + 1);
}


MyString::MyString(int count, char symbol) {
	this->Allocate(count + 1);

	memset(this->my_string, symbol, count);

	this->lenght_ = count;
	this->my_string[count] = 0;
}


MyString::MyString(const MyString& other) {
	*this = other.my_string;
}


MyString::~MyString() {
	std::cout << "destruct" << std::endl;

	if (this->my_string != NULL) {
		free(my_string);
	}
}


void MyString::Allocate(unsigned int size) {
	this->my_string = (char*)malloc(sizeof(char) * size);
	this->capacity_ = size;
}


void MyString::ReAllocate(unsigned int new_size) {
	this->my_string = (char*)realloc(this->my_string, sizeof(char) * new_size);
	this->capacity_ = new_size;
}


void MyString::operator+=(const char* string){
	unsigned int string_lenght = strlen(string);

	this->ReAllocate(this->lenght_ + string_lenght + 1);
	memcpy(this->my_string + this->lenght_, string, string_lenght);
	
	this->lenght_ += string_lenght;
	this->my_string[this->lenght_] = 0;
}


void MyString::operator=(char c) {
	this->my_string[1] = 0;
	this->my_string[0] = c;
	this->lenght_ = 1;
}


MyString operator+(const MyString& other, const char* string) {
	MyString temp_string = other;
	temp_string += string;
	return temp_string;
}


MyString operator+(const char* string, const MyString& other) {
	MyString temp_string = string;
	temp_string += other.my_string;
	return temp_string;
}


MyString operator+(const MyString& s1, const MyString& s2) {
	MyString temp_string = s1;
	temp_string += s2.my_string;
	return temp_string;
}


MyString& MyString::operator=(const MyString& other) {
	if (this == &other) {
		return *this;
	}
	*this = other.my_string;
	return *this;
}


bool MyString::operator==(const MyString& other) {
	return !strcmp(this->c_str(), other.my_string);
}


bool MyString::operator!=(const MyString& other) {
	return strcmp(this->c_str(), other.my_string);
}


bool MyString::operator>(const MyString& other) {
	if (strcmp(this->c_str(), other.my_string) > 0) {
		return true;
	}
	return false;
}


bool MyString::operator>=(const MyString& other) {
	if (strcmp(this->c_str(), other.my_string) >= 0) {
		return true;
	}
	return false;
}


bool MyString::operator<(const MyString& other) {
	if (strcmp(this->c_str(), other.my_string) < 0) {
		return true;
	}
	return false;
}


bool MyString::operator<=(const MyString& other) {
	if (strcmp(this->c_str(), other.my_string) <= 0) {
		return true;
	}
	return false;
}


void MyString::operator=(const char* string) {
	unsigned int string_lenght = strlen(string);

	this->ReAllocate(string_lenght + 1);
	memcpy(this->my_string, string, string_lenght);

	this->lenght_ = string_lenght;
	this->my_string[this->lenght_] = 0;
}


std::ostream& operator<<(std::ostream& cout, const MyString& string) {
	return (cout << string.my_string);
}


std::istream& operator>>(std::istream& cin, MyString& string) {
	const unsigned int max_size = 1024; //better to define it somethere else as a constant value
	char buffer[max_size];
	
	cin >> buffer;

	string = buffer;

	return cin;
}


void MyString::insert(unsigned int index, unsigned int count, char c) {
	const unsigned int max_size = 1024;
	
	const unsigned int lbuf_size = index;
	const unsigned int rbuf_size = this->lenght() - lbuf_size;
	
	char lbuf[max_size / 2];	//seems like we dont need the lbuf at all
	char rbuf[max_size / 2];

	memcpy(lbuf, this->c_str(), lbuf_size);
	memcpy(rbuf, this->c_str() + lbuf_size, rbuf_size);

	this->lenght_ = this->lenght_ + count;

	this->ReAllocate(this->lenght_ + 1);

	for (int i = count; i > 0; --i) {
		this->my_string[index++] = c;
	}

	memcpy(this->my_string + index, rbuf, rbuf_size);

	this->my_string[lenght_] = 0;
}


void MyString::insert(unsigned int index, const char* string) {
	const unsigned int max_size = 1024;
	unsigned int string_lenght = strlen(string);
	const unsigned int lbuf_size = index;
	const unsigned int rbuf_size = this->lenght() - lbuf_size;

	char lbuf[max_size / 2];	//seems like we dont need the lbuf at all
	char rbuf[max_size / 2];

	//memcpy(lbuf, this->c_str(), lbuf_size);
	memcpy(rbuf, this->c_str() + lbuf_size, rbuf_size);

	this->lenght_ = this->lenght_ + string_lenght;

	this->ReAllocate(this->lenght_ + 1);

	memcpy(this->my_string + index, string, string_lenght);

	memcpy(this->my_string + index + string_lenght, rbuf, rbuf_size);

	this->my_string[lenght_] = 0;
}



void MyString::insert(unsigned int index, const char* string, unsigned int count) {
	const unsigned int max_size = 1024;
	//unsigned int string_lenght = count;
	const unsigned int lbuf_size = index;
	const unsigned int rbuf_size = this->lenght() - lbuf_size;

	char lbuf[max_size / 2];	//seems like we dont need the lbuf at all
	char rbuf[max_size / 2];

	//memcpy(lbuf, this->c_str(), lbuf_size);
	memcpy(rbuf, this->c_str() + lbuf_size, rbuf_size);

	this->lenght_ = this->lenght_ + count;

	this->ReAllocate(this->lenght_ + 1);

	memcpy(this->my_string + index, string, count);

	memcpy(this->my_string + index + count, rbuf, rbuf_size);

	this->my_string[lenght_] = 0;
}


void MyString::erase(unsigned int index, unsigned int count) {
	const unsigned int max_size = 1024;
	unsigned int rbuf_size = this->lenght_ - count - index;

	memcpy(this->my_string + index, this->my_string + index + count, rbuf_size);

	this->lenght_ = this->lenght_ - count;
	this->my_string[lenght_] = 0;
}


void MyString::append(unsigned int count, char c) {
	unsigned int index = this->lenght_;
	this->insert(index, count, c);
}


void MyString::append(const char* string) {
	unsigned int index = this->lenght_;
	this->insert(index, string);
}


void MyString::append(const char* str, unsigned int index, unsigned int count) {
	unsigned int at = this->lenght_;
	this->insert(at, str + index, count);
	//this->insert(str + index, at, count);
}

/*add check if allocated size is less than required*/
void MyString::replace(unsigned int index, unsigned int count, const char* string) {
	const int max_size = 1024;
	const char* rbuf[max_size / 2];
	unsigned int rbuf_size = this->lenght_ - index - count;
	unsigned int lbuf_size = index;
	memcpy(rbuf, this->my_string + index + count, rbuf_size);
	memcpy(this->my_string + index, string, strlen(string));
	memcpy(this->my_string + index + count, rbuf, rbuf_size);
	this->lenght_ = lbuf_size + strlen(string) + rbuf_size;
	this->my_string[this->lenght_] = 0;
	//memcpy(this->my_string + index, string, count);
}


//void MyString::replace(unsigned int index, unsigned int count, const char* string) {
//	memcpy(this->my_string + index, string, count);
//}


int MyString::find(const char* str) {
	const char* substr = strstr(this->my_string, str);
	
	if (substr != NULL) {
		return (substr - this->my_string);
	}

	return -1;
}


int MyString::find(const char* str, unsigned int index) {
	return (this->find(str + index));
}


/*	this function returns the constant pointer to the string
*/
const char* MyString::c_str() {
	const char* c = this->my_string;
	return c;
}


MyString MyString::substr(unsigned int index) {
	/*MyString temp_string = this->my_string + index;
	return temp_string;*/
	return MyString(this->my_string + index);
}


MyString MyString::substr(unsigned int index, unsigned int count) {
	/*const unsigned int max_size = 1024;
	char buf[max_size];
	memcpy(buf, this->my_string + index, count);
	buf[count] = 0;*/

	/*MyString temp_string(this->my_string + index, count)*/;

	return MyString(this->my_string + index, count);
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


unsigned int MyString::capacity() {
	return this->capacity_;
}


char* MyString::data() {
	return this->my_string;
}
