#!/bin/bash

g++ -c battle.cpp
g++ -c memory_functions_chitwoo.cpp
g++ -o hw10 battle.o battleship.o memory_functions_chitwoo.o -lcurses
