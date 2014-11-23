#ifndef SortLists_h
#define SortLists_h

#include <list>
#include <iterator>
#include <vector>

using namespace std;

// class to organise hard-coded arrays and lists to test implementations of sorting algorithms
class SortLists
{
public:
	static const int numoftestcases = 4;
	
	//hardcoded arrays:
	int test[numoftestcases][10000];
	int medtest[numoftestcases][1000];
	int smalltest[numoftestcases][100];

	//init arrays and lists:
	SortLists();
	
	//vector of lists:
	vector<list<int> > testlists;
	vector<list<int> > med_testlists;
	vector<list<int> > small_testlists;
	
	// method that creates a list of pseudorandom numbers
	list<int> create_randomlist(int size, int init);

	//method that tests if list is sorted
	bool issorted(list<int> data);
};

#endif
