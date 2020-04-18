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


void Game::newGame() {
	m_deck.fillAsDeck();
	m_playerHand.store(m_deck.deal());
}

int Game::playGame() {
	cin.ignore();
	string face;
	string suit;
	int gameCtr = 1;
	while (gameCtr)
	{
		if (readCard(face,suit) == 0) {
			return 0;
		}
		if (evaluateTurn(face, suit) == 1) {
			cout <<endl << " > Congratulations you Won!!!" <<endl;
			cout << endl << " Continue, [y]yes or [n]no? : ";
			char option;
			cin >> option;
			if (option == 'y')
				m_playerHand.store(m_deck.deal());
			else
				return 0;
		}
		else
			cout << endl << " > You missed." << endl;
	}
}

int Game::readCard(string& face, string& suit) {

	string newFace;
	string newSuit;

	int loopCtr = 1;

	while (loopCtr == 1) {
		cout << endl << " Guess the card's face." << endl;
		cout << " Type exactly one of these options, or \"quit\" to end: " << endl <<" ";
		m_deck.printFaces();
		cout << " Face Guess:  ";
		getline(cin, newFace);
		if (newFace.compare("quit")) {
			if (m_deck.isValidFace(newFace) == 1) {
				face = newFace;
				loopCtr = 0;
			}
			else {
				cout <<endl<< " > \""<< newFace<<"\" is not a valid card face, please try again. " << endl;
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
		cout << " Type exactly one of these options, or \"quit\" to end: " << endl<< " ";
		m_deck.printSuits();
		cout << " Suits Guess:  ";
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
	cout << endl << " >Your guess is: " << face << " of " << suit << "." << endl;
	return 1;
}


int Game::evaluateTurn(string& face, string& suit) {
	int hits = 0;
	Card playerCard = m_playerHand.getLastCard();

	//playerCard.print();
	int cardValue = m_deck.getFaceValue(playerCard.getface());
	int guessedValue = m_deck.getFaceValue(face);

	//cout << "guessedValue: " << guessedValue << ", cardValue: " << cardValue << endl;
		
	if (guessedValue < cardValue) {
		cout << " >The face \"" << face << "\" is too Low, please try again." << endl;
	}
	else if (guessedValue > cardValue) {
		cout << " >The face \"" << face << "\" is too High, please try again." << endl;
	}
	else{
		cout << " >The face \"" << face << "\" is correct." << endl;
		++hits;
	}

	if (suit.compare(playerCard.getSuit()) == 0) {
		cout << " >The suit \"" << suit << "\" is correct." << endl;
		++hits;
	}
	else
		cout << " >The suit \"" << suit << "\" is incorrect." << endl;

	return (hits == 2 ? 1 : 0);
}