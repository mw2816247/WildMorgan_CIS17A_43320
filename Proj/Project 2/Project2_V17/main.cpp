/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on June 1, 12:54 PM
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
 * V8 - More exception handling
 * V9 - Adding more comments. Also created a Ctgries class, edited Player to not inherit from Array, and
 * then added a Ctgries object to Player. Edited code to be compatible with these modifications
 * V10 - Make Array a class template
 * V11 - Operator overloading
 * V12 - Added copy constructor for Dice, edited Game to sort a separate copy of dice instead of dice itself
 * V13 - Created constructors for Array and the classes that inherit from it
 * V14 - Made newAry a protected member of Array. It should only be called when an Array is created!
 * Also now a private member of Ctgries and Dice. Added another constructor to Array.
 * V15 - Created a vector of pointers to Game objects. The user can now play multiple games
 * V16 - Exception handling involving user inputs when choosing whether or not to start a game
 * V17 - After the user is done playing, output the results of each game they played
 */

#include <iostream> //For input and output
#include <iomanip> //Formatting results and scorecard
#include <ctime> //For randomization
#include <fstream> //For file operations
#include <vector>

using namespace std;

#include "Player.h"
#include "Game.h"
#include "Dice.h"
#include "Array.h"

short menu();

int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    vector<Game *> games;
    short input,
            gameNum = 0;
    bool again = true;
    
    cout << "Welcome to Yahtzee!" << endl;
    while (again) {
        try {
            input = menu();
            again = false;
        } catch (string error) {
            cout << error;
        }
    }
    
    while (input == 1) {
        again = true;
        games.push_back(new Game());
        games[gameNum]->play();
        while (again) {
            try {
                input = menu();
                again = false;
            } catch (string error) {
                cout << error;
            }
        }
        gameNum++;
    }
    
    for (int i = 0; i < games.size(); i++) {
        cout << endl << "--------------------" << endl << "Game " << i+1 << " Results" << endl;
        games[i]->results();
    }
    
    for (int i = 0; i < games.size(); i++) {
        delete games[i];
    }
    return 0;
}

short menu() {
    short input;
    cout << "If you would like to play a round, enter 1. If not, enter 2: ";
    cin >> input;
    if (input == 1 || input == 2) {
        return input;
    } else {
        string error;
        error = "ERROR: Input must be either 1 or 2.\n";
        throw error;
    }
}