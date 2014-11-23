#include <list>
#include <iterator>
#include <iostream>

#include "include/Sort.h"

int main()
{
	//simpel first test:
	
	//create list of nonsorted numbers:
	std::list<int> test;
	for (int i=0; i<40; i++)
		test.push_front((i*i)%30);
		
	//print to console:
	cout << "before:\n";
	for (std::list<int>::iterator it=test.begin(); it!=test.end(); it++)
		cout << *it << "\n";
	
	//sort:
	std::list<int> s_test = Sort::quicksort_rec(test);
	
	//print sorted to console:
	cout << "after:\n";
	for (std::list<int>::iterator it=s_test.begin(); it!=s_test.end(); it++)
		cout << *it << "\n";
		
	// end
	return 0;
}
