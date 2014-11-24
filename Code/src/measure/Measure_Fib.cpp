#include "../../include/measure/Meter.h"
#include "../../include/Fibonacci.h"

int main(){
	char casename[15];
	char filename[20];
	
	int nom;
	
	bool prepare_for_plotting = true;

	// for getFibo1 only 10 measurements
	nom = 10;
	sprintf(filename, "%s", "measure_Fibo1");
	Meter m = Meter(filename);
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo1, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}
	
	// all other methods are much faster, so make 1000 measurements:
	// => one will observe that random peaks in used time will happen in almost every testcase
	nom = 1000;

	sprintf(filename, "%s", "measure_Fibo2");
	m = Meter(filename);
	for (int i=1; i<90; i++){
		m.measure(nom, Fibonacci::getFibo2, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}

	sprintf(filename, "%s", "measure_Fibo3");
	m = Meter(filename);
	for (int i=1; i<90; i++){
		m.measure(nom, Fibonacci::getFibo3, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}

	sprintf(filename, "%s", "measure_Fibo4");
	m = Meter(filename);
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo4, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}
	
	sprintf(filename, "%s", "measure_Fibo4_2");
	m = Meter(filename);
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo4_2, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}

	sprintf(filename, "%s", "measure_Fibo5");
	m = Meter(filename);
	for (int i=1; i<37; i++){
		m.measure(nom, Fibonacci::getFibo5, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}

	sprintf(filename, "%s", "measure_Fibo6");
	m = Meter(filename);
	for (int i=1; i<40; i++){
		m.measure(nom, Fibonacci::getFibo6, i);
		sprintf(casename, "%i",i);
		m.printData(casename);
		if (prepare_for_plotting) m.printData_plotting(casename);
	}

	return 0;
}
