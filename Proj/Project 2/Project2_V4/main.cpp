/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on May 27, 11:53 AM
 * Purpose: Simulate a game of Yahtzee.
 * V1 - Start converting structures from Project 1 to classes and make sure basic functions work
 * V2 - Create a Dice class
 * V3 - Create an Array class for the other classes to utilize, add comments to the other classes
 * & implement Array in Player
 * V4 - More edits to Player class. Add in a function to print out the information about each player
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
    bool again = true;
    Game game;
    int input;
    char *name = nullptr;
    
    cout << "Enter the number of players (1-6): ";
    cin >> input;
    
    while (again) {
        try {
            game.setNPlyrs(input);
            again = false; //If the program made it here, then no error was detected!
        } catch (string error) {
            cout << error;
            cout << "Enter the number of players (1-6): ";
            cin >> input;
        }
    }
    
//    for (int i = 0; i < game.getNPlyrs(); i++) {
//        name = new char[Player::getNAME()];
//        cout << "Enter a name for Player " << i+1 << ": ";
//        cin >> name;
//        game.setPlyr(name, i);
//        cout << game.getName(i) << endl;
//    }
//    
//    for (int i = 0; i < game.getNPlyrs(); i++) {
//        for (int j = 0; j < Player::getMAX(); j++) {
//            cout << "Score: " << game.getScr(i, j) << endl;
//        }
//    }
    
    Player player;
    player.setName("Player");
    cout << player << endl;
    
    delete []name;
    return 0;
}