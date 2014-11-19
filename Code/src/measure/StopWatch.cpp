#include "../../include/measure/StopWatch.h"
	
// start Timer
void StopWatch::startWatch(){
	start = std::chrono::system_clock::now();
}
	
// stop Timer, compute elapsed time
void StopWatch::stopWatch(){
	total = std::chrono::system_clock::now()-start;
}
	
void StopWatch::resetWatch(){
	total = std::chrono::system_clock::duration::zero();
}
	
// returns measured time in microseconds
uint64_t StopWatch::getTime(bool reset){
	return total.count();
	if (reset) resetWatch();
}

