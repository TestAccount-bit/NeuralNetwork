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
	if (i >= 0 && i < this->rows && j >= 0 && j < this->rows) {
		return data.at(i*this->cols + j);
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
Matrix<T>& Matrix<T>::operator=(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols) {
		this->rows = m.rows;
		this->cols = m.cols;
		this->data = m.data;
		return *this;
	}
	cout << "Matrices of different size(1)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator=(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols) {
		this->rows = m.rows;
		this->cols = m.cols;
		this->data = m.data;
		return *this;
	}
	cout << "Matrices of different size(2)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator+=(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				(*this)(i, j) = (*this)(i, j) + m(i, j);
		//m3.print();
		return *this;
	}
	cout << "Can't add different matricies(5)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator+=(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				this(i, j) = this(i, j) + m(i, j);
		//m3.print();
		return this;
	}
	cout << "Can't add different matricies(4)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator+(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols) 
	{
		return (*this) += m;
	}
	cout << "m.rows " << m.rows << ", m.cols " << m.cols << endl;
	cout << "this->rows " << this->rows << ", this->cols " << this->cols << endl;
	cout << "Can't add different matricies(6)" << endl;
	exit(0); 
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols) 
	{
		return (*this) += m;
	}
	cout << "m.rows " << m.rows << ", m.cols " << m.cols << endl;
	cout << "this->rows " << this->rows << ", this->cols " << this->cols << endl;
	cout << "Can't add different matricies(7)" << endl;
	exit(0); 
}

template<class T>
Matrix<T>& Matrix<T>::operator-=(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				(*this)(i, j) = (*this)(i, j) - m(i, j);
		return *this;
	}
	cout << "Can't subtract different matricies(1)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator-=(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		for (int i = 0; i < m.rows; i++)
			for (int j = 0; j < m.cols; j++)
				(*this)(i, j) = (*this)(i, j) - m(i, j);
		return *this;
	}
	cout << "Can't subtract different matricies(1)" << endl;
	exit(0);
}

template<class T>
Matrix<T>& Matrix<T>::operator-(Matrix<T> m)
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		return (*this) -= m;
	}
	cout << "Can't subtract different matrices(3)" << endl;
	exit(0);
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> m) const
{
	if (m.rows == this->rows && m.cols == this->cols)
	{
		return (*this) -= m;
	}
	cout << "Can't subtract different matrices(4)" << endl;
	exit(0);
}

template<class T>
inline Matrix<T>::~Matrix()
{
	vector<T>().swap(data);
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

