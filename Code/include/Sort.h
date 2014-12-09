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
	// general:
	template<typename T>
	static void swap(vector<T> *data, int i1, int i2)
	{
		T tmp = (*data)[i1];
		(*data)[i1] = (*data)[i2];
		(*data)[i2] = tmp;
	}
	template<typename T>
	static T get_pivot(vector<T> *data, int beg, int end)
	{
		// returns pivot element as medium of the three values
		// from begin, middle and end of array
		T p1 = (*data)[beg];
		T p2 = (*data)[beg+ (end-beg)/2];
		T p3 = (*data)[end-1];
	
		//get medium of p1, p2, p3:
		if (p1>p2)
		{
			if (p2>p3)
				return p2;
			else if (p1>p3)
				return p3;
			else
				return p1;
		}else{
			if (p1>p3)
				return p1;
			else if (p2>p3)
				return p3;
			else
				return p2;
		}
	}

	// for quicksort_vec:
	template<typename T>
	static void quicksort_vec_subroutine(vector<T> *data, int beg, int end);
	template<typename T>
	static void quicksort_vec_partition(vector<T> *data, int beg, int end);
	
	// for quicksort_list:
	template<typename T>
	static void quicksort_list_subroutine(list<T> *data, typename list<T>::iterator beg, typename list<T>::iterator end);
	
	// for mergesort:
	template<typename T>
	static void mergesort_subroutine(vector<T> *data, int beg, int end, vector<T> *tmp);
	
	// for insertionsort:
	template<typename T>
	static void insertionsort_vec_subroutine(vector<T> *data, int beg, int end);

public:
	// fixed size of testlists and -vectors:	
	static const int size_of_testarrays = 1000;

	// implementations with lists:
	template<typename T>
	static list<T> insertionsort_list(list<T> data);
	template<typename T>
	static list<T> quicksort_list(list<T> data);
	
	// implementations with vectors:
	template<typename T>
	static void insertionsort_vec(vector<T> *data);
	template<typename T>
	static void quicksort_vec(vector<T> *data);
	template<typename T>
	static void mergesort(vector<T> *data);
	
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

//--------------------------------------------------------------------------------------
// Implementations of template-functions
//--------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------
//implementations with lists
//--------------------------------------------------------------------------------------

// Insertionsort
// simple sorting algorithm

// worst case in O(n^2)
// average case in O(n^2)
// best case in O(n)
// needs only constant additional space
template<typename T>
list<T> Sort::insertionsort_list(list<T> data)
{
	if (data.size() < 2) return data;
	bool found;
	// iterate through all elements:
	typename list<T>::iterator it=data.begin();
	while (it != data.end())
	{
		if (it == data.begin()) it++;
		found = false;
		// insert the new element at the correct position between begin() and it
		for (typename list<T>::iterator it2 = data.begin(); it2!=it && !found; it2++)
		{
			// if a value *it2 in the current sorted part of the list is greater than the current value *it
			// insert the current value in front of it2
			// note that this enforces a stable sort, since all "older" equal values will be passed bevor *it is inserted
			if (*it2>*it)
			{
				found = true;
				data.insert(it2, *it);
				it++;
				data.erase(prev(it));
			}
			// if no such position is found, it is greater than all preceding elements
			// and thus stayes at its current position
		}
		if (!found)it++;
	}
	return data;
}

// quicksort algorithm 

// worst-case running time in O(n^2)
// average running time in O(nlogn)
// best case in O(nlogn)
// needs linear additional space

// NOT in-place-implementation, did not improve this one (I focused on vector-implementations)
template<typename T>
list<T> Sort::quicksort_list(list<T> data)
{	
	quicksort_list_subroutine(&data, data.begin(), data.end());
	return data;
}

template<typename T>
void Sort::quicksort_list_subroutine (list<T> *data, typename list<T>::iterator beg, typename list<T>::iterator end)
{
	//divide list by pivot-element
	// make sure both partitions are not empty:
	// look at the first two _different_ elements in data, choose the greater one as pivot
	// all elements smaller than p into first partition => at least one
	// all elements equal or greater than p into second partition => at least one
	T p = *beg;
	typename list<T>::iterator it=beg;
	while (*it == p && it != end) it++;
	// if the end is reached, all elements are the same => no sorting necessary => return list
	if (it == end)
		return;
		
	// else divide list into two non-empty partitions as described above:
	// choose pivot-element as described above:
	if (*it > p) p = *it;
	
	//mid: iterator that points to first element of second partition
	typename list<T>::iterator mid = end;
	for (typename list<T>::iterator it=beg; it!=mid; it++)
	{
		if (*it>=p)
		{
			// current element is >= pivot-element
			// move element to second partition i.e. to the back of the current interval
			(*data).insert(end, *it);
			if (mid==end)
				mid--;
			// erase old position of element:
			// if it == beg, reassign beg:
			if (it == beg)
				beg++;
			// if it = begin(), reassign it:
			if (it == (*data).begin())
			{
				(*data).erase(it);
				it = (*data).begin();
			}else{
				typename list<T>::iterator tmp = it;
				(*data).erase(tmp);
			}
			//decrease iterator because the current pointed-at-element has not yet been visited
			it--;
		}
		// else leave element in first partition: do nothing
	}
	
	// recursion: sort both partitions:
	quicksort_list_subroutine(data, beg, mid);
	quicksort_list_subroutine(data, mid, end);
	
	return;
}

//--------------------------------------------------------------------------------------
//implementations with vectors
//--------------------------------------------------------------------------------------

// insertion sort: simple sorting algorithm

// worst case in O(n^2)
// average case in O(n^2)
// best case in O(n)

// in-place sorting, the original vector will be altered
// needs only constant additional space
template<typename T>
void Sort::insertionsort_vec(vector<T> *data)
{
	Sort::insertionsort_vec_subroutine(data, 0, (*data).size());
	return;
}

template<typename T>
void Sort::insertionsort_vec_subroutine(vector<T> *data, int beg, int end)
{
	if (end-beg < 2)
		return;
	
	// flag to note if a correct insertion-position is found:
	bool found;
	// iterate through all elements:
	for (int i=beg; i<end; i++){
		int j=i-1;
		// start with last element of all currently visited elements,
		// search backwards until a smaller or equal element is found
		found = false;
		while (!found && j>=beg){
			// elment is greater:
			if ((*data)[j]>(*data)[j+1]){
				// swap elements:
				swap (data, j, j+1);
				// search further:
				j--;
			}else{
				//break
				found = true;
			}
		}
	}
	return;
}

// quicksort

// for big inputs: (>>100)
// running time worst case in O(n^2)
// average case in O(n logn)
// best case in O(n log n) 
// for smaller inputs:
// best case in O(n)

// in place-sorting, the originial vector will be altered
// needs only constant additional space
template<typename T>
void Sort::quicksort_vec(vector<T> *data)
{	
	Sort::quicksort_vec_subroutine(data,0,(*data).size());
	return;
}

template<typename T>
void Sort::quicksort_vec_subroutine(vector<T> *data, int beg, int end)
{
	if (end-beg <= 1)
		//nothing to do
		return;

	// short case: do faster insertionSort
	//if (end-beg < 100)
	if (end-beg < 100)
	{
		Sort::insertionsort_vec_subroutine(data,beg,end);
		return;
	}

	// divide part of vector by pivot-element

	// get pivot-element:
	T p = get_pivot(data, beg, end);
	
	// the *_target iterator will point to the first element NOT BELONGING to the partition
	// the *_search iterator will point to the first element belonging to THE OTHER partition
	// this difference is needed to realize fat-partitioning
	
	// iterator for first partition (from beginning of array):
	int it_beg_search = beg;
	int it_beg_target = beg;
	// iterator for second partition (backwards, from end of array)
	int it_end_search = end-1;
	int it_end_target = end-1;
	
	while (it_beg_search < it_end_search)
	{
		// find the smallest index with data >=p
		while ((*data)[it_beg_target] < p)
			it_beg_target++;
		
		// now find the smallest index with data >p
		it_beg_search = it_beg_target;
		while ((*data)[it_beg_search] <= p && it_beg_search < (end-1))
			it_beg_search++;
		
		// same procedure for elements > p, starting from end of data:
		// find the biggest index with data <=p
		while ((*data)[it_end_target] > p)
			it_end_target--;
			
		// now find the biggest index with data <p
		it_end_search = it_end_target;
		while ((*data)[it_end_search] >= p && it_end_search > beg)
			it_end_search--;
		
		// if both search-iterators went through whole set
		// => sorted => return
		if (it_beg_search == end-1 && it_end_search == beg)
			return;
			
		// if beg_search >= end_target or end_search <= beg_target
		// => first >p-element from beginning is in second partition
		// 		& first <p-element from end is in first partition
		// => array is correctly partitioned
		
		// else: swap elements:
		if (it_beg_target < it_end_target)
		{
			// if either beg_search > end_target or end_search < beg_target
			// => between both targets are only elements <= p
			//		or only elements >= p, respectivly
			// => swap beg_target and end_target and bring all p-elements to correct side
			if (it_beg_search >= it_end_target)
			{
				swap (data, it_beg_target, it_end_target);
				// bring all p-elements to upper side of subarray beg_target,end_target
				int i1 = it_end_target;
				while ((*data)[i1] == p)
					i1--;
				// i1 points to highest non-p-element
				if (i1 > it_beg_target)
				{
					for (int i2=i1-1; i2>=it_beg_target; i2--)
					{
						if ((*data)[i2] == p)
						{
							swap(data,i1,i2);
							i1--;
						}
					}
				}
				it_beg_target = i1; 
			}
			else if (it_end_search <= it_beg_target)
			{
				swap (data, it_beg_target, it_end_target);
				// bring all p-elements to lower side of subarray beg_target,end_target
				int i1 = it_beg_target;
				while ((*data)[i1] == p)
					i1++;
				// i1 points to lowest non-p-element
				if (i1 < it_end_target)
				{
					for (int i2=i1+1; i2<=it_end_target; i2++)
					{
						if ((*data)[i2] == p)
						{
							swap(data,i1,i2);
							i1++;
						}
					}
				}
				it_end_target = i1;
			}
			else
			{			
				// if not equal, swap data from beg_search and beg_target
				// => p-element swapped towards middle of array
				if (it_beg_search != it_beg_target)
					swap (data, it_beg_search, it_beg_target);
			
				// if not equal, swap data from end_search and end_target
				// => p-element swapped towards middle of array
				if (it_end_search != it_end_target)
					swap (data, it_end_search, it_end_target);
		
				// now elements at beg_target and end_target are non-p-elements.
				// and data[beg_target] > p > data[end_target]
				// swap them!
				
				swap (data, it_beg_target, it_end_target);
			
				// update iterators so they point to the next unvisited elements:
				it_beg_search = it_beg_target++;
				it_end_search = it_end_target--;
			}
		}
		
	}
	
	// now all elements <p at beginning of array
	// all elements >p at end of array
	// all elements =p between these two partitions
	
	while ((*data)[it_beg_target] >= p) it_beg_target--;
	while ((*data)[it_end_target] <= p) it_end_target++;
		
	// start partition for interval [beg,beg+i_beg)
	Sort::quicksort_vec_subroutine(data, beg, it_beg_target+1);
	
	//start partition for interval [end-i_end,end)
	Sort::quicksort_vec_subroutine(data, it_end_target, end);
	
	return;
}

// mergesort

// in \Theta(n log n) time
// and linear memory, because the algorithm only needs additional memory during merge which is pre-allocated
template<typename T>
void Sort::mergesort(vector<T> *data)
{
	//preallocate memory needed for merge, so it has to be done only once:
	vector<T> tmp = vector<T>((*data).size());
	
	Sort::mergesort_subroutine(data, 0, (*data).size(), &tmp);
	return;
}

template<typename T>
void Sort::mergesort_subroutine(vector<T> *data, int beg, int end, vector<T> *tmp)
{
	// trivial case:
	if (end-beg < 2)
		return;


	// short case: do faster insertionSort
	if (end-beg < 130)
	{
		Sort::insertionsort_vec_subroutine(data,beg,end);
		return;
	}


	// divide:
	int mid = beg+((end-beg)/2);
	mergesort_subroutine(data, beg, mid, tmp);
	mergesort_subroutine(data, mid, end, tmp);
	
	// conquer (merge):
	vector<T> t = vector<T>(end-beg);
	int i1=beg;
	int i2=mid;
	for (int i=0; i<end-beg; i++)
	{
		if (i1<mid && i2<end)
		{
			// insert the smaller element from both partitions at current position:
			if ((*data)[i1] <= (*data)[i2])
				(*tmp)[i] = (*data)[i1++];
			else
				(*tmp)[i] = (*data)[i2++];
		}else
		{
			// one partition is completely integrated: add rest of other partition
			if (i1==mid)
				(*tmp)[i] = (*data)[i2++];
			else // i.e. i2==end
				(*tmp)[i] = (*data)[i1++];
		}
	}
	
	// write t back to data:
	for (int i=0; i<end-beg; i++)
		(*data)[beg+i] = (*tmp)[i];
	
	return;
}

#endif
