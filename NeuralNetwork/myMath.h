#pragma once
#include <vector>
#include <iostream>
#include "Matrix.h"

std::vector<int> mat_to_vec(Matrix<int> m);
int maxVec(std::vector<int> v);
Matrix<int> vec_to_mat(std::vector<int> v);