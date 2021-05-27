/* 
 * File:   Game.cpp
 * Author: Morgan Wild
 * Created on May 26, 2021, 10:40 AM
 * Purpose: Game class specification
 */

#include <string>

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

void Game::setPlyr(char *n, int index) {
    players[index].setName(n);
}

char *Game::getName(int index) const {
    return players[index].getName();
}