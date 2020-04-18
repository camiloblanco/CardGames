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
#include "Game.h"

/****************************************************************************************
*									APPLICATION MAIN									*
****************************************************************************************/

int main()

{
	Game guessingGame;


	int option = 9;

	while (option != 0) {
		system("CLS");
		cout << " ****************************************************************************" << endl;
		cout << "				Card Games								  " << endl;
		cout << " ****************************************************************************" << endl << endl;
		cout << " Select the Game you want to play, or exit.:" << endl << endl;
		cout << " 1. Guess a hiden card!!!" << endl;
		cout << " 2. Play Spanish Veintiuna" << endl;
		cout << " 0. Exit" << endl;
		cout << " ****************************************************************************" << endl;
		cout << endl << " Please enter the option number: ";
		cin >> option;
		if (option == 1) {
			guessingGame.gameMenu();
		}
		if (option == 2) {
			cout << "Spanish Veintiuna" << endl;
		}
		else if (option == 0) {
			cout << endl << " Thank you for playing, have a nice day. " << endl << endl;
		}
		else {
			cout << " Invalid Option" << endl;
			cout << endl << " Press Enter to continue ..." << endl;
		}
		cin.ignore();
		cin.get();

	}

	return 0;
}