#include <vector>
#include <iostream>
#include "Matrix.h"
#include "pch.h"
#include "myMath.h"
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

Matrix<int> vec_to_mat(std::vector<int> v){
	Matrix<int> m(v.size(), maxVec(v));
	for (int i = 0; i < v.size(); i++) {
		m(i, v.at(i) - 1) = 1;
	}
	return m;
}