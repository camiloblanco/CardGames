/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	CPP file for implementarion of the Game Class.
*
* References	:	- Instruction by Dr Ling Ma <ling.ma@qmul.ac.uk>
*					- Instruction by Dr Jeremy Gow <jeremy.gow@qmul.ac.uk>
*                   - B. Stroustrup: The C++ Programming Language (Fourth Edition).
*					  Addison Wesley. Reading Mass. USA. May 2013. ISBN 0-321-56384-0.
*					- https://stackoverflow.com/questions/3705740/c-lnk2019-error-unresolved-external-symbol-template-classs-constructor-and
*					- https://stackoverflow.com/questions/8810224/inheriting-from-a-template-class-in-c
* Git Control	:	https://github.com/camiloblanco/CardGames/
* Author - Year	:	Camilo Blanco Vargas	-	Apr-2020
* Mail - Web	:	mail@camiloblanco.com	-	www.camiloblanco.com
****************************************************************************************/

/****************************************************************************************
*								#INCLUDES AND #CONSTANTS								*
****************************************************************************************/

#include "Game.h"
#pragma once
#ifndef _Game_CPP_
#define _Game_CPP_

/****************************************************************************************
*									MEMBER FUNCTIONS									*
****************************************************************************************/

//****** constructors *******
template <class T>
Game<T>::Game():m_round(0){
}

//****** Public functions *******

// Prepare to start a new game
template <class T>
void Game<T>::newGame() {

	//Reset game stats
	m_round = 0;
	m_results.clear();

	//Reset the Deck and Shuffle
	m_deck.fillAsDeck();
	m_deck.suffle();

	//Test: Print Shufled m_deck
	//cout << endl << " ********************************************************************************************" << endl;
	//cout << "					   Deck After Shuffle" << endl;
	//m_deck.printSet();

	//Clear the player and bank hand
	m_playerHand.emptySet();
	m_bankHand.emptySet();
}

// Print last round Stats
template <class T>
void Game<T>::printStats() {
	cout << endl << " ********************************************************************************************" << endl;
	cout << "				 	  Game Stats " << endl;
	cout << " Rounds: " << m_round << endl;
	cout << " Won: "<< count(m_results.begin(), m_results.end(), "won")<<endl;
	cout << " Lost: " << count(m_results.begin(), m_results.end(), "lost")<<endl << " --" << endl;
	int roundNum = 1;
	for (auto result: m_results) {
		cout << " Round " << roundNum << " : " << result << "." << endl;
		++roundNum;
	}
}

//****** Private functions *******

#endif