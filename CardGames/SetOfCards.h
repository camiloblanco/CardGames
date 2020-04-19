/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	Header file for the SetOfCards Class
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
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <algorithm>
#include <random>       
#include <chrono>       
#include "Card.h"
using namespace std;
/****************************************************************************************
*									CLASS DECLARATION									*
****************************************************************************************/

class SetOfCards
{
public:
	//Constructors
	SetOfCards();

	//public member functions

	void store(Card cardObj);
	void suffle();
	Card deal();
	Card getLastCard();
	int getFaceValue(string face);
	int valuate();

	void printSet();
	void printSuits();
	void printFaces();

	void emptySet();
	void fillAsDeck();

	int isValidSuit(string word);
	int isValidFace(string word);

	//Destructors
	~SetOfCards();

private:

	// private member functions

	// member variables
	vector<Card> m_set; //Vector of Cards to represent Any set of cards (Decks, Hands, Etc)
	vector <string> m_suits; //Vector for suits names
	map<string, int> m_faces; //A map for face names ans specific values for the game
	
};

