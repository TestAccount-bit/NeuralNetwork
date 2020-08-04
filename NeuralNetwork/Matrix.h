#pragma once

#include <vector>
template<class T>
class Matrix
{
public:
	inline Matrix<T>(size_t rows, size_t cols);
	inline Matrix<T>(size_t rows, size_t cols, std::vector<T> data);
	inline ~Matrix();

	size_t getRows();
	size_t getCols();

	inline T&  operator()(size_t i, size_t j);
	inline T   operator()(size_t i, size_t j) const;

	Matrix<T>& operator= (Matrix<T> m);
	Matrix<T>  operator= (Matrix<T> m) const;

	Matrix<T>& operator+=(Matrix<T> m);
	Matrix<T>  operator+=(Matrix<T> m) const;

	Matrix<T>& operator-=(Matrix<T> m);
	Matrix<T>  operator-=(Matrix<T> m) const;

	Matrix<T>& operator*=(Matrix<T> m);
	Matrix<T>  operator*=(Matrix<T> m) const;

	Matrix<T>& operator*=(T num);
	Matrix<T>  operator*=(T num) const;


	Matrix<T> hadamard (Matrix<T> m1, Matrix<T> m2);
	Matrix<T> kronecker(Matrix<T> m1, Matrix<T> m2);
	Matrix<T> concatOf (Matrix<T> m1, Matrix<T> m2);
	Matrix<T> transpose();
	void print(int width=7, int precision=4);
	

private:
	size_t rows;
	size_t cols;
	std::vector<T> data;
};

