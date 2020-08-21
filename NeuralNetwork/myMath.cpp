#include <vector>
#include <iostream>
#include <math.h>
#include "Matrix.h"
#include "pch.h"
#include "Matrix.cpp"


std::vector<int> mat_to_vec(Matrix<int> m){
	std::vector<int> v;
	for (int i = 0; i < m.getRows(); i++) {
		int j = 0;
		while (m(i, j) != 1) {
			j++;
		}
		j++;
		v.push_back(j);
	}
	return v;
}


int maxVec(std::vector<int> v){
	if (v.size() > 0) {
		int counter = v.at(0);
		for (int i = 1; i < v.size(); i++) {
			if (v.at(i) > counter) {
				counter = v.at(i);
			}
		}
		return counter;
	}
	cout << "Vector is empty" << endl;
	exit(1);
}

Matrix<int> vec_to_mat(std::vector<int> v)
{
	Matrix<int> m(v.size(), maxVec(v));
	for (int i = 0; i < v.size(); i++) {
		m(i, v.at(i) - 1) = 1;
	}
	return m;
}


Matrix<double> activation1(Matrix<double> m)
{
	Matrix<double> ret(m.getRows(), m.getCols());
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			ret(i, j) = (tanh(m(i, j)) + 1) / 2;
		}
	}
	return ret;
}

Matrix<double> activation_der1(Matrix<double> m)
{
	Matrix<double> ret(m.getRows(), m.getCols());
	for (int i = 0; i < m.getRows(); i++) {
		for (int j = 0; j < m.getCols(); j++) {
			ret(i, j) = (1 - (tanh(m(i, j)) * tanh(m(i, j)))) / 2.0;
		}
	}
	return ret;
}


double foo1(double x)
{
	return (tanh(x)+1)/2;
}



double foo_d1(double x)
{
	return (1-(tanh(x)*tanh(x)))/2.0;
}
