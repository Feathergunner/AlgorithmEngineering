#include "../../include/measure/StopWatch.h"
	
// start Timer
void StopWatch::startWatch(){
	start = std::chrono::system_clock::now();
}
	
// stop Timer, compute elapsed time
void StopWatch::stopWatch(){
	//explizitly cast duration into desired format:
	total = std::chrono::duration_cast<std::chrono::duration<uint64_t,std::ratio<1,1000000> >>(std::chrono::system_clock::now()-start);
}
	
void StopWatch::resetWatch(){
	total = std::chrono::system_clock::duration::zero();
}
	
// returns measured time in microseconds
uint64_t StopWatch::getTime(bool reset){
	return total.count();
	if (reset) resetWatch();
}

