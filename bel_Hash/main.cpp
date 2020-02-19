#include <stdlib.h>
#include <iostream>
#include <string>
#include "hash.h"
int main()
{
	int useless = 0;
	std::string input = "";
	std::cin >> input;
	std::cout << (hash<std::string>(input)) << std::endl;
	std::cin >> useless;
	return 0;
}