#include "VeintiunaGame.h"

// Main function to play a Twenty-One game
int VeintiunaGame::playGame() {

	cin.ignore();
	// Game loop until "quit" input
	string option="y";
	int gameCtr = 1;
	while (gameCtr==1)
	{
		//Check if he wants to play again.
		if (option.compare("y") == 0) {
			cout << endl << " ********************************************************************************************" << endl;
			cout << "				Twenty-One Game. Round:" << m_round + 1 << "							  " << endl;
			cout << " ********************************************************************************************" << endl << endl;
			newRound();
			int PlayerPoints = playerPlay();
			if (PlayerPoints == -1) {
				//The player has decided to quit
				return -1;
			}
			else if (PlayerPoints == 0)
			{
				//The player got busted, bank wins
				cout << endl << " > The Payer got busted, you lose." << endl;
				m_results.push_back("lost");
			}
			else if (bankPlay() == 0)
			{
				//The bank got busted, player wins
				cout << endl << " > The Bank got busted, you win!!!" << endl;
				m_results.push_back("won");
			}
			else
			{
				if (m_playerHand.valuate() > m_bankHand.valuate()) {
					//The player got more points than the bank, wins
					cout << endl << " > The player has more points than the bank, you win!!!" << endl;
					m_results.push_back("won");
				}
				else if (m_playerHand.valuate() < m_bankHand.valuate()) {
					//The player got less points than the bank, losses
					cout << endl << " > The player has less points than the bank, you lose." << endl;
					m_results.push_back("lost");
				}
				else if (m_playerHand.getSetSize() > m_bankHand.getSetSize()) {
					//Same points, but The player got more cards than the bank, wins
					cout << endl << " > Same points, but The player has more cards, you win!!!" << endl;
					m_results.push_back("won");
				}
				else if (m_playerHand.getSetSize() < m_bankHand.getSetSize()) {
					//Same points, but The player got less cards than the bank, loses
					cout << endl << " > Same points, but The player has less cards, you lose." << endl;
					m_results.push_back("lost");
				}
				else {
					//Full tie, the player wins
					cout << endl << " >Full tie, you win!!!" << endl;
					m_results.push_back("won");
				}
			}
		}

		//Ask the player if he wants to play again.
		cout << endl << " Do you want to play again? [y]es or [n]o to see the results and exit? : ";
		getline(cin, option);
		//Put all caracters in lowercase Evaluate the user input
		transform(option.begin(), option.end(), option.begin(), ::tolower);
		if (option.compare("quit") == 0) {
			//exit
			return -1;
		}
		else if (option.compare("y") == 0)
		{
			//Play again
			gameCtr = 1;
		}
		else if (option.compare("n") == 0) {
			//Print stats and exit
			printStats();
			cout << endl << " Press any key and then Enter to continue..." << endl;
			cin.ignore();
			cin.get();
			gameCtr = 0;
		}
		else {
			cout << option << " is an invalid option, try again." << endl;
			gameCtr = 1;
		}
		
	}
	return 0;
}

// Prompt the user for a face and suit guess

int VeintiunaGame::playerPlay() {

	string option;
	int gameCtr = 1;
	while (gameCtr==1){
		if (m_playerHand.valuate() > 21) {
			cout << endl << " Your hand is:" << endl;
			m_playerHand.printSet();
			cout << " Value: " << m_playerHand.valuate() << endl;
			cout << " BUST!!!" << endl;
			return 0;
		}
		else if (m_playerHand.valuate() == 21) {
			cout << endl << " The Player hand is:" << endl;
			m_playerHand.printSet();
			cout << " Value: " << m_playerHand.valuate() << endl;
			cout << " The Player has Twenty-One." << endl;
			gameCtr = 0;
		}
		else if (m_playerHand.getSetSize() == 5) {
			cout << endl << " Your hand is:" << endl;
			m_playerHand.printSet();
			cout << " Value: " << m_playerHand.valuate() << endl;
			cout << endl << " You have reached the 5 card limit." << endl;
			gameCtr = 0;
		}
		else {
			cout << endl << " Your hand is:" << endl;
			m_playerHand.printSet();
			cout << " Value: " << m_playerHand.valuate() << endl;
			cout << " [s]tick or [t]twist? : ";
			getline(cin, option);
			//Put all caracters in lowercase Evaluate the user input
			transform(option.begin(), option.end(), option.begin(), ::tolower);
			if (option.compare("quit")==0) {
				return -1;
			}
			else if (option.compare("s")==0)
			{
				gameCtr = 0;
			}
			else if (option.compare("t")==0) {
				m_playerHand.store(m_deck.deal());
				gameCtr = 1;
			}
			else {
				cout << option << " is an invalid option, try again." << endl;
				gameCtr = 1;
			}
		}
	}
	return m_playerHand.valuate();
}


int VeintiunaGame::bankPlay() {

	int gameCtr = 1;
	while (gameCtr==1) {
		if (m_bankHand.valuate() > 21) {
			cout << endl << " The Bank hand is:" << endl;
			m_bankHand.printSet();
			cout << " Value: " << m_bankHand.valuate() << endl;
			cout << " BUST!!!" << endl;
			return 0;
		}
		else if (m_bankHand.valuate() == 21) {
			cout << endl << " The Bank hand is:" << endl;
			m_bankHand.printSet();
			cout << " Value: " << m_bankHand.valuate() << endl;
			cout << " The Bank has Twenty-One." << endl;
			gameCtr = 0;
		}
		else if (m_bankHand.getSetSize() == 5) {
			cout << endl << " The Bank hand is:" << endl;
			m_bankHand.printSet();
			cout << " Value: " << m_bankHand.valuate() << endl;
			cout << endl << "  The Bank has reached the 5 card limit." << endl;
			gameCtr = 0;
		}
		else {
			cout << endl << " The Bank hand is:" << endl;
			m_bankHand.printSet();
			cout << " Value: " << m_bankHand.valuate() << endl;
			cout << " [s]tick or [t]twist? ";
			
			if (m_bankHand.valuate() < m_playerHand.valuate()) {
				//Introduce a dealy to mimic the Bank thinking
				pauseAndPoint(3);
				cout << "t"<<endl;
				m_bankHand.store(m_deck.deal());
			}
			else  {
				//Introduce a dealy to mimic the Bank thinking
				pauseAndPoint(3);
				cout << "s"<<endl;
				gameCtr = 0;
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
