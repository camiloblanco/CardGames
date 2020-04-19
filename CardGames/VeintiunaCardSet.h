/****************************************************************************************
* Project		:	Card Games, a C++ Abstraction, Inheritance and Polymorphism Program.
* License		:	Apache License Ver 2.0, www.apache.org/licenses/LICENSE-2.0
* Description	:	Header and implementation file for the VeintiunaCardSet Class
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
class VeintiunaCardSet :	public SetOfCards
{
public:
	// Constructors
	VeintiunaCardSet() {
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
			{"Jack",10},
			{"Queen",10},
			{"King",10}
		};
	}
};

