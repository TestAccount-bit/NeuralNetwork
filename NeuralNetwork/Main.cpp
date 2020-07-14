#include "pch.h"
#include "Header.h"
#include <iostream>
#include "Matrix.cpp"


#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#include "gnuplot_c.c"


#define X_MIN		-5.0                             
#define X_MAX		5.0
#define Y_MIN		0.0
#define Y_MAX		1.0

h_GPC_Plot *h2DPlot1;                // Declare plot object


												// Declare an arry of fun colours to use
const char *plotColour[] = { "purple", "green", "blue", "black", "orange", "cyan", "violet", "grey", "magenta", "light-red" };

char graphTitle[40];


int main()
{
	std::vector<Point> gr;
	for (int i = 0; i < 50; i++) {
		Point a;
		a.xVal = i-15;
		a.yVal = rand() % 35 - 15;
		cout << i << "-th point: " << a.xVal << ", " << a.yVal << endl;
		gr.push_back(a);
	}
	int n = gr.size();
	Point* arr;
	arr = (Point*)malloc(sizeof(Point)*n);
	for (int i = 0; i < n; i++) {
		*(arr + i) = gr.at(i);
	}

	h2DPlot1 =                                  // Initialize plot
		gpc_init_2d("Data plot",               // Plot title
			"x",                    // X-Axis label
			"f(x)",               // Y-Axis label
			//20.0,                      // Scaling mode
			GPC_AUTO_SCALE,            // Scaling mode
			GPC_SIGNED,                // Sign mode
			GPC_KEY_ENABLE);           // Legend / key mode

	if (h2DPlot1 == NULL)                       // Plot creation failed - e.g is server running ?
	{
		printf("\nPlot creation failure. Please ensure gnuplot is located on your system path\n");
		exit(1);
	}

	/*
	gpc_graph_plot(h2DPlot1,		
		"1/(1+exp(-x))",       
		X_MIN,
		X_MAX,             
		Y_MIN,
		Y_MAX,          
		"#ff1a1a");
		*/
	gpc_plot_by_points(h2DPlot1,
		"Random function",
		n,
		arr,
		-15.0,
		50.0,
		-15.0,
		50.0,
		"lines",
		"#00ff00");
	printf("\nHit <Carriage Return> to continue ....\n"); getchar();
	gpc_close(h2DPlot1);
	return 0;
}



/*
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
*/


