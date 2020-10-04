#include "mystring.h"
#include <iostream>
#include <string>


int main() {

	std::string s("diuasdhiuashdssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssisdhdsadadad");

	//s = "123";

	std::cout << s.capacity() << std::endl;


	s.clear();
	std::cout << s.capacity() << std::endl;
	s.shrink_to_fit();
	std::cout << s.capacity() << std::endl;



	return 0;
}