/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	CPP file for implementarion of the Card Class.
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

#include "Card.h"

/****************************************************************************************
*									MEMBER FUNCTIONS									*
****************************************************************************************/
//Constructors
Card::Card() {}
Card::Card(string suit, string face) : m_suit(suit), m_face(face) {}

//public member functions

//Get-Set functions
string Card :: getSuit(){ return m_suit; }
string Card :: getface(){ return m_face; }

//print function
void Card::print() { cout << m_face << " of " << m_suit << endl; }

//Destructors
Card::~Card(){}

