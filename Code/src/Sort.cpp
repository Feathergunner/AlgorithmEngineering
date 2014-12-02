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
// in-place-implementation (the original list will be altered), needs only constant additional space
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

// insertion sort: simple sorting algorithm in O(n^2)
// in-place sorting, the original vector will be altered
// needs only constant additional space
template<typename T>
vector<T> Sort::insertionsort_vec(vector<T> data)
{
	int size = data.size();
	if (size < 2) return data;
	
	// flag to note if a correct insertion-position is found:
	bool found;
	// iterate through all elements:
	for (int i=1; i<size; i++){
		int j=i-1;
		// start with last element of all currently visited elements,
		// search backwards until a smaller or equal element is found
		found = false;
		while (!found && j>=0){
			// elment is greater:
			if (data[j]>data[j+1]){
				// swap elements:
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

//another version of insertionsort that gets pointer to vector and sorts elements between indices beg and end
// to use for small cases in quicksort and mergesort
template<typename T>
void Sort::insertionsort_vec_quick(vector<T> *data, int beg, int end)
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
				T tmp = (*data)[j];
				(*data)[j] = (*data)[j+1];
				(*data)[j+1] = tmp;
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

// recursive quicksort
// in place-sorting, the originial vector will be altered
// running time as above (the list-quicksort) worst case O(n^2), better on average
// but only constant memory, only needs additional memory during partitioning
template<typename T>
vector<T> Sort::quicksort_vec(vector<T> data)
{
	Sort::quicksort_vec_subroutine(&data,0,data.size());
	return data;
}

template<typename T>
void Sort::quicksort_vec_subroutine(vector<T> *data, int beg, int end)
{
	if (end-beg == 1)
		//nothing to do
		return;

	// short case: do faster insertionSort
	if (end-beg < 130)
	{
		Sort::insertionsort_vec_quick(data,beg,end);
		return;
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
	Sort::quicksort_vec_subroutine(data, beg, beg+i_beg);
	
	//start partition for interval [beg+i_beg,end)
	Sort::quicksort_vec_subroutine(data, beg+i_beg, end);
	
	return;
}

// mergesort
// in \Theta(n log n) time
// and linear memory, because the algorithm only needs additional memory during merge
template<typename T>
vector<T> Sort::mergesort(vector<T> data)
{
	//preallocate memory needed for merge, so it has to be done only once:
	vector<T> tmp = vector<T>(data.size());
	
	Sort::mergesort_subroutine(&data, 0, data.size(), &tmp);
	return data;
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
		Sort::insertionsort_vec_quick(data,beg,end);
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

using namespace std;

//--------------------------------------------------------------------------------
// create lists
//--------------------------------------------------------------------------------

list<int> Sort::create_randomlist(int size, int init){
	list<int> randlist;
	// initialize with constant: 'randomlist' is pseudo-random, ca be recreated
	srand(init);
	for (int i=0; i<size; i++){
		randlist.push_back(rand()%1000);
	}
	return randlist;
}

list<int> Sort::create_permutedlist(int size){
	// note that random.shuffle() needs random-access-iterators => not possible for lists
	// create permuted vector:
	vector<int> pv = create_permutedvector(size);
	// create list from vector:
	list<int> plist(pv.begin(), pv.end());
	return plist;
}

list<int> Sort::create_orderedlist(int size){
	list<int> olist;
	for(int i=0; i<size; i++){
		olist.push_back(i);
	}
	return olist;
}

list<int> Sort::create_revorderedlist(int size){
	list<int> rlist;
	for(int i=0; i<size; i++){
		rlist.push_front(i);
	}
	return rlist;
}

list<int> Sort::create_multilist(int size){
	list<int> rlist;
	for (int i=0; i<size; i++){
		if (i<100)
			rlist.push_front((i*i)%10);
		else
			rlist.push_front((i*i)%100);
	}
	return rlist;
}

//--------------------------------------------------------------------------------
// create vectors
//--------------------------------------------------------------------------------

vector<int> Sort::create_randomvector(int size, int init)
{
	vector<int> rvector(size,0);
	srand(init);
	for (int i=0; i<size; i++)
		rvector[i] = rand()%100000;
	return rvector;
}

vector<int> Sort::create_orderedvector(int size)
{
	vector<int> ovector(size,0);
	for (int i=0; i<size; i++)
		ovector[i] = i;
	return ovector;
}

vector<int> Sort::create_revorderedvector(int size)
{
	vector<int> rvector(size,0);
	for (int i=0; i<size; i++)
		rvector[i] = size-i;
	return rvector;
}

vector<int> Sort::create_permutedvector(int size)
{
	// create ordered vector:
	vector<int> pvector = create_orderedvector(size);
	// shuffle vector:
	random_shuffle(pvector.begin(), pvector.end());
	return pvector;
}

vector<int> Sort::create_multivector(int size)
{
	vector<int> rvector(size, 0);
	srand(0);
	for (int i=0; i<size; i++)
		rvector[i] = rand()%(size/10);
	return rvector;
}

// pre-instantiate templates:
void Sort::instantiate()
{
	list<int> tl;
	Sort::quicksort_list(tl);
	Sort::insertionsort_list(tl);
	vector<int> tv = vector<int> (1,1);
	Sort::quicksort_vec(tv);
	Sort::insertionsort_vec(tv);
	Sort::mergesort(tv);
	return;
}
