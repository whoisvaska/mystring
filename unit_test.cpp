#include "pch.h"
#include "CppUnitTest.h"
#include "./oop_lab1/mystring.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/*	Covered methods:
	1) concatenate with MyString (ConcatenateWithMyString)
	2) concatenate with char array (ConcatenateWithCharArray)
		also includes:
		2.2) assignment concatenate with char array
		2.3) assignment concatenate with std::string
	3) concatenate with std::string (ConcatenateWithStdString)
		also includes:
		3.1) char assignment
		3.2) index operator
	4) lexicographically comparing (LexicographicallyComparing)
	5) insert count of char in index position (InsertingCountOfCharAtIndex)
	6) insert null-terminated char string at index position (InsertingCharStringAtIndex)
	7) insert count of null-terminated char string at index position (InsertingCountOfCharStringAtIndex)
	8) insert null-terminated char string at index position (InsertingStdStringAtIndex)
		also includes:
		8.1) length
	9) erase count of char at index position (EraseCountAtIndex)
		also includes:
		9.1) find
	10) append count of char (AppendCountOfChar)
		also includes:
		10.1) clear
	11) append null-terminated char string(AppendCharString)
		also includes:
		11.1) erase
		11.2) length
	12) append a count of null-terminated char string by index position (AppendCountOfCharStringAtIndex)
	13) replace a count of char at index by null-terminated string (ReplaceCountAtIndexByCharString)
	14) replace a count of char at index by std::string (ReplaceCountAtIndexByStdString)
	15) substring starts with index position (SubstringAtIndex)
	16) count of substring char starts with index position (SubstringCountAtIndex)
	17) find null-terminated string (FindCharString)
	18) find null-terminated string starting from index position (FindCharStringFromIndex)

	Another tests:
	1) appending/insering in for i in range of 10000 (AppendInsert10000)
*/


namespace unittest
{
	TEST_CLASS(ConcatenateWithMyString)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string string1("hello");
			std::string string2(", world!");
			std::string string3(string1 + string2);

			MyString my_string1("hello");
			MyString my_string2(", world!");
			MyString my_string3(my_string1 + my_string2);


			Assert::AreEqual(string3.c_str(), my_string3.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string string1("0");					
			std::string string2("1");					
			std::string string3 = string1 + string2;	// -> "01"
			string3 = string3 + string1 + string2;		// -> "0101"
			string3 = string3 + std::string("1010");	// -> "01011010"
		
			MyString my_string1("0");
			MyString my_string2("1");
			MyString my_string3 = my_string1 + my_string2;		// -> "01"
			my_string3 = my_string3 + my_string1 + my_string2;	// -> "0101"
			my_string3 = my_string3 + MyString("1010");			// -> "01011010"
		
			Assert::AreEqual(string3.c_str(), my_string3.c_str());
		}
		

	};

	TEST_CLASS(ConcatenateWithCharArray)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string string1("hello");
			std::string string2("world!");
			std::string string3 = string1 + ", beautiful ";
			string3 = string3 + string2.c_str();

			MyString my_string1("hello");
			MyString my_string2("world!");
			MyString my_string3 = my_string1 + ", beautiful ";
			my_string3 = my_string3 + my_string2.c_str();


			Assert::AreEqual(string3.c_str(), my_string3.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string string9("9");

			std::string string1;
			string1 = string1 + "0123";
			string1 += "456";
			std::string string2("78");
			string1 += string2.c_str();
			string1 += string9;

			MyString my_string1;
			my_string1 = my_string1 + "0123";
			my_string1 += "456";
			MyString my_string2("78");
			my_string1 += my_string2.c_str();
			my_string1 += string9;

			Assert::AreEqual(string1.c_str(), my_string1.c_str());
		}
	};

	TEST_CLASS(ConcatenateWithStdString)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string string1 = "hello";
			std::string string2 = " world!";
			std::string string3 = string1 + ',' + string2;

			MyString my_string1;
			my_string1 = ',';
			MyString my_string2 = " world!";
			MyString my_string3 = string1 + my_string1 + my_string2;

			Assert::AreEqual(string3.c_str(), my_string3.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string string = "000,000";
			std::string string1 = "0123";
			std::string string2 = "4567";
			std::string string3 = string1 + string[3] + string2;

			MyString my_string = "000,000";
			MyString my_string1;
			my_string1 = string1 + my_string[3] + string2;

			Assert::AreEqual(string3.c_str(), my_string1.c_str());
		}
	};
	TEST_CLASS(LexicographicallyComparing)
	{
	public:
		/*>*/
		TEST_METHOD(TestG)
		{
			std::string string1 = "01234567890";
			std::string string2 = "01234567891";

			MyString my_string1 = "01234567890";
			MyString my_string2 = "01234567891";

			Assert::AreEqual(string1 > string2 , my_string1 > my_string2);
		}
		/*>=*/
		TEST_METHOD(TestGE)
		{
			std::string string1 = "01234567890";
			std::string string2 = "01234567890";

			MyString my_string1 = "01234567890";
			MyString my_string2 = "01234567890";

			Assert::AreEqual(string1 >= string2, my_string1 >= my_string2);
		}
		/*<*/
		TEST_METHOD(TestL)
		{
			std::string string1 = "Done building project \"unit_test.vcxproj\".";
			std::string string2 = "Done building project \"unit_testvcxproj\".";

			MyString my_string1 = "Done building project \"unit_test.vcxproj\".";
			MyString my_string2 = "Done building project \"unit_testvcxproj\".";

			Assert::AreEqual(string1 < string2, my_string1 < my_string2);
		}
		/*<=*/
		TEST_METHOD(TestLE)
		{
			std::string string1 = "abclsadlkdjsaio213j";
			std::string string2 = "abclsadlkdjsaio213j";

			MyString my_string1 = "abclsadlkdjsaio213j";
			MyString my_string2 = "abclsadlkdjsaio213j";

			Assert::AreEqual(string1 <= string2, my_string1 <= my_string2);
		}
		/*==*/
		TEST_METHOD(TestE) 
		{
			std::string string1 = "Done building project \"unit_test.vcxproj\".";
			std::string string2 = "Done building project \"unit_test.vcxproj\".";

			MyString my_string1 = "Done building project \"unit_test.vcxproj\".";
			MyString my_string2 = "Done building project \"unit_test.vcxproj\".";

			Assert::AreEqual(string1 == string2, my_string1 == my_string2);
		}
		/*!=*/
		TEST_METHOD(TestNE)
		{
			std::string string1 = "Done building project \"unit_testvcxproj\".";
			std::string string2 = "Done building project \"unit_test.vcxproj\".";

			MyString my_string1 = "Done building project \"unit_test.vcxproj\".";
			MyString my_string2 = "Done building project \"unit_testvcxproj\".";

			Assert::AreEqual(string1 != string2, my_string1 != my_string2);
		}
	};

	TEST_CLASS(InsertingCountOfCharAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "012356789";
			s1.insert(4, 1, '4');			// -> "0123456789"

			MyString ms1 = "012356789";
			ms1.insert(4, 1, '4');			// -> "0123456789"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.insert(s1.length(), 4, '9');

			MyString ms1 = "here we have 4 nines: ";
			ms1.insert(ms1.length(), 4, '9');

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(InsertingCharStringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "012356789";
			s1.insert(4, "4");			// -> "0123456789"

			MyString ms1 = "012356789";
			ms1.insert(4, "4");			// -> "0123456789"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.insert(s1.length(), "9999");

			MyString ms1 = "here we have 4 nines: ";
			ms1.insert(ms1.length(), "9999");

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(InsertingCountOfCharStringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "aaaaa";
			s1.insert(1, "@@@@", 2);			// -> "a@@aaaa"

			MyString ms1 = "aaaaa";
			ms1.insert(1, "@@@@", 2);				// -> "a@@aaaa"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.insert(s1.length(), "9999999", 4);

			MyString ms1 = "here we have 4 nines: ";
			ms1.insert(ms1.length(), "9999999", 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(InsertingStdStringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "012356789";
			std::string s2 = "4";
			s1.insert(4, s2);			// -> "0123456789"

			MyString ms1 = "012356789";
			ms1.insert(4, s2);			// -> "0123456789"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			std::string s2 = "9999";
			s1.insert(s1.length(), s2);

			MyString ms1 = "here we have 4 nines: ";
			ms1.insert(ms1.length(), s2);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(InsertingCountOfStdStringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "aaaaa";
			std::string s2 = "@@@@";
			s1.insert(1, s2, 2);			// -> "a@@aaaa"

			MyString ms1 = "aaaaa";
			ms1.insert(1, s2, 2);				// -> "a@@aaaa"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			std::string s2 = "9999999";
			s1.insert(s1.length(), "9999999", 4);

			MyString ms1 = "here we have 4 nines: ";
			ms1.insert(ms1.length(), s2, 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(EraseCountAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "aa@@@@@aaa";
			s1.erase(2, 3);					// -> "a@@aaaa"

			MyString ms1 = "aa@@@@@aaa";
			ms1.erase(2, 3);				// -> "a@@aaaa""

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: 99999999";
			s1.erase(s1.find("9999"), 4);

			MyString ms1 = "here we have 4 nines: 99999999";
			ms1.erase(ms1.find("9999"), 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(AppendCountOfChar)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "aa@@@@@aaa";
			s1.clear();						// -> ""
			s1.append(3, '!');				// -> "!!!"
			s1.append(3, '@');				// -> "!!!@@@"

			MyString ms1 = "aa@@@@@aaa";
			ms1.clear();					// -> ""
			ms1.append(3, '!');				// -> "!!!"
			ms1.append(3, '@');				// -> "!!!@@@"


			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.append('9', 4);

			MyString ms1 = "here we have 4 nines: ";
			ms1.append('9', 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(AppendCharString)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "aa@@@@@aaa";
			s1.erase(0, s1.length());		// -> ""
			s1.append("!!!");				// -> "!!!"
			s1.append("@@@");				// -> "!!!@@@"

			MyString ms1 = "aa@@@@@aaa";
			ms1.erase(0, ms1.length());		// -> ""
			ms1.append("!!!");				// -> "!!!"
			ms1.append("@@@");				// -> "!!!@@@"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.append("9999");

			MyString ms1 = "here we have 4 nines: ";
			ms1.append("9999");

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(AppendCountOfCharStringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "";
			s1.append("hello world", 0, 6);
			s1.append("hello world", 6, 5);

			MyString ms1 = "";
			ms1.append("hello world", 0, 6);
			ms1.append("hello world", 6, 5);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.append("88889999", 4, 4);

			MyString ms1 = "here we have 4 nines: ";
			ms1.append("88889999", 4, 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};
	TEST_CLASS(AppendStdString)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "aa@@@@@aaa";
			s1.erase(0, s1.length());			// -> ""
			s1.append(std::string("hello "));	// -> "hello "
			s1.append(std::string("world"));	// -> "hello world"

			MyString ms1 = "aa@@@@@aaa";
			ms1.erase(0, ms1.length());			// -> ""
			ms1.append(std::string("hello "));	// -> "hello "
			ms1.append(std::string("world"));	// -> "hello world"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.append(std::string("9999"));

			MyString ms1 = "here we have 4 nines: ";
			ms1.append(std::string("9999"));

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};
	TEST_CLASS(AppendCountOfStdStringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "";
			s1.append(std::string("hello world"), 0, 6);
			s1.append(std::string("hello world"), 6, 5);

			MyString ms1 = "";
			ms1.append(std::string("hello world"), 0, 6);
			ms1.append(std::string("hello world"), 6, 5);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: ";
			s1.append(std::string("88889999"), 4, 4);

			MyString ms1 = "here we have 4 nines: ";
			ms1.append(std::string("88889999"), 4, 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(ReplaceAtIndexByCharString)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";
			s1.replace(6, 7, "wonderful");			// -> "hello wonderful world"

			MyString ms1 = "hello amazing world";
			ms1.replace(6, 7, "wonderful");			// -> "hello wonderful world"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: 88888";
			s1.replace(s1.find("88888"), 5, "9999");

			MyString ms1 = "here we have 4 nines: 88888";
			ms1.replace(ms1.find("88888"), 5, "9999");

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(ReplaceCountAtIndexByStdString)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";
			s1.replace(6, 7, std::string("wonderful"));		// -> "hello wonderful world"

			MyString ms1 = "hello amazing world";
			ms1.replace(6, 7, std::string("wonderful"));	// -> "hello wonderful world"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: 88888";
			s1.replace(s1.find("88888"), 5, std::string("9999"));

			MyString ms1 = "here we have 4 nines: 88888";
			ms1.replace(ms1.find("88888"), 5, std::string("9999"));

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};
	TEST_CLASS(SubstringAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";
			s1.substr(6);								// -> "amazing world"

			MyString ms1 = "hello amazing world";
			ms1.substr(6);								// -> "amazing world"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: 9999";
			s1.substr(s1.find("9999"));

			MyString ms1 = "here we have 4 nines: 9999";
			ms1.substr(ms1.find("9999"));

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(SubstringCountAtIndex)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";
			s1.substr(6, 7);								// -> "amazing"

			MyString ms1 = "hello amazing world";
			ms1.substr(6, 7);								// -> "amazing"

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
		TEST_METHOD(Test2)
		{
			std::string s1 = "here we have 4 nines: 9999999";
			s1.substr(s1.find("9999"), 4);				

			MyString ms1 = "here we have 4 nines: 9999999";
			ms1.substr(ms1.find("9999"), 4);

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};

	TEST_CLASS(FindCharString)
	{
	public:
		/*found*/
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			Assert::AreEqual(s1.find("amazing"), static_cast<size_t>(ms1.find("amazing")));
		}
		/*not found*/
		TEST_METHOD(Test2)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			/*i dont know if its actually right way to return the max value of size_t if a substring was not found so
			in my implementation find() returns -1 if substring was not found*/
			Assert::AreEqual(s1.find("wonderful"), static_cast<size_t>(ms1.find("wonderful")));
		}
	};

	TEST_CLASS(FindCharStringFromIndex)
	{
	public:
		/*found*/
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			Assert::AreEqual(s1.find("amazing", 6), static_cast<size_t>(ms1.find("amazing"), 6));
		}
		/*not found*/
		TEST_METHOD(Test2)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			Assert::AreEqual(s1.find("amazing", 10), static_cast<size_t>(ms1.find("amazing", 10)));
		}
	};

	TEST_CLASS(FindStdString)
	{
	public:
		/*found*/
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			Assert::AreEqual(s1.find(std::string("amazing")), static_cast<size_t>(ms1.find(std::string("amazing"))));
		}
		/*not found*/
		TEST_METHOD(Test2)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			/*i dont know if its actually right way to return the max value of size_t if a substring was not found so
			in my implementation find() returns -1 if substring was not found*/
			Assert::AreEqual(s1.find(std::string("wonderful")), static_cast<size_t>(ms1.find(std::string("wonderful"))));
		}
	};

	TEST_CLASS(FindStdStringFromIndex)
	{
	public:
		/*found*/
		TEST_METHOD(Test1)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			Assert::AreEqual(s1.find(std::string("amazing"), 6), static_cast<size_t>(ms1.find(std::string("amazing")), 6));
		}
		/*not found*/
		TEST_METHOD(Test2)
		{
			std::string s1 = "hello amazing world";

			MyString ms1 = "hello amazing world";

			Assert::AreEqual(s1.find(std::string("amazing"), 10), static_cast<size_t>(ms1.find(std::string("amazing"), 10)));
		}
	};

	TEST_CLASS(AppendInsert10000)
	{
	public:
		TEST_METHOD(Test1)
		{
			std::string s1 = "";
			MyString ms1 = "";
			for (int i = 0; i < 10000; ++i) {
				if (i % 2 == 0) {
					s1.append(1, 'a');
					ms1.append(1, 'a');
				}
				else {
					s1.insert(s1.length() - 1, 1, 'b');
					ms1.insert(ms1.length() - 1, 1, 'b');
				}
			}

			Assert::AreEqual(s1.c_str(), ms1.c_str());
		}
	};
}
