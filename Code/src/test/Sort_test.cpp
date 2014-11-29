#include <Sort_test.h>

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

//--------------------------------------------------------------------------------
// TESTS
//--------------------------------------------------------------------------------

TEST(InsertionSort_list, TestRandom)
{
	// create list:
	list<int> test = Sort::create_randomlist(Sort::size_of_testarrays, 10);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(InsertionSort_list, TestOrdered)
{
	// create list:
	list<int> test = Sort::create_orderedlist(Sort::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(InsertionSort_list, TestRevOrdered)
{
	// create list:
	list<int> test = Sort::create_revorderedlist(Sort::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));	
}

TEST(InsertionSort_list, TestPermuted)
{
	// create list:
	list<int> test = Sort::create_permutedlist(Sort::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));	
}

TEST(QuickSort_list, TestRandom)
{
	// create list:
	list<int> test = Sort::create_randomlist(Sort::size_of_testarrays, 10);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_list, TestOrdered)
{
	// create list:
	list<int> test = Sort::create_orderedlist(Sort::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_list, TestRevOrdered)
{
	// create list:
	list<int> test = Sort::create_revorderedlist(Sort::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_list, TestPermuted)
{
	// create list:
	list<int> test = Sort::create_permutedlist(Sort::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort::issorted<list<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(InsertionSort_vector, TestRandom)
{
	// create vector:
	vector<int> test = Sort::create_randomvector(Sort::size_of_testarrays, 10);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(InsertionSort_vector, TestOrdered)
{
	// create vector:
	vector<int> test = Sort::create_orderedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(InsertionSort_vector, TestRevOrdered)
{
	// create vector:
	vector<int> test = Sort::create_revorderedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(InsertionSort_vector, TestPermuted)
{
	// create vector:
	vector<int> test = Sort::create_permutedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_vector, TestRandom)
{
	// create vector:
	vector<int> test = Sort::create_randomvector(Sort::size_of_testarrays, 10);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_vector, TestOrdered)
{
	// create vector:
	vector<int> test = Sort::create_orderedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_vector, TestRevOrdered)
{
	// create vector:
	vector<int> test = Sort::create_revorderedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(QuickSort_vector, TestPermuted)
{
	// create vector:
	vector<int> test = Sort::create_permutedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(MergeSort, TestRandom)
{
	// create vector:
	vector<int> test = Sort::create_randomvector(Sort::size_of_testarrays, 10);
	// sort:
	vector<int> sorted = Sort::mergesort(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(MergeSort, TestOrdered)
{
	// create vector:
	vector<int> test = Sort::create_orderedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::mergesort(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(MergeSort, TestRevOrdered)
{
	// create vector:
	vector<int> test = Sort::create_revorderedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::mergesort(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}

TEST(MergeSort, TestPermuted)
{
	// create vector:
	vector<int> test = Sort::create_permutedvector(Sort::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::mergesort(test);
	// test:
	EXPECT_TRUE(Sort::issorted<vector<int>::iterator>(sorted.begin(), Sort::size_of_testarrays));
}
