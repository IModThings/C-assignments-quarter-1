/* Final Exam Alternative.cpp:
Version 1.1
James Lee
3/16/19
This program takes scores from a file "Scores.dat" and outputs a revised list to "Scores Output.dat" with averages and grades appended to the list.
*/

#include "pch.h"
#include <iostream>//data streams
#include <fstream>//file io
#include <string>//First & last names
#include <iomanip>//setw

const int QUIZ_NUM = 5,//Changable Constants
LAB_NUM = 4,
MAX_STUDENT_NUM = 25;

struct student_scores {//array structure containing all input data
	std::string first_name,
		last_name;
	int quizes[20],
		labs[20],
		midterm,
		final;
}scores[MAX_STUDENT_NUM];

int main()//main function used to call other functions.
{
	int student_num = 0;
	double average;
	char grade;

	void ReadFile(struct student_scores, int& student_num);
	void OutputData(struct student_scores, int& student_num, double& average, char& grade);
	ReadFile(scores[MAX_STUDENT_NUM], student_num);
	OutputData(scores[MAX_STUDENT_NUM], student_num, average, grade);
	std::cout << "\n\nAll Data Written to Output File\nEND" << std::endl;
	return 0;

}

//Pre-Condition: None
//Post-condition: Structure Array filled with data from input file & student_num contains the number of lines in file.
void ReadFile(struct student_scores, int& student_num)
{
	std::ifstream scores_input("Scores.dat");
	if (!scores_input.fail())
	{
		while (!scores_input.eof()) {
			scores_input
				>> scores[student_num].first_name
				>> scores[student_num].last_name;
			for (int j = 0; j < QUIZ_NUM; j++)
			{
				scores_input >> scores[student_num].quizes[j];
			}
			for (int j = 0; j < LAB_NUM; j++)
			{
				scores_input >> scores[student_num].labs[j];
			}
			scores_input
				>> scores[student_num].midterm
				>> scores[student_num].final;
			student_num++;
		}
		scores_input.close();
	}
	else
	{
		std::cout << "Input File Not Found Or Corrupted!!!\nEXITING\n";
		return;
	}
}
//Pre-condition: FileRead has been run and filled the score arrays.
//Post-condition: Has run two other functions, CalculateAverage and CalculateGrade, and determined the average and grade from the score values and outputed all data to screen and output file. 
void OutputData(struct student_scores, int& student_num, double& average, char& grade)
{
	void CalculateAverage(struct student_scores, double& average);
	void CalculateGrade(struct student_scores, char& grade);
	//==========================================================================================v Screen output
	std::cout << std::setw(15) << std::left << "First Name"
		<< std::setw(15) << "Last Name"
		<< std::setw(10) << "Average"
		<< std::setw(10) << "Grade" << "\n";
	//==========================================================================================^
	std::ofstream scores_output("Scores Output.dat", std::ios::trunc);
	scores_output << std::setw(15) << std::left << "First Name"
		<< std::setw(15) << "Last Name"
		<< std::setw(QUIZ_NUM * 5) << "Quiz Scores"
		<< std::right
		<< "|"
		<< std::left
		<< std::setw(LAB_NUM * 5) << "Lab Scores"
		<< std::right
		<< "|"
		<< std::left
		<< std::setw(10) << "Midterm"
		<< "|"
		<< std::setw(7) << "Final"
		<< "|"
		<< std::setw(10) << "Average"
		<< "|"
		<< std::setw(10) << "Grade" << "\n";

	for (int i = 0; i < student_num; i++) {
		scores_output << std::setw(15) << scores[i].first_name
			<< std::setw(15) << scores[i].last_name;

		for (int j = 0; j < QUIZ_NUM; j++)
		{
			scores_output << std::setw(5) << scores[i].quizes[j];
		}
		scores_output << "|";

		for (int j = 0; j < LAB_NUM; j++)
		{
			scores_output << std::setw(5) << scores[i].labs[j];
		}
		scores_output << "|";

		scores_output << std::setw(10) << scores[i].midterm;
		scores_output << "|" << std::setw(7) << scores[i].final;
		average = i;
		CalculateAverage (scores[MAX_STUDENT_NUM], average);

		scores_output << "|" << std::setw(10) << average;

		grade = average;
		CalculateGrade (scores[MAX_STUDENT_NUM], grade);
		scores_output << "|" << std::setw(10) << grade << std::endl;
		//=============================================================================================v Screen output
		std::cout << std::setw(15) << scores[i].first_name
			<< std::setw(15) << scores[i].last_name;
		std::cout << std::setw(10) << average; 
		std::cout << std::setw(10) << grade << std::endl;
		//=============================================================================================^
	}
	scores_output.close();
}
//Pre-condition: average is set to the current student number
//Post-condition: average is the weighted average of the students scores.
void CalculateAverage(struct student_scores, double& average)
{
	int current_num;
	double quiz_scores(0), lab_scores(0);
	current_num = average;
	for (int k = 0; k < QUIZ_NUM; k++) {
		quiz_scores += scores[current_num].quizes[k];
	}
	quiz_scores = quiz_scores / QUIZ_NUM;

	for (int k = 0; k < LAB_NUM; k++) {
		lab_scores += scores[current_num].labs[k];
	}
	lab_scores = lab_scores / LAB_NUM;

	average = (quiz_scores * 0.25) + (lab_scores * 0.35) + (scores[current_num].midterm * 0.2) + (scores[current_num].final * 0.2);
	
	return;
}
//Pre-condition: grade is set to the average despite the char double thing.
//Post-condition: letter grade is determined from average.
void CalculateGrade(struct student_scores, char& grade)
{
	if (grade >= 90)//check score level
	{
		grade = 'A';
		return;
	}
	else if (grade >= 80)
	{
		grade = 'B';
		return;
	}
	else if (grade >= 70)
	{
		grade = 'C';
		return;
	}
	else if (grade >= 60)
	{
		grade = 'D';
		return;
	}
	else
	{
		grade = 'F';
		return;
	}
}
//END