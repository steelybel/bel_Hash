//hash.h
#pragma once
#include <limits>

// template declaration for hash
template<typename T>
size_t hash(const T& val)
{
	// unelegant way of telling users to specialize this template
	T::please_specialize_this_template_for_your_type;
}

// template specialization for int
template<>
size_t hash<int>(const int& val)
{
	// Knuth's hash function
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}

// template specialization for char
template<>
size_t hash<char>(const char& val)
{
	return (int)val * 2654435761 % std::numeric_limits<size_t>::max();
}

template<typename K, typename V>
class tHashmap
{
	V * data;                       // buffer holding all potential pairs in the hashmap
	size_t dataCapacity;            // size of the above buffers

public:
	tHashmap();                     // constructs the hashmap with a specific size
	~tHashmap();                    // cleans-up any underlying data

	V& operator[] (const K& key);   // returns the object at the given key
};