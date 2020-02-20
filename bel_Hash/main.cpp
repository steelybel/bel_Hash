#include <stdlib.h>
#include <iostream>
#include <string>
#include "hash.h"
int main()
{
	std::string input = "";
	std::cout << "Type in a word to convert it to a hash >";
	std::cin >> input;
	std::cout << input << " = " << (hash<std::string>(input)) << std::endl;
	std::cin.ignore();

	//initialize hashmap
	tHashmap<std::string, int> favoriteNumbersByName;
	//put value into said hashmap
	favoriteNumbersByName["Bel"] = -4;

	//copying that first hashmap, meaning all the values will be carried over
	tHashmap<std::string, int> favoriteNumbersByEvil = favoriteNumbersByName;

	//prints the value of bel's favorite number from the original hashmap AND the new one!
	std::cout << "my faaavorite number is... " << favoriteNumbersByName["Bel"] << "!!! huzzah!!!" <<std::endl;
	std::cout << "yeah? well I'M evil and I like... " << favoriteNumbersByEvil["Bel"] << "." << std::endl;
	std::cin.ignore();
	return 0;
}