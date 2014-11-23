#include "../include/Sort.h"

using namespace std;

//simple sorting algorithm in O(n^2)
// needs only constant additional space
list<int> Sort::insertionsort(list<int> data)
{
	if (data.size() < 2) return data;
	bool found;
	// iterate through all elements:
	list<int>::iterator it=data.begin();
	while (it != data.end())
	{
		if (it == data.begin()) it++;
		found = false;
		// insert the new element at the correct position between begin() and it
		for (list<int>::iterator it2 = data.begin(); it2!=it && !found; it2++)
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

// quicksort algorithm with worst-case running time in O(n^2), better on average
// recursive implementation, needs nlogn space
list<int> Sort::quicksort_rec(list<int> data)
{	
	//divide list by pivot-element
	// make sure both partitions are not empty:
	// look at the first two _different_ elements in data, choose the greater one as pivot
	// all elements smaller than p into first partition => at least one
	// all elements equal or greater than p into second partition => at least one
	int p = *(data.begin());
	list<int>::iterator it=data.begin();
	while (*it == p && it != data.end()) it++;
	// if the end is reached, all elements are the same => no sorting necessary => return list
	if (it == data.end())
		return data;
	// else divide list into two non-empty partitions as described above:
	if (*it > p) p = *it;
	list<int> first, second;
	for (list<int>::iterator it=data.begin(); it!=data.end(); it++)
	{
		if (*it<p)
			first.push_back(*it);
		else
			second.push_back(*it);
	}
	
	// recursion: sort 'first' and 'second'
	list<int> f_s = quicksort_rec(first);
	list<int> s_s = quicksort_rec(second);
	
	// merge, i.e. insert 'first' at the beginning of 'second'
	s_s.insert(s_s.begin(),f_s.begin(),f_s.end());
	
	return s_s;
}

