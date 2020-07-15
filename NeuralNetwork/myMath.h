#pragma once
#include <vector>
#include <iostream>
#include "Matrix.h"


double foo1  (double x);
double foo_d1(double x);

std::vector<int> mat_to_vec(Matrix<int> m);
int maxVec(std::vector<int> v);
Matrix<int> vec_to_mat(std::vector<int> v);


Matrix<double> activation1    (Matrix<double> m);
Matrix<double> activation_der1(Matrix<double> m);


