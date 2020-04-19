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

	//Clear the player hand and deal the first hidden card
	m_playerHand.emptySet();
	m_playerHand.store(m_deck.deal());
}

// Main function to play a game
template <class T>
int Game<T>::playGame() {
	// Variables to read the players guess
	string face;
	string suit;

	cin.ignore();
	// Game loop until m_deck is empty, "quit" input or "Continue" = no
	int gameCtr = 1;
	while (gameCtr)
	{
		cout <<endl<< " ********************************************************************************************" << endl;
		cout << "					   Round:"<< m_round+1 <<"							  " << endl;
		cout << " ********************************************************************************************" << endl << endl;
		
		//Start the round, Player Play: Read a player's card guess, if "quit" input return 0
		if (playerPlay(face, suit) == 0) {
			//The player has decided to quit
			return 0;
		}
		else {
			//The player has done a valid guess
			++m_round;
		}
		//Evaluate the round
		if (evaluateRound(face, suit) == 1) {
			cout << " Congratulations you Won!!!" << endl;
			m_results.push_back("won");
			printStats();
			cout << endl << " Continue [y]yes?, any other key to [e]end : ";
			char option;
			cin >> option;
			if (option == 'y')
				newRound();
			else
				return 0;
		}
		else {
			cout  << " You missed." << endl;
			m_results.push_back("lost");
			printStats();
		}
	}
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
		cout << " Guess " << roundNum << " : " << result << "." << endl;
		++roundNum;
	}
}

//****** Private functions *******

// Prompt the user for a face and suit guess
template <class T>
int Game<T>::playerPlay(string& face, string& suit) {

	string newFace;
	string newSuit;

	int loopCtr = 1;

	while (loopCtr == 1) {
		cout << endl << " Guess the card's face." << endl;
		cout << " Type exactly one of these options, or \"quit\" to end: " << endl << " ";
		m_deck.printFaces();
		cout << " Face Guess?:  ";
		getline(cin, newFace);
		if (newFace.compare("quit")) {
			if (m_deck.isValidFace(newFace) == 1) {
				face = newFace;
				loopCtr = 0;
			}
			else {
				cout << endl << " > \"" << newFace << "\" is not a valid card face, please try again. " << endl;
				loopCtr = 1;
			}
		}
		else {
			return 0;
		}
	}

	loopCtr = 1;

	while (loopCtr == 1) {
		cout << endl << " Guess the card's suit." << endl;
		cout << " Type exactly one of these options, or \"quit\" to end: " << endl << " ";
		m_deck.printSuits();
		cout << " Suits Guess?:  ";
		getline(cin, newSuit);
		if (newSuit.compare("quit")) {
			if (m_deck.isValidSuit(newSuit) == 1) {
				suit = newSuit;
				loopCtr = 0;
			}
			else {
				cout << endl << " > \"" << newSuit << "\" is not a valid card suit, please try again. " << endl;
				loopCtr = 1;
			}
		}
		else {
			return 0;
		}
	}
	
	return 1;
}

// Evaluate the face and suit given by the user
template <class T>
int Game<T>::evaluateRound(string& face, string& suit) {
	int hits = 0;
	Card playerCard = m_playerHand.getLastCard();


	int cardValue = m_deck.getFaceValue(playerCard.getface());
	int guessedValue = m_deck.getFaceValue(face);

	cout << endl << " ********************************************************************************************" << endl;
	cout << "					Round Results " << endl;
	cout << endl << " Your guess is: " << face << " of " << suit << "." << endl;
	if (guessedValue < cardValue) {
		cout << " > The face \"" << face << "\" is too Low." << endl;
	}
	else if (guessedValue > cardValue) {
		cout << " > The face \"" << face << "\" is too High." << endl;
	}
	else {
		cout << " > The face \"" << face << "\" is correct." << endl;
		++hits;
	}

	if (suit.compare(playerCard.getSuit()) == 0) {
		cout << " > The suit \"" << suit << "\" is correct." << endl;
		++hits;
	}
	else
		cout << " > The suit \"" << suit << "\" is incorrect." << endl;

	return (hits == 2 ? 1 : 0);
}

// Prepare to start a new round
template <class T>
void Game<T>::newRound() {
	cin.ignore();
	//Reset game stats
	m_round = 0;
	m_results.clear();
	//Deal the next hidden card to the player hand
	m_playerHand.store(m_deck.deal());
}

#endif