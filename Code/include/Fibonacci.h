#ifndef Fibonacci_h
#define Fibonacci_h

#include <cstdint>
#include <vector>
#include <math.h>

#include "IntMatrix.h"

//class to collect all Fibonacci-algorithms
class Fibonacci{
public:
	static uint64_t getFibo1(uint32_t n);
	static uint64_t getFibo2(uint32_t n);
	static uint64_t getFibo3(uint32_t n);
	static uint64_t getFibo4(uint32_t n);
	static uint64_t getFibo5(uint32_t n);
	static uint64_t getFibo6(uint32_t n);
};

#endif
