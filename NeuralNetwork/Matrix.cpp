#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

//Matrix::Matrix(size_t rows, size_t cols)
//{
//	try {
//		if (rows < 1) { throw 1; }
//		if (cols < 1) { throw 2; }
//		this->rows = rows;
//		this->cols = cols;
//		data = vector<double>(rows*cols, 0.0);
//	}
//	catch (int n) 
//	{
//		cout << "\"rows\" and \"cols\" must be more than 0" << endl;
//		exit(0);
//	}
//	catch (exception& e) {
//		cout << "exception in Matrix(size_t rows, size_t cols) constructor" << endl;
//		exit(0);
//		//abort();
//	}
//}

Matrix::Matrix(size_t rows, size_t cols)
{
	//cout << "rows: " << rows << "columns: " << cols << endl;
	if (rows == 0 || cols == 1 || rows > 30 || cols > 30) 
	{ 
		cout << "Nonpositive amount of rows or/and columns" << endl;
		exit(0);
	}
	else {
		this->rows = rows;
		this->cols = cols;
		data = vector<double>(rows*cols, 0.0);
	}
}

Matrix::Matrix(size_t rows, size_t cols, std::vector<double> data)
{

	if (data.size() != rows * cols) {
		cout << "rows*cols != data.size()" << endl;
		exit(0);
	}
	if (rows == 0 || cols == 1 || rows > 30 || cols > 30) {
		cout << "\"rows\" and \"cols\" must be more than 0" << endl;
		exit(0);
	}
	this->rows = rows;
	this->cols = cols;
	this->data = data;
}

double & Matrix::operator()(size_t i=0, size_t j=0)
{
	if (i >= 0 && i < rows && j >= 0 && j < rows) {
		return data.at(i*cols + j);
	}
	else {
		cout << "Out of bounds " << endl;
		exit(0);
	}
}

double Matrix::operator()(size_t i, size_t j) const
{
	if (i >= 0 && i < rows && j >= 0 && j < rows) {
		return data.at(i*cols + j);
	}
	else {
		cout << "Out of bounds " << endl;
		exit(0);
	}
}


Matrix::~Matrix()
{
}

void Matrix::print(int precision)
{
	try {
		for (int i = 0; i < (int)rows; i++) {
			for (int j = 0; j < (int)cols; j++) {
				cout << setw(precision) << data.at(i*cols + j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}
