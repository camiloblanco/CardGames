/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	Header file for the CardGame Derived Abstract Class
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
#include "Game.h"
#include "GuessingCardSet.h"
#include "VeintiunaCardSet.h"
using namespace std;
/****************************************************************************************
*									CLASS DECLARATION									*
****************************************************************************************/
template <class T>
class CardGame : public Game
{
public:
	//constructors
	CardGame();
	void newGame();
	virtual int playGame()=0;
	void printStats();

protected:
	//protected functions
	void pauseAndPoint(int numPoints);
	//protected variable members
	T m_deck;
	T m_playerHand;
	T m_bankHand;
};
//Include the implementation file so the compiler can solve the template <class T>
#include "CardGame.cpp"

