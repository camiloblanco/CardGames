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
		m_faces = {
			{"ace",1},
			{"two",2},
			{"three",3},
			{"four",4},
			{"five",5},
			{"six",6},
			{"seven",7},
			{"eight",8},
			{"nine",9},
			{"ten",10},
			{"jack",10},
			{"queen",10},
			{"king",10}
		};
	}
};

