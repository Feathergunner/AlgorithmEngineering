#include "../../include/measure/Meter.h"
#include "../../include/Fibonacci.h"

int main(){
	char casename[15];
	
	// for getFibo1 only 10 measurements
	int nom = 10;
	Meter m = Meter("measure_Fibo1.txt");
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo1, i);
		sprintf(casename, "Fibo1(%i)",i);
		m.printData(casename);
	}
	
	// all other methods are much faster, so make 1000 measurements:
	// => one will observe that random peaks in used time will happen in almost every testcase
	nom = 1000;
	
	m = Meter("measure_Fibo2.txt");
	for (int i=1; i<90; i++){
		m.measure(nom, Fibonacci::getFibo2, i);
		sprintf(casename, "Fibo2(%i)",i);
		m.printData(casename);
	}
	
	m = Meter("measure_Fibo3.txt");
	for (int i=1; i<90; i++){
		m.measure(nom, Fibonacci::getFibo3, i);
		sprintf(casename, "Fibo3(%i)",i);
		m.printData(casename);
	}
	
	m = Meter("measure_Fibo4.txt");
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo4, i);
		sprintf(casename, "Fibo4(%i)",i);
		m.printData(casename);
	}
	
	m = Meter("measure_Fibo5.txt");
	for (int i=1; i<37; i++){
		m.measure(nom, Fibonacci::getFibo5, i);
		sprintf(casename, "Fibo5(%i)",i);
		m.printData(casename);
	}
	
	m = Meter("measure_Fibo6.txt");
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo6, i);
		sprintf(casename, "Fibo6(%i)",i);
		m.printData(casename);
	}
	
	return 0;
}
