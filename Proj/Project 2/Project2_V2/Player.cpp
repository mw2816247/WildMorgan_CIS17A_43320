/* 
 * File:   Player.cpp
 * Author: Morgan Wild
 * Created on May 26, 2021, 9:25 AM
 * Purpose: Player class specification
 */

#include <string>
using namespace std;

#include "Player.h"

Player::Player() {
    setScr(0);
    setBns(0);
}

void Player::setScr(unsigned short s) {
   score = s; 
}

void Player::setBns(unsigned short b) {
    bonus = b;
}

void Player::setName(char *n) {
    for (int i = 0; i < NAME; i++) {
        name[i] = n[i];
    }
}

void Player::setCtgry(int index, short score) {
    ctgries[index] = score;
}

unsigned short Player::getNAME() {
    return NAME;
}

unsigned short Player::getMAX() {
    return MAX;
}