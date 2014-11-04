#include "Ex02-Fibonacci.cpp"
#include <gtest/gtest.h>

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
