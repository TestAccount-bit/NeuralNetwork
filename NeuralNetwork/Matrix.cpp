#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

Matrix::Matrix(size_t rows, size_t cols)
{
	try {
		if (rows < 1) { throw 1; }
		if (cols < 1) { throw 2; }
		this->rows = rows;
		this->cols = cols;
		data = vector<double>(rows*cols, 0.0);
	}
	catch (exception& e) {
		cout << "\"rows\" and \"cols\" must be more than 0" << endl;
		abort();
	}
}

Matrix::Matrix(size_t rows, size_t cols, std::vector<double> data)
{
	try {
		this->rows = rows;
		this->cols = cols;
		this->data = data;
	}
	catch (exception& e) {
		cout << "\"rows\" and \"cols\" must be more than 0" << endl;
		abort();
	}
}


Matrix::~Matrix()
{
}

void Matrix::print()
{
	try {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << setw(3) << data.at(i*cols + j) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}
