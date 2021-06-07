/* 
 * File:   Game.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 10:20 AM
 * Purpose: Game class specification
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dice.h"
#include "Array.h"

class Game;

ostream &operator << (ostream &, const Game &);

class Game {
    private:
        enum Ctgry { ACES, TWOS, THREES, FOURS, FIVES, SIXES,
            THRKIND, FRKIND, FULLHS, SMSTRT, LGSTRT, YAHTZEE,
            CHANCE }; //An enumerator for comparing user inputs to Yahtzee categories
        static const unsigned short MAX, //Maximum number of turns
                DICE; //The number of Dice in the game
        unsigned short turn = 0; //First turn will be turn 0
        unsigned short nPlyrs; //Number of players
        Player *players = nullptr; //An array that stores information about each player
        Dice dice{DICE}; //A set of dice to be used in the game
    public:
        Game(); //Constructor
        ~Game() { //Destructor
            delete []players;
        }
        static unsigned short getMAX(); //Retrieve MAX
        //Since the last function is static, it can be retrieved before a Game object is created
        unsigned short getNPlyrs() const { //Retrieve the number of players
            return nPlyrs;
        }
        short getScr(int player, int ctgry) const { //Retrieve the player's score in a category
            short temp;
            temp = players[player].ctgries.getCont(ctgry);
            return temp;
        }
        string getName(int) const; //Retrieve the name of a player
        void setNPlyrs(short); //Set the number of players
        void setPlyr(string, int); //Set a specific player
        void setTurn() { //Increment turn
            turn++;
        };
        unsigned short getTurn() { //Retrieve the turn number
            return turn;
        }
        void round(); //Play a round
        void numRoll(short &); //Check how many dice the user wants to roll
        void reroll(const short, short &); //Check which dice the user wants to reroll
        void vwRoll(); //Display the user's roll
        void slctCat(int, short &); //Allow the user to select which category they would
        //like to save their score to
        void setScr(int, short); //Analyze the player's roll and calculate their score
        //then set the score in their chosen category
        void lastScr(int); //Calculate a player's score at the end of the game
        friend ostream &operator << (ostream &, const Game &);
};

#endif /* GAME_H */