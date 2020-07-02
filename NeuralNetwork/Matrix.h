#pragma once

#include <vector>
class Matrix
{
public:
	Matrix(size_t rows, size_t cols);
	Matrix(size_t rows, size_t cols, std::vector<double> data);
	~Matrix();
	void print();
	std::vector<double> data;
private:
	size_t rows;
	size_t cols;
	
};

