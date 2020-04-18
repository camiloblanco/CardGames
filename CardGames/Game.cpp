/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	CPP file for implementarion of the Game Class.
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

#include "Game.h"

/****************************************************************************************
*									MEMBER FUNCTIONS									*
****************************************************************************************/

//constructor
Game::Game() {
}

// Clear the whole console
void Game::clearConsole() {
	//cout << "\x1B[2J\x1B[H"; // Linux
	system("CLS"); // Windows
}

// Pause execution waiting for a key
void Game::menuPause() {
	cout << endl << " Press Enter to continue ..." << endl;
	cin.ignore();
	cin.get();
}

// Read a line from the console including spaces
void Game::readLine(string& description) {
	cin.ignore();
	getline(cin, description);
}

//Main menu for accesing the CPlusPlus programs
void Game::gameMenu() {

	int option = 9;

	while (option != 0) {
		clearConsole();
		cout << " ****************************************************************************" << endl;
		cout << "			Cards Games : The Guessing Game							  " << endl;
		cout << " ****************************************************************************" << endl << endl;
		cout << " Select an option:" << endl << endl;
		cout << " 1. Play Guess a hiden card!!!" << endl;
		cout << " 0. Return to the main menu" << endl;
		cout << " ****************************************************************************" << endl;
		cout << endl << " Please enter the option number: ";
		cin >> option;
		if (option == 1) {
			cout << "The game is loading ..." << endl;
		}
		else if (option == 0) {
			cout << endl << " Thank you for playing The Guessing Game		 " << endl << endl;
		}
		else {
			cout << " Invalid Option" << endl;
		}
		menuPause();
	}
}
