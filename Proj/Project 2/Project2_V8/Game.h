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

class Game {
    private:
        enum Ctgry { ACES, TWOS, THREES, FOURS, FIVES, SIXES,
            THRKIND, FRKIND, FULLHS, SMSTRT, LGSTRT, YAHTZEE,
            CHANCE };
        const unsigned short MAX = 13, //Maximum number of turns
                DICE = 5;
        unsigned short turn = 0; //First turn will be turn 0
        unsigned short nPlyrs; //Number of players
        Player *players = nullptr; //An array that stores information about each player
        Dice dice; //A set of dice to be used in the game
    public:
        Game();
        ~Game() { //Destructor
            delete []players;
        }
        unsigned short getNPlyrs() const { //Retrieve the number of players
            return nPlyrs;
        }
        short getScr(int player, int ctgry) const { //Retrieve the player's score in a category
            short temp;
            temp = players[player].getCont(ctgry);
            return temp;
        }
        string getName(int) const; //Retrieve the name of a player
        void setNPlyrs(short); //Set the number of players
        void setPlyr(string, int); //Set a specific player
        void setTurn(unsigned short) { //Increment turn
            turn++;
        };
        unsigned short getTurn() { //Retrieve the turn number
            return turn;
        }
        void round();
        void numRoll(short &);
        void reroll(const short, short &);
        void vwRoll();
        void slctCat(int, short &);
        void setScr(int, short);
        void play();
        void results();
        void lastScr(int);
};

#endif /* GAME_H */