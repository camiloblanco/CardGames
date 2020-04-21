#include "GuessingGame.h"

// Main function to play a Guessing Game.
int GuessingGame::playGame() {
	// Variables to read the players guess
	string face;
	string suit;

	cin.ignore();
	// Game loop until m_deck is empty, "quit" input or "Continue" = no
	newRound();
	int gameCtr = 1;
	while (gameCtr)
	{
		cout << endl << " ********************************************************************************************" << endl;
		cout << "				Guessing Game. Round:" << m_round + 1 << "							  " << endl;
		cout << " ********************************************************************************************" << endl << endl;

		if (m_deck.getSetSize() == 0) {
			gameCtr = 0;
		}
		else {
			//Start the round, Player Play: Read a player's card guess, if "quit" input return 0
			if (playerPlay(face, suit) == -1) {
				//The player has decided to quit
				gameCtr = 0;
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
				option = tolower(option);
				if (option == 'y')
					newRound();
				else
					return 0;
			}
			else {
				cout << " You missed." << endl;
				m_results.push_back("lost");
				printStats();
			}
		}
	}
	return 0;
}

// Function to read the player guess for a face and suit
int GuessingGame::playerPlay(string& face, string& suit) {

	string newFace;
	string newSuit;

	int loopCtr = 1; 
	//Read the player guessed card's face
	while (loopCtr == 1) {
		cout << endl << " Guess the card's face." << endl;
		cout << " Type exactly one of these options, or \"quit\" to end: " << endl << " ";
		m_deck.printFaces();
		//Read the guess and put all caracters in lowercase
		cout << " Face Guess?:  ";
		getline(cin, newFace);
		transform(newFace.begin(), newFace.end(), newFace.begin(), ::tolower);
		//Evaluate the user input
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
			return -1;
		}
	}

	loopCtr = 1;
	//Read the player guessed card's suit
	while (loopCtr == 1) {
		cout << endl << " Guess the card's suit." << endl;
		cout << " Type exactly one of these options, or \"quit\" to end: " << endl << " ";
		m_deck.printSuits();
		//Read the guess and put all caracters in lowercase
		cout << " Suits Guess?:  ";
		getline(cin, newSuit);
		transform(newSuit.begin(), newSuit.end(), newSuit.begin(), ::tolower);
		// Evaluate the user input
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
			return -1;
		}
	}

	return 1;
}

// Evaluate the face and suit given by the user

int GuessingGame::evaluateRound(string& face, string& suit) {
	//Initialize and read variables
	int hits = 0;
	Card playerCard = m_playerHand.getLastCard();
	int cardValue = m_deck.getFaceValue(playerCard.getface());
	int guessedValue = m_deck.getFaceValue(face);

	cout << endl << " ********************************************************************************************" << endl;
	cout << "					Round Results " << endl;
	//print face results	
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
	//print suits results
	if (suit.compare(playerCard.getSuit()) == 0) {
		cout << " > The suit \"" << suit << "\" is correct." << endl;
		++hits;
	}
	else
		cout << " > The suit \"" << suit << "\" is incorrect." << endl;
	//comptact if : if hits == 2, return 1, else, return 0.
	return (hits == 2 ? 1 : 0);
}

// Prepare to start a new round
void GuessingGame::newRound() {
	//cin.ignore();
	//Reset game stats
	m_round = 0;
	m_results.clear();
	//Deal the next hidden card to the player hand
	m_playerHand.store(m_deck.deal());
}