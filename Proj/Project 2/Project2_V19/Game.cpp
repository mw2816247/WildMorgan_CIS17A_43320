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

unsigned short Game::getMAX() {
    return MAX;
}

void Game::setPlyr(string n, int index) {
    players[index].setName(n);
}

string Game::getName(int index) const {
    return players[index].name;
}

void Game::round() {
    short input = 1, //For storing user input, initialize it so we can check if the user
            //would like to reroll the dice
            index; //For rerolling dice
    unsigned short rerolls = 0; //Keep track of how many times the player has rolled
    bool again = true; //For exception handling
    cout << "Round " << turn + 1 << endl << "--------------------" << endl;

    for (int i = 0; i < nPlyrs; i++) {
        //Output the current player's stats
        cout << players[i];
        for (int j = 0; j < DICE; j++) {
            //Randomize the dice
            dice.setRoll(j);
        }
        
        //Output the player's roll
        vwRoll();

        //Check if the user wants to reroll the dice, and if they do, which dice
        //Then actually reroll it
        while (rerolls < 2 && input != 0) {
            again = true;
            while (again) {
                try {
                numRoll(input);
                again = false;
                } catch (string error) {
                    cout << error;
                }
            }

            for (int j = 0; j < input; j++) {
                again = true; //Reset again to be true for handling exceptions
                //With dice indices
                
                while (again) {
                        try {
                        reroll(j, index);
                        again = false;
                    } catch (string error) {
                        cout << error;
                    }
                }
                dice.setRoll((index-1));
            }
            //Output the dice roll and increase the number of rerolls
            vwRoll();
            rerolls++;
        } 
        //Reset reRolls for next player
        rerolls = 0;

        again = true;
        while (again) {
            try {
                slctCat(i, input);
                again = false;
            } catch (string error) {
                cout << error;
            }
        }
        setScr(i, input);
        input++; //Return to original input, otherwise program will get confused when trying to determine
        //dice rerolling if the previously chosen category was aces
    }
}

void Game::slctCat(int pNum, short &input) {
    cout << "Which category would you like to save your score to? Enter the numeric value: ";
    cin >> input;
    input--;

    if (input < ACES || input > CHANCE) {
        string error;
        error = "ERROR: That category does not exist.\n";
        throw error;
    } else if (players[pNum].ctgries.getCont(input) != -1) {
        string error = "ERROR: That category has been used.\n";
        throw error;
    }
}

void Game::numRoll(short &input) {
    cout << "How many dice would you like to reroll (1-5)? ";
    cin >> input;

    if (input < 0 || input > 5) {
        string error;
        error = "ERROR: Invalid number of dice. Please try again.\n";
        throw error;
    }
}

void Game::reroll(const short j, short &index) {
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
    cin >> index;
    if (index < 1 || index > 5) {
        string error;
        error = "ERROR: Invalid dice index. Please try again.\n";
        throw error;
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
    Dice srtDice = dice; //We'll have a sorted version of the dice, but also leave the original dice alone
    
    srtDice.ascSort();
    
    //Check for full house, three of a kind, four of a kind, or yahtzee
    for (int i = 0; i < DICE - 1; i++) {
            for (int j = i + 1; j < DICE; j++) {
                if (srtDice.getCont(i) == srtDice.getCont(j)) {
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
    srtDice.dupSort();
    
    if (players[pNum].ctgries.getCont(11) == 50 && maxCnt >= 5 && players[pNum].bonus == 0) {
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
    } else if (input == SMSTRT) {
        if (srtDice.getCont(0) == 1 && srtDice.getCont(1) == 2 && srtDice.getCont(2) == 3 
                && srtDice.getCont(3) == 4) {
            score = 30;
        } else if (srtDice.getCont(0) == 2 && srtDice.getCont(1) == 3 && srtDice.getCont(2) == 4
                && srtDice.getCont(3) == 5) {
            score = 30;
        } else if (srtDice.getCont(0) == 3 && srtDice.getCont(1) == 4 && srtDice.getCont(2) == 5
                && srtDice.getCont(3) == 6) {
            score = 30;
        } else if (srtDice.getCont(1) == 1 && srtDice.getCont(2) == 2 && srtDice.getCont(3) == 3
                && srtDice.getCont(4) == 4) {
            score = 30;
        } else if (srtDice.getCont(1) == 2 && srtDice.getCont(2) == 3 && srtDice.getCont(3) == 4
                && srtDice.getCont(4) == 5) {
            score = 30;
        } else if (srtDice.getCont(1) == 3 && srtDice.getCont(2) == 4 && srtDice.getCont(3) == 5
                && srtDice.getCont(4) == 6) {
            score = 30;
        }
    } else if (input == LGSTRT) {
        if (srtDice.getCont(0) == 1 && srtDice.getCont(1) == 2 && srtDice.getCont(2) == 3
                && srtDice.getCont(3) == 4 && srtDice.getCont(4) == 5) {
            score = 40;
        } else if (srtDice.getCont(0) == 2 && srtDice.getCont(1) == 3 && srtDice.getCont(2) == 4
                && srtDice.getCont(3) == 5 && srtDice.getCont(4) == 6) {
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
    
    players[pNum].ctgries.setCont(input, score);
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
    
    string name;
    for (int i = 0; i < nPlyrs; i++) {
        cout << "Enter a name for Player " << i+1 << ": ";
        cin >> name;
        setPlyr(name, i);
    }
}

void Game::lastScr(int pNum) {
    unsigned short score = 0;
    
    score += players[pNum].ctgries;
    
    score += players[pNum].bonus;
    
    players[pNum].setScr(score);
}

ostream &operator << (ostream &stream, const Game &obj) {
    for (int i = 0; i < obj.nPlyrs; i++) {
        const unsigned short SIZE = 6;
        string first = "1st Place: ",
                second = "2nd Place: ",
                third = "3rd Place: ",
                fourth = "4th Place: ",
                fifth = "5th Place: ",
                sixth = "6th Place: ";
        Array<short> score(SIZE);

        stream << "Final Results" << endl << "--------------------" << endl;
        for (int i = 0; i < obj.nPlyrs; i++) {
            stream << obj.players[i];
            stream << "Score: " << obj.players[i].score << endl;
            stream << "Bonus points: " << obj.players[i].bonus << endl;
        }

        for (int i = 0; i < obj.nPlyrs; i++) {
            short temp = obj.players[i];
            score.setCont(i, temp);
        }

        score.dscSort();
        score.dupSort();

        for (int i = 0; i < obj.nPlyrs; i++) {
            if (obj.players[i].score == score.getCont(0)) {
                if (first != "1st Place: ") {
                    first = first + ", " + obj.players[i].name;
                } else {
                    first += obj.players[i].name;
                }
            } else if (obj.players[i].score == score.getCont(1)) {
                if (second != "2nd Place: ") {
                    second = second + ", " + obj.players[i].name;
                } else {
                    second += obj.players[i].name;
                }
            } else if (obj.players[i].score == score.getCont(2)) {
                if (third != "3rd Place: ") {
                    third = third + ", " + obj.players[i].name;
                } else {
                    third += obj.players[i].name;
                }
            } else if (obj.players[i].score == score.getCont(3)) {
                if (fourth != "4th Place: ") {
                    fourth = fourth + ", " + obj.players[i].name;
                } else {
                    fourth += obj.players[i].name;
                }
            } else if (obj.players[i].score == score.getCont(4)) {
                if (fifth != "5th Place: ") {
                    fifth = fifth + ", " + obj.players[i].name;
                } else {
                    fifth += obj.players[i].name;
                }
            } else {
                if (sixth != "6th Place: ") {
                    sixth = sixth + ", " + obj.players[i].name;
                } else {
                    sixth += obj.players[i].name;
                }
            }
        }

        stream << endl << "--------------------" << endl;

        stream << first << endl;
        if (second != "2nd Place: ") {
            stream << second << endl;
        }
        if (third != "3rd Place: ") {
            stream << third << endl;
        }
        if (fourth != "4th Place: ") {
            stream << fourth << endl;
        }
        if (fifth != "5th Place: ") {
            stream << fifth << endl;
        }
        if (sixth != "6th Place: ") {
            stream << sixth << endl;
        }
    }
    return stream;
}

const unsigned short Game::MAX = 13;
const unsigned short Game::DICE = 5;