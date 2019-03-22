// Calculating PI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	
	cout << setiosflags(ios::fixed) << setprecision(100);
	long double pi(3), num(2), div, mult;
	int itterations(10000);
	
	while (itterations > 0)
	{
		mult = num * (num + 1) * (num + 2);
		num = num + 2;
		div = 4 / mult;
		pi = pi + div;
		cout << pi << "\n";

		mult = num * (num + 1) * (num + 2);
		num = num + 2;
		div = 4 / mult;
		pi = pi - div;

		itterations = itterations- 2;
	}
}
    

