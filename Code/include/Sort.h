#ifndef Sort_h
#define Sort_h

#include <list>
#include <iterator>

using namespace std;

//class to collect sorting Algorithms
class Sort
{
public:
	static list<int> insertionsort(list<int> data);
	static list<int> quicksort_rec(list<int> data);
	//static list<int> mergesort(list<int>);
};

#endif
