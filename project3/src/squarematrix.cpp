#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "matrix.h"
#include "squarematrix.h"
using namespace std;
SquareMatrix::SquareMatrix(int size)
{
	cout << "input the square matrix" << endl;
	for (int i = 0; i < size; i++)
	{
		vector<double> temp;
		for (int j = 0; j < size; j++)
		{
			double c;
			cin >> c;
			temp.push_back(c);
		}
		data.push_back(temp);
	}
}

SquareMatrix::SquareMatrix(Matrix A)
{
	if (A.getColumn() == A.getRow())
	{
		data = A.getData();
	}
	else
	{
		cout << "error";
	}
}

void SquareMatrix::setup()
{
	cout << "input n in order to construct a n*n square matrix" << endl;
	int size;
	cin >> size;
	cout << "input the matrix" << endl;
	for (int i = 0; i < size; i++)
	{
		vector<double> temp;
		for (int j = 0; j < size; j++)
		{
			double a;
			cin >> a;
			temp.push_back(a);
		}
		data.push_back(temp);
	}
}

double Det(vector<vector<double> > input)
{
	int n = input.size();
	double output = 0;
	if (n == 1)
	{
		return input[0][0];
	}
	else if (n == 2)
	{
		return input[0][0] * input[1][1] - input[0][1] * input[1][0];
	}
	else
	{
		for (int k = 0; k < n; k++)
		{
			vector<vector<double> > next;
			for (int i = 0; i < n; i++)
			{
				if (i != k)
				{
					vector<double> tmp;
					for (int j = 1; j < n; j++)
					{
						tmp.push_back(input[i][j]);
					}
					next.push_back(tmp);
				}
			}
			if (k % 2 == 0)
			{
				output += input[k][0] * Det(next);
			}
			else
			{
				output -= input[k][0] * Det(next);
			}
		}
		return output;
	}
}

void SquareMatrix::setDet()
{
	det = Det(data);
}

void SquareMatrix::printDeterminant()
{
	setDet();
	cout << "determinant = " << det << endl;
}

void SquareMatrix::setAdjugate()
{
	SquareMatrix *C = new SquareMatrix;
	for (int i = 0; i < getRow(); i++)
	{
		vector<double> c_temp;
		for (int j = 0; j < getRow(); j++)
		{
			vector<vector<double> > next;
			for (int p = 0; p < getRow(); p++)
			{
				if (p != i)
				{
					vector<double> tmp;
					for (int q = 0; q < getRow(); q++)
					{
						if (q != j)
						{
							tmp.push_back(data[p][q]);
						}
					}
					next.push_back(tmp);
				}
			}
			if ((i + j) % 2 == 0)
			{
				c_temp.push_back(Det(next));
			}
			else
			{
				c_temp.push_back(-Det(next));
			}
		}
		C->data.push_back(c_temp);
	}
	C->setTrans();
	adjugate = (SquareMatrix *)(C->trans);
}

void SquareMatrix::printAdjugate()
{
	setAdjugate();
	cout << "adjugate" << endl;
	adjugate->print();
}

void SquareMatrix::setInverse()
{
	setDet();
	setAdjugate();
	if (det != 0)
	{
		SquareMatrix *temp = new SquareMatrix;
		temp = adjugate;
		for (int i = 0; i < getRow(); i++)
		{
			for (int j = 0; j < getRow(); j++)
			{
				temp->data[i][j] /= det;
			}
		}
		inverse = temp;
	}
}

void SquareMatrix::printInverse()
{
	setInverse();
	if (det != 0)
	{
		cout << "inverse" << endl;
		inverse->print();
	}
	else
	{
		cout << "inverse does not exist" << endl;
	}
}

double SquareMatrix::getDet()
{
	setDet();
	return det;
}
