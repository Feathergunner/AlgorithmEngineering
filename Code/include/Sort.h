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
	static void quicksort_vec_subroutine(vector<T> *data, int beg, int end);
	template<typename T>
	static void quicksort_list_subroutine(list<T> *data, typename list<T>::iterator beg, typename list<T>::iterator end);
	template<typename T>
	static void mergesort_subroutine(vector<T> *data, int beg, int end);

public:
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
};


#endif
