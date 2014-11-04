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

int main(){
	return 0;
}
