#include <vector>

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

int main(){
	return 0;
}
