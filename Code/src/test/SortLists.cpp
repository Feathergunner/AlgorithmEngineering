#include "../../include/SortLists.h"

SortLists::SortLists()
{
	//test[0]:
	// the sorted array: 0,1,2,...,9999
	for (int i=0; i<10000; i++){
		test[0][i]=i;
	}
	
	//test[1]:
	// the reverse sorted array: 9999,9998,...,1,0
	for (int i=0; i<10000; i++){
		test[1][i]=9999-i;
	}
	
	//test[2]:
	//0,100,200,...,9900,1,101,201,...,9901,2,...,3,...,99,199,...,9999
	for (int i=0; i<100; i++){
		for (int j=0; j<100;j++){
			test[2][i*100+j]=j*100+i;
		}
	}
	
	// test[3]:
	for (int i=0; i<10000; i++){
		test[3][i]= (i*i)%1000;
	}
	
	//medtest
		for (int i=0; i<1000; i++){
		medtest[0][i]=i;
		medtest[1][i]=999-i;
	}
	
	for (int i=0; i<10; i++){
		for (int j=0; j<100; j++){
			medtest[2][i*100+j]=j*10+i;
		}
	}
	
	for (int i=0; i<1000; i++){
		medtest[3][i] = (i*i)%100;
	}
	
	// smalltest, analog to test
	for (int i=0; i<100; i++){
		smalltest[0][i]=i;
		smalltest[1][i]=99-i;
	}
	
	for (int i=0; i<10; i++){
		for (int j=0; j<10; j++){
			smalltest[2][i*10+j]=j*10+i;
		}
	}
	
	for (int i=0; i<100; i++){
		smalltest[3][i] = (i*i)%20;
	}
	
	//init lists:
	testlists = vector<list<int> >(numoftestcases,list<int>());
	for (int i=0; i<numoftestcases; i++)
		testlists[i] = list<int>(test[i], test[i] + 10000);
		
	small_testlists = vector<list<int> >(numoftestcases,list<int>());
	for (int i=0; i<numoftestcases; i++)
		small_testlists[i] = list<int>(smalltest[i], smalltest[i] + 100);
		
	med_testlists = vector<list<int> >(numoftestcases,list<int>());
	for (int i=0; i<numoftestcases; i++)
		med_testlists[i] = list<int>(medtest[i], medtest[i] + 1000);
}

list<int> SortLists::create_randomlist(int size, int init){
	list<int> randlist;
	// initialize with constant: 'randomlist' is pseudo-random, ca be recreated
	srand(init);
	for (int i=0; i<size; i++){
		randlist.push_back(rand()%1000);
	}
	return randlist;
}


bool SortLists::issorted(list<int> data)
{
	//iterate through list and check for each number that the next number is not smaller
	list<int>::iterator it=data.begin();
	while(next(it)!=data.end())
		if (*it>*(it++)) return false;
	return true;
}



