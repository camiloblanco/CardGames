#include "VeintiunaGame.h"

// Main function to play a game

int VeintiunaGame::playGame() {

	cin.ignore();
	// Game loop until "quit" input
	
	int gameCtr = 1;
	while (gameCtr)
	{
		cout << endl << " ********************************************************************************************" << endl;
		cout << "				Twenty-One Game. Round:" << m_round + 1 << "							  " << endl;
		cout << " ********************************************************************************************" << endl << endl;
		newRound();
		if (playerPlay() == -1) {
			//The player has decided to quit
			gameCtr = 0;
		}
		else if (m_playerHand.valuate() == 0)
		{
			//The player got busted, bank wins
			m_results.push_back("lost");
		}
		else if (bankPlay() == 0)
		{
			//The bank got busted, player wins
			m_results.push_back("won");
		}
		else
		{
			if (m_playerHand.valuate() > m_bankHand.valuate()) {
				//The player got more points than the bank, wins
				m_results.push_back("won");
			}else if (m_playerHand.valuate() < m_bankHand.valuate()) {
				//The player got less points than the bank, losses
				m_results.push_back("lost");
			}
			else if (m_playerHand.getSetSize() > m_bankHand.getSetSize()) {
				//Same points, but The player got more cards than the bank, wins
				m_results.push_back("won");
			}
			else if (m_playerHand.getSetSize() < m_bankHand.getSetSize()) {
				//Same points, but The player got less cards than the bank, loses
				m_results.push_back("lost");
			}
			else {
				//Full tie, the player wins
				m_results.push_back("won");
			}
		}
		printStats();
	}
	return 0;
}

// Prompt the user for a face and suit guess

int VeintiunaGame::playerPlay() {
	char option = 't';
	int gameCtr = 1;
	while (gameCtr){
		if (m_playerHand.valuate() > 21) {
			return 0;
		}
		else {
			cout << "Your hand is:" << endl;
			m_playerHand.printSet();
			cout << "Value: " << m_playerHand.valuate() << endl;
			cout << "[s]tick or [t]twist? ";
			cin >> option;
			if (option == 'q') {
				return -1;
			}
			else if (option == 's')
			{
				gameCtr = 0;
			}
			else if (option == 't') {
				m_playerHand.store(m_deck.deal());
			}
			else {
				cout << " Invalid option." << endl;
				option = 't';
			}
		}
	}
	return m_playerHand.valuate();
}


int VeintiunaGame::bankPlay() {

	int gameCtr = 1;
	while (gameCtr) {
		if (m_bankHand.valuate() > 21) {
			return 0;
		}
		else {
			cout << "The bank hand is:" << endl;
			m_bankHand.printSet();
			cout << "Value: " << m_bankHand.valuate() << endl;
			cout << "[s]tick or [t]twist? ";
			
			if (m_bankHand.valuate() < m_playerHand.valuate()) {
				cout << "t";
				m_bankHand.store(m_deck.deal());
			}
			else  {
				cout << "s";
				int gameCtr = 0;
			}
		}
	}
	return m_bankHand.valuate();
}

// Prepare to start a new round

void VeintiunaGame::newRound() {

	//Increment the round 
	++m_round;

	//Reset the Deck and Shuffle
	m_deck.fillAsDeck();
	m_deck.suffle();

	//Clear the player and bank hand
	m_playerHand.emptySet();
	m_bankHand.emptySet();

	//Deal two cards for each player hand
	m_playerHand.store(m_deck.deal());
	m_playerHand.store(m_deck.deal());
	m_bankHand.store(m_deck.deal());
	m_bankHand.store(m_deck.deal());
}
