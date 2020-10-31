#include "mystring.h"
#include <iostream>
#include <string>


int main() {
	std::string s;
	std::cout << s.length() << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << "\n" << std::endl;

	s = "123";

	std::cout << s.length() << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << "\n" << std::endl;
	
	s.shrink_to_fit();

	std::cout << s.length() << std::endl;
	std::cout << s.size() << std::endl;
	std::cout << s.capacity() << "\n" << std::endl;

	return 0;

}