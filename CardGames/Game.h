/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	Header file for the Game Class
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
*							#GUARDS #INCLUDES AND #CONSTANTS							*
****************************************************************************************/
#pragma once
#include <iostream>
#include <random>
#include <string>
#include <stdlib.h>
#include "SetOfCards.h"

using namespace std;

/****************************************************************************************
*									CLASS DECLARATION									*
****************************************************************************************/
class Game
{
public:
	//constructors
	Game();
	void newGame();
	int playGame();
	void printStats();

private:
	int readCard(string& face, string& suit);
	int evaluateRound(string& face, string& suit);
	void newRound();

	SetOfCards m_deck;
	SetOfCards m_playerHand;
	vector<string> m_results;
	int m_round;
};

