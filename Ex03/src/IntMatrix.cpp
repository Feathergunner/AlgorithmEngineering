#include "../include/IntMatrix.h"
#include <gtest/gtest.h>

//constructs new r x c -Matrix and initialises all entries = 0
IntMatrix::IntMatrix(unsigned int r, unsigned int c){
	//check if dimensions > 0
	EXPECT_GT(r,0);
	EXPECT_GT(c,0);
	
	rows = r;
	cols = c;
	matrix = std::vector<std::vector<int> >(rows, std::vector<int>(cols,0));
}

//constructs new r x c -Matrix with commited data
IntMatrix::IntMatrix(unsigned int r, unsigned int c,  std::vector<std::vector<int> > data){
	//check if dimensions > 0
	EXPECT_GT(r,0);
	EXPECT_GT(c,0);
	
	//check that size of data is equal to passed dimension
	EXPECT_EQ(r,data.size());
	EXPECT_EQ(c,data[0].size());
	
	
	rows = r;
	cols = c;
	matrix = data;
}

//returns identity matrix of size r*c
IntMatrix IntMatrix::getIdentityMatrix(unsigned int r, unsigned int c){
	//check if dimensions > 0
	EXPECT_GT(r,0);
	EXPECT_GT(c,0);
	
	IntMatrix ret = IntMatrix(r,c);
	//get minimum of r,c
	unsigned int min = 0;
	if (r<c) min = r;
	else min = c;
	
	//set diagonal entries [i][i]=1
	for (unsigned int i=0; i<min; i++)
		ret.matrix[i][i] = 1;
		
	return ret;
}

//scales the matrix by factor s
//in O(size of Matrix)
void IntMatrix::scale(int s){
	for (unsigned int i=0; i<rows; i++)
		for (unsigned int j=0; j<cols; j++)
			matrix[i][j] *= s;	
}


//computes Matrix-Product THIS x RHS
//simple implementation in O(n^3) with n = max(rows, cols of both matrices)
IntMatrix IntMatrix::multiply(IntMatrix rhs){
	//check if dimensions allow multiplication:
	EXPECT_EQ(cols, rhs.rows);
	
	//construct resultmatrix
	IntMatrix ret = IntMatrix(rows, rhs.cols);
	//stadard matrix-multiplication
	for (unsigned int i=0; i<rows; i++)
		for (unsigned int j=0; j<rhs.cols; j++)
				for (unsigned int k=0; k<cols; k++)
					ret.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
	
	return ret;
}

//computes the p-th power of THIS
//uses exponentiation-by-squaring
// => O(log n) time, with n=size of matrix
IntMatrix IntMatrix::expBySqr(unsigned int p){
	//check if matrix is square
	EXPECT_EQ(rows, cols);
	
	//initialise ret = this:
	IntMatrix ret = IntMatrix(cols, rows, matrix);
	if (p==0)
		return getIdentityMatrix(rows,cols);
	if (p==1) //do nothing
		return ret;
	if (p%2==0){
		ret = ret.multiply(ret);
		ret = ret.expBySqr(p/2);
	}else{ // p%2 == 1
		ret = ret.multiply(expBySqr(p-1));
	}
	return ret;
}

void IntMatrix::print(){
	for (unsigned int i=0; i<rows; i++){
		for (unsigned int j=0; j<cols; j++){
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// "Constructor" for a identity matrix
IntMatrix getIdentityMatrix(unsigned int r, unsigned int c);
