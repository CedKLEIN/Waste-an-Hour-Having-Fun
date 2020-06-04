#include <stdlib.h>     /* srand, rand */
#include "player.hpp"

const short int Player::getScore() const {
	return _score;
}

const bool Player::getIsRealPlayer() const {
	return isRealPlayer;
}

const short int Player::getChoice() const {
	return _currentChoice;
}

void Player::incrementScore() {
	++_score;
}

void Player::setIsRealPlayer() {
	isRealPlayer = true;
}

void Player::setPlayerChoice(const short int iNewRPS) {
	_currentChoice = iNewRPS;

}