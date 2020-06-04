#include "utility.hpp"


void utility::cleanConsole() {
	cout << string(50, '\n') << endl;
}

void utility::printScore(const short int& iScorePlayer1, const short int& iScorePlayer2) {
	cout << "\n\nScore : " << iScorePlayer1 << " - " << iScorePlayer2 << "\n" << endl;
}

void utility::printUserVsComputer() {
	cout << "\n\n  USER vs COMPUTER\n\n";
	cout << "You are the player 1 !\n" << endl;
}

void utility::printComputerVsComputer() {
	cout << "\n\n  COMPUTER vs COMPUTER\n" << endl;
}

void utility::printMainMenu() {
    cout << " WASTE AN HOUR HAVING FUN !\n\n";
    cout << " (1) - User vs Computer \n";
    cout << " (2) - Computer vs Computer \n";
    cout << " (3) - Exit \n";
    cout << "\n => ";
}

void utility::printUvsCMenu() {
	cout << "(1) - Rock \n";
	cout << "(2) - Paper \n";
	cout << "(3) - Scissors \n\n";
	cout << "(4) - Exit \n";
    cout << "\n => ";
}

void utility::printCvsCMenu() {
	cout << "(1) - Start a new round \n";
	cout << "(2) - Exit \n";
    cout << "\n => ";
}

void utility::printNewGame() {
	cleanConsole();
	cout << " ****     ** ******** **       **     ********      **     ****     **** ********\n";
	cout << "/**/**   /**/**///// /**      /**    **//////**    ****   /**/**   **/**/**///// \n";
	cout << "/**//**  /**/**      /**   *  /**   **      //    **//**  /**//** ** /**/**      \n";
	cout << "/** //** /**/******* /**  *** /**  /**           **  //** /** //***  /**/******* \n";
	cout << "/**  //**/**/**////  /** **/**/**  /**    ***** **********/**  //*   /**/**////  \n";
	cout << "/**   //****/**      /**** //****  //**  ////**/**//////**/**   /    /**/**      \n";
	cout << "/**    //***/********/**/   ///**   //******** /**     /**/**        /**/********\n";
	cout << "//      /// //////// //       //     ////////  //      // //         // //////// \n" << endl;
}

void utility::printRock() {
	cout << "     ______\n";
	cout << "    |   _  |_\n";
	cout << "----|  |_|_|_|\n"; 
	cout << "       |_____|\n";
	cout << "       |_____|\n";
	cout << "----|__|____|\n\n" << endl;
}

void utility::printPaper() {
	cout << "     ______\n";
	cout << "    |   _  |____\n";
	cout << "----|    |_|____|_\n";
	cout << "          ________|\n";
	cout << "          ______|\n";
	cout << "----|__________|\n\n" << endl;
}

void utility::printScissors() {
	cout << "               __\n";
	cout << "     ______  _- _|\n";
	cout << "    |   _  |- _-\n";
	cout << "----|    |_|_- \n";
	cout << "        ____ -_\n";
	cout << "       |____|_ -_\n";
	cout << "----|__|____| -__|\n\n"<< endl;
}

void utility::printVS() {
	cout << "      ___\n";
	cout << "\\  / |___\n";
	cout << " \\/   ___|\n\n" << endl;
}

void utility::printError(const short int &iNum1, const short int &iNum2) {
	cout << "Input is invalid, please keep a number in [" << iNum1 << ":" << iNum2 << "]\n\n" << endl;
}

void utility::printPlayer(const short int &iPlayer) {
	cout << "\nPlayer " << iPlayer << " :\n" << endl;
}

void utility::printWinner(const short int &iPlayer) {
	cout << "Player " << iPlayer << " win !!" << endl;
}

void utility::printNoWinner() {
	cout << "No winner ..." << endl;
}