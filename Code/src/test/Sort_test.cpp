#include <Sort_test.h>

using namespace std;

//--------------------------------------------------------------------------------
// create lists
//--------------------------------------------------------------------------------

list<int> Sort_test::create_randomlist(int size, int init){
	list<int> randlist;
	// initialize with constant: 'randomlist' is pseudo-random, ca be recreated
	srand(init);
	for (int i=0; i<size; i++){
		randlist.push_back(rand()%1000);
	}
	return randlist;
}

list<int> Sort_test::create_permutedlist(int size){
	// note that random.shuffle() needs random-access-iterators => not possible for lists
	// create permuted vector:
	vector<int> pv = create_permutedvector(size);
	// create list from vector:
	list<int> plist(pv.begin(), pv.end());
	return plist;
}

list<int> Sort_test::create_orderedlist(int size){
	list<int> olist;
	for(int i=0; i<size; i++){
		olist.push_back(i);
	}
	return olist;
}

list<int> Sort_test::create_revorderedlist(int size){
	list<int> rlist;
	for(int i=0; i<size; i++){
		rlist.push_front(i);
	}
	return rlist;
}

//--------------------------------------------------------------------------------
// create vectors
//--------------------------------------------------------------------------------

vector<int> Sort_test::create_randomvector(int size, int init)
{
	vector<int> rvector(size,0);
	srand(init);
	for (int i=0; i<size; i++)
		rvector[i] = rand()%1000;
	return rvector;
}

vector<int> Sort_test::create_orderedvector(int size)
{
	vector<int> ovector(size,0);
	for (int i=0; i<size; i++)
		ovector[i] = i;
	return ovector;
}

vector<int> Sort_test::create_revorderedvector(int size)
{
	vector<int> rvector(size,0);
	for (int i=0; i<size; i++)
		rvector[i] = size-i;
	return rvector;
}

vector<int> Sort_test::create_permutedvector(int size)
{
	// create ordered vector:
	vector<int> pvector = create_orderedvector(size);
	// shuffle vector:
	random_shuffle(pvector.begin(), pvector.end());
	return pvector;
}

/*
bool Sort_test::issorted_list(list<int> data)
{
	//iterate through list and check for each number that the next number is not smaller
	list<int>::iterator it=data.begin();
	while(next(it)!=data.end())
		if (*it>*(it++)) return false;
	return true;
}
*/

// method to test if list or vector is sorted
// needs input-iterator at begin of container
// and size of container to be tested
template<typename InputIterator>
bool Sort_test::issorted(InputIterator it, int size)
{
	for (int i=0; i<size-1; i++)
	{
		InputIterator it2 = it;
		InputIterator it2p = ++it;
		//cout << "vgl. " << *it2 << " und " << *it2p << "\n";
		if (*it2 > *it2p) return false;
	}
	return true;
}


// for debugging purpose: prints elements of container
// needs input-iterator as start and number of elements to print
template<typename InputIterator>
void Sort_test::print(InputIterator it, int size)
{
	for (int i=0; i<size-1; i++)
		cout << *it++ << " ";
	cout << "\n";
	return;
}

//--------------------------------------------------------------------------------
// TESTS
//--------------------------------------------------------------------------------

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(InsertionSort_list, TestRandom)
{
	// create list:
	list<int> test = Sort_test::create_randomlist(Sort_test::size_of_testarrays, 0);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(InsertionSort_list, TestOrdered)
{
	// create list:
	list<int> test = Sort_test::create_orderedlist(Sort_test::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(InsertionSort_list, TestRevOrdered)
{
	// create list:
	list<int> test = Sort_test::create_revorderedlist(Sort_test::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));	
}

TEST(InsertionSort_list, TestPermuted)
{
	// create list:
	list<int> test = Sort_test::create_permutedlist(Sort_test::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::insertionsort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));	
}

TEST(QuickSort_list, TestRandom)
{
	// create list:
	list<int> test = Sort_test::create_randomlist(Sort_test::size_of_testarrays, 0);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_list, TestOrdered)
{
	// create list:
	list<int> test = Sort_test::create_orderedlist(Sort_test::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_list, TestRevOrdered)
{
	// create list:
	list<int> test = Sort_test::create_revorderedlist(Sort_test::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_list, TestPermuted)
{
	// create list:
	list<int> test = Sort_test::create_permutedlist(Sort_test::size_of_testarrays);
	// sort:
	list<int> sorted = Sort::quicksort_list(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(InsertionSort_vector, TestRandom)
{
	// create vector:
	vector<int> test = Sort_test::create_randomvector(Sort_test::size_of_testarrays, 0);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(InsertionSort_vector, TestOrdered)
{
	// create vector:
	vector<int> test = Sort_test::create_orderedvector(Sort_test::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(InsertionSort_vector, TestRevOrdered)
{
	// create vector:
	vector<int> test = Sort_test::create_revorderedvector(Sort_test::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(InsertionSort_vector, TestPermuted)
{
	// create vector:
	vector<int> test = Sort_test::create_permutedvector(Sort_test::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::insertionsort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_vector, TestRandom)
{
	// create vector:
	vector<int> test = Sort_test::create_randomvector(Sort_test::size_of_testarrays, 0);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_vector, TestOrdered)
{
	// create vector:
	vector<int> test = Sort_test::create_orderedvector(Sort_test::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_vector, TestRevOrdered)
{
	// create vector:
	vector<int> test = Sort_test::create_revorderedvector(Sort_test::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}

TEST(QuickSort_vector, TestPermuted)
{
	// create vector:
	vector<int> test = Sort_test::create_permutedvector(Sort_test::size_of_testarrays);
	// sort:
	vector<int> sorted = Sort::quicksort_vec(test);
	// test:
	EXPECT_TRUE(Sort_test::issorted(sorted.begin(), Sort_test::size_of_testarrays));
}



