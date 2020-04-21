/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	main CPP file for the program, entry point.
*
* References	:	- Instruction by Dr Ling Ma <ling.ma@qmul.ac.uk>
*					- Instruction by Dr Jeremy Gow <jeremy.gow@qmul.ac.uk>
*                   - B. Stroustrup: The C++ Programming Language (Fourth Edition).
*					  Addison Wesley. Reading Mass. USA. May 2013. ISBN 0-321-56384-0.
*
* Git Control	:	https://github.com/camiloblanco/CardGames/
* Author - Year	:	Camilo Blanco Vargas	-	Apr-2020
* Mail - Web	:	mail@camiloblanco.com	-	www.camiloblanco.com
****************************************************************************************/

/****************************************************************************************
*								#INCLUDES AND #CONSTANTS								*
****************************************************************************************/
#include "GuessingGame.h"
#include "VeintiunaGame.h"
/****************************************************************************************
*									APPLICATION MAIN									*
****************************************************************************************/
// Clear the whole console
void clearConsole() {
	//cout << "\x1B[2J\x1B[H"; //Linux
	system("CLS"); //Windows
}

// Pause execution waiting for a key
void menuPause() {
	cout << endl << " Press any key and then Enter to continue..." << endl;
	cin.ignore();
	cin.get();
}

// main function, entry point.
int main()
{
	//variable declaration
	int option = 9;
	//loop for menu
	while (option != 0) {
		system("CLS");
		cout << " ********************************************************************************************" << endl;
		cout << "				Card Games Main Menu								  " << endl;
		cout << " ********************************************************************************************" << endl << endl;
		cout << " Select the Game you want to play, or [0]exit:" << endl << endl;
		cout << " 1. Guess a hiden card." << endl;
		cout << " 2. Play Twenty-One." << endl;
		cout << " 0. Exit" << endl;
		cout << " Note: In the games you can type \"quit\" at any time to return to this menu." << endl;
		cout << " ********************************************************************************************" << endl;
		cout << endl << " Please enter the option number: ";
		//read the user option and evaluate
		cin >> option;
		if (option == 1 || (option == 2)) {
			//Execute the selected game polymorphically.
			Game* gamePTR;
			if (option == 1)
				gamePTR = new GuessingGame();
			else 
				gamePTR = new VeintiunaGame();
			gamePTR->newGame();
			gamePTR->playGame();
			delete gamePTR;
		}
		else if (option == 0) {
			cout << endl << " Thank you for playing, have a nice day. " << endl << endl;
			menuPause();
		}
		else {
			cout << " Invalid Option" << endl;
			menuPause();
		}
	}
	return 0;
}