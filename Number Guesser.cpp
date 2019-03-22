//=============================================================================================================================================
// Number Guesser
// Version 1.0
// Author(s): 
// Date:
// Changelog:
//=============================================================================================================================================
//includes and configuration
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>//This is for sleep function
using namespace std;
//=============================================================================================================================================
//Setup stage
void game()//function for the actual game
{
	int numberToGuess, numberOfGuesses, loop_num(75), guess;//variables initialized
	char choice;
	cout << "Enter Number of Guesses:\n";
	cin >> numberOfGuesses;
	cout << "Generating Random Number\n";
	srand((unsigned int)time(NULL));
	numberToGuess = rand() % 10 + 1;
	while (loop_num > 0)//This while loop is for a purely aesthetic loading bar that doesnt actually load anything
	{
		cout << "=";
		Sleep(25);
		loop_num = loop_num - 1;
	}
//=============================================================================================================================================
//Guess processing stage
	cout << "\n\nNumber Generated\nStart Guessing\n";
	while (numberOfGuesses > 0)
	{
		cin >> guess;
		if (guess == numberToGuess)
		{
			numberOfGuesses--;
			cout << "\nCongratulations You Win!\nYou Had " << numberOfGuesses << " Remaining\nPlay Again? (y/n)\n";
			cin >> choice;
			if (choice == 'y')
			{
				game();
			}
			else if (choice == 'n')
			{
				cout << "   _____                         ____                 \n  / ____|                       / __ \\                \n | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n | | |_ |/ _` | \'_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ \'__|\n | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n";
				//^^^^more ascii^^^^
				return;
			}
		}
		else if (guess < numberToGuess)
		{
			numberOfGuesses--;
			cout << "Guess Higher\nYou Have " << numberOfGuesses << " Remaining\n";

			
		}
		else if (guess > numberToGuess)
		{
			numberOfGuesses--;
			cout << "Guess Lower\nYou Have " << numberOfGuesses << " Remaining\n";
			
		}
	}
	cout << "Out Of Guesses\nPlay Again? (y/n)\n";//Restarts "game" function or ends program
	cin >> choice;
	if (choice == 'y')
	{
		game();
	}
	else if (choice == 'n')
	{
		cout << "   _____                         ____                 \n  / ____|                       / __ \\                \n | |  __  __ _ _ __ ___   ___  | |  | |_   _____ _ __ \n | | |_ |/ _` | \'_ ` _ \\ / _ \\ | |  | \\ \\ / / _ \\ \'__|\n | |__| | (_| | | | | | |  __/ | |__| |\\ V /  __/ |   \n  \\_____|\\__,_|_| |_| |_|\\___|  \\____/  \\_/ \\___|_|   \n";
		//^^^^more ascii^^^^
		return;
	}
//=============================================================================================================================================
//mostly useless main stage
}
int main()//main function that literely ONLY does title and ascii text
{
	cout << " _   _                 _                  ____                               \n| \\ | |_   _ _ __ ___ | |__   ___ _ __   / ___|_   _  ___  ___ ___  ___ _ __ \n|  \\| | | | | \'_ ` _ \\| \'_ \\ / _ \\ \'__| | |  _| | | |/ _ \\/ __/ __|/ _ \\ \'__|\n| |\\  | |_| | | | | | | |_) |  __/ |    | |_| | |_| |  __/\\__ \\__ \\  __/ |   \n|_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|     \\____|\\__,_|\\___||___/___/\\___|_|   \n";
	//^^^^^Above line is an ascii title^^^^^
	cout << "Number Guesser\nVersion 1.0\nAuthor: James Lee and PARTNERNAMEHERE\n\n";
	game();//calls the actually useful function
}
//=============================================================================================================================================
//END
