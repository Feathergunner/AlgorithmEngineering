#include "Fibonacci.cpp"

int main(){
	std::cout << "{";
	for (int i=0; i<=40; i++){
		std::cout << getFibo4(i) << ", " << std::endl;
	}
	std::cout << "}";
	return 0;
}
