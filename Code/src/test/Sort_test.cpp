#include <gtest/gtest.h>
#include <stdlib.h>
#include <list>

#include "../../include/Sort.h"
#include "../../include/SortLists.h"

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


TEST(InsertionSortTest, Test_Deterministic_Cases){
	SortLists sl;
	for (int i=0; i<sl.numoftestcases; i++)
	{
		EXPECT_TRUE(sl.issorted(Sort::insertionsort(sl.testlists[i])));
	}
	
}

TEST(InsertionSortTest, Test_Random_Cases){
	SortLists sl;
	EXPECT_TRUE(sl.issorted(Sort::insertionsort(sl.create_randomlist(10000,0))));
}

TEST(QuickSortTest, Test_Deterministic_Cases){
	SortLists sl;
	for (int i=0; i<sl.numoftestcases; i++)
	{
		EXPECT_TRUE(sl.issorted(Sort::quicksort_rec(sl.med_testlists[i])));
	}
}

TEST(QuickSortTest, Test_Random_Cases){
	SortLists sl;
	EXPECT_TRUE(sl.issorted(Sort::quicksort_rec(sl.create_randomlist(10000,0))));
	EXPECT_TRUE(sl.issorted(Sort::quicksort_rec(sl.create_randomlist(100000,0))));
}


