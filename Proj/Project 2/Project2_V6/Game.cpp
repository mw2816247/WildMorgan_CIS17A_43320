/* 
 * File:   Game.cpp
 * Author: Morgan Wild
 * Created on May 26, 2021, 10:40 AM
 * Purpose: Game class specification
 */

#include <string>
#include <iostream>

using namespace std;

#include "Game.h"

void Game::setNPlyrs(short n) {
    if (n > 0 && n < 7) {
        nPlyrs = n;
        players = new Player[nPlyrs];
    } else {
        string error = "ERROR: Invalid number of players!\n";
        throw error;
    }
}

void Game::setPlyr(string n, int index) {
    players[index].setName(n);
}

string Game::getName(int index) const {
    return players[index].getName();
}

void Game::round() {
    dice.newAry(DICE);
    short input = 1, //For storing user input, initialize it so we can check if the user
            //would like to reroll the dice
            index; //For rerolling dice
    unsigned short rerolls = 0; //Keep track of how many times the player has rolled
    cout << "Round " << turn + 1 << endl << "--------------------" << endl;

    for (int i = 0; i < nPlyrs; i++) {
        cout << players[i];
        for (int j = 0; j < DICE; j++) {
            dice.setRoll(j);
        }
        
        vwRoll();

        while (rerolls < 2 && input != 0) {
            cout << "How many dice would you like to reroll (1-5)? ";
            cin >> input;

            while (input < 0 || input > 6) {
                cout << "Invalid entry. Please try again." << endl;
                cout << "How many dice would you like to reroll (1-5)? ";
                cin >> input;
            }

            for (int j = 0; j < input; j++) {
                reroll(j);
                cin >> index;

                while (index < 1 || index > 5) {
                    cout << "Invalid entry. Please try again." << endl;
                    reroll(j);
                    cin >> index;
                }
                dice.setRoll(j);
            }
            vwRoll();
            rerolls++;
        } 
        rerolls = 0; //Reset reRolls for next player

        cout << "Which category would you like to save your score to? Enter the numeric value: ";
        cin >> input;
        input--;

        while (input < ACES || input > CHANCE || players[i].getCont(input) != -1) {
            cout << "Invalid input. " <<
                    "That category has been used or does not exist." << endl;
            cout << "Which category would you like to save your score to? Enter the numeric value: ";
            cin >> input;
            input--;
        }
        setScr(i, input);
        input++; //Return to original input, otherwise program will get confused when trying to determine
        //dice rerolling if the previously chosen category was aces
    }
    for (int i = 0; i < nPlyrs; i++) {
        lastScr(i);
    }
    
    results();
}

void Game::reroll(const short j) {
    if (j == 0) {
        cout << "What is the first dice would you like to reroll: ";
    } else if (j == 1) {
        cout << "What is the second dice would you like to reroll: ";
    } else if (j == 2) {
        cout << "What is the third dice would you like to reroll: ";
    } else if (j == 3) {
        cout << "What is the fourth dice would you like to reroll: ";
    } else {
        cout << "What is the fifth dice would you like to reroll: ";
    }
}

void Game::vwRoll() {
    for (int i = 0; i < DICE; i++) {
            cout << "Dice " << i+1 << ": " << dice.getCont(i) << endl;
        }
}

void Game::setScr(int pNum, short input) {
    unsigned short count = 1,
            maxCnt = 1; //Checking for matching dice
    bool pair = false; //For scoring full-houses
    short score = 0;
    
    dice.ascSort();
    
    //Check for full house, three of a kind, four of a kind, or yahtzee
    for (int i = 0; i < DICE - 1; i++) {
            for (int j = i + 1; j < DICE; j++) {
                if (dice.getCont(i) == dice.getCont(j)) {
                    count++;
                } else {
                    if (count > maxCnt) {
                        maxCnt = count;
                    }
                    
                    if (count == 2) {
                        pair = true;
                    }
                    count = 1;
                }
            }
        //Check if count > maxCnt at the end but it wasn't caught earlier because dice[i]=dice[j]
        if (count > maxCnt) {
            maxCnt = count;
        }    
    }
    
    //Sort to check for straights
    dice.dupSort();
    
    if (players[pNum].getCont(11) == 50 && maxCnt >= 5 && players[pNum].getBns() == 0) {
        players[pNum].setBns(100);
        cout << "You got a Yahtzee bonus!" << endl;
    }
    
    if (input == ACES) {
        for (int i = 0; i < DICE; i++) {
            if (dice.getCont(i) == 1) {
                score++;
            }
        }
    } else if (input == TWOS) {
        for (int i = 0; i < DICE; i++) {
            if (dice.getCont(i) == 2) {
                score+=2;
            }
        }
    } else if (input == THREES) {
        for (int i = 0; i < DICE; i++) {
            if (dice.getCont(i) == 3) {
                score+=3;
            }
        }
    } else if (input == FOURS) {
        for (int i = 0; i < DICE; i++) {
            if (dice.getCont(i) == 4) {
                score+=4;
            }
        }
    } else if (input == FIVES) {
        for (int i = 0; i < DICE; i++) {
            if (dice.getCont(i) == 5) {
                score+=5;
            }
        }
    } else if (input == SIXES) {
        for (int i = 0; i < DICE; i++) {
            if (dice.getCont(i) == 6) {
                score+=6;
            }
        }
    } else if (input == THRKIND) {
        if (maxCnt >= 3) {
            for (int i = 0; i < DICE; i++) {
                score += dice.getCont(i);
            }
        }
    } else if (input == FRKIND) {
        if (maxCnt >= 4) {
            for (int i = 0; i < DICE; i++) {
                score += dice.getCont(i);
            }
        }
    } else if (input == FULLHS) {
        if (maxCnt >= 3 && pair == true) {
            score = 25;
        }
    } else if (input == SMSTRT) { //The code for lines 407-425 is an edit of code from Mike Kitchen. His original code can be found on https://www.codeproject.com/Articles/8657/A-Simple-Yahtzee-Game
        if (dice.getCont(0) == 1 && dice.getCont(1) == 2 && dice.getCont(2) == 3 && dice.getCont(3) == 4) {
            score = 30;
        } else if (dice.getCont(0) == 2 && dice.getCont(1) == 3 && dice.getCont(2) == 4 && dice.getCont(3) == 5) {
            score = 30;
        } else if (dice.getCont(0) == 3 && dice.getCont(1) == 4 && dice.getCont(2) == 5 && dice.getCont(3) == 6) {
            score = 30;
        } else if (dice.getCont(1) == 1 && dice.getCont(2) == 2 && dice.getCont(3) == 3 && dice.getCont(4) == 4) {
            score = 30;
        } else if (dice.getCont(1) == 2 && dice.getCont(2) == 3 && dice.getCont(3) == 4 && dice.getCont(4) == 5) {
            score = 30;
        } else if (dice.getCont(1) == 3 && dice.getCont(2) == 4 && dice.getCont(3) == 5 && dice.getCont(4) == 6) {
            score = 30;
        }
    } else if (input == LGSTRT) {
        if (dice.getCont(0) == 1 && dice.getCont(1) == 2 && dice.getCont(2) == 3 && dice.getCont(3) == 4 && dice.getCont(4) == 5) {
            score = 40;
        } else if (dice.getCont(0) == 2 && dice.getCont(1) == 3 && dice.getCont(2) == 4 && dice.getCont(3) == 5 && dice.getCont(4) == 6) {
            score = 40;
        }
    } else if (input == YAHTZEE) {
        if (maxCnt >= 5) {
            score = 50;
        }
    } else {
        for (int i = 0; i < DICE; i++) {
            score += dice.getCont(i);
        }
    }
    
    players[pNum].setCont(input, score);
}

void Game::play() {
    for (turn; turn < MAX; turn++) {
        round();
    }
}

Game::Game() {
    bool again = true;
    short input;
    cout << "Enter the number of players (1-6): ";
    cin >> input;
    while (again) {
        try {
            setNPlyrs(input);
            again = false; //If the program made it here, then no error was detected!
        } catch (string error) {
            cout << error;
            cout << "Enter the number of players (1-6): ";
            cin >> input;
        }
    }
    
    string name;;
    for (int i = 0; i < nPlyrs; i++) {
        cout << "Enter a name for Player " << i+1 << ": ";
        cin >> name;
        setPlyr(name, i);
    }
}

void Game::results() {
    const unsigned short SIZE = 6;
    string first = "1st Place: ",
            second = "2nd Place: ",
            third = "3rd Place: ",
            fourth = "4th Place: ",
            fifth = "5th Place: ",
            sixth = "6th Place: ";
    Array score;
    score.newAry(SIZE);
    
    for (int i = 0; i < nPlyrs; i++) {
        short temp = players[i].getScr();
        score.setCont(i, temp);
    }
    
    score.dscSort();
    score.dupSort();
    
    for (int i = 0; i < nPlyrs; i++) {
        if (players[i].getScr() == score.getCont(0)) {
            if (first != "1st Place: ") {
                first = first + ", " + players[i].name;
            } else {
                first += players[i].name;
            }
        } else if (players[i].getScr() == score.getCont(1)) {
            if (second != "2nd Place: ") {
                second = second + ", " + players[i].name;
            } else {
                second += players[i].name;
            }
        } else if (players[i].getScr() == score.getCont(2)) {
            if (third != "3rd Place: ") {
                third = third + ", " + players[i].name;
            } else {
                third += players[i].name;
            }
        } else if (players[i].getScr() == score.getCont(3)) {
            if (fourth != "4th Place: ") {
                fourth = fourth + ", " + players[i].name;
            } else {
                fourth += players[i].name;
            }
        } else if (players[i].getScr() == score.getCont(4)) {
            if (fifth != "5th Place: ") {
                fifth = fifth + ", " + players[i].name;
            } else {
                fifth += players[i].name;
            }
        } else {
            if (sixth != "6th Place: ") {
                sixth = sixth + ", " + players[i].name;
            } else {
                sixth += players[i].name;
            }
        }
    }
    
    cout << endl << "--------------------" << endl;
    
    cout << first << endl;
    if (second != "2nd Place: ") {
        cout << second << endl;
    }
    if (third != "3rd Place: ") {
        cout << third << endl;
    }
    if (fourth != "4th Place: ") {
        cout << fourth << endl;
    }
    if (fifth != "5th Place: ") {
        cout << fifth << endl;
    }
    if (sixth != "6th Place: ") {
        cout << sixth << endl;
    }
}

void Game::lastScr(int pNum) {
    unsigned short score = 0;
    
    for (int i = 0; i < MAX; i++) {
        score += players[pNum].getCont(i);
    }
    
    score += players[pNum].getBns();
    
    players[pNum].setScr(score);
}