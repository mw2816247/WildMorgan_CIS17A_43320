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
        Player *players = nullptr;
    public:
        ~Game() {
            delete []players;
        }
        unsigned short getNPlyrs() const {
            return nPlyrs;
        }
        char *getName(int) const;
        void setNPlyrs(short);
        void setPlyr(char *, int);
};

#endif /* GAME_H */

