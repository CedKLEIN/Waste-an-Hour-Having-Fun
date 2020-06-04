#pragma once

#include <iostream>

using namespace std;

class utility {
public:

	enum RPS {
		UNDEFINED = 0,
		ROCK,
		PAPER,
		SCISSORS
	};

	static void cleanConsole();
	static void printScore(const short int&, const short int&);
	static void printComputerVsComputer();
	static void printUserVsComputer();
	static void printMainMenu();
	static void printUvsCMenu();
	static void printCvsCMenu();
	static void printNewGame();
	static void printRock();
	static void printPaper();
	static void printScissors();
	static void printVS();
	static void printError(const short int &, const short int &);
	static void printPlayer(const short int &);
	static void printWinner(const short int &);
	static void printNoWinner();
};
