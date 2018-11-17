// STL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "basic_string.h"
#include "string"
int main(){
	basic_string ch;
	std::cin >> ch;
	std::cout << ch.size() << std::endl;
	std::cout << ch.c_str() << std::endl;
	std::cout << ch.insert(1,"rty",3) << std::endl;
	std::cout << ch.at(3) << std::endl;
	std::cout << ch << std::endl;
	std::cout << ch.erase(1,3) << std::endl;
	std::cout << ch.front() << std::endl;
	std::cout << ch << std::endl;
	basic_string ar = "123456789";
	ch += "world";
	std::cout << ch << std::endl;
	ch.replace(1, 3, ar);
	std::cout << ch << std::endl;
	basic_string a = "0123456789abcdefghij";
	basic_string sub1 = a.substr(10);
	std::cout << sub1 << '\n';
	basic_string sub2 = a.substr(5, 3);
	std::cout << sub2 << '\n';
	basic_string sub3 = a.substr(12, 100);
	std::cout << sub3 << '\n';
	basic_string foo("quuuux");
	char bar[7];
	foo.copy(bar, sizeof bar);
	bar[6] = '\0';
	basic_string s1 = "Hello";
	//basic_string s2 = "world";
	std::cout << s1 + '0' + "111";
	std::cout << stoi("ABCD121", 0 , 16) << '\n';
 	std::cout << stol("012345676", 0, 8) << '\n';
	std::cout << stoll("00000000", 4, 10) << '\n';
	basic_string strin = to_string(12345678.1);
	std::cout << strin << '\n';
	std::cout << strin.front() << '\n';
	std::cout << strin[strin.size() - 2] << '\n';
	std::cout << stoi("ABCD121", 0, 16) << '\n';
}

