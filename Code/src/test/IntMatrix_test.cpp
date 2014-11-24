#include "../../include/IntMatrix.h"

#include <gtest/gtest.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv){
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}

//Construct a non-zero, non-identity matrix:
IntMatrix constructMatrix(){
	vector<vector<int> > a = vector<vector<int> >(3,vector<int>(3,0));
	int k=0;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			a[i][j] = ++k;
	return IntMatrix(3,3,a);
}

// TESTS:

TEST(IntMatrix, Test_ctors)
{
	IntMatrix mat_a = IntMatrix(2,2);
	IntMatrix mat_b = IntMatrix(2,3);
	IntMatrix mat_c = IntMatrix(3,2);
	IntMatrix mat_d = constructMatrix();
	
	mat_a.print();
	mat_b.print();
	mat_c.print();
	mat_d.print();
}

TEST(IntMatrix, Test_getElement)
{
	IntMatrix mat = constructMatrix();
	EXPECT_EQ(mat.get_elementAt(0,0),1);
	EXPECT_EQ(mat.get_elementAt(0,2),3);
	EXPECT_EQ(mat.get_elementAt(1,1),5);
	EXPECT_EQ(mat.get_elementAt(2,0),7);
	
}

TEST(IntMatrix, Test_eq)
{
	vector<vector<int> > a = vector<vector<int> >(3,vector<int>(3,5));
	vector<vector<int> > a2 = vector<vector<int> >(3,vector<int>(3,5));
	vector<vector<int> > b = vector<vector<int> >(3,vector<int>(4,5));
	vector<vector<int> > b2 = vector<vector<int> >(3,vector<int>(4,6));
	vector<vector<int> > c = vector<vector<int> >(4,vector<int>(3,6));
	
	IntMatrix mat_a = IntMatrix(3,3,a);
	IntMatrix mat_a2 = IntMatrix(3,3,a2);
	IntMatrix mat_b = IntMatrix(3,4,b);
	IntMatrix mat_b2 = IntMatrix(3,4,b2);
	IntMatrix mat_c = IntMatrix(4,3,c);
	
	EXPECT_TRUE(mat_a == mat_a2);
	EXPECT_FALSE(mat_a == mat_b);
	EXPECT_FALSE(mat_b == mat_b2);
	EXPECT_FALSE(mat_b2 == mat_c);
}

TEST(IntMatrix, Test_getIdentity)
{
	IntMatrix mat_id_1 = IntMatrix(3,3);
	IntMatrix mat_id_2 = mat_id_1.getIdentityMatrix(2);
	
	mat_id_1.print();
	mat_id_2.print();
}

TEST(IntMatrix, Test_scale)
{
	// scale a matrix by factor 5
	IntMatrix mat_a = constructMatrix();
	mat_a.scale(5);
	
	// construct the same matrix manually:
	vector<vector<int> > b = vector<vector<int> >(3,vector<int>(3,0));
	int k=5;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++){
			b[i][j] +=k;
			k += 5;
		}
	IntMatrix mat_b = IntMatrix(3,3,b);
	
	EXPECT_TRUE(mat_a == mat_b);
	mat_a.print();
	mat_b.print();
}

TEST(IntMatrix, Test_multiply)
{
	// construct matrices:
	vector<vector<int> > a = vector<vector<int> >(2,vector<int>(2,0));
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	vector<vector<int> > b = vector<vector<int> >(2,vector<int>(2,0));
	b[0][0] = 4;
	b[0][1] = 3;
	b[1][0] = 2;
	b[1][1] = 1;
	IntMatrix mat_a = IntMatrix(2,2,a);
	IntMatrix mat_b = IntMatrix(2,2,b);
	//multiply:
	IntMatrix mat_ab = mat_a.multiply(mat_b);
	mat_ab.print();
	
	//construct expected solution:
	vector<vector<int> > ab = vector<vector<int> >(2,vector<int>(2,0));
	ab[0][0] = 8;
	ab[0][1] = 5;
	ab[1][0] = 20;
	ab[1][1] = 13;
	IntMatrix mat_ab_manual = IntMatrix(2,2,ab);
	EXPECT_TRUE(mat_ab == mat_ab_manual);
	
	//Test muliply with identity-matrix
	IntMatrix mat_id_2 = mat_a.getIdentityMatrix(2);
	IntMatrix mat_a_2 = mat_a.multiply(mat_id_2);
	IntMatrix mat_b_2 = mat_b.multiply(mat_id_2);
	EXPECT_TRUE(mat_a == mat_a_2);
	EXPECT_TRUE(mat_b == mat_b_2);
	
	//mutliplication of matrices of different dimensions:
	vector<vector<int> > c = vector<vector<int> >(2,vector<int>(3,0));
	c[0][0] = 1;
	c[0][1] = 2;
	c[0][2] = 5;
	c[1][0] = 3;
	c[1][1] = 4;
	c[1][2] = 6;
	vector<vector<int> > d = vector<vector<int> >(3,vector<int>(1,0));
	d[0][0] = 1;
	d[1][0] = 1;
	d[2][0] = 1;
	IntMatrix mat_c = IntMatrix(2,3,c);
	IntMatrix mat_d = IntMatrix(3,1,d);
	//multiply:
	IntMatrix mat_cd = mat_c.multiply(mat_d);
	mat_cd.print();
	
	//construct expected solution:
	vector<vector<int> > cd = vector<vector<int> >(2,vector<int>(1,0));
	cd[0][0] = 8;
	cd[1][0] = 13;
	IntMatrix mat_cd_manual = IntMatrix(2,1,cd);
	EXPECT_TRUE(mat_cd == mat_cd_manual);
}

TEST(IntMatrix, Test_expBySqr)
{
	//compute 4th power of a nonzero, nonidentity matrix and of a identity matrix
	vector<vector<int> > a = vector<vector<int> >(2,vector<int>(2,0));
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	IntMatrix mat_a = IntMatrix(2,2,a);
	IntMatrix mat_id = mat_a.getIdentityMatrix(2);
	IntMatrix mat_id_4 = mat_id.expBySqr(4);
	IntMatrix mat_a_4 = mat_a.expBySqr(4);
	
	mat_a_4.print();
	
	//construct expected solution of mat_a^4 by hand:
	vector<vector<int> > a4 = vector<vector<int> >(2,vector<int>(2,0));
	a4[0][0] = 199;
	a4[0][1] = 290;
	a4[1][0] = 435;
	a4[1][1] = 634;
	IntMatrix mat_a4 = IntMatrix(2,2,a4);
	
	EXPECT_TRUE(mat_id == mat_id_4);
}

TEST(IntMatrix, Test_expBySqr2)
{
	//exponentiate random matrices:
	vector<vector<int> > a;
	//initialise pseudo-random-generator => reproduzible
	srand(0);
	
	// test 10 pseudo-random cases:
	for (int j=0; j<10; j++)
	{
		a = vector<vector<int> >(2,vector<int>(2,0));
		a[0][0] = rand()%10;
		a[0][1] = rand()%10;
		a[1][0] = rand()%10;
		a[1][1] = rand()%10;
		
		IntMatrix mat_a = IntMatrix(2,2,a);
		
		for (int i=0; i<10; i++)
		{
			// compute mat_a^i with expBySqr and expBySqr2 and compare results
			IntMatrix mat_ai1 = mat_a.expBySqr(i);
			mat_ai1.print();
			IntMatrix mat_ai2 = mat_a.expBySqr2(i);
			mat_ai2.print();
			EXPECT_TRUE(mat_ai1 == mat_ai2);
		}
	}
	 
}
