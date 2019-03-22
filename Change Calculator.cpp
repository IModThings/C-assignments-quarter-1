// Change Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int N_Quar, N_Dime, N_Nick, N_Penn;
	int N_Total;
	cout << "Please enter number of Quarters\n";
		cin >> N_Quar;
	cout << "Please enter number of Dimes\n";
		cin >> N_Dime;
	cout << "Please enter number of Nickels\n";
		cin >> N_Nick;
	cout << "Please enter number of Pennies\n";
		cin >> N_Penn;

	cout << "You entered:\n" << N_Quar << " Quarters\n" << N_Dime << " Dimes\n" << N_Nick << " Nickels\n" << N_Penn << " Pennies\n";
	cout << "The Total Amount of Change is:" << (N_Quar * 25) + (N_Dime * 10) + (N_Nick * 5) + (N_Penn);
	return 0;
}
