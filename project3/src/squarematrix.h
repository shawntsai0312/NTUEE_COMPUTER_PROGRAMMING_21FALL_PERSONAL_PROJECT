#ifndef _SQUAREMATRIX_H_
#define _SQUAREMATRIX_H_
#include "matrix.h"
#include <vector>
using namespace std;
class SquareMatrix : public Matrix
{
	friend double Det(vector<vector<double> >);

public:
	// constructor and setup
	SquareMatrix() {}
	SquareMatrix(int);
	SquareMatrix(Matrix);
	void setup(); // setup

	// function for printing information
	void printDeterminant(); // print det(B)
	void printAdjugate();	 // print adj(B)
	void printInverse();	 // print B^(-1)
	//		void printCharPoly();

	// function for getting information
	double getDet();

private:
	double det;	   // determinant:det(B)
	void setDet(); // set det(B)

	SquareMatrix *adjugate; // adjugate:adj(B)
	void setAdjugate();		// set adj(B)

	SquareMatrix *inverse; // B^(-1)
	void setInverse();	   // set B^(-1)

	//		vector <double> CharPoly;	//characteristic polynomial f(x)
	//		void setCharPoly();			//set f(x)
};
#endif
