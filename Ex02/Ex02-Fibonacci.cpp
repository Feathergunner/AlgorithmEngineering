#include <vector>
#include <gtest/gtest.h>

using namespace std;

/*
 1) computes the n-th Fibonacci-number in exponential time in n (simple implementation of definition)
*/
int getFibo1(int n){
    //trivial cases:
    if (n<0) return -1;
    if (n==0) return 0;
    if (n==1) return 1;
    //recursive computation following the definition:
    return getFibo1(n-1)+getFibo1(n-2);
}

/*
 2) computes the n-th Fibonacci-Number in linear time and linear memory(in n)
*/
int getFibo2(int n){
    // trivial cases:
    if (n<0) return -1;
    if (n==0) return 0;
    if (n==1) return 1;
    //initialize a vector which keeps the i-th fibonacci-number at position i:
    vector<int> fib_numbers = vector<int>(n);
    fib_numbers[0]=0;
    fib_numbers[1]=1;
    //compute fibonacci-numbers iteratively:
    for (int i=2;i<n;i++){
        fib_numbers[i] = fib_numbers[i-1]+fib_numbers[i-2];
    }
    return fib_numbers[n-2]+fib_numbers[n-1];
}

/*
 3) computes the n-th fibonacci-number in linear time (in n) and constant memory
*/
int getFibo3(int n){
    // trivial cases:
    if (n<0) return -1;
    if (n==0) return 0;
    if (n==1) return 1;

    /*
     initialise two integers to keep the last two computed fibonacci-numbers:
      lastTwoNumbers[0] always keeps the Fibonacci-numbers of EVEN n, and
      lastTwoNumbers[1] always keeps the Fibonacci-numbers of ODD n
    */
    int lastTwoNumbers[2];
    lastTwoNumbers[0]=0;
    lastTwoNumbers[1]=1;
    for (int i=2; i<n; i++){
        if (i%2 == 0){
            lastTwoNumbers[0] += lastTwoNumbers[1];
        }else{
            lastTwoNumbers[1] += lastTwoNumbers[0];
        }
    }
    return lastTwoNumbers[0]+lastTwoNumbers[1];
}

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();;
}

/*
	Tests
*/

TEST(Fib1Test, TestCorrectComputation){
	EXPECT_EQ(0, getFibo1(0));
	EXPECT_EQ(1, getFibo1(1));
	EXPECT_EQ(1, getFibo1(2));
	EXPECT_EQ(2, getFibo1(3));
	EXPECT_EQ(3, getFibo1(4));
	EXPECT_EQ(5, getFibo1(5));
	EXPECT_EQ(55, getFibo1(10));
	EXPECT_EQ(6765, getFibo1(20));
	EXPECT_EQ(832040, getFibo1(30));
}

TEST(Fib2Test, TestCorrectComputation){
	EXPECT_EQ(0, getFibo2(0));
	EXPECT_EQ(1, getFibo2(1));
	EXPECT_EQ(1, getFibo2(2));
	EXPECT_EQ(2, getFibo2(3));
	EXPECT_EQ(3, getFibo2(4));
	EXPECT_EQ(5, getFibo2(5));
	EXPECT_EQ(55, getFibo2(10));
	EXPECT_EQ(6765, getFibo2(20));
	EXPECT_EQ(832040, getFibo2(30));
}

TEST(Fib3Test, TestCorrectComputation){
	EXPECT_EQ(0, getFibo3(0));
	EXPECT_EQ(1, getFibo3(1));
	EXPECT_EQ(1, getFibo3(2));
	EXPECT_EQ(2, getFibo3(3));
	EXPECT_EQ(3, getFibo3(4));
	EXPECT_EQ(5, getFibo3(5));
	EXPECT_EQ(55, getFibo3(10));
	EXPECT_EQ(6765, getFibo3(20));
	EXPECT_EQ(832040, getFibo3(30));
}

