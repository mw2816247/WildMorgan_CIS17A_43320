/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on May 28, 11:30 AM
 * Purpose: Simulate a game of Yahtzee.
 * V1 - Start converting structures from Project 1 to classes and make sure basic functions work
 * V2 - Create a Dice class
 * V3 - Create an Array class for the other classes to utilize, add comments to the other classes
 * & implement Array in Player
 * V4 - More edits to Player class. Add in a function to print out the information about each player
 * V5 - Edits to the Game class, mainly adding in altered code from previous project.
 * The game will play, but it won't calculate or output results
 * V6 - Calculate and output results! Also made Game a friend of Player
 * V7 - Since Game is a friend of Player, can make edits in areas of Game where accessor functions
 * of Player were used, e.g. getScr and getName
 */

#include <iostream>
#include <iomanip> //Formatting results and scorecard
#include <ctime> //For randomization
#include <fstream>
using namespace std;

#include "Player.h"
#include "Game.h"
#include "Dice.h"
#include "Array.h"

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    Game game;
    
    game.play();
    
    return 0;
}