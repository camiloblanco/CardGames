#pragma once
#include "Game.h"
class GuessingGame : public Game<GuessingCardSet>
{
public:
	int playGame();

protected:
	int playerPlay(string& face, string& suit);
	int evaluateRound(string& face, string& suit);
	void newRound();
};

