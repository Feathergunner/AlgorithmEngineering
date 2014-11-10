#include "../src/IntMatrix.cpp"
#include <vector>
#include <math.h>

using namespace std;

/*
	computes the Fibonacci numbers using matrix-exponentiation in logarithmic time in n
*/
int getFibo4(int n){
	//trivial cases:
	if (n<0) return -1;
	if (n==0) return 0;
	if (n==1) return 1;

	/*
	 construct needed matrix:
	 mat_fib_exp = 0 1
	               1 1
	 and vector:
	 mat_fib_vec = 0
	 							 1
	*/
	vector<vector<int> > fib_exp = vector<vector<int> >(2,vector<int>(2,0));
	fib_exp[0][0] = 0;
	fib_exp[0][1] = 1;
	fib_exp[1][0] = 1;
	fib_exp[1][1] = 1;
	IntMatrix mat_fib_exp = IntMatrix(2,2,fib_exp);

	vector<vector<int> > fib_vec = vector<vector<int> >(2,vector<int>(1,0));
	fib_vec[0][0] = 0;
	fib_vec[1][0] = 1;
	IntMatrix mat_fib_vec = IntMatrix(2,1,fib_vec);
	
	//compute the (n-1)th power of mat_fib_exp:
	mat_fib_exp = mat_fib_exp.expBySqr(n-1);
	//now the n-th fibonacci-number is at mat_fib_exp[1][1]
	return mat_fib_exp.get_elementAt(1,1);
	
	/*
	 the implementation above is equivalent to the implementation discussed in class,
	 which follows here:
	 (note that this is non-reachable code)
	*/
	
	// multiply this matrix with mat_fib_vec
	IntMatrix fib = mat_fib_exp.multiply(mat_fib_vec);
	// now the n-th fibonacci-number is at fib[1][0]
	return fib.get_elementAt(1,0);
}

/*
	computes the n-th fibonacci-number in constant time using the derived formula
*/
int getFibo5(int n){
	//trivial cases:
	if (n<0) return -1;
	if (n==0) return 0;
	if (n==1) return 1;
	
	//the formula:
	int res = (int)floor((1/sqrt(5))*pow((1+sqrt(5))/2,n)-(1/2));
	//i don't know why, but it seems like res is always 1 too small for odd n
	if (n%2==1) res+=1;
	return res;
}

/*
	returns for n<=40 the n-th fibonacci-number from a lookup-table
*/
int getFibo6(int n){
	//trivial cases:
	if (n<0 || n>40) return -1;
	
	// numbers computed by getFibo4 (see Fibonacci_main.cpp)
	int fibs[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 
		6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 
		2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155};
	return fibs[n];
}
