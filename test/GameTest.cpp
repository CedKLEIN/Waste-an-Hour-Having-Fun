#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "game.hpp"
#include "utility.hpp"

using namespace std;
using ::testing::MockFunction;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class GameMock : public Game {
public:
	MOCK_CONST_METHOD0( inputUser, const short int() );
};

TEST(GameTest, checkInputMenu) {
	Game aNewGame;

	//True Case
	EXPECT_TRUE(aNewGame.checkInputMenu(1));
	EXPECT_TRUE(aNewGame.checkInputMenu(2));
	EXPECT_TRUE(aNewGame.checkInputMenu(3));

	//Wrong case
	EXPECT_FALSE(aNewGame.checkInputMenu(0));
	EXPECT_FALSE(aNewGame.checkInputMenu(4));
	EXPECT_FALSE(aNewGame.checkInputMenu(-999));
	EXPECT_FALSE(aNewGame.checkInputMenu(999));
}

TEST(GameTest, checkInputMenuCvsC) {
	Game aNewGame;

	//True Case
	EXPECT_TRUE(aNewGame.checkInputMenuCvsC(1));
	EXPECT_TRUE(aNewGame.checkInputMenuCvsC(2));

	//Wrong case
	EXPECT_FALSE(aNewGame.checkInputMenuCvsC(0));
	EXPECT_FALSE(aNewGame.checkInputMenuCvsC(3));
	EXPECT_FALSE(aNewGame.checkInputMenuCvsC(4));
	EXPECT_FALSE(aNewGame.checkInputMenuCvsC(-999));
	EXPECT_FALSE(aNewGame.checkInputMenuCvsC(999));
}

TEST(GameTest, checkInputMenuUvsC) {
	Game aNewGame;

	//True Case
	EXPECT_TRUE(aNewGame.checkInputMenuUvsC(1));
	EXPECT_TRUE(aNewGame.checkInputMenuUvsC(2));
	EXPECT_TRUE(aNewGame.checkInputMenuUvsC(3));
	EXPECT_TRUE(aNewGame.checkInputMenuUvsC(4));

	//Wrong case
	EXPECT_FALSE(aNewGame.checkInputMenuUvsC(0));
	EXPECT_FALSE(aNewGame.checkInputMenuUvsC(5));
	EXPECT_FALSE(aNewGame.checkInputMenuUvsC(-999));
	EXPECT_FALSE(aNewGame.checkInputMenuUvsC(999));
}

TEST(GameTest, requestInputMenu) {

	// (1) - User vs Computer
	GameMock aGame1;

	EXPECT_CALL(aGame1, inputUser())
	.Times(1)
	.WillOnce(Return(1));

	EXPECT_TRUE(aGame1.requestInputMenu());
	EXPECT_FALSE(aGame1.isExitGame());
	EXPECT_TRUE(aGame1.getRealPlayer());

	// (2) - Computer vs Computer
	GameMock aGame2;

	EXPECT_CALL(aGame2, inputUser())
	.Times(1)
	.WillOnce(Return(2));

	EXPECT_TRUE(aGame2.requestInputMenu());
	EXPECT_FALSE(aGame2.isExitGame());
	EXPECT_FALSE(aGame2.getRealPlayer());

	// (3) - Exit
	GameMock aGame3;

	EXPECT_CALL(aGame3, inputUser())
	.Times(1)
	.WillOnce(Return(3));

	EXPECT_TRUE(aGame3.requestInputMenu());
	EXPECT_TRUE(aGame3.isExitGame());
	EXPECT_FALSE(aGame3.getRealPlayer());

	// Error case
	GameMock aGameError;

	EXPECT_CALL(aGameError, inputUser())
	.Times(1)
	.WillOnce(Return(0));

	EXPECT_FALSE(aGameError.requestInputMenu());
	EXPECT_FALSE(aGameError.isExitGame());
	EXPECT_FALSE(aGameError.getRealPlayer());
}

TEST(GameTest, processResult) {

	// Case P1:Rock vs P2:Rock ----------------
	GameMock aNewGameRR;
	aNewGameRR.setPlayer1Choice(utility::RPS::ROCK);
	aNewGameRR.setPlayer2Choice(utility::RPS::ROCK);

	aNewGameRR.processResult();

	ASSERT_EQ(0,aNewGameRR.getScorePlayer1());
	ASSERT_EQ(0,aNewGameRR.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Rock vs P2:Paper ---------------
	GameMock aNewGameRP;
	aNewGameRP.setPlayer1Choice(utility::RPS::ROCK);
	aNewGameRP.setPlayer2Choice(utility::RPS::PAPER);

	aNewGameRP.processResult();

	ASSERT_EQ(0,aNewGameRP.getScorePlayer1());
	ASSERT_EQ(1,aNewGameRP.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Rock vs P2:Scissors ------------
	GameMock aNewGameRS;
	aNewGameRS.setPlayer1Choice(utility::RPS::ROCK);
	aNewGameRS.setPlayer2Choice(utility::RPS::SCISSORS);

	aNewGameRS.processResult();

	ASSERT_EQ(1,aNewGameRS.getScorePlayer1());
	ASSERT_EQ(0,aNewGameRS.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Paper vs P2:Rock ---------------
	GameMock aNewGamePR;
	aNewGamePR.setPlayer1Choice(utility::RPS::PAPER);
	aNewGamePR.setPlayer2Choice(utility::RPS::ROCK);

	aNewGamePR.processResult();

	ASSERT_EQ(1,aNewGamePR.getScorePlayer1());
	ASSERT_EQ(0,aNewGamePR.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Paper vs P2:Paper ---------------
	GameMock aNewGamePP;
	aNewGamePP.setPlayer1Choice(utility::RPS::PAPER);
	aNewGamePP.setPlayer2Choice(utility::RPS::PAPER);

	aNewGamePP.processResult();

	ASSERT_EQ(0,aNewGamePP.getScorePlayer1());
	ASSERT_EQ(0,aNewGamePP.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Paper vs P2:Scissors -----------
	GameMock aNewGamePS;
	aNewGamePS.setPlayer1Choice(utility::RPS::PAPER);
	aNewGamePS.setPlayer2Choice(utility::RPS::SCISSORS);

	aNewGamePS.processResult();

	ASSERT_EQ(0,aNewGamePS.getScorePlayer1());
	ASSERT_EQ(1,aNewGamePS.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Scissors vs P2:Rock -----------
	GameMock aNewGameSR;
	aNewGameSR.setPlayer1Choice(utility::RPS::SCISSORS);
	aNewGameSR.setPlayer2Choice(utility::RPS::ROCK);

	aNewGameSR.processResult();

	ASSERT_EQ(0,aNewGameSR.getScorePlayer1());
	ASSERT_EQ(1,aNewGameSR.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Scissors vs P2:Paper -----------
	GameMock aNewGameSP;
	aNewGameSP.setPlayer1Choice(utility::RPS::SCISSORS);
	aNewGameSP.setPlayer2Choice(utility::RPS::PAPER);

	aNewGameSP.processResult();

	ASSERT_EQ(1,aNewGameSP.getScorePlayer1());
	ASSERT_EQ(0,aNewGameSP.getScorePlayer2());
	//-----------------------------------------

	// Case P1:Scissors vs P2:Scissors --------
	GameMock aNewGameSS;
	aNewGameSS.setPlayer1Choice(utility::RPS::SCISSORS);
	aNewGameSS.setPlayer2Choice(utility::RPS::SCISSORS);

	aNewGameSS.processResult();

	ASSERT_EQ(0,aNewGameSS.getScorePlayer1());
	ASSERT_EQ(0,aNewGameSS.getScorePlayer2());
	//-----------------------------------------
}
