/* 
 * File:   Game.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 10:20 AM
 * Purpose: Game class specification
 */

#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game {
    private:
        unsigned short nPlyrs; //Number of players
        Player *players = nullptr; //An array that stores information about each player
    public:
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
        char *getName(int) const; //Retrieve the name of a player
        void setNPlyrs(short); //Set the number of players
        void setPlyr(char *, int); //Set a specific player
};

#endif /* GAME_H */

