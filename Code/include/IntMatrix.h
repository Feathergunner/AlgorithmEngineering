#ifndef IntMatrix_h
#define IntMatrix_h

#include <gtest/gtest.h>
#include <cstdint>

#include <vector>

class IntMatrix{
	public:
	//getter:
	uint32_t get_rows(){return rows;}
	uint32_t get_cols(){return cols;}
	int get_elementAt(uint32_t r, uint32_t c){return matrix[r][c];}
	
	//ctor for empty matrix:
	IntMatrix(uint32_t r, uint32_t c);
	//ctor for initialised matrix:
	IntMatrix(uint32_t r, uint32_t c, std::vector<std::vector<int> > data);
	
	// "Constructor" for a identity matrix
	IntMatrix getIdentityMatrix(uint32_t s);
	
	// methods for scaling, multipliing and exponentiation
	void scale(int s);
	IntMatrix multiply(IntMatrix rhs);
	IntMatrix expBySqr(uint32_t power);
	IntMatrix expBySqr2(uint32_t power);
	
	// print matrix to screen:
	void print();
		
	private:
	uint32_t rows;
	uint32_t cols;
	
	std::vector<std::vector<int> > matrix;
};

bool operator==(IntMatrix& lhs, IntMatrix& rhs);

#endif

