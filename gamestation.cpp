/***********************************************************
* Author:                             Kyle Wood
* Date Created:                       2/4/14
* Last Modification Date:             2/9/14
* Filename:                           gamestation.cpp
*
* Overview:
*	This program will create a main function where the user
*	can pick from one of four options to play the number
*	guess, word guess or phrase guess game. The last option
*	is to quit. The main function will then call the function
*	corresponding to the game they chose. When the user is
*	done with a game they can then return to the main menu.
*
************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Function Declarations
void numguess();
void wordguess();
void phraseguess();

int main()
{
	int quit = 0;
	int gamechoice;

	while (quit == 0)
	{

		cout << "Welcome to the Gamestation! Please type the number of the game you wish to play or 4 to quit:" << endl << endl
			<< "1. Number Guess (2 player)" << endl
			<< "2. Word Guess (2 player)" << endl
			<< "3. Phrase Guess (1 player)" << endl
			<< "4. Quit" << endl;
		std::cin >> gamechoice;

		while (!std::cin) //This while statement ensures the program does not keep looping if the user inputs a character or some other value instead of an integer
		{
			cout << "That was not a number!!!" << endl << endl
				<< "Please type the number of the game you wish to play or 4 to quit : " << endl << endl
				<< "1. Number Guess (2 player)" << endl
				<< "2. Word Guess (2 player)" << endl
				<< "3. Phrase Guess (1 player)" << endl
				<< "4. Quit" << endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> gamechoice;
		}

		if ((gamechoice != 1) && (gamechoice != 2) && (gamechoice != 3) && (gamechoice != 4))
		{
			cout << "ERROR please choose a number between 1 and 4." << endl << endl;
			continue;
		}

		if (gamechoice == 1)
		{
			cout << endl << endl << endl;
			numguess();
		}
		if (gamechoice == 2)
		{
			cout << endl << endl << endl;
			wordguess();
		}
		if (gamechoice == 3)
		{
			cout << endl << endl << endl;
			phraseguess();
		}
		if (gamechoice == 4)
		{
			cout << endl << endl << endl;
			cout << "Come play again soon! Bye!" << endl;
			break;
		}
	}


	std::cin.get();
	std::cin.get(); // I added these two to make the executable pause before closing when I compile at home

	return 0;
}

//Function Definitions
void numguess()
{
	char game;
	game = 'Y';
	const char Y = 'Y';
	const char N = 'N';
	while ((game == 'Y') || (game == 'y'))
	{
		int number;
		cout << "Player 1 please type a number between 1 and 10" << endl;
		std::cin >> number;
		while (!std::cin)
		{
			cout << "That was not a number! Please enter a number between 1 and 10: " << endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> number;
		}
		int guesses, lowValue, highValue;
		guesses = 3;
		lowValue = 1;
		highValue = 10;

		if ((number != 1) && (number != 2) && (number != 3) && (number != 4) && (number != 5) && (number != 6) && (number != 7) && (number != 8) && (number != 9) && (number != 10))
		{
			cout << "ERROR. Please select a number between 1 and 10" << endl << endl;
			continue;
		}
		while (guesses > 0)
		{

			if ((number >= lowValue) && (number <= highValue))
			{
				int guess;
				cout << "Player 2 please guess Player 1's number (between " << lowValue << " and " << highValue << ") you have " << guesses << " tries left" << endl << endl;
				std::cin >> guess;
				while (!std::cin)
				{
					cout << "ERROR. That was not a number!!! " << endl << endl
					<< "Player 2 please guess Player 1's number (between " << lowValue << " and " << highValue << ") you have " << guesses << " tries left" << endl << endl;
					std::cin.clear();
					std::cin.ignore();
					std::cin >> number;
				}
				if ((guess < lowValue) || (guess > highValue))
				{
					cout << "ERROR. Please select a number between " << lowValue << " and " << highValue << endl << endl;
					continue;
				}
				if ((guess >= lowValue) && (guess < number))
				{
					lowValue = guess;
				}
				if ((guess < number) && (guess >= lowValue))
				{
					cout << "Sorry, your guess is less than Player 1's number" << endl << endl;
					guesses = guesses - 1;
				}
				if ((guess <= highValue) && (guess > number))
				{
					highValue = guess;
				}
				if ((guess <= highValue) && (guess > number))
				{
					cout << "Sorry, your guess is more than Player 1's number" << endl << endl;
					guesses = guesses - 1;
				}
				if (guess == number)
				{
					cout << "Congratulations! You guessed correctly! Player 2 Wins!" << endl << endl;
					break;
				}
				if (guesses <= 0)
				{
					cout << "You failed to guess correctly in time! Player 1 Wins!" << endl;
					if (guess < number)
					{
						cout << "The correct number was " << number << "! You were " << number - guess << " off!" << endl << endl;
					}
					if (guess > number)
					{
						cout << "The correct number was " << number << "! You were " << guess - number << " off!" << endl << endl;
					}
				}

			}
		}
		cout << "Would you like to play again Y/N? (N returns you to the main menu)" << endl;
		std::cin >> game;
		while (!std::cin)
		{
			cout << "That was not a letter!!!" << endl << endl
				<< "Would you like to play again Y/N? (N returns you to the main menu)" << endl << endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> game;
		}
		while ((game != 'y') && (game != 'Y') && (game != 'n') && (game != 'N'))
		{
			cout << "ERROR. Please enter a Y or an N" << endl << endl;
			cout << "Would you like to play again Y/N? (N returns you to the main menu)" << endl << endl;
			std::cin >> game;
		}
	}


	if ((game == 'N') || (game == 'n'))
	{
		cout << endl << endl;
	}
}

void wordguess()
{
	char game;
	game = 'Y';
	const char Y = 'Y';
	const char N = 'N';
	while ((game == 'Y') || (game == 'y'))
	{
		string phrase, phrasecopy;
		cout << "Player 1 please enter a 4 letter word (lowercase only)." << endl;
		std::cin >> phrase;
		phrasecopy = phrase;
		char x, guess1, guess2, guess3, guess4, guess5, guess6, guess7, guess8;
		x = '_';
		guess1 = x;
		guess2 = x;
		guess3 = x;
		guess4 = x;
		guess5 = x;
		guess6 = x;
		guess7 = x;
		guess8 = x;
		int failstate;
		failstate = 0;
		phrasecopy[0] = x;
		phrasecopy[1] = x;
		phrasecopy[2] = x;
		phrasecopy[3] = x;
		int guesses;
		guesses = 8;

		if ((phrase.length() > 4) || (phrase.length() < 4))
		{
			cout << "ERROR. Please make sure to enter a 4 letter word." << endl;
			continue;
		}

		if (phrase.find_first_not_of("abcdefghijklmnopqrstuvwxyz") != std::string::npos)
		{
			cout << "ERROR. Please make sure to use ONLY lowercase alphabetical letters." << endl;
			continue;
		}

		while (guesses > 0)
		{
			char guess, a, b, c, d;
			a = phrase[0];
			b = phrase[1];
			c = phrase[2];
			d = phrase[3];
			cout << endl << endl << "Player 2 please guess a letter (lowercase only)." << endl << "Here is what you have gotten so far:" << endl << phrasecopy[0] << " " << phrasecopy[1] << " " << phrasecopy[2] << " " << phrasecopy[3] << endl << "You have " << guesses << " tries left." << endl << "Here are the letters you have guessed so far:" << endl << guess1 << " " << guess2 << " " << guess3 << " " << guess4 << " " << guess5 << " " << guess6 << " " << guess7 << " " << guess8 << endl;
			std::cin >> guess;

			if (isalpha(guess))
			{
				cout << endl;
			}
			else
			{
				cout << "ERROR. Please enter a valid lowercase letter." << endl << endl;
				continue;
			}
			if (isupper(guess))
			{
				cout << "ERROR. Please enter a valid lowercase letter." << endl << endl;
				continue;
			}
			if ((guess == guess1) || (guess == guess2) || (guess == guess3) || (guess == guess4) || (guess == guess5) || (guess == guess6) || (guess == guess7) || (guess == guess7))
			{
				cout << "ERROR. You already guessed that letter." << endl << endl;
				continue;
			}
			if (guess == a)
			{
				phrasecopy[0] = phrase[0];
				cout << "Congrats! You guessed a correct letter!" << endl << endl;
			}
			if (guess == b)
			{
				phrasecopy[1] = phrase[1];
				cout << "Congrats! You guessed a correct letter!" << endl << endl;
			}
			if (guess == c)
			{
				phrasecopy[2] = phrase[2];
				cout << "Congrats! You guessed a correct letter!" << endl << endl;
			}
			if (guess == d)
			{
				phrasecopy[3] = phrase[3];
				cout << "Congrats! You guessed a correct letter!" << endl << endl;
			}
			if ((guess != a) && (guess != b) && (guess != c) && (guess != d))
			{
				cout << "Sorry, that was not one of the letters." << endl << endl;
			}
			if ((phrasecopy[0] == phrase[0]) && (phrasecopy[1] == phrase[1]) && (phrasecopy[2] == phrase[2]) && (phrasecopy[3] == phrase[3]))
			{
				cout << "Awesome! You got it! You guessed the word:" << endl << phrasecopy << endl << "Player 2 Wins!" << endl << endl;
				break;
			}
			if (guesses == 8)
			{
				guess1 = guess;
			}
			if (guesses == 7)
			{
				guess2 = guess;
			}
			if (guesses == 6)
			{
				guess3 = guess;
			}
			if (guesses == 5)
			{
				guess4 = guess;
			}
			if (guesses == 4)
			{
				guess5 = guess;
			}
			if (guesses == 3)
			{
				guess6 = guess;
			}
			if (guesses == 2)
			{
				guess7 = guess;
			}
			if (guesses == 1)
			{
				guess8 = guess;
			}
			if (guesses > 0)
			{
				guesses = guesses - 1;
			}
			if (guesses == 0)
			{
				cout << "Sorry, but you did not guess the word in time. Player 1 Wins!" << endl << endl;
				failstate = failstate + 1;
			}
		}
		while (failstate >= 1)
		{
			if (phrasecopy[0] != phrase[0])
			{
				cout << "Player 2, you missed the letter '" << phrase[0] << "'" << endl;
			}
			if (phrasecopy[1] != phrase[1])
			{
				cout << "Player 2, you missed the letter '" << phrase[1] << "'" << endl;
			}
			if (phrasecopy[2] != phrase[2])
			{
				cout << "Player 2, you missed the letter '" << phrase[2] << "'" << endl;
			}
			if (phrasecopy[3] != phrase[3])
			{
				cout << "Player 2, you missed the letter '" << phrase[3] << "'" << endl;
			}
			if (failstate = 1)
			{
				cout << endl << "The correct word was:" << endl << phrase << endl << endl;
				failstate = failstate - 1;
			}
		}

		cout << "Would you like to play again Y/N? (N returns you to the main menu)" << endl;
		std::cin >> game;
		while (!std::cin)
		{
			cout << "That was not a letter!!!" << endl << endl
				<< "Would you like to play again Y/N? (N returns you to the main menu)" << endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> game;
		}
		while ((game != 'y') && (game != 'Y') && (game != 'n') && (game != 'N'))
		{
			cout << "ERROR. Please enter a Y or an N" << endl << endl;
			cout << "Would you like to play again Y/N? (N returns you to the main menu)" << endl << endl;
			std::cin >> game;
		}
	}


	if ((game == 'N') || (game == 'n'))
	{
		cout << endl << endl;
	}
}

void phraseguess()
{
	char game;
	game = 'Y';
	const char Y = 'Y';
	const char N = 'N';
	int randomizer = 1; //Used to help change the srand every time the player decides to replay the game without closing the program
	while ((game == 'Y') || (game == 'y')) //Master loop used for the replay function
	{
		cout << "Welcome Player 1! Today you will be guessing a 3 word phrase word by word." << endl << endl;
		int words = 3;
		int victory = 0;
		string phrasewords[] = { "duck", "when", "were", "face", "door", "case", "huff", "blow", "back", "lisp", "felt", "pond" };
		string phrase, phrasecopy, word1, word2, word3;
		srand(time(NULL) + randomizer); //A function I found online to make the srand change every time the program is run

		word1 = phrasewords[rand() % 12];	 //Random number used to guess each of the words for each part of the phrase
		randomizer = randomizer + 1;         //Used to change the srand, if not it would keep picking the same word
		word2 = phrasewords[rand() % 12];
		randomizer = randomizer + 1;
		word3 = phrasewords[rand() % 12];
		randomizer = randomizer + 1;

		while (words > 0)
		{
			if (words == 3)
			{
				phrase = word1;
				cout << "Player 1 it is time to guess the FIRST word of the 3 word phrase." << endl;
			}
			if (words == 2)
			{
				phrase = word2;
				cout << "Player 1 it is time to guess the SECOND word of the 3 word phrase." << endl;
			}
			if (words == 1)
			{
				victory = 1;
				phrase = word3;
				cout << "Player 1 it is time to guess the THIRD AND FINAL word of the 3 word phrase." << endl;
			}
			phrasecopy = phrase;
			char x, guess1, guess2, guess3, guess4, guess5, guess6, guess7, guess8;
			x = '_';
			guess1 = x;
			guess2 = x;
			guess3 = x;
			guess4 = x;
			guess5 = x;
			guess6 = x;
			guess7 = x;
			guess8 = x;
			int failstate;
			failstate = 0;
			phrasecopy[0] = x;
			phrasecopy[1] = x;
			phrasecopy[2] = x;
			phrasecopy[3] = x;
			int guesses;
			guesses = 8;

			while (guesses > 0)
			{
				char guess, a, b, c, d; //Variables to store the letters of 'phrase' for easy use later
				a = phrase[0];
				b = phrase[1];
				c = phrase[2];
				d = phrase[3];
				cout << "Player 1 please guess a letter (lowercase only)." << endl << "Here is what you have gotten so far:" << endl << phrasecopy[0] << " " << phrasecopy[1] << " " << phrasecopy[2] << " " << phrasecopy[3] << endl << "You have " << guesses << " tries left." << endl << "Here are the letters you have guessed so far:" << endl << guess1 << " " << guess2 << " " << guess3 << " " << guess4 << " " << guess5 << " " << guess6 << " " << guess7 << " " << guess8 << endl;
				std::cin >> guess;

				if (isalpha(guess)) //Function to make sure the user input is a letter
				{
					cout << endl;
				}
				else
				{
					cout << "ERROR. Please enter a valid lowercase letter." << endl << endl;
					continue;
				}
				if (isupper(guess)) //Function to make sure the user enters a lowercase letter
				{
					cout << "ERROR. Please enter a valid lowercase letter." << endl << endl;
					continue;
				}
				if ((guess == guess1) || (guess == guess2) || (guess == guess3) || (guess == guess4) || (guess == guess5) || (guess == guess6) || (guess == guess7) || (guess == guess7)) //Used to avoid repeating previous guesses and losing turns because of it
				{
					cout << "ERROR. You already guessed that letter." << endl << endl;
					continue;
				}
				if (guess == a)
				{
					phrasecopy[0] = phrase[0];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if (guess == b)
				{
					phrasecopy[1] = phrase[1];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if (guess == c)
				{
					phrasecopy[2] = phrase[2];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if (guess == d)
				{
					phrasecopy[3] = phrase[3];
					cout << "Congrats! You guessed a correct letter!" << endl << endl;
				}
				if ((guess != a) && (guess != b) && (guess != c) && (guess != d))
				{
					cout << "Sorry, that was not one of the letters." << endl << endl;
				}
				if ((phrasecopy[0] == phrase[0]) && (phrasecopy[1] == phrase[1]) && (phrasecopy[2] == phrase[2]) && (phrasecopy[3] == phrase[3])) //Victory condition for a word (not the whole phrase though)
				{
					cout << "Awesome! You got it! You guessed the word:" << endl << phrasecopy << endl << endl;
					words = words - 1;
					break;
				}
				if (guesses == 8) //Used to store the player's guesses so the program can check and make sure they don't repeat previous guesses
				{
					guess1 = guess;
				}
				if (guesses == 7)
				{
					guess2 = guess;
				}
				if (guesses == 6)
				{
					guess3 = guess;
				}
				if (guesses == 5)
				{
					guess4 = guess;
				}
				if (guesses == 4)
				{
					guess5 = guess;
				}
				if (guesses == 3)
				{
					guess6 = guess;
				}
				if (guesses == 2)
				{
					guess7 = guess;
				}
				if (guesses == 1)
				{
					guess8 = guess;
				}
				if (guesses > 0)
				{
					guesses = guesses - 1;
				}
				if (guesses == 0)
				{
					cout << "Sorry, but you did not guess the word in time. You lose!" << endl << endl;
					failstate = failstate + 1; //Used to initiate failure sequence below
				}
			}
			if ((victory == 1) && (phrasecopy == word3))
			{
				cout << "CONGRATULATIONS!!! You guessed the 3 word phrase " << "'" << word1 << " " << word2 << " " << word3 << "'! YOU WIN!!!" << endl << endl; //Victory condition for the whole phrase
				break;
			}
			while (failstate >= 1) //Failure sequence
			{
				if (phrasecopy[0] != phrase[0])
				{
					cout << "Player 1, you missed the letter '" << phrase[0] << "'" << endl;
				}
				if (phrasecopy[1] != phrase[1])
				{
					cout << "Player 1, you missed the letter '" << phrase[1] << "'" << endl;
				}
				if (phrasecopy[2] != phrase[2])
				{
					cout << "Player 1, you missed the letter '" << phrase[2] << "'" << endl;
				}
				if (phrasecopy[3] != phrase[3])
				{
					cout << "Player 1, you missed the letter '" << phrase[3] << "'" << endl;
				}
				if (failstate = 1)
				{
					cout << endl << "The correct word was:" << endl << phrase << endl << endl;
					failstate = failstate - 1;
				}
				cout << "Too Bad! You failed to guess the 3 word phrase '" << word1 << " " << word2 << " " << word3 << "' YOU LOSE!!!" << endl << endl;
				words = 0;
			}
		}
		randomizer = randomizer + 1; //added to change the srand if the player decides to play again
		cout << "Would you like to play again Y/N? (N returns you to the main menu)" << endl;
		std::cin >> game;
		while (!std::cin)
		{
			cout << "That was not a letter!!!" << endl << endl
				<< "Would you like to play again Y/N? (N returns you to the main menu)" << endl;
			std::cin.clear();
			std::cin.ignore();
			std::cin >> game;
		}
		while ((game != 'y') && (game != 'Y') && (game != 'n') && (game != 'N'))
		{
			cout << "ERROR. Please enter a Y or an N" << endl << endl;
			cout << "Would you like to play again Y/N? (N returns you to the main menu)" << endl << endl;
			std::cin >> game;
		}
	}


	if ((game == 'N') || (game == 'n')) //Ends the main loop if player does not wish to play again
	{
		cout << endl << endl;
	}
}

struct people
{
	string name;
	int age;
	double weight;
};

void peopleInfo()
{
	people dan =
	{
		"Dan",
		24,
		150.5
	};
	people bill =
	{
		"Bill",
		65,
		180
	};
	people butch =
	{
		"Garry",
		56,
		170.5
	};
	people mary =
	{
		"Mary",
		37,
		120
	};
	people susan =
	{
		"Susan",
		19,
		119.5
	};
	struct people *pSusan;
	pSusan = &susan; // Pointer to a struct for requirement #26

	cout << dan.name << " is " << dan.age << " years old and " << dan.weight << " pounds." << endl;
	cout << bill.name << " is " << bill.age << " years old and " << bill.weight << " pounds." << endl;
	cout << butch.name << " is " << butch.age << " years old and " << butch.weight << " pounds." << endl;
	cout << mary.name << " is " << mary.age << " years old and " << mary.weight << " pounds." << endl;
	cout << susan.name << " is " << susan.age << " years old and " << susan.weight << " pounds." << endl;
}