#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <vector>
using namespace std;

class Matrix
{
public:
	// constructor and setup
	Matrix() {}		  // ordinary
	Matrix(int, int); // construct with (column,row)
	void setup();	  // setup
	void modify();	  // modify print out the matrix and choose the element to reset

	// function for printing information
	void printRowSize();	// print row size ,which is n
	void printColumnSize(); // print column size ,which is m
	void printTrans();		// print A^T
	void print();			// print	the matrix

	// function for getting information
	int getRow() const;
	int getColumn() const;
	vector<vector<double> > getData() const;

	// operator
	Matrix operator+(Matrix &); // A+B
	Matrix operator-(Matrix &); // A-B
	Matrix operator*(double);	// k*A
	Matrix operator/(double);	//(1/k)*A
	Matrix operator*(Matrix &); // AB
	Matrix& operator=(const Matrix &); // A=B B assign to A
	bool operator==(Matrix &);	// A=B?

protected:
	vector<vector<double> > data; // based on 2D vector

	Matrix *trans;	 // transposition:A^T
	void setTrans(); // set A^T
};

#endif
