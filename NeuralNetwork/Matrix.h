#pragma once

#include <vector>
template<class T>
class Matrix
{
public:
	inline Matrix<T>(size_t rows, size_t cols);
	inline Matrix<T>(size_t rows, size_t cols, std::vector<T> data);
	inline T& operator()(size_t i, size_t j);
	inline T operator()(size_t i, size_t j) const;

	inline ~Matrix();
	inline void print(int precision=3);
	std::vector<T> data;
private:
	size_t rows;
	size_t cols;
	
};

