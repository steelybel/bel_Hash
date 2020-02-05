#include <stdlib.h>
#include <iostream>
#include <string>
#include "hash.h"
int main()
{
	tHashmap<std::string, int> favoriteNumbersByName;
	favoriteNumbersByName["Terry"] = 5;

	std::cout << favoriteNumbersByName["Terry"] << std::endl; // 5
	return 0;
}