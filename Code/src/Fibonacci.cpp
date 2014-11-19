#include "../include/Fibonacci.h"

using namespace std;

/*
 1) computes the n-th Fibonacci-number in exponential time in n (simple implementation of definition)
*/
uint64_t Fibonacci::getFibo1(uint32_t n){
    //trivial cases:
    if (n==0) return 0;
    if (n==1) return 1;
    //recursive computation following the definition:
    return getFibo1(n-1)+getFibo1(n-2);
}

/*
 2) computes the n-th Fibonacci-Number in linear time and linear memory(in n)
*/
uint64_t Fibonacci::getFibo2(uint32_t n){
    // trivial cases:
    if (n==0) return 0;
    if (n==1) return 1;
    //initialize a vector which keeps the i-th fibonacci-number at position i:
    vector<uint64_t> fib_numbers = vector<uint64_t>(n);
    fib_numbers[0]=0;
    fib_numbers[1]=1;
    //compute fibonacci-numbers iteratively:
    for (uint32_t i=2;i<n;i++){
        fib_numbers[i] = fib_numbers[i-1]+fib_numbers[i-2];
    }
    return fib_numbers[n-2]+fib_numbers[n-1];
}

/*
 3) computes the n-th fibonacci-number in linear time (in n) and constant memory
*/
uint64_t Fibonacci::getFibo3(uint32_t n){
    // trivial cases:
    if (n==0) return 0;
    if (n==1) return 1;

    /*
     initialise two integers to keep the last two computed fibonacci-numbers:
      lastTwoNumbers[0] always keeps the Fibonacci-numbers of EVEN n, and
      lastTwoNumbers[1] always keeps the Fibonacci-numbers of ODD n
    */
    uint64_t lastTwoNumbers[2];
    lastTwoNumbers[0]=0;
    lastTwoNumbers[1]=1;
    for (uint32_t i=2; i<n; i++){
        if (i%2 == 0){
        	//update even fibonacci-number
          lastTwoNumbers[0] += lastTwoNumbers[1];
        }else{
        	//update uneven fibonacci-number
        	lastTwoNumbers[1] += lastTwoNumbers[0];
        }
    }
    //return n-th fibonacci-number
    return lastTwoNumbers[0]+lastTwoNumbers[1];
}

/*
	computes the Fibonacci numbers using matrix-exponentiation in logarithmic time in n
*/
uint64_t Fibonacci::getFibo4(uint32_t n){
	//trivial cases:
	if (n==0) return 0;
	if (n==1) return 1;
	
	// construct needed matrix:
	// mat_fib_exp = 0 1
	//               1 1
	// and vector:
	// mat_fib_vec = 0
	// 							 1
	
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
	
	// the implementation above is equivalent to the implementation discussed in class,
	// which follows here:
	// (note that this is non-reachable code)
	
	// multiply this matrix with mat_fib_vec
	IntMatrix fib = mat_fib_exp.multiply(mat_fib_vec);
	// now the n-th fibonacci-number is at fib[1][0]
	return fib.get_elementAt(1,0);
}

/*
	computes the n-th fibonacci-number in constant time using the derived formula
*/
uint64_t Fibonacci::getFibo5(uint32_t n){
	//trivial cases:
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
uint64_t Fibonacci::getFibo6(uint32_t n){
	//trivial cases:
	if (n<0 || n>40) return 0;
	
	// numbers computed by getFibo4 (see Fibonacci_main.cpp)
	int fibs[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 
		6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 
		2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155};
	return fibs[n];
}
