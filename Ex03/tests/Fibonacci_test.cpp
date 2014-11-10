#include "../src/Fibonacci.cpp"
#include "../../Ex02/src/Fibonacci.cpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

TEST(Fib4Test, TestCorrectComputation){
	for (int i=0; i<30; i++){
		EXPECT_EQ(getFibo3(i), getFibo4(i));
	}
}

TEST(Fib5Test, TestCorrectComputation){
	for (int i=0; i<30; i++){
		EXPECT_EQ(getFibo3(i), getFibo5(i));
	}
}

/*
	a test for getFibo6 is not necessary, since it returns the values computed by getFibo4.
*/
