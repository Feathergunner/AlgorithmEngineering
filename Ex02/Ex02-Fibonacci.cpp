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

int main(){
	return 0;
}
