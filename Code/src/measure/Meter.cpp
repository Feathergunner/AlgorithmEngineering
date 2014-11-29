#include <measure/Meter.h>

Meter::Meter(char file[50]){
	min = 0;
	max = 0;
	mean = 0;
	std_deviation = 0;
	
	sprintf(filename, "measurements/%s",file);
	sprintf(filename_p, "measurements/%s_p",file);
	initfile();
	initfile_plotting();
}

// compute statistics:
void Meter::compute_statistics()
{
	// min, max, mean:
	min = data[0];
	max = 0;
	uint64_t sum = 0;
	for (int i=0; i<number_of_measurements; i++){
		if (data[i] < min) min = data[i];
		if (data[i] > max) max = data[i];
		sum += data[i];
	}
	mean = sum/number_of_measurements;

	//standart deviation:
	int64_t dev, sum_of_dev = 0;
	for (int i=0; i<number_of_measurements; i++){
		dev = mean-data[i];
		sum_of_dev += (dev*dev);
	}
	std_deviation = sqrt((double)sum_of_dev/(number_of_measurements-1));
}

void Meter::initfile(){
	remove(filename);
	fstream file;
	file.open (filename, fstream::out | fstream::app);
	file << " Input:        I #Tests:       I Minimum:      I Maximum:      I Mean:         I std. deviation:\n";
	file << "---------------I---------------I---------------I---------------I---------------I--------------------\n";
	file.close();
}

void Meter::printData(char* casename){
	fstream file;
	file.open(filename, fstream::out | fstream::app);
	file << setw(14) << casename << " I" << setw(14) << number_of_measurements << " I" << std::setw(14) << min << " I" << std::setw(14) << max << " I" << std::setw(14) << mean << " I" << std::setprecision(3) << std::fixed << std::setw(14) << std_deviation << "\n";
	file.close();
}

void Meter::initfile_plotting()
{
	remove(filename_p);
}

void Meter::printData_plotting(char* casename)
{
	fstream file;
	file.open(filename_p, fstream::out | fstream::app);
	file << casename << "\t" << min << "\t" << max << "\t" << mean << "\t" << std::setprecision(2) << std::fixed << std_deviation << "\n";
	file.close();
}
