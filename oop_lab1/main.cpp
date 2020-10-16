#include "mystring.h"
#include <iostream>
#include <string>


int main() {

	MyString s;

	s = "hello amazing world";

	s.replace(6, 7, "wonderful");

	std::cout << s << std::endl;
}