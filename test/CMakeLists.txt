cmake_minimum_required(VERSION 3.17.3)

set(SOURCES
	GameTest.cpp
)

add_executable(game_test ${SOURCES})

target_link_libraries(game_test PUBLIC
	gtest_main
	gmock_main
	core
)

add_test(
	NAME game_test
	COMMAND game_test
)
