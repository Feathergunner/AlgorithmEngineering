#include "../../include/measure/Meter.h"
#include "../../include/Fibonacci.h"

int main(){
	Meter m = Meter("measure_Fibo.txt");
		
	int nom = 100;
	m.measure(nom,Fibonacci::getFibo1,20);
	m.printData("Fibo1(20)");
	m.measure(nom,Fibonacci::getFibo1,30);
	m.printData("Fibo1(30)");
	m.measure(20,Fibonacci::getFibo1,35);
	m.printData("Fibo1(30)");
	m.measure(1,Fibonacci::getFibo1,40);
	m.printData("Fibo1(30)");
	
	m.measure(nom,Fibonacci::getFibo2,20);
	m.printData("Fibo2(20)");
	m.measure(nom,Fibonacci::getFibo2,30);
	m.printData("Fibo2(30)");
	m.measure(nom,Fibonacci::getFibo2,50);
	m.printData("Fibo2(50)");
	m.measure(nom,Fibonacci::getFibo2,100);
	m.printData("Fibo2(100)");
	m.measure(nom,Fibonacci::getFibo2,200);
	m.printData("Fibo2(200)");
	
	m.measure(nom,Fibonacci::getFibo3,20);
	m.printData("Fibo3(20)");
	m.measure(nom,Fibonacci::getFibo3,30);
	m.printData("Fibo3(30)");
	m.measure(nom,Fibonacci::getFibo3,50);
	m.printData("Fibo3(50)");
	m.measure(nom,Fibonacci::getFibo3,100);
	m.printData("Fibo3(100)");
	m.measure(nom,Fibonacci::getFibo3,200);
	m.printData("Fibo3(200)");
	
	m.measure(nom,Fibonacci::getFibo4,20);
	m.printData("Fibo4(20)");
	m.measure(nom,Fibonacci::getFibo4,30);
	m.printData("Fibo4(30)");
	m.measure(nom,Fibonacci::getFibo4,50);
	m.printData("Fibo4(50)");
	m.measure(nom,Fibonacci::getFibo4,100);
	m.printData("Fibo4(100)");
	m.measure(nom,Fibonacci::getFibo4,200);
	m.printData("Fibo4(200)");
	
	m.measure(nom,Fibonacci::getFibo5,20);
	m.printData("Fibo5(20)");
	m.measure(nom,Fibonacci::getFibo5,30);
	m.printData("Fibo5(30)");
	m.measure(nom,Fibonacci::getFibo5,50);
	m.printData("Fibo5(50)");
	m.measure(nom,Fibonacci::getFibo5,100);
	m.printData("Fibo5(100)");
	m.measure(nom,Fibonacci::getFibo5,200);
	m.printData("Fibo5(200)");
	
	m.measure(nom,Fibonacci::getFibo2,20);
	m.printData("Fibo6(20)");
	m.measure(nom,Fibonacci::getFibo2,30);
	m.printData("Fibo6(30)");
	m.measure(nom,Fibonacci::getFibo2,40);
	m.printData("Fibo6(40)");
	
	return 0;
}
