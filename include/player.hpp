#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Player {
public:

	void incrementScore();

	// Getter
	const bool getIsRealPlayer() const;
	const short int getScore() const;
	const short int getChoice() const;

	// Setter
	void setIsRealPlayer();
	void setPlayerChoice(const short int iNewRPS);

private:
	bool isRealPlayer{false};
	short int _score{0};
	short int _currentChoice{0};
};
