#include "include/Fibonacci.h"
#include <iostream>
#include <iomanip>

int main(){
	for (int i=0; i<=100; i++){
		std::cout << "Fib(" << std::setw(3) << i << ")=" << std::setw(20) << Fibonacci::getFibo3(i) << std::endl;
	}
	return 0;
}
