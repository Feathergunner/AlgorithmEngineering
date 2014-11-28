#ifndef Sort_h
#define Sort_h

#include <vector>
#include <list>
#include <iterator>

using namespace std;

//class to collect sorting Algorithms
class Sort
{
private:
	void instantiate();
	template<typename T>
	static void quicksort_rec_vec_subroutine(vector<T> *data, int beg, int end);

public:
	template<typename T>
	static list<T> insertionsort_list(list<T> data);
	template<typename T>
	static list<T> quicksort_rec(list<T> data);
	
	template<typename T>
	static vector<T> insertionsort(vector<T> data);
	template<typename T>
	static vector<T> quicksort_rec(vector<T> data);
	//static list<int> mergesort(list<int>);
};


#endif
