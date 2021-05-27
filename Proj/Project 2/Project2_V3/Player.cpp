/* 
 * File:   Player.cpp
 * Author: Morgan Wild
 * Created on May 26, 2021, 9:25 AM
 * Purpose: Player class specification
 */

#include <string>
#include <iostream>
using namespace std;

#include "Player.h"
#include "Array.h"

Player::Player() {
    setScr(0);
    setBns(0);
    newAry(-1);
    //Initialize each category with a score of -1 to flag that it's currently unused
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

unsigned short Player::getNAME() {
    return NAME;
}

unsigned short Player::getMAX() {
    return MAX;
}

void Player::newAry(short value) {
    setSize(MAX);
    for (int i = 0; i < MAX; i++) {
        setCont(i, value);
    }
}