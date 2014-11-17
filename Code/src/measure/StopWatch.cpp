#include <chrono>
#include <cstdint>

class StopWatch
{
public:	

	std::chrono::system_clock::time_point start;
	std::chrono::duration<uint64_t,std::ratio<1,1000000> > total;
	
	StopWatch(){}
	
	// start Timer
	void startWatch(){
		start = std::chrono::system_clock::now();
	}
	
	// stop Timer, compute elapsed time
	void stopWatch(){
		total = std::chrono::system_clock::now()-start;
	}
	
	void resetWatch(){
		total = std::chrono::system_clock::duration::zero();
	}
	
	// returns measured time in microseconds
	uint64_t getTime(bool reset = true){
		return total.count();
		if (reset) resetWatch();
	}
};
