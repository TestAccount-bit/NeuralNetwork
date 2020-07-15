#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>  

/*
#include "gnuplot_c.c"

	int n = 69;
	Point* arr;
	arr = (Point*)malloc(sizeof(Point)*n);
	for (int i = 0; i < n; i++) {
		(*(arr + i)).xVal = i - 15;
		(*(arr + i)).yVal = rand() % 10 - 5;
	}

	h_GPC_Plot *Plot2D;               

	Plot2D = gpc_init_2d_("Plot",
		"x",
		"f(x)",
		GPC_AUTOSCALE,
		0.0,
		10.0,
		-140.0,
		100.0,
		GPC_TOP);
	if (Plot2D == NULL) {
		cout << "Plot creation failure" << endl;
		exit(1);
	}

	gpc_plot_by_points(Plot2D,
		"Random function",
		n,
		arr,
		"lines",
		"#ff0000");
	gpc_graph_plot(Plot2D,
		"1/(1+exp(-x))",
		"#ff1a1a");
	gpc_graph_plot(Plot2D,
		"sin(x)",
		"rand");

	printf("\nHit <Carriage Return> to continue ....\n"); getchar();
	gpc_close(Plot2D);
*/


using namespace std;

int main()
{
	
	vector<double> vect; 
	vector<double> vect2; 
	for (int i = 0; i < 15; i++) {
		vect. push_back(rand() % 50 - 15);
	}
	for (int i = 0; i < 18; i++) {
		vect2.push_back(rand() % 50 - 15);
	}
	Matrix<double> mat (3, 5, vect);
	mat.print(5);
	Matrix<double> mat2(3, 6, vect2);
	mat2.print(5);
	Matrix<double> mat3(kroneckerR(mat, mat2), kroneckerC(mat, mat2));

	mat3.concatOf(mat, mat2);
	mat3.print();


	mat. ~Matrix();
	mat2.~Matrix();
	mat3.~Matrix();
	cout << "   " << endl;
	//cout << factorial(4)<< endl;
	return 0;
	
}



