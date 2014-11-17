#include <vector>

//typedef intmatrix std::vector<std::vector<int> >

class IntMatrix{
	public:
	//getter:
	unsigned int get_rows(){return rows;}
	unsigned int get_cols(){return cols;}
	int get_elementAt(unsigned int r, unsigned int c){return matrix[r][c];}
	
	//ctor for empty matrix:
	IntMatrix(unsigned int r, unsigned int c);
	//ctor for initialised matrix:
	IntMatrix(unsigned int r, unsigned int c, std::vector<std::vector<int> > data);
	
	// "Constructor" for a identity matrix
	IntMatrix getIdentityMatrix(unsigned int r, unsigned int c);
	
	// methods for scaling, multipliing and exponentiation
	void scale(int s);
	IntMatrix multiply(IntMatrix rhs);
	IntMatrix expBySqr(unsigned int power);
	
	// print matrix to screen:
	void print();
		
	private:
	unsigned int rows;
	unsigned int cols;
	
	std::vector<std::vector<int> > matrix;
};

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

bool operator!=(IntMatrix& lhs, IntMatrix& rhs){
	return !(lhs==rhs);
}

