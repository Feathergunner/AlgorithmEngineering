#include <gtest/gtest.h>

#include <Fibonacci.h>

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

/*
	test fails because of integer overflow
	
	can be fixed by using an integer type with extra larg positiv range
	contra:
		- needs more space
		- more programming time effort needed
*/
TEST(FailTheImplementaion, Fib4Test){
	EXPECT_GT(Fibonacci::getFibo4(94),Fibonacci::getFibo4(94));
}

/*
	test fails because the formula becomes inaccurate for high n
	because float-numbers become inaccurate
	
	can be fixed by using a floating-point datatype with higher precision.
	contra:
		- needs more space
*/
TEST(FailTheImplementaion, Fib5Test){
	EXPECT_EQ(Fibonacci::getFibo4(41),Fibonacci::getFibo5(41));
}

/*
	test fails because getFibo6 is only implemented for n<=40
	
	could be fixed by extending the array of precomputed fibonacci-numbers
	contra:
		- has to be computed first, independent of if it's needed
*/
TEST(FailTheImplementaion, Fib6Test){
	EXPECT_GT(Fibonacci::getFibo6(42),0);
}
