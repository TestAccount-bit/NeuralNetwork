#pragma once

#include <vector>
class Matrix
{
public:
	Matrix(size_t rows, size_t cols);
	Matrix(size_t rows, size_t cols, std::vector<double> data);
	double& operator()(size_t i, size_t j);
	double operator()(size_t i, size_t j) const;

	~Matrix();
	void print(int precision=3);
	std::vector<double> data;
private:
	size_t rows;
	size_t cols;
	
};

