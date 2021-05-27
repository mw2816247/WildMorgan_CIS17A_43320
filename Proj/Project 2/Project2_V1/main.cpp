/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on May 26, 9:23 AM
 * Purpose: Simulate a game of Yahtzee.
 * V1 - Start converting structures from Project 1 to classes and make sure basic functions work
 */

#include <iostream>
#include <iomanip> //Formatting results and scorecard
#include <ctime> //For randomization
#include <fstream>
using namespace std;

#include "Player.h"
#include "Game.h"

int main(int argc, char** argv) {
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
    
    for (int i = 0; i < game.getNPlyrs(); i++) {
        name = new char[Player::getNAME()];
        cout << "Enter a name for Player " << i+1 << ": ";
        cin >> name;
        game.setPlyr(name, i);
        cout << game.getName(i) << endl;
    }
    
    delete []name;
    return 0;
}