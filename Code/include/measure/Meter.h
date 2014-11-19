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
	
	const char* filename;

public:
	
	Meter(const char* file);
	
	void measure(uint32_t nom, uint64_t(*function)(uint32_t), uint32_t val);
	
	void initfile();

	void printData(char* casename);
};

#endif
