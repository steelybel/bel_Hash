//hash.h
#pragma once
#include <limits>
#include <string>

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

// template specialization for c-strings (ew ew ew ew ew ew ew ew ew ew ew ewwwwwwWWWWWWWWWWWWWWWW)
template<>
size_t hash<char*>(char * const& val)
{
	int sum = 0;
	int temp = 0;
	while (val[temp] != '\0')
	{
		sum += val[temp];
	}
	return (int)sum * 2654435761 % std::numeric_limits<size_t>::max();
}

// template specialization for strings (the normal people kind)
template<>
size_t hash<std::string>(const std::string& val)
{
	int sum = 0;
		for (int i = 0; i < val.length(); ++i)
		{
			sum += val[i];
		}
		return (int)sum * 2654435761 % std::numeric_limits<size_t>::max();
}

template<typename K, typename V>
class tHashmap
{
	V * data;                       // buffer holding all potential pairs in the hashmap
	size_t dataCapacity;            // size of the above buffers

public:
	tHashmap();                     // constructs the hashmap with a specific size
	tHashmap(size_t size);                     // constructs the hashmap with a specific size
	~tHashmap();                    // cleans-up any underlying data
	tHashmap(const tHashmap&);		//copy constructor :O
	tHashmap operator= (const tHashmap&);		//copy OPERATOR>???? :OO
	V& operator[] (const K& key);   // returns the object at the given key
};

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap()
{
	dataCapacity = 10;
	data = new V[dataCapacity];
}

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap(size_t size)
{
	dataCapacity = 10;
	data = new V[dataCapacity];
}

template<typename K, typename V>
inline tHashmap<K, V>::~tHashmap()
{
	delete(data);
}

template<typename K, typename V>
inline tHashmap<K, V>::tHashmap(const tHashmap & other)
{
	data = new V[other.dataCapacity];
	dataCapacity = other.dataCapacity;
	for (int i = 0; i < other.dataCapacity; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename K, typename V>
inline tHashmap<K, V> tHashmap<K, V>::operator=(const tHashmap & other)
{
	return (new tHashmap(other));
}

template<typename K, typename V>
inline V & tHashmap<K, V>::operator[](const K & key)
{
	auto hashed = hash(key) % dataCapacity;
	return data[hashed];
}
