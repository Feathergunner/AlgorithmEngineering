#include <measure/Meter.h>
#include <Fibonacci.h>

typedef	uint64_t (*function)(uint32_t);

int main(){
	char casename[15];
	char filename_t[30];
	char filename_c[30];
	
	// Meters for time and cycles:
	Meter m_t, m_c;
	
	int nom;
	int maxinput;
	
	bool prepare_for_plotting = true;
	
	// filenames for testcases:
	const char* cases[7] = {"Fibo1",
													"Fibo2",
													"Fibo3",
													"Fibo4",
													"Fibo4-2",
													"Fibo5",
													"Fibo6"};
	
	// functionpointers for testcases:
	function fiboalgos[7] = {Fibonacci::getFibo1,
														Fibonacci::getFibo2,
														Fibonacci::getFibo3,
														Fibonacci::getFibo4,
														Fibonacci::getFibo4_2,
														Fibonacci::getFibo5,
														Fibonacci::getFibo6};
	
	nom = 1000;
	maxinput = 40;
	for (int c=0; c<7; c++)
	{
		if (c==0)
		{
			// for getFibo1 only 10 measurements
			nom = 10;
		}
		
		// adjust max. input:
		if (c==1 || c==2)
			maxinput = 90;
		if (c==5)
			maxinput = 37;
			
		sprintf(filename_t, "time_%s", cases[c]);
		m_t = Meter(filename_t);
		sprintf(filename_c, "cycles_%s", cases[c]);
		m_c = Meter(filename_c);
		for (int i=1; i<maxinput; i++)
		{
			// measure time:
			m_t.measure_time<uint64_t, uint32_t>(nom, fiboalgos[c], i);
			// measure cycles:
			m_c.measure_cycles<uint64_t, uint32_t>(nom, fiboalgos[c], i);
			sprintf(casename, "%i",i);
			m_t.printData(casename);
			m_c.printData(casename);
			if (prepare_for_plotting)
			{
				m_t.printData_plotting(casename);
				m_c.printData_plotting(casename);
			}
		}
		

	}

	return 0;
}
