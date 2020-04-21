#pragma once
#include "Game.h"
class VeintiunaGame : public Game<VeintiunaCardSet>
{
public:
	//implement the virtual function
	int playGame();

protected:
	int playerPlay();
	int bankPlay();
	void newRound();
};

