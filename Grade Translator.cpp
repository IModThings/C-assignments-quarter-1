

//Grade Translator

//A simple tool to convert either a ratio or a percent into a letter grade
//version 1.0
//date: 1/10/19
//author James Lee

#include "pch.h"
#include <iostream>
#include <string> //add string libraries to program
using namespace std;//prevent me having to always add std: to cout/cin

	int main ()//main (and only) function
	{
	int mode;//intialize variables
	double total_q, right_q, grade_percent;
	string student_name;//ohhhh a fancy new variable
	//-----------------------------------------------------------------------------------------------------------------
		cout << "   _____               _        _______                  _       _              \n  / ____|             | |      |__   __|                | |     | |             \n | |  __ _ __ __ _  __| | ___     | |_ __ __ _ _ __  ___| | __ _| |_ ___  _ __  \n | | |_ | \'__/ _` |/ _` |/ _ \\    | | \'__/ _` | \'_ \\/ __| |/ _` | __/ _ \\| \'__| \n | |__| | | | (_| | (_| |  __/    | | | | (_| | | | \\__ \\ | (_| | || (_) | |    \n  \\_____|_|  \\__,_|\__,__|\\___|    |_|_|  \\__,_|_| |_|___/_|\\__,_|\\__\\___/|_|    \nGrade Translator Version 1.0 \n";
		cout << "Enter Student Name \n";
		getline(cin, student_name);//Determine student name
		if (student_name.compare("James Lee") == 0)//extra lines I added in. [DELETABLE]
		{//[DELETABLE]
			cout << "Student Name: James Lee\n100% correct\nLetter Grade Is A plus additional points for lame joke\n";//[DELETABLE]
			main();//[DELETABLE]
			return(0);//[DELETABLE]
		}//[DELETABLE]
		else//[DELETABLE]
		{//[DELETABLE]
			cout << "Select Mode\n(1.) Ratio to Grade\n(2.) Percent to Grade\n";//Mode selector for different gradeing options!!!
			cin >> mode;
				if (mode == 1)//check if mode is 1
				{
					cout << "Please enter total number of questions\n";
					cin >> total_q;
					cout << "Please enter number of correct questions \n";
					cin >> right_q;
					cout << "Total  Questions : Correct Questions \n" << total_q << " : " << right_q << "\n";
					grade_percent = (right_q / total_q) * 100;//convert ratio to percent score
						if (grade_percent >= 90)//check score level
						{
							cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";//output score
							cout << "Letter Grade = A\n\n\n";//3 new lines because I thought it made the UI easer to read
							main();//go back to main
							return(0);//...reset stuff?? not really sure what this is for but its blue and I like blue so thats a good enough reson for me...
						}
						else if (grade_percent >= 80)
						{
							cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
							cout << "Letter Grade = B\n\n\n";
							main();
							return(0);
						}
						else if (grade_percent >= 70)
						{
							cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
							cout << "Letter Grade = C\n\n\n";
							main();
							return(0);
						}
						else if (grade_percent >= 60)
						{
							cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
							cout << "Letter Grade = D\n\n\n";
							main();
							return(0);
						}
						else
						{
							cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
							cout << "Letter Grade = F\n\n\n";
							main();
							return(0);
						}
					
				}
				else if (mode == 2)//check if mode is 2
				{
					cout << "Please Enter Percent Score\n";//just like mode 1 except I can skip the ratio bit if I already know the percent
					cin >> grade_percent;
					if (grade_percent >= 90)
					{
						cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
						cout << "Letter Grade = A\n\n\n";
						main();
						return(0);
					}
					else if (grade_percent >= 80)
					{
						cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
						cout << "Letter Grade = B\n\n\n";
						main();
						return(0);
					}
					else if (grade_percent >= 70)
					{
						cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
						cout << "Letter Grade = C\n\n\n";
						main();
						return(0);
					}
					else if (grade_percent >= 60)
					{
						cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
						cout << "Letter Grade = D\n\n\n";
						main();
						return(0);
					}
					else
					{
						cout << "Student Name:" << student_name << "\n" << grade_percent << "% Correct \n";
						cout << "Letter Grade = F\n\n\n";
						main();
						return(0);
					}

				}
		}//[DELETABLE]
}