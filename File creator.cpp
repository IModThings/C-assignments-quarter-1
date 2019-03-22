// File creator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>  
#include <string>

using namespace std;

int main()
{
	int itterations, count(1);
	string file_name, path;
	ofstream file;
	cout << "Enter file name and path\n";
	getline(cin, file_name);
	ifstream ifile(file_name);
	if (ifile)
	{
		ifstream input(file_name);
		cout << "Enter initial number of bottles\n";
		cin >> itterations;
		ifstream myfile(file_name.c_str());
		file.open(file_name, ios::in | ios::app);
		while (itterations > 0)
		{
			file << itterations << " bottles of beer on the wall\n" << itterations << " bottles of beer\nTake one down\nPass it arround\n";
			itterations--;
			file << itterations << " bottles of beer on the wall\n\n\n";
			
			cout << count << " Complete\n";
			count++;		
		}
	}
	else
	{
		cout << "File Does Not Exist!!!\n";
		main();
	}
}
