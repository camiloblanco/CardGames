/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	CPP file for implementation of the VeintiunaGame Class.
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
#include "VeintiunaGame.h"
/****************************************************************************************
*									MEMBER FUNCTIONS									*
****************************************************************************************/

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
			system("CLS");
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

// Function to prompt the user for his play and analisys
int VeintiunaGame::playerPlay() {
	//declare variables
	string option;
	int gameCtr = 1;
	while (gameCtr==1){
		//evaluate the game state or ask the player for input
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
			//ask the player for input
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
				//stick
				gameCtr = 0;
			}
			else if (option.compare("t")==0) {
				//twist
				m_playerHand.store(m_deck.deal());
				gameCtr = 1;
			}
			else {
				cout << option << " is an invalid option, try again." << endl;
				gameCtr = 1;
			}
		}
	}
	//return the value of the hand
	return m_playerHand.valuate();
}

// Implement the Bank playing logic
int VeintiunaGame::bankPlay() {
	// variable declaration
	int gameCtr = 1;
	while (gameCtr==1) {
		//evaluate the game state or generate and automatic Bank input
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
			//Generate and automatic Bank input
			cout << endl << " The Bank hand is:" << endl;
			m_bankHand.printSet();
			cout << " Value: " << m_bankHand.valuate() << endl;
			cout << " [s]tick or [t]twist? ";
			
			if (m_bankHand.valuate() < m_playerHand.valuate()) {
				//Twist, and Introduce a dealy to mimic the Bank thinking
				pauseAndPoint(2);
				cout << "t"<<endl;
				m_bankHand.store(m_deck.deal());
			}
			else  {
				//Stick, and Introduce a dealy to mimic the Bank thinking
				pauseAndPoint(2);
				cout << "s"<<endl;
				gameCtr = 0;
			}
		}
	}
	//return the value of the hand
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
