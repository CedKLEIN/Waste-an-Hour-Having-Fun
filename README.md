# Waste-an-Hour-Having-Fun

## Table of content
* [Introduction](#Introduction)
* [Technologies](#technologies)
* [Setup](#setup)

### Introduction
Here is my version of "Waste-an-Hour-Having-Fun".
I chose to not use UI but only the console.
I still tried to do a attractive display.
Hope you will have fun during the next hour with this game :D

### Technologies
* MinGW-W64 7.3.0             => http://mingw.org/wiki/Getting_Started
* cmake version 3.17.3        => https://cmake.org/download/
* GNU Make 4.2.1
* C++17
* googletest / googlemock     => https://github.com/google/googletest (included in the project)
* Sublime Text 3

### Setup
How to run in local :

After having all tools download in local...
(main.exe and game_test.exe are provided in the project).

```
$ cmake . -G "MinGW Makefiles"
$ make
```

To run the game
```
$ main.exe
```

To run the unit test
```
$ cd test
$ game_test.exe
```
