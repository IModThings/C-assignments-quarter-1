// Ice Cream Vending Machine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//==============================================================================
#include "pch.h"
#include <iostream>
#include <string>//Needed a string to hold the selection... could have done with int and cases but im lazy
using namespace std;
//global variable initializing
const double SCOST(2.50), DCOST(3.00), NCOST(2.00);
//===============================================================================
void payment(double total_paid, double cost);//Function to handle payment
void change(double total_paid, double cost);//function to handle change
int main()
{
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	int choice;
	double total_paid(0), cost(0);
	cout << "Frozen Food Vending Machine\n\nPlease Make A Selection:\n(1.) Ice Cream Sandwhich [$2.50]\n(2.) Drumstick [$3.00]\n(3.) Nestle Crunch Ice-cream Bar [$2.00]\n";
	cin >> choice;
	switch (choice)//switch function to choose item
	{
		case (1):
			cost = SCOST;
			payment(total_paid, cost);
			return(0);
		case (2):
			cost = DCOST;
			payment(total_paid, cost);
			return(0);
		case (3):
			cost = NCOST;
			payment(total_paid, cost);
			return (0);
		default:
			cout << "INVALID INPUT!";//ensures input matches options
			return(0);
			
	}
	return(0);
}
void payment(double total_paid, double cost)//separate function for payment
{
	//variables initialized
	char input;
	//================================================================
	cout << "Please Insert $" << cost << "\nOne Dollar Bills, Quarters, Dimes, and Nickels Are Accepted\nPlease Enter D for dollars, q for quarter, d for dimes, and n for nickels\n";
	total_paid = 0;
	while (cost > total_paid && cost != total_paid)
	{
		cin >> input;
		if (input == 'D')//had I thought this out better I would have used cases here instead...
		{
			total_paid = total_paid + 1;
			cout << "Please insert $" << cost - total_paid << "\n";
		}
		else if (input == 'q')
		{
			total_paid = total_paid + 0.25;
			cout << "Please insert $" << cost - total_paid << "\n";
		}
		else if (input == 'd')
		{
			total_paid = total_paid + 0.1;
			cout << "Please insert $" << cost - total_paid << "\n";
		}
		else if (input == 'n')
		{
			total_paid = total_paid + 0.05;
			cout << "Please insert $" << cost - total_paid << "\n";
		}
		else
		{
			cout << "INVALID INPUT!\n";//other verification
		}
	}
	cout << "Thank You For Using This Machine\n\nYour Change Is $";
	change(total_paid, cost);
	return;
}
void change(double total_paid, double cost)
{
	cout << total_paid - cost << " Have a good day!";
	exit;
}
