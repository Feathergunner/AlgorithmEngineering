#ifndef meter_h
#define meter_h

#include <vector>
#include <cstdint>
#include <math.h>
#include <fstream>
#include <iomanip>

#include "StopWatch.h"

using namespace std;

class Meter{
	StopWatch w;
	vector<uint64_t> data;
	uint64_t mean;
	uint64_t min;
	uint64_t max;
	double std_deviation;
	int number_of_measurements;

	//const char* filename;
	char filename[80];
	char filename_p[80];
	
	void compute_statistics();

public:
	Meter(){}
	Meter(char file[80]);

	//Templates: RT for return-type and PT for parameter-type
	template<typename RT, typename PT>
	void measure_time(uint32_t nom, RT(*function)(PT arg), PT val);
	template<typename RT, typename PT>
	void measure_cycles(uint32_t nom, RT(*function)(PT arg), PT val);
	
	void initfile();
	void printData(char* casename);
	
	void initfile_plotting();
	void printData_plotting(char* casename);
	
	uint64_t get_mean(){return mean;}
};

// Measures the time needed by function given by the pointer *function with parameter val for nom times
// and computes statistics
template<typename RT, typename PT>
void Meter::measure_time(uint32_t nom, RT(*function)(PT arg), PT val)
{
	number_of_measurements = nom;

	//measured values:
	data = vector<uint64_t>(nom, 0);

	// run tests:
	for (int i=0; i<number_of_measurements; i++){
		w.startWatch();
		function(val);
		w.stopWatch();
		data[i] = w.getTime();
	}
	compute_statistics();
}

// Measures the cpu cycles needed by function given by the pointer *function with parameter val for nom times
// and computes statistics
template<typename RT, typename PT>
void Meter::measure_cycles(uint32_t nom, RT(*function)(PT arg), PT val)
{
	number_of_measurements = nom;
	uint32_t cycles_low, cycles_high, cycles_low1, cycles_high1;
	uint64_t start, end;
	
	data = vector<uint64_t>(nom, 0);
	
	//run tests:
	for (int i=0; i<number_of_measurements; i++)
	{
	
	/*
		// Code as in paper:
		// doesnt work "Bad register name %%rax" (in lines 93-94)
		asm volatile ("CPUID\n\t"::: "%rax", "%rbx", "%rcx", "%rdx");
		asm volatile ("RDTSC\n\t"
									"mov %%edx, %0\n\t"
									"mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low):: "%rax", "%rdx");
									
		function(val);
		
		asm volatile ("mov %%cr0, %%rax\n\t"
									"mov %%rax, %%cr0\n\t"
									"RDTSC\n\t"
									"mov %%edx, %0\n\t"
									"mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low1):: "%rax", "%rdx");
	*/
		asm volatile ("CPUID\n\t": : : "%rax", "%rbx", "%rcx", "%rdx");
		asm volatile ("RDTSC\n\t"
									"mov %%edx, %0\n\t"
									"mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low):: "%rax", "%rbx", "%rcx", "%rdx");
									
		function(val);
		
		asm volatile ("CPUID\n\t"
									"RDTSC\n\t"
									"mov %%edx, %0\n\t"
									"mov %%eax, %1\n\t": "=r" (cycles_high1), "=r" (cycles_low1):: "%rax", "%rbx", "%rcx", "%rdx");
										
		start = ( ((uint64_t)cycles_high << 32) | cycles_low );
		end = (((uint64_t)cycles_high1 << 32) | cycles_low1 );
		
		data[i]=end-start;
	}
	compute_statistics();

}
#endif
