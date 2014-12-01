#ifndef Sort_h
#define Sort_h

#include <stdlib.h>
#include <algorithm>		// std::random_shuffle
#include <iostream>

#include <vector>
#include <list>
#include <iterator>

using namespace std;

// class to organize sorting Algorithms
class Sort
{
private:
	void instantiate();
	template<typename T>
	static void quicksort_vec_subroutine(vector<T> *data, int beg, int end);
	template<typename T>
	static void quicksort_list_subroutine(list<T> *data, typename list<T>::iterator beg, typename list<T>::iterator end);
	template<typename T>
	static void mergesort_subroutine(vector<T> *data, int beg, int end, vector<T> *tmp);

public:
	// fixed size of testlists and -vectors:	
	static const int size_of_testarrays = 5000;
	
	/*
	Sort(int size = 5000)
	{
		size_of_testarrays = size;
	}
	*/

	template<typename T>
	static list<T> insertionsort_list(list<T> data);
	template<typename T>
	static list<T> quicksort_list(list<T> data);
	
	template<typename T>
	static vector<T> insertionsort_vec(vector<T> data);
	template<typename T>
	static vector<T> quicksort_vec(vector<T> data);
	template<typename T>
	static vector<T> mergesort(vector<T> data);
	
	// methods to construct lists/vectors
	// for testing and measuring

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
	
	// methods that creates lists with entries appearing multiple times
	static list<int> create_multilist(int size);
	static vector<int> create_multivector(int size);

	// method to test if list or vector is sorted
	// needs input-iterator at begin of container
	// and size of container to be tested
	template<typename InputIterator>
	static bool issorted(InputIterator it, int size)
	{
		for (int i=0; i<size-1; i++)
		{
			InputIterator it2 = it;
			InputIterator it2p = ++it;
			if (*it2 > *it2p) return false;
		}
		return true;
	}

	// for debugging purpose: prints elements of container
	// needs input-iterator as start and number of elements to print
	template<typename InputIterator>
	static void print(InputIterator it, int size)
	{
		for (int i=0; i<size-1; i++)
			cout << *it++ << " ";
		cout << "\n";
		return;
	}
};

#endif
