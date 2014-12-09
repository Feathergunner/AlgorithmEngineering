#include <Sort.h>

#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------
// for testing and measuring: create lists
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
