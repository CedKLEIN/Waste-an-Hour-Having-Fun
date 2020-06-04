#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "game.hpp"
#include "utility.hpp"

bool Game::callMenu() {
	utility::printMainMenu();

	if(requestInputMenu()) {
        return !isExitGame();
    } else {
        utility::printError(1,3);
        return false;
    }
}

bool Game::requestInputMenu() {
	const short int aMenuChoice{inputUser()};

	bool isInputValid{checkInputMenu(aMenuChoice)};

    if (isInputValid) {
    	if (aMenuChoice == 1) {
    		setRealPlayer();
    	} else if (aMenuChoice == 3) {
    		_exitGame = true;
    	}
    }

    return isInputValid;
}

const bool Game::checkInputMenu(const short int &oChoice) const {
	utility::cleanConsole();

    return (checkCin() && !(oChoice != 1 && oChoice != 2 && oChoice != 3));
}

const bool Game::checkInputMenuUvsC(const short int &oChoice) const {
	utility::cleanConsole();

	return (checkCin() && !(oChoice != 1 && oChoice != 2 && oChoice != 3 && oChoice != 4));
}

const bool Game::checkInputMenuCvsC(const short int &oChoice) const {
	utility::cleanConsole();

	return (checkCin() && !(oChoice != 1 && oChoice != 2));
}

const bool Game::checkCin() const {
	if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    } 
    return true;
}

const short int Game::inputUser() const {

	short int aMenuChoice{0};
    cin >> aMenuChoice;
    return aMenuChoice;
}

void Game::startGame () {
	// initialize random RPS
  	srand(time(nullptr));

	utility::printNewGame();

	if (getRealPlayer()) {
		utility::printUserVsComputer();
		startRoundRealVsComputer();

	} else {
		utility::printComputerVsComputer();
		startComputerVsComputer(); 
	}
}

void Game::startRoundRealVsComputer() {

	while (true) {

		utility::printScore(getScorePlayer1(), getScorePlayer2());
		utility::printUvsCMenu();

		const short int aNewChoice{inputUser()};

		// (4) - Exit
		if ( aNewChoice == 4 ) {
			utility::cleanConsole();
			return;
		}

		if (checkInputMenuUvsC(aNewChoice)) {
			setPlayer1Choice(aNewChoice);
			setPlayer2Choice(generateRandomChoice());

			displayGraphic();
			processResult();
		} else {
            utility::printError(1,4);
        }
	}
}

void Game::startComputerVsComputer() {

	while (true) {

		utility::printScore(getScorePlayer1(), getScorePlayer2());
		utility::printCvsCMenu();

		const short int aNewChoice{inputUser()};

		// (2) - Exit
		if ( aNewChoice == 2 ) {
			utility::cleanConsole();
			return;
		} 

		if (checkInputMenuCvsC(aNewChoice)) {
			setPlayer1Choice(generateRandomChoice());
			setPlayer2Choice(generateRandomChoice());

			displayGraphic();
			processResult();
		} else {
            utility::printError(1,2);
        }
	}
}

void Game::processResult() {

	if (getChoicePlayer1() == getChoicePlayer2()) {
		utility::printNoWinner();
	} else {
		checkWinner();
	}
}

void Game::displayGraphic() const {
	utility::cleanConsole();
	utility::printPlayer(1);
	displayPictureText(getChoicePlayer1());
	utility::printVS();

	utility::printPlayer(2);
	displayPictureText(getChoicePlayer2());
}

void Game::displayPictureText(const int &iRPS) const {
	if ( iRPS == utility::RPS::ROCK ) {
		utility::printRock();
	} else if  ( iRPS == utility::RPS::PAPER ) {
		utility::printPaper();
	} else if  ( iRPS == utility::RPS::SCISSORS ) {
		utility::printScissors();
	}
}

void Game::checkWinner() {
	if ( (getChoicePlayer1() == utility::RPS::ROCK) && (getChoicePlayer2() == utility::RPS::PAPER) 
		|| (getChoicePlayer1() == utility::RPS::PAPER) && (getChoicePlayer2() == utility::RPS::SCISSORS) 
		|| (getChoicePlayer1() == utility::RPS::SCISSORS) && (getChoicePlayer2() == utility::RPS::ROCK) ) {
		utility::printWinner(2);
		_player2.incrementScore();
	} else {
		utility::printWinner(1);
		_player1.incrementScore();
	}
}

const short int Game::generateRandomChoice() const {
	return rand()%3 + 1;
}

const bool Game::isExitGame() const {
	return _exitGame;
}

const bool Game::getRealPlayer() const {
	return _player1.getIsRealPlayer();
}

const short int Game::getChoicePlayer1() const {
	return _player1.getChoice();
}

const short int Game::getChoicePlayer2() const {
	return _player2.getChoice();
}

const short int Game::getScorePlayer1() const {
	return _player1.getScore();
}

const short int Game::getScorePlayer2() const {
	return _player2.getScore();
}

void Game::setRealPlayer() {
	_player1.setIsRealPlayer();
}

void Game::setPlayer1Choice(const short int &iNewRPS) {
	_player1.setPlayerChoice(iNewRPS);
}

void Game::setPlayer2Choice(const short int &iNewRPS) {
	_player2.setPlayerChoice(iNewRPS);
}