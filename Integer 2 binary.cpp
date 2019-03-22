// Integer 2 binary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//james
//2/19/19
// convert from int to binary

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()// main function
{
	int convert_o_tron(int integer, int remainder, string binary);
	int integer, remainder(0);
	string binary;
	char y_n;
	cout << "Enter an integer between 1 and 1000 to convert to decimal or 0 to quit:  ";
	cin >> integer;
	if (cin && integer != 0 && integer <= 1000 && integer >= 1)
	{
		cout << "\nYou entered the integer " << integer << " is that correct? [y/n]:  ";
		cin >> y_n;
		switch (y_n)
		{
			case 'y': case 'Y':
			{
				cout << "\n";
				convert_o_tron(integer, remainder, binary);
				cout << " is the the binary value of the integer";
				cout << "\nDo you need another convertion? [y/n]:  ";
				y_n = 0;
				cin >> y_n;
				switch (y_n)
				{
				case 'y': case 'Y':
					main();

				case 'n': case 'N':
					return(1);

				default:
					cout << "\nInvalid Input\n";
					main();
				}
			}

			case 'n': case 'N':
			{
				main();
			}

			default:
			{
				cout << "\nInvalid Input\n";
				main();
			}
		}
	}
	else if (integer == 0)
	{
		return(0);
	}
	else
	{
		cout << "\nInvalid Input\n";
		main();
	}
}
int convert_o_tron(int integer, int remainder, string binary)
/*input(s) - integer
output(s) - binary
*/
{
	if (integer == 0)
	{
		reverse(binary.begin(), binary.end());
		cout << binary;
		return(0);
	}
	else
	{
		remainder = integer % 2;
		integer = integer / 2;
		binary += to_string(remainder);
		convert_o_tron(integer, remainder, binary);
	}
}