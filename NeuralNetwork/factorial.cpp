#include "pch.h"

int factorial(int a)
{
	int temp = 1;
	for (int i = 1; i <= a; i++)
	{
		temp *= i;
	}
	return temp;
}