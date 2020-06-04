#pragma once

#include <iostream>
#include "player.hpp"

using namespace std;

class Game {

public:
	virtual ~Game () = default;

	bool callMenu();
	bool requestInputMenu();
	const bool checkInputMenu(const short int &) const;
	const bool checkInputMenuUvsC(const short int &) const;
	const bool checkInputMenuCvsC(const short int &) const;
	const bool checkCin() const;
	virtual const short int inputUser() const; // Virtual for Unit Test
	void startGame();
	void startRoundRealVsComputer();
	void startComputerVsComputer();
	void processResult();
	void displayGraphic() const;
	void displayPictureText(const int &) const;
	void checkWinner();
	const short int generateRandomChoice() const;

	// Getter
	const bool isExitGame() const;
	const bool getRealPlayer() const ;
	const short int getChoicePlayer1() const;
	const short int getChoicePlayer2() const;
	const short int getScorePlayer1() const;
	const short int getScorePlayer2() const;

	// Setter
	void setRealPlayer();
	void setPlayer1Choice(const short int &);
	void setPlayer2Choice(const short int &);

protected:
	Player _player1;
	Player _player2;
	bool _exitGame{false};
};
