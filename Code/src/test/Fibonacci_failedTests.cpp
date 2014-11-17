#include "../Fibonacci.cpp"
#include <gtest/gtest.h>

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

/*
	test fails because of integer overflow
	
	can be fixed by using an integer type with larger positiv range, like uint64_t
	contra:
		- needs more space
		- with unsigned integers, one cannot return -1 as a error flag
*/
TEST(FailTheImplementaion, Fib4Test){
	EXPECT_GT(getFibo4(50),0);
}

/*
	test fails because the formula becomes inaccurate for high n
	because float-numbers become inaccurate
	
	can be fixed by using a floating-point datatype with higher precision.
	contra:
		- needs more space
*/
TEST(FailTheImplementaion, Fib5Test){
	EXPECT_EQ(getFibo4(37),getFibo5(37));
}

/*
	test fails because getFibo6 is only implemented for n<=40
	
	could be fixed by extending the array of precomputed fibonacci-numbers
	contra:
		- has to be computed first, independent of if it's needed
*/
TEST(FailTheImplementaion, Fib6Test){
	EXPECT_GT(getFibo6(42),0);
}
