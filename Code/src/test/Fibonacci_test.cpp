#include <gtest/gtest.h>

#include "../../include/Fibonacci.h"

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(Fib1Test, TestCorrectComputation){
	EXPECT_EQ(0, Fibonacci::getFibo1(0));
	EXPECT_EQ(1, Fibonacci::getFibo1(1));
	EXPECT_EQ(1, Fibonacci::getFibo1(2));
	EXPECT_EQ(2, Fibonacci::getFibo1(3));
	EXPECT_EQ(3, Fibonacci::getFibo1(4));
	EXPECT_EQ(5, Fibonacci::getFibo1(5));
	EXPECT_EQ(55, Fibonacci::getFibo1(10));
	EXPECT_EQ(6765, Fibonacci::getFibo1(20));
	EXPECT_EQ(832040, Fibonacci::getFibo1(30));
}

TEST(Fib2Test, TestCorrectComputation){
	EXPECT_EQ(0, Fibonacci::getFibo2(0));
	EXPECT_EQ(1, Fibonacci::getFibo2(1));
	EXPECT_EQ(1, Fibonacci::getFibo2(2));
	EXPECT_EQ(2, Fibonacci::getFibo2(3));
	EXPECT_EQ(3, Fibonacci::getFibo2(4));
	EXPECT_EQ(5, Fibonacci::getFibo2(5));
	EXPECT_EQ(55, Fibonacci::getFibo2(10));
	EXPECT_EQ(6765, Fibonacci::getFibo2(20));
	EXPECT_EQ(832040, Fibonacci::getFibo2(30));
}

TEST(Fib3Test, TestCorrectComputation){
	EXPECT_EQ(0, Fibonacci::getFibo3(0));
	EXPECT_EQ(1, Fibonacci::getFibo3(1));
	EXPECT_EQ(1, Fibonacci::getFibo3(2));
	EXPECT_EQ(2, Fibonacci::getFibo3(3));
	EXPECT_EQ(3, Fibonacci::getFibo3(4));
	EXPECT_EQ(5, Fibonacci::getFibo3(5));
	EXPECT_EQ(55, Fibonacci::getFibo3(10));
	EXPECT_EQ(6765, Fibonacci::getFibo3(20));
	EXPECT_EQ(832040, Fibonacci::getFibo3(30));
}

TEST(Fib4Test, TestCorrectComputation){	
	for (int i=0; i<45; i++){
		EXPECT_EQ(Fibonacci::getFibo3(i), Fibonacci::getFibo4(i));
	}
}

TEST(Fib4_2Test, TestCorrectComputation){	
	for (int i=0; i<45; i++){
		EXPECT_EQ(Fibonacci::getFibo3(i), Fibonacci::getFibo4_2(i));
	}
}

TEST(Fib5Test, TestCorrectComputation){
	for (int i=0; i<35; i++){
		EXPECT_EQ(Fibonacci::getFibo3(i), Fibonacci::getFibo5(i));
	}
}

/*
	a test for getFibo6 is not necessary, since it returns the values computed by getFibo4.
*/
