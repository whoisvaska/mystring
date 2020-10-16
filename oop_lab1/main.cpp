#include "mystring.h"
#include <iostream>
#include <string>


int main() {

	MyString s;

	s = "hello amazing world";

	std::cout << s.capacity() << std::endl;
	
	s.replace(6, 7, "wonderful");
	
	std::cout << s.capacity() << std::endl;

	std::cout << s << std::endl;
}