// File IO assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
// James Lee
//3/3/19
// other info thats susposed to be here
//
#include "pch.h"
#include <iostream>
#include <fstream>  
#include <string>
#include <vector>//for the vector
#include <numeric>//for accumulate 
//all libraries included
using namespace std;


int main()
{
	int smallest_value(1000000000), largest_value(-1000000000), count(0), value(0);//in sure theirs a better way to do that but this way works
	vector<double> LoN;//fancy new vector that I definitly did not use correctly
	double average;
	string line;
	ifstream fileinput("input.dat");
	ofstream fileoutput("output.dat", ios::out | ios::app);//these damn anoying things ,ios::out not needed | ios:app makes it append it to the end of the file
	if (fileinput.fail())
	{
		exit(6);
	}
	else
	{
		for (string line; getline(fileinput, line); )
		{
			count++;
			value = stoi(line);
			LoN.push_back(value);
			if (value < smallest_value) { smallest_value = value; }//determining s_v and l_v
			if (value > largest_value) { largest_value = value; }
		}
		fileinput.close();
		average = accumulate(LoN.begin(), LoN.end(), 0.0) / LoN.size();//dont fully understand this... I found it online... :D
		cout << "The full list of numbers is:\n";
		fileoutput << "The full list of numbers is:\n";
		for (int i = 0; i < LoN.size(); i++) {
			cout << LoN.at(i) << ' ';
			fileoutput << LoN.at(i) << ' ';
		}
		cout << "The number of integers is " << count << endl;
		fileoutput << "The number of integers is " << count << endl;
		cout << "The smallest value is " << smallest_value << endl;
		fileoutput << "The smallest value is " << smallest_value << endl;
		cout << "The largest value is " << largest_value << endl;
		fileoutput << "The largest value is " << largest_value << endl;
		cout << "The average is " << average << endl;
		fileoutput << "The average is " << average << endl;
		fileoutput << "\n\n\n";

		cout << "All data written to output file.\n";
		fileoutput.close();
		return(0);
	}
}
