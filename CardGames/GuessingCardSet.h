/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	Header and implementation file for the GuessingCardSet Class
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
#include "SetOfCards.h"
/****************************************************************************************
*									CLASS DECLARATION									*
****************************************************************************************/
class GuessingCardSet :	public SetOfCards
{
public:
	// Constructors
	GuessingCardSet(){
		m_suits = { "Clubs","Diamons","Hearts","Spades" };
		m_faces = {
			{"Ace",1},
			{"Two",2},
			{"Three",3},
			{"Four",4},
			{"Five",5},
			{"Six",6},
			{"Seven",7},
			{"Eight",8},
			{"Nine",9},
			{"Ten",10},
			{"Jack",11},
			{"Queen",12},
			{"King",13}
		};
	}
};

