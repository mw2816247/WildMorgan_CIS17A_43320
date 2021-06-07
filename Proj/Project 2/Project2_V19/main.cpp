/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on June 2, 7:25 AM
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
 * V18 - Took some functions away from Game. main will now deal with those functions, and it will use
 * the setters and getters of Game to do so
 * V19 - Added file operations
 */

#include <iostream> //For input and output
#include <iomanip> //Formatting results and scorecard
#include <ctime> //For randomization
#include <fstream> //For file operations
#include <vector> //For vectors

using namespace std;

#include "Player.h"
#include "Game.h"
#include "Dice.h"
#include "Array.h"
#include "Ctgries.h"

short menu();
void stats(fstream &, vector<Game *>);

int main(int argc, char** argv) {
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize and declare variables
    vector<Game *> games; //To store pointers to the Game objects created by the player
    short input, //To track user input
            gameNum = 0; //To track how many games have been played
    bool again = true; //For exception handling
    fstream results; //To store the results for the set of games
    //Open the results file for output
    results.open("Yahtzee.txt", ios::out);
    
    cout << "Welcome to Yahtzee!" << endl;
    while (again) {
        //Check if the user would like to play a game
        //If the user's input is valid, the program will set again to false and continue
        //Otherwise, it will catch the error and ask them again
        try {
            input = menu();
            again = false;
        } catch (string error) {
            cout << error;
        }
    }
    
    while (input == 1) {
        //If the user chose to play another game, go through the loop again
        again = true; //More exception handling coming up
        games.push_back(new Game()); //Add a new element to the games vector
        //As long as the current Game's turn number is less than the maximum turn number, play another round
        for (games[gameNum]->getTurn(); games[gameNum]->getTurn() < Game::getMAX(); games[gameNum]->setTurn()) {
            games[gameNum]->round();
        }
        //Once all rounds have been played, the scores must be calculated for each player
        for (int i = 0; i < games[gameNum]->getNPlyrs(); i++) {
            games[gameNum]->lastScr(i);
        }
        //Output the results
        cout << *games[gameNum];
        //Check if the user would like to play again, using the same method from earlier
        while (again) {
            try {
                input = menu();
                again = false;
            } catch (string error) {
                cout << error;
            }
        }
        //Increase the game number by one
        gameNum++;
    }
    
    //Output the results for all of the games the user played
    stats(results, games);
    
    //Since we dynamically allocated each Game in the games vector, we need to cleanup before the program ends
    for (int i = 0; i < games.size(); i++) {
        delete games[i];
    }
    
    //Close the results file
    results.close();
    return 0;
}

//menu displays the menu prompting the user to select if they want to play another round
//will return valid inputs or throw an error if an invalid input is detected
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

//First stats will write the game results to the results file
//Then it will read in and print the results
void stats(fstream &results, vector<Game *> games) {
    string data;
    
    for (int i = 0; i < games.size(); i++) {
        results << endl << "--------------------" << endl << "Game " << i+1 << " Results" << endl;
        results << *games[i];
    }
    
    results.close();
    results.open("Yahtzee.txt", ios::in);
    
    getline(results, data);
    
    while (results) {
        cout << data << endl;  
        getline(results, data);
    }
} 