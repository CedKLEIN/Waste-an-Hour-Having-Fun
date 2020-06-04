cmake_minimum_required(VERSION 3.17.3)

project(C++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_C_COMPILER "C:/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "C:/mingw64/bin/g++.exe")

enable_testing()

add_subdirectory(googletest-master)

set(HEADERS
	include/game.hpp
	include/player.hpp
	include/utility.hpp
)

set(SOURCES
	src/game.cpp
	src/player.cpp
	src/utility.cpp
)

add_library(core ${HEADERS} ${SOURCES})

target_include_directories(core
	PUBLIC
	 ${PROJECT_SOURCE_DIR}/include)

add_executable(
	main
	main.cpp
)

target_link_libraries(main
	core
)

add_subdirectory(test)