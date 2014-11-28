#include <Sort.h>

#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------
//implementations with lists
//--------------------------------------------------------------------------------------

//simple sorting algorithm in O(n^2)
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

// quicksort algorithm with worst-case running time in O(n^2), better on average
// recursive implementation, needs nlogn space
template<typename T>
list<T> Sort::quicksort_rec(list<T> data)
{	
	//divide list by pivot-element
	// make sure both partitions are not empty:
	// look at the first two _different_ elements in data, choose the greater one as pivot
	// all elements smaller than p into first partition => at least one
	// all elements equal or greater than p into second partition => at least one
	T p = *(data.begin());
	typename list<T>::iterator it=data.begin();
	while (*it == p && it != data.end()) it++;
	// if the end is reached, all elements are the same => no sorting necessary => return list
	if (it == data.end())
		return data;
	// else divide list into two non-empty partitions as described above:
	if (*it > p) p = *it;
	list<T> first, second;
	for (typename list<T>::iterator it=data.begin(); it!=data.end(); it++)
	{
		if (*it<p)
			first.push_back(*it);
		else
			second.push_back(*it);
	}
	
	// recursion: sort 'first' and 'second'
	list<T> f_s = quicksort_rec(first);
	list<T> s_s = quicksort_rec(second);
	
	// merge, i.e. insert 'first' at the beginning of 'second'
	s_s.insert(s_s.begin(),f_s.begin(),f_s.end());
	
	return s_s;
}

//--------------------------------------------------------------------------------------
//implementations with vectors
//--------------------------------------------------------------------------------------

// insertion sort: simple sorting algorithm in O(n^2)
// in-place sorting, the original vector will be altered
// needs only constant additional space
template<typename T>
vector<T> Sort::insertionsort(vector<T> data)
{
	int size = data.size();
	if (size < 2) return data;
	bool found;
	
	// iterate through all elements:
	for (int i=1; i<size; i++){
		int j=i-1;
		// search backwards until a smaller or equal element is found
		found = false;
		while (!found && j>=0){
			// elment is greater:
			if (data[j]>data[j+1]){
				T tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
				// search further:
				j--;
			}else{
				//break
				found = true;
			}
		}
	}
	return data;
}

// recursive quicksort
// in place-sorting
template<typename T>
vector<T> Sort::quicksort_rec(vector<T> data)
{
	Sort::quicksort_rec_vec_subroutine(&data,0,data.size());
	return data;
}

template<typename T>
void Sort::quicksort_rec_vec_subroutine(vector<T> *data, int beg, int end)
{
	if (end-beg == 1)
		//nothing to do
		return;
	if (end-beg == 2)
	{
		// check if two elements are in correct order
		if ((*data)[beg] <= (*data)[beg+1])
			// in correct order: nothing to do
			return;
		else
		{
			// else: swap elements:
			T tmp = (*data)[beg];
			(*data)[beg] = (*data)[beg+1];
			(*data)[beg+1] = tmp;
			return;
		}
	}
	
	//divide part of vector by pivot-element
	// make sure both partitions are not empty:
	// look at the first two _different_ elements in data, choose the greater one as pivot
	// all elements smaller than p into first partition => at least one
	int i = beg+1;
	T p = (*data)[beg];
	//iterate through data until two different elements are found
	while (p == (*data)[i] && i<end)
		i++;
	if (i == end)
		// all elements are equal: data is sorted between beg and end
		// nothing to be done
		return;
	// else: pivot element is found
	if ((*data)[i] > p) p = (*data)[i];
	// "sort" elements into partitions as described above:
	vector<T> tmp = vector<T>(end-beg);
	int i_beg = 0;
	int i_end = 1;
	for (int j=beg; j<end; j++)
	{
		if ((*data)[j]<p)
		{
			//insert element from front:
			tmp[i_beg]=(*data)[j];
			i_beg++;
		}else{
			//insert element from back:
			tmp[end-beg-i_end]=(*data)[j];
			i_end++;
		}
	}
	//write tmp back into data
	for (int i=0; i<(end-beg); i++)
	{
		(*data)[beg+i] = tmp[i];
	}
	
	// start partition for interval [beg,beg+i_beg)
	Sort::quicksort_rec_vec_subroutine(data, beg, beg+i_beg);
	
	//start partition for interval [beg+i_beg,end)
	Sort::quicksort_rec_vec_subroutine(data, beg+i_beg, end);
	
	return;
}

// pre-instantiate templates:
void Sort::instantiate()
{
	list<int> tl;
	Sort::quicksort_rec(tl);
	Sort::insertionsort_list(tl);
	vector<int> tv = vector<int> (4,1);
	Sort::quicksort_rec(tv);
	Sort::insertionsort(tv);
	return;
}
