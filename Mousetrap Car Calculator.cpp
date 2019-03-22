// Mousetrap Car Simulator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	double
		arm_length,
		axel_dia,
		pulley_dia,
		drive_wheel_dia,
		ineffencicy_factor;

	double
		string_length,
		mid_axel_rot,
		drive_axel_rot,
		mid_gr,
		drive_gr,
		total_gr,
		drive_wheel_cir,
		distance;


	char y_or_n;

	cout << "Mousetrap Car Calculator\n\"Building A Better Mousetrap( Car) since Version 1.0\"\n\n";

	cout << "\nInput mousetrap arm length:  ";
	cin >> arm_length;

	cout << "\nInput axel diameter:  ";
	cin >> axel_dia;

	cout << "\nInput drive wheel diameter:  ";
	cin >> drive_wheel_dia;

	cout << "\nInput ineffencicy factor:  ";
	cin >> ineffencicy_factor;

	cout << "\nDoes your design feature a pulley gear? (y/n):  ";
	cin >> y_or_n;
	switch (y_or_n)
	{
		case 'y': case 'Y':
		{
			cout << "\nInput diameter of pulley gear:  ";
			cin >> pulley_dia;

			cout << "\nMousetrap arm length is " << arm_length << " units";

			string_length = arm_length * 2;
			cout << "\nLength of functional string is " << string_length << " units";

			cout << "\nDiameter of the pulley wheel is " << pulley_dia << " units";

			mid_axel_rot = string_length / axel_dia;
			cout << "\nThe pulley axel will rotate " << mid_axel_rot << " times";

			mid_gr = pulley_dia / axel_dia;
			cout << "\nThe gear ratio for the pulley wheel is " << mid_gr << ":1";

			drive_axel_rot = mid_gr * mid_axel_rot;
			cout << "\nThe drive axel will rotate " << drive_axel_rot << " times";

			drive_gr = drive_wheel_dia / axel_dia;
			cout << "\nThe gear ratio for the drive wheel is " << drive_gr << ":1";

			total_gr = drive_gr * mid_gr;
			cout << "\nThe total gear ratio is " << total_gr << ":1";

			drive_wheel_cir = drive_wheel_dia * 3.14159;
			cout << "\nThe circumference of the drive wheel is " << drive_wheel_cir << " units";

			distance = drive_wheel_cir * drive_axel_rot;
			cout << "\nThe estimated distance without ineffencicy is " << distance << " units";
			cout << "\nThat divided by 12 is " << distance / 12;

			cout << "\nThe estimated distance WITH ineffencicy is " << distance * ((100 - ineffencicy_factor) / 100) << " units";
			cout << "\nThat divided by 12 is " << (distance * ((100 - ineffencicy_factor) / 100)) / 12;
			break;
		}
	

		case 'n': case 'N':
		{
			cout << "\nMousetrap arm length is " << arm_length << " units";

			string_length = arm_length * 2;
			cout << "\nLength of functional string is " << string_length << " units";

			drive_axel_rot = string_length / axel_dia;
			cout << "\nThe drive axel will rotate " << drive_axel_rot << " times";

			drive_gr = drive_wheel_dia / axel_dia;
			cout << "\nThe gear ratio for the drive wheel is " << drive_gr << ":1";

			drive_wheel_cir = drive_wheel_dia * 3.14159;
			cout << "\nThe circumference of the drive wheel is" << drive_wheel_cir << " units";
	
			distance = drive_wheel_cir * drive_axel_rot;
			cout << "\nThe estimated distance without ineffencicy is " << distance << " units";
			cout << "\nThat divided by 12 is " << distance / 12;

			cout << "\nThe estimated distance WITH ineffencicy is " << distance * ((100 - ineffencicy_factor) / 100) << " units";
			cout << "\nThat divided by 12 is " << (distance * ((100 - ineffencicy_factor) / 100)) / 12;
			break;
		}
		default:
		{
			cout << "\n!!INVALID INPUT!!";
			main();
		}
	}
	cout << "\nDo you need another calculation? (y/n):  ";
	cin >> y_or_n;
	switch (y_or_n)
	{
		case 'y': case 'Y':
		{
			main();
		}
		case 'n': case 'N':
		{
			return(0);
		}
	}
}