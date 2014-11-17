#include "Meter.cpp"
#include "../Fibonacci.cpp"

int main(){
	Meter m = Meter("measure_Fibo.txt");
	
	int nom = 100;
	m.measure(nom,getFibo1,20);
	m.printData("Fibo1(20)");
	m.measure(nom,getFibo1,30);
	m.printData("Fibo1(30)");
	m.measure(20,getFibo1,35);
	m.printData("Fibo1(30)");
	m.measure(1,getFibo1,40);
	m.printData("Fibo1(30)");
	
	m.measure(nom,getFibo2,20);
	m.printData("Fibo2(20)");
	m.measure(nom,getFibo2,30);
	m.printData("Fibo2(30)");
	m.measure(nom,getFibo2,50);
	m.printData("Fibo2(50)");
	m.measure(nom,getFibo2,100);
	m.printData("Fibo2(100)");
	m.measure(nom,getFibo2,200);
	m.printData("Fibo2(200)");
	
	m.measure(nom,getFibo3,20);
	m.printData("Fibo3(20)");
	m.measure(nom,getFibo3,30);
	m.printData("Fibo3(30)");
	m.measure(nom,getFibo3,50);
	m.printData("Fibo3(50)");
	m.measure(nom,getFibo3,100);
	m.printData("Fibo3(100)");
	m.measure(nom,getFibo3,200);
	m.printData("Fibo3(200)");
	
	m.measure(nom,getFibo4,20);
	m.printData("Fibo4(20)");
	m.measure(nom,getFibo4,30);
	m.printData("Fibo4(30)");
	m.measure(nom,getFibo4,50);
	m.printData("Fibo4(50)");
	m.measure(nom,getFibo4,100);
	m.printData("Fibo4(100)");
	m.measure(nom,getFibo4,200);
	m.printData("Fibo4(200)");
	
	m.measure(nom,getFibo5,20);
	m.printData("Fibo5(20)");
	m.measure(nom,getFibo5,30);
	m.printData("Fibo5(30)");
	m.measure(nom,getFibo5,50);
	m.printData("Fibo5(50)");
	m.measure(nom,getFibo5,100);
	m.printData("Fibo5(100)");
	m.measure(nom,getFibo5,200);
	m.printData("Fibo5(200)");
	
	m.measure(nom,getFibo2,20);
	m.printData("Fibo6(20)");
	m.measure(nom,getFibo2,30);
	m.printData("Fibo6(30)");
	m.measure(nom,getFibo2,40);
	m.printData("Fibo6(40)");
	
	return 0;
}
