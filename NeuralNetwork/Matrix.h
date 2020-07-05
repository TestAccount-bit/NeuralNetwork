#pragma once

#include <vector>
template<class T>
class Matrix
{
public:
	inline Matrix<T>(size_t rows, size_t cols);
	inline Matrix<T>(size_t rows, size_t cols, std::vector<T> data);
	inline ~Matrix();

	inline T&  operator()(size_t i, size_t j);
	inline T   operator()(size_t i, size_t j) const;

	Matrix<T>& operator= (Matrix<T> m);
	Matrix<T>  operator= (Matrix<T> m) const;

	Matrix<T>& operator+=(Matrix<T> m);
	Matrix<T>  operator+=(Matrix<T> m) const;
	Matrix<T>& operator+ (Matrix<T> m);
	Matrix<T>  operator+ (Matrix<T> m) const;

	Matrix<T>& operator-=(Matrix<T> m);
	Matrix<T>  operator-=(Matrix<T> m) const;
	Matrix<T>& operator- (Matrix<T> m);
	Matrix<T>  operator- (Matrix<T> m) const;

	Matrix<T>& operator*=(Matrix<T> m);
	Matrix<T>  operator*=(Matrix<T> m) const;
	Matrix<T>& operator* (Matrix<T> m);
	Matrix<T>  operator* (Matrix<T> m) const;

	Matrix<T>& operator*=(T num);
	Matrix<T>  operator*=(T num) const;
	Matrix<T>& operator* (T num);
	Matrix<T>  operator* (T num) const;

	Matrix<T> transpose();
	inline void print(int precision=3);
	
private:
	size_t rows;
	size_t cols;
	std::vector<T> data;
};

