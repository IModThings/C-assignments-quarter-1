// CoinStar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Pseudo Code
//
//declare variables
//cout << enter the total amount of change
//cin >> total
//make sure total is between values
//q_num = total / 25
//total = remainder of div
//d_num = total /10
//total = remainder
//n_num = total / 5
//total = remainder
//P_num = total
//cout << all the values


#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int total(0), q_num(0), d_num(0), n_num(0), p_num(0);//declaring variables
	void changeMaker(int total, int& q_num, int& d_num, int& n_num, int& p_num); //declareing changeMaker function
	char y_n;
		cout << "Enter total value of change between 0 and 1000:  ";
		cin >> total;
		if (total != 0 && total <= 1000)//verifying that it is between 0 and 100 and ending program otherwise
		{
			cout << "\nYou entered " << total << ". Is that correct? (y/n):  ";
			cin >> y_n;
			switch (y_n)
			{
			case 'y': case 'Y':
			{
				changeMaker(total, q_num, d_num, n_num, p_num);
				cout << "\nThe Number Of Quarters is " << q_num
					<< "\nThe Number Of Dimes is " << d_num
					<< "\nThe Number Of Nickles is " << n_num
					<< "\nThe Number Of Pennies is " << p_num;

				cout << "\nDo you need another calculation?";
				cin >> y_n;
				switch (y_n)
				{
				case 'y': case 'Y':
					main();
					return(2);

				case 'n': case 'N': default:
					return(2);
				}
			}
			case 'n': case 'N': default://input validation
			{
				main();
				return (1);
			}
			}
		
		}
		else
		{
			cout << "\nExiting Program";
			return(1);
		}
		return(1);
}
void changeMaker(int total, int& q_num, int& d_num, int& n_num, int& p_num)//function definition
{
	q_num = total / 25;
	total = total % 25;
	d_num = total / 10;
	total = total % 10;
	n_num = total / 5;
	total = total % 5;
	p_num = total;
}
