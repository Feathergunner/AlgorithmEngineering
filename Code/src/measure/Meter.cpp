#include "../../include/measure/Meter.h"


Meter::Meter(const char* file="measurements.txt"){
	filename = file;
	initfile();
}
	
void Meter::measure(uint32_t nom, uint64_t(*function)(uint32_t), uint32_t val){
	number_of_measurements = nom;
	data = vector<uint64_t>(nom, 0);
		
	// run tests:	
	for (int i=0; i<number_of_measurements; i++){
		w.startWatch();
		function(val);
		w.stopWatch();
		data[i] = w.getTime();
	}
		
	// compute statistics:
	// min, max, mean:
	min = data[0];
	max = 0;
	uint64_t sum = 0;
	for (int  i=0; i<number_of_measurements; i++){
		if (data[i] < min) min = data[i];
		if (data[i] > max) max = data[i];
		sum += data[i];
	}
	mean = sum/number_of_measurements;
	
	//standart deviation:
	int64_t dev, sum_of_dev = 0;
	for (int  i=0; i<number_of_measurements; i++){
		dev = mean-data[i];
		sum_of_dev += (dev*dev);
	}
	std_deviation = sqrt((double)sum_of_dev/(number_of_measurements-1));
}
	
void Meter::initfile(){
	remove(filename);
	fstream file;
	file.open (filename, fstream::out | fstream::app);
	
	file << " Case:         I #Tests:       I Minimum(µs):  I Maximum(µs):  I Mean(µs):     I std. deviation(µs):\n";
	file << "---------------I---------------I---------------I---------------I---------------I--------------------\n";
	file.close();
}

void Meter::printData(char* casename){
	fstream file;
	file.open(filename, fstream::out | fstream::app);
	file << setw(14) << casename << " I" << setw(14) << number_of_measurements << " I" << std::setw(14) << min << " I" << std::setw(14) << max << " I" << std::setw(14) << mean << " I" << std::setprecision(3) << std::fixed << std::setw(14) << std_deviation << "\n";
	file.close();
}

