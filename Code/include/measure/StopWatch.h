#ifndef stopwatch_h
#define stopwatch_h

#include <chrono>
#include <cstdint>

class StopWatch
{
	std::chrono::system_clock::time_point start;
	std::chrono::duration<uint64_t,std::ratio<1,1000000> > total;

public:	
	
	StopWatch(){}
	
	// start Timer
	void startWatch();
	
	// stop Timer, compute elapsed time
	void stopWatch();
	
	void resetWatch();
	
	// returns measured time in microseconds
	uint64_t getTime(bool reset = true);
};

#endif
