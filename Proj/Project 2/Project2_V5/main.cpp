/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on May 27, 12:47 PM
 * Purpose: Simulate a game of Yahtzee.
 * V1 - Start converting structures from Project 1 to classes and make sure basic functions work
 * V2 - Create a Dice class
 * V3 - Create an Array class for the other classes to utilize, add comments to the other classes
 * & implement Array in Player
 * V4 - More edits to Player class. Add in a function to print out the information about each player
 * V5 - Edits to the Game class, mainly adding in altered code from previous project.
 * The game will play, but it won't calculate or output results
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
//    
//    for (int i = 0; i < game.getNPlyrs(); i++) {
//        for (int j = 0; j < Player::getMAX(); j++) {
//            cout << "Score: " << game.getScr(i, j) << endl;
//        }
//    }
//    
//    Player player;
//    player.setName("Player");
//    cout << player << endl;
    
    return 0;
}