#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include "matrix.h"
using namespace std;

Matrix::Matrix(int col, int row)
{
	cout << "input the matrix" << endl;
	for (int i = 0; i < col; i++)
	{
		vector<double> temp;
		for (int j = 0; j < row; j++)
		{
			double a;
			cin >> a;
			temp.push_back(a);
		}
		data.push_back(temp);
	}
}

void Matrix::setup()
{
	cout << "input m and n in order to construct a m*n matrix" << endl;
	int col, row;
	cin >> col >> row;
	cout << "input the matrix" << endl;
	for (int i = 0; i < col; i++)
	{
		vector<double> temp;
		for (int j = 0; j < row; j++)
		{
			double a;
			cin >> a;
			temp.push_back(a);
		}
		data.push_back(temp);
	}
}

void Matrix::print()
{
	for (int i = 0; i < getColumn(); i++)
	{
		for (int j = 0; j < getRow(); j++)
		{
			cout << setw(6) << fixed << setprecision(2) << data[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::printRowSize()
{
	cout << "Row = " << getRow() << endl;
}

void Matrix::printColumnSize()
{
	cout << "Column = " << getColumn() << endl;
}

void Matrix::setTrans()
{
	Matrix *B = new Matrix;
	for (int i = 0; i < getRow(); i++)
	{
		vector<double> temp;
		for (int j = 0; j < getColumn(); j++)
		{
			temp.push_back(data[j][i]);
		}
		B->data.push_back(temp);
	}
	trans = B;
}

void Matrix::printTrans()
{
	setTrans();
	cout << "transposition" << endl;
	trans->print();
}

void Matrix::modify()
{
	cout << "now" << endl;
	print();
	int i, j;
	cout << "input (i,j). (i,j) is element that needs modifying" << endl;
	cin >> i >> j;
	double alter;
	cout << "input the number you want to replace the element in (" << i << "," << j << ")" << endl;
	cin >> alter;
	data[i - 1][j - 1] = alter;
	cout << "after modifying" << endl;
	print();
}

int Matrix::getColumn() const
{
	return data.size();
}

int Matrix::getRow() const
{
	if (data.size() != 0)
	{
		return data[0].size();
	}
	else
	{
		return 0;
	}
}

vector<vector<double> > Matrix::getData() const
{
	return data;
}

Matrix Matrix::operator+(Matrix &A)
{
	if (getColumn() == A.getColumn() && getRow() == A.getRow())
	{
		Matrix *output = new Matrix;
		for (int i = 0; i < getColumn(); i++)
		{
			vector<double> tmp;
			for (int j = 0; j < getRow(); j++)
			{
				tmp.push_back(data[i][j] + A.data[i][j]);
			}
			output->data.push_back(tmp);
		}
		return *output;
	}
	else
	{
		//		cout<<"error!"<<endl;
		return *this;
	}
}

Matrix Matrix::operator-(Matrix &A)
{
	if (getColumn() == A.getColumn() && getRow() == A.getRow())
	{
		Matrix *output = new Matrix;
		for (int i = 0; i < getColumn(); i++)
		{
			vector<double> tmp;
			for (int j = 0; j < getRow(); j++)
			{
				tmp.push_back(data[i][j] - A.data[i][j]);
			}
			output->data.push_back(tmp);
		}
		return *output;
	}
	else
	{
		//		cout<<"error!"<<endl;
		return *this;
	}
}

Matrix Matrix::operator*(double k)
{
	Matrix *output = new Matrix;
	for (int i = 0; i < getColumn(); i++)
	{
		vector<double> tmp;
		for (int j = 0; j < getRow(); j++)
		{
			tmp.push_back(data[i][j] * k);
		}
		output->data.push_back(tmp);
	}
	return *output;
}

Matrix Matrix::operator/(double k)
{
	Matrix *output = new Matrix;
	for (int i = 0; i < getColumn(); i++)
	{
		vector<double> tmp;
		for (int j = 0; j < getRow(); j++)
		{
			tmp.push_back(data[i][j] / k);
		}
		output->data.push_back(tmp);
	}
	return *output;
}

Matrix Matrix::operator*(Matrix &A)
{
	if (getRow() == A.getColumn())
	{
		Matrix *output = new Matrix;
		for (int i = 0; i < getColumn(); i++)
		{
			vector<double> tmp;
			for (int j = 0; j < A.getRow(); j++)
			{
				double sub_sum = 0;
				for (int k = 0; k < getRow(); k++)
				{
					sub_sum += data[i][k] * A.getData()[k][j];
				}
				tmp.push_back(sub_sum);
			}
			output->data.push_back(tmp);
		}
		return *output;
	}
	else
	{
		cout << "error!" << endl;
		return *this;
	}
}

Matrix& Matrix::operator=(const Matrix &A)
{
    if (this != &A) // Check for self-assignment
    {
        // Clear existing data
        data.clear();
        
        // Copy data from A
        for (int i = 0; i < A.getRow(); i++)
        {
            vector<double> tmp;
            for (int j = 0; j < A.getColumn(); j++)
            {
                tmp.push_back(A.getData()[i][j]);
            }
            data.push_back(tmp);
        }
    }
    return *this;
}

bool Matrix::operator==(Matrix &A)
{
	if (getRow() != A.getRow() || getColumn() != A.getColumn())
	{
		return false;
	}
	else
	{
		bool test = true;
		for (int i = 0; i < getColumn(); i++)
		{
			for (int j = 0; j < getRow(); j++)
			{
				if (data[i][j] - A.getData()[i][j] > pow(10, -10))
				{
					return false;
				}
			}
		}
		return test;
	}
}
