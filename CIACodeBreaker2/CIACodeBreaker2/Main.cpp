/*File Creator: Paul Boyer
contact: pauboyer@uat.edu
CSC215 wk 3*/

/* CIA Code Breaker Simulator
New recruits are challenged to decode the random words generated.
Hints are available if needed.*/

//includes let the output to the screen.
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

//Used so that I dont have to type std:: for each line
using namespace std;

//Entry point function and all C++ starts with the main function
int main()
{

	//Title to the output
	cout << "\t\t\tWelcome Recruit to the CIA Code Breaker Simulator Training!\n\n";
	//press enter to continue.
	system("pause");

	//Provide recruit an intro to thier training to prepare them for code breaking. Include provided materials.
	cout << "\nDuring this training simulation you will be presented with 3 rounds of 10 randomly scrambled words that you";
	cout << "\nwill attempt to decode. Using only the letters and your ability to deduce information enter the correct word.";
	cout << "\nProvided to you is blank sheet of paper, a #2 pencil, and if entered you may ask the system for a hint";
	cout << "\nin order to help you decode the scrambled word. There is no time limit and you may encounter the same words";
	cout << "\nmore than once.\n\n";
	//Give the user time to process above information before continuing.
	system("pause");

	//Have user verify identity with their name, and a 3-digit code. Code can be anything. Would have it be the last 4 digits
	//of the SSN, but do not want PII for this simulation.
	cout << "\n\nBefore moving on you must verify some information so that your scores can be input into your training file\n";
	//Will store input data to memory
	string playerName;
	string badgeNumber;
	//Ask recruit for their name as they entered it on their application to enter the program.
	cout << "\nPlease verify your name as you entered it on your program application: ";
	//Will get the name stored to memory that was input by the recruit.
	cin >> playerName;
	//Ask recruit for their 3-digit badge ID. No PII!!
	cout << "\nPlease enter your 3-digit badge ID: ";
	//Will get the number stored to memory that was input by the recruit.
	cin >> badgeNumber;
	//Verify user ID.
	cout << "\n\nThank you " + playerName + " " + badgeNumber + " your identity has been verified. Please proceed when ready.\n\n";
	system("pause");

	//Provide recruit final instructions before proceeding to training.
	cout << "\n\nProvided below are final instructions prior to starting your training, take it seriously and be mindful that failure\n";
	cout << "to comply with any of the rules may result in your immediate removal from the training simulator. Repeat offenders may\n";
	cout << "be removed from the CIA Training Program permenantly.\n\n";
	cout << "Enter letters in correct spelling order and hit enter when you believe you have decoded the scrambled word.\n";
	cout << "Enter 'hint' to recieve a hint to help you decode the word.\n";
	cout << "Enter 'help' for help from the program.\n\n";
	//Display a warning to recruit to understand rules for quitting before completing the simulation.
	cout << "\t\t\t\t ***WARNING***\t\t\t\t";
	cout << "\n\nEnter 'quit' to leave the CodeBreaker Simulator";
	cout << "\n\n *** You will NOT be asked if you wish to leave the training after entering. DO NOT ENTER unless you intend to do so.";
	cout << "\nIt is highly recommended to exhaust all means of solving the scrambled words and help/hint functions. Additionally";
	cout << "\nit is highly recommended to speak with an agent before entering quit.";
	cout << "\nThere is no time limit for this simulation take your time.";
	cout << "\nProceed to begin your decoder training " + playerName + " " + badgeNumber + " and good luck!\n\n";
	//Give recruit one last minute to prepare to enter the training.
	system("pause");

	//This is the game
	bool playAgain = false;
	//this is the start of the game loop.
	do
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "\n\nThis is turn " << i + 1 << " of 3.\n\n";

			enum fields { WORD, HINT, NUM_FIELDS };
			const int NUM_WORDS = 10;
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				//List of words and hints to be randomly generated.
				{"shadow", "Cast when the sun is shining."},
				{"swing", "Can be hung from a tree or limb."},
				{"shelter", "Keeps you warm and dry during incliment weather."},
				{"dinosaur", "Went extinct about 65 million years ago."},
				{"flower", "Blooms is the spring."},
				{"badge", "Worn to gain access to certain locations."},
				{"lunch", "A meal that is had in the afternoon."},
				{"orange", "A citrusy fruit, that is also really hard to rhyme with."},
				{"popcorn", "A movie theater snack."},
				{"holiday", "December 25th or July 4th are considered these."}
			};

			srand(static_cast <unsigned int> (time(0)));
			int choice = (rand() % NUM_WORDS);
			//Word to guess
			string theWord = WORDS[choice][WORD];
			//Hint for word
			string theHint = WORDS[choice][HINT];

			//Scrambled version of the word.
			string scramble = theWord;
			int length = scramble.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = scramble[index1];
				scramble[index1] = scramble[index2];
				scramble[index2] = temp;
			}
			//Displays the scrambled word for the recurit to decode.
			cout << "\nThe scramble is: " << scramble;
			string guess;
			cout << "\n\nYour guess: ";
			cin >> guess;
			//While loop allows me to repeat this section of the code as long as the expressions stays true.
			while ((guess != theWord))
			{
				//Displays the hint stored in memory
				if (guess == "hint")
				{
					cout << "Your hint is: \n";
					cout << theHint;
				}
				//Implemented this quit function to end the program when entered rather than needing to entering quit for each round.
				else if (guess == "quit")
				{

					/*inform recruit that they have ended thier CodeBreaker Simulation before completting the required 3 rounds
				and this may result in their removal from the program */
					cout << "\nPlease gather your belongings and see the agent before exiting.";
					cout << "\nAgent will inform you about your options to continue in the CIA Code Breaker simulation";
					cout << "\nThank you " + playerName + " " + badgeNumber + " for your participation. We hope to see you back again.\n\n\n";
					return 0;
				}
				// Implemented to provide user with feedback to help them decode their word and improve their skills.
				else if (guess == "help")
				{
					cout << "\n\nYou have everything you need!! Make sure to use your hint and the provided pencil and paper to help you";
					cout << "\ndecode the scramble! If you're unable to solve the word notify the test procter and enter 'quit'";
					cout << "\nto exit the training program. Upon entering 'quit' you will not be asked if you're sure you wish to exit";
					cout << "\nand forfeit your oppertunity to complete the simulation";
				}
				//When the entry does not fit the criteria for what is stored in memory it will display this and allow the user to try again.
				else
				{
					cout << "\nSorry that's not it.Try agian.";
					
				}
				cout << "\n\nYour guess: ";
				cin >> guess;
			}
			/*If the decoded word matches the word stored in memory than the user will be able to move onto the next round or complete
			the simulator training and move onto the exit screen*/
			if (guess == theWord)
			{
				cout << "\nThat's it! You've decoded it!\n";
			}
			//This is the end of the games 3 rounds.
			// This will be the number of health points higher or lower to add/sub.
		}

		//Ask player if the wish to play again.
		cout << "\n\nPlay Again? ";
		//store players answer to memory
		string userPlayAgainChoice;
		//answer stored to memory to play again or not.
		cin >> userPlayAgainChoice;
		//evaluate the answer (is the ==)
		if (userPlayAgainChoice == "Y" or userPlayAgainChoice == "y" or userPlayAgainChoice == "yes")
		{
			//assignment single equal sign
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
		//this is the end of the game loop.
	} while (playAgain == true);
	//Final display to the recruit before closing the program.
	cout << "\n***Congratulations! " + playerName + " " + badgeNumber + " you have completed the Code Breaker Simulation.***";
	cout << "\nPlease gather all your materials and turn them into the agent before exiting.";
	cout << "\nYour class sponser will inform you and your fellow recruits of your results after all tests have been completed.";
	cout << "\nGood luck recruit and thanks for your participation.\n\n\n";
	return 0;
}