/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	CPP file for implementarion of the SetOfCards Class.
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

#include "SetOfCards.h"

/****************************************************************************************
*									MEMBER FUNCTIONS									*
****************************************************************************************/

// Constructors
SetOfCards::SetOfCards() {}

//public member functions

// function to Store a Card on m_set
void SetOfCards::store(Card cardObj) {
		m_set.push_back(cardObj);
}

// function to Suffle the Cards on m_set
void SetOfCards::suffle(){
	// seed declaration
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	// sufle std fucntion on m_set
	shuffle(m_set.begin(), m_set.end(), default_random_engine(seed));
}

// function to Deal the last Card on m_set
Card SetOfCards::deal(){
	if (m_set.size() > 0) {
		Card cardObj = m_set.back();
		m_set.pop_back();
		return cardObj;
	}
	else
	{
		cout << "There are no cards on this Set." << endl;
		Card cardObj;
		return cardObj;
	}
}

// function to Get the last Card on m_set
Card SetOfCards::getLastCard() {
	if (m_set.size() > 0) {
		Card cardObj = m_set.back();
		return cardObj;
	}
	else
	{
		cout << "There are no cards on this Set." << endl;
		Card cardObj;
		return cardObj;
	}
}

// function to Get the value of a given face
int SetOfCards::getFaceValue(string face) {	return m_faces[face];}

// function to Get the number of cards in m_set
int SetOfCards::getSetSize(){ return m_set.size();}

// function to Add all Cards points on m_set
int SetOfCards::valuate(){
	int totalValue = 0;
	for (auto card : m_set)
		totalValue += m_faces[card.getface()];
	return totalValue;
}

// Print all Cards points on m_set
void SetOfCards::printSet(){
	for (auto card : m_set)
		card.print();
}

// Print all the posible suits in the SetOfCards
void SetOfCards::printSuits() {
	for (auto suit : m_suits)
		cout <<"| "<< suit << " ";
	cout << "|" << endl;
}

// Print all the posible faces in the SetOfCards
void SetOfCards::printFaces() {
	typedef pair<string, int> cardPair;

	// create an empty vector of pairs
	vector<cardPair> pairsVec;

	// copy key-value pairs from the map to the vector
	copy(m_faces.begin(), m_faces.end(),back_inserter<vector<cardPair>>(pairsVec));

	// sort the vector by increasing order of its pair's second value
	// if second value are equal, order by the pair's first value
	sort(pairsVec.begin(), pairsVec.end(),[](const cardPair& l, const cardPair& r) {
			if (l.second != r.second)
				return l.second < r.second;
			return l.first < r.first;
		});

	// print the vector
	for (auto const& pair : pairsVec)
		cout << "| " <<pair.first << " ";
	cout << "|" << endl;
}

// Empty the set of Cards
void SetOfCards::emptySet() {
	m_set.clear();
}

// Fill the set of Cards as a whole new deck
void SetOfCards::fillAsDeck() 
{
	emptySet();
	for (auto suit : m_suits) {
		for (auto face : m_faces) {
			Card cardObj(suit, face.first);
			m_set.push_back(cardObj);
		}
	}
}

// Check if word is a valid suit for this set of cards
int SetOfCards::isValidSuit(string word){
	if (find(m_suits.begin(), m_suits.end(), word) != m_suits.end())
		return 1;
	return 0;
}

// Check if word is a valid face for this set of cards
int SetOfCards::isValidFace(string word){
	if (m_faces.count(word) > 0)
		return 1;
	return 0;
}

//Destructors
SetOfCards::~SetOfCards(){}
