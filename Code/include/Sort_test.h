#ifndef SortLists_h
#define SortLists_h

#include <gtest/gtest.h>
#include <stdlib.h>
#include <algorithm>		// std::random_shuffle
#include <iostream>

#include <list>
#include <iterator>
#include <vector>
#include <Sort.h>

using namespace std;

// class to test and measure implementations of sorting algorithms
class Sort_test
{
public:
	static const int size_of_testarrays = 1000;

	// method that creates a list of pseudorandom numbers
	static list<int> create_randomlist(int size, int init);
	static vector<int> create_randomvector(int size, int init);
	
	// method that creates an ordered list
	static list<int> create_orderedlist(int size);
	static vector<int> create_orderedvector(int size);
	
	// method that creates a reverse ordered list
	static list<int> create_revorderedlist(int size);
	static vector<int> create_revorderedvector(int size);
	
	// method that creates a list of permuted numbers
	static list<int> create_permutedlist(int size);
	static vector<int> create_permutedvector(int size);

	//method that tests if list/vector is sorted
	template<typename InputIterator>
	static bool issorted(InputIterator begin, int size);
	
	//method that prints data of list/vector
	template<typename InputIterator>
	static void print(InputIterator begin, int size);
	
	int main();
};

#endif
