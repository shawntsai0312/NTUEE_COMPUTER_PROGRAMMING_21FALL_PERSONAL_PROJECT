#include <iostream>
#include "matrix.h"
#include "squarematrix.h"
#include <iomanip>
using namespace std;

void printM(vector<Matrix> X)
{
	for (int i = 0; i < X.size(); i++)
	{
		cout << "Matrix " << i + 1 << ":" << endl;
		X[i].print();
	}
}

void printS(vector<SquareMatrix> X)
{
	for (int i = 0; i < X.size(); i++)
	{
		cout << "Square Matrix " << i + 1 << ":" << endl;
		X[i].print();
	}
}

void printInfo()
{
	cout << endl
		 << "Below are the function provided by this program" << endl
		 << " 1.enter p to print all matrices" << endl
		 << " 2.enter a to add a new matrix" << endl
		 << " 3.enter m to choose and modify a matrix" << endl
		 << " 4.enter d to delete a matrix" << endl
		 << " 5.enter + to print the addition of the two matrices" << endl
		 << " 6.enter - to print the subtraction of the two matrices" << endl
		 << " 7.enter * to print the multiplication of the two matrices or a matrix and a real number " << endl
		 << " 8.enter / to print the division of a matrix and a real number" << endl
		 << " 9.enter T to print the transpostion matrix" << endl
		 << "10.enter D to print the determinant" << endl
		 << "11.enter A to print the adjugate matrix" << endl
		 << "12.enter I to print the inverse matrix" << endl
		 << "13.enter e to end the loop" << endl
		 << endl
		 << "*************************************************************" << endl
		 << "note that m is for ordinary matrix and s is for square matrix" << endl
		 << "*************************************************************" << endl
		 << "enter somthing here :";
}

int main()
{
	char condition;
	vector<Matrix> M;
	vector<SquareMatrix> S;
	while (true)
	{
		printInfo();
		cin >> condition;
		cout << endl;
		if (condition == 'e')
			break; // end loop
		switch (condition)
		{
		case 'p':
		{
			printM(M);
			printS(S);
			if (M.size() + S.size() == 0)
				cout << "no data! add some matrix" << endl;
			break;
		}
		case 'a':
		{ // set
			cout << "enter column and row :";
			int column, row;
			cin >> column >> row;
			if (column == row)
			{
				SquareMatrix temp(row);
				S.push_back(temp);
			}
			else
			{
				Matrix temp(column, row);
				M.push_back(temp);
			}
			break;
		}
		case 'm':
		{ // modify
			printM(M);
			printS(S);
			cout << "enter type and number for the matrices :";
			char mode;
			cin >> mode;
			int x;
			cin >> x;
			if (mode == 'm')
				M[x - 1].modify();
			else if (mode == 's')
				S[x - 1].modify();
			break;
		}
		case 'd':
		{ // delete
			printM(M);
			printS(S);
			cout << "enter type and number for the matrix :";
			char mode;
			cin >> mode;
			int x;
			cin >> x;
			if (mode == 'm')
				M.erase(M.begin() + x - 1);
			else if (mode == 's')
				S.erase(S.begin() + x - 1);
			break;
		}
		case '+':
		{ // addition
			printM(M);
			printS(S);
			cout << "enter type and number for the matrices :";
			char mode;
			cin >> mode;
			int x, y;
			cin >> x >> y;
			if (mode == 'm')
			{
				if ((M[x - 1] + M[y - 1]) == M[x - 1])
				{
					cout << "error they cannot be added together" << endl;
					break;
				}
				cout << endl
					 << "answer :" << endl;
				(M[x - 1] + M[y - 1]).print();
			}
			else if (mode == 's')
			{
				if ((S[x - 1] + S[y - 1]) == S[x - 1])
				{
					cout << "error they cannot be added together" << endl;
					break;
				}
				cout << endl
					 << "answer :" << endl;
				(S[x - 1] + S[y - 1]).print();
			}
			else
				cout << "error" << endl;
			break;
		}
		case '-':
		{ // subtraction
			printM(M);
			printS(S);
			cout << "enter type and number for the matrix :";
			char mode;
			cin >> mode;
			int x, y;
			cin >> x >> y;
			if (mode == 'm')
			{
				if ((M[x - 1] - M[y - 1]) == M[x - 1])
				{
					cout << "error the first subtracted the second" << endl;
					break;
				}
				cout << endl
					 << "answer :" << endl;
				(M[x - 1] - M[y - 1]).print();
			}
			else if (mode == 's')
			{
				if ((S[x - 1] - S[y - 1]) == S[x - 1])
				{
					cout << "error the first subtracted the second" << endl;
					break;
				}
				cout << endl
					 << "answer :" << endl;
				(S[x - 1] - S[y - 1]).print();
			}
			else
				cout << "error" << endl;
			break;
		}
		case '*':
		{ // multiplication
			cout << "enter m to do matrices multiplication" << endl
				 << "enter r to do real number multiplication" << endl
				 << "your choice :";
			char choose;
			cin >> choose;
			printM(M);
			printS(S);
			if (choose == 'm')
			{
				cout << "enter type and number for the first matrix :";
				char mode1;
				cin >> mode1;
				if (mode1 == 'm')
				{
					int x;
					cin >> x;
					Matrix temp;
					temp = M[x - 1];
					int count = 0;
					for (int i = 0; i < M.size(); i++)
					{
						if (M[i].getColumn() == temp.getRow())
						{
							cout << "Matrix " << i + 1 << endl;
							M[i].print();
							count++;
						}
					}
					for (int i = 0; i < S.size(); i++)
					{
						if (S[i].getColumn() == temp.getRow())
						{
							cout << "Square Matrix " << i + 1 << endl;
							S[i].print();
							count++;
						}
					}
					if (count > 0)
					{
						cout << "above are the metrices availible for multiplication" << endl;
						cout << "enter type and number for the second matrix :";
						char mode2;
						cin >> mode2;
						int y = 0;
						cin >> y;
						y--;
						if (mode2 == 'm')
						{
							cout << endl
								 << "answer :" << endl;
							(temp * M[y]).print();
						}
						else if (mode2 == 's')
						{
							cout << endl
								 << "answer :" << endl;
							(temp * S[y]).print();
						}
						else
						{
							cout << "error" << endl;
							break;
						}
					}
					else
					{
						cout << "not found" << endl;
						break;
					}
				}
				else if (mode1 == 's')
				{
					int x;
					cin >> x;
					Matrix temp;
					temp = S[x - 1];
					int count = 0;
					for (int i = 0; i < M.size(); i++)
					{
						if (M[i].getColumn() == temp.getRow())
						{
							cout << "Matrix " << i + 1 << endl;
							M[i].print();
							count++;
						}
					}
					for (int i = 0; i < S.size(); i++)
					{
						if (S[i].getColumn() == temp.getRow())
						{
							cout << "Square Matrix " << i + 1 << endl;
							S[i].print();
							count++;
						}
					}
					if (count > 0)
					{
						cout << "above are the metrices availible for multiplication" << endl;
						cout << "enter type and number for the second matrix :";
						char mode2;
						cin >> mode2;
						int y = 0;
						cin >> y;
						y--;
						if (mode2 == 'm')
						{
							cout << endl
								 << "answer :" << endl;
							(temp * M[y]).print();
						}
						else if (mode2 == 's')
						{
							cout << endl
								 << "answer :" << endl;
							(temp * S[y]).print();
						}
						else
						{
							cout << "error" << endl;
							break;
						}
					}
					else
					{
						cout << "not found" << endl;
						break;
					}
				}
				else
					cout << "error" << endl;
			}
			else if (choose == 'r')
			{
				cout << "enter type and number for the matrix :";
				char mode;
				cin >> mode;
				int x;
				cin >> x;
				cout << "enter the real number :";
				double d;
				cin >> d;
				if (mode == 'm')
				{
					if (x - 1 >= M.size())
						cout << "not found" << endl;
					else
					{
						cout << endl
							 << "answer :" << endl;
						(M[x - 1] * d).print();
					}
				}
				else if (mode == 's')
				{
					if (x - 1 >= S.size())
						cout << "not found" << endl;
					else
					{
						cout << endl
							 << "answer :" << endl;
						(S[x - 1] * d).print();
					}
				}
				else
					cout << "error" << endl;
			}
			break;
		}
		case '/':
		{ // division
			printM(M);
			printS(S);
			cout << "enter type and number for the matrix :";
			char mode;
			cin >> mode;
			int x;
			cin >> x;
			cout << "enter the real number :";
			double d;
			cin >> d;
			if (d == 0)
			{
				cout << "you cannot divide 0" << endl;
				break;
			}
			if (mode == 'm')
			{
				if (x - 1 >= M.size())
					cout << "not found" << endl;
				else
				{
					cout << endl
						 << "answer :" << endl;
					(M[x - 1] / d).print();
				}
			}
			else if (mode == 's')
			{
				if (x - 1 >= S.size())
					cout << "not found" << endl;
				else
				{
					cout << endl
						 << "answer :" << endl;
					(S[x - 1] / d).print();
				}
			}
			else
				cout << "error" << endl;
			break;
		}
		case 'T':
		{ // print transposition
			printM(M);
			printS(S);
			cout << "enter type and number for the matrix :";
			char mode;
			cin >> mode;
			int x;
			cin >> x;
			if (mode == 'm')
			{
				if (x - 1 >= M.size())
					cout << "not found" << endl;
				else
					M[x - 1].printTrans();
			}
			else if (mode == 's')
			{
				if (x - 1 >= S.size())
					cout << "not found" << endl;
				else
					S[x - 1].printTrans();
			}
			else
				cout << "error" << endl;
			break;
		}
		case 'D':
		{
			printS(S);
			cout << "enter the number for the matrix :";
			int x;
			cin >> x;
			if (x - 1 >= S.size())
				cout << "not found" << endl;
			else
				cout << "Determinant = " << S[x - 1].getDet() << endl;
			break;
		}
		case 'A':
		{ // print adjugate
			printS(S);
			cout << "enter the number for the matrix :";
			int x;
			cin >> x;
			if (x - 1 >= S.size())
				cout << "not found" << endl;
			else
				S[x - 1].printAdjugate();
			break;
		}
		case 'I':
		{ // print inverse
			printS(S);
			cout << "enter the number for the matrix :";
			int x;
			cin >> x;
			if (x - 1 >= S.size())
				cout << "not found" << endl;
			else
				S[x - 1].printInverse();
			break;
		}
		default:
		{
			cout << "please enter again!!";
			break;
		}
		}
	}
	return 0;
}
