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

//returns identity matrix of size s x s
IntMatrix IntMatrix::getIdentityMatrix(uint32_t s){
	//check if dimensions > 0
	EXPECT_GT(s,0);
	EXPECT_GT(s,0);
	
	IntMatrix ret = IntMatrix(s,s);
	
	//set diagonal entries [i][i]=1
	for (uint32_t i=0; i<s; i++)
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
		return getIdentityMatrix(rows);
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

//computes the p-th power of THIS
//second implementation using only constant memory
IntMatrix IntMatrix::expBySqr2(unsigned int p){
	//check if matrix is square
	EXPECT_EQ(rows, cols);
	
	if (p==0)
		return getIdentityMatrix(rows);
	//initialise ret = this:
	IntMatrix ret = IntMatrix(cols, rows, matrix);
	IntMatrix rest_odd = getIdentityMatrix(rows);
	while (p>1)
	{
		if(p%2==0){
			p /= 2;
			ret = ret.multiply(ret);
		}else{ // p%2 == 1
			p = (p-1)/2;
			rest_odd = rest_odd.multiply(ret);
			ret = ret.multiply(ret);
		}
	}
	// now p==1
	ret = ret.multiply(rest_odd);
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

//relational operators:
// equality: checks if lhs and rhs are of the same size, returns falso if not
// else checks if every entry in lhs is equal to the corresponding entry in rhs
bool operator==(IntMatrix& lhs, IntMatrix& rhs){
	if (lhs.get_rows() != rhs.get_rows() || lhs.get_cols() != rhs.get_cols()) return false;
	else{
		for (unsigned int i=0; i<lhs.get_rows(); i++)
			for (unsigned int j=0; j<lhs.get_cols(); j++)
				if (lhs.get_elementAt(i,j) != rhs.get_elementAt(i,j)) return false;
	}
	return true;
}
