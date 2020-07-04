#include "pch.h"
#include "Matrix.h"
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


template<class T>
inline Matrix<T>::Matrix(size_t rows, size_t cols)
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
		data = vector<T>(rows*cols, 0);
	}
}

template<class T>
inline Matrix<T>::Matrix(size_t rows, size_t cols, std::vector<T> data)
{
	if (data.size() != rows * cols) {
		cout << "rows*cols != data.size()" << endl;
		exit(0);
	}
	if (rows == 0 || cols == 0 || rows > 30 || cols > 30) {
		cout << "\"rows\" and \"cols\" must be more than 0" << endl;
		exit(0);
	}
	this->rows = rows;
	this->cols = cols;
	this->data = data;
}


template<class T>
inline T & Matrix<T>::operator()(size_t i, size_t j)
{
	if (i >= 0 && i < rows && j >= 0 && j < rows) {
		return data.at(i*cols + j);
	}
	else {
		cout << "Out of bounds " << endl;
		exit(0);
	}
}

template<class T>
inline T Matrix<T>::operator()(size_t i, size_t j) const
{
	if (i >= 0 && i < rows && j >= 0 && j < rows) {
		return data.at(i*cols + j);
	}
	else {
		cout << "Out of bounds " << endl;
		exit(0);
	}
}

template<class T>
inline Matrix<T>::~Matrix()
{
}

template<class T>
inline void Matrix<T>::print(int precision)
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

