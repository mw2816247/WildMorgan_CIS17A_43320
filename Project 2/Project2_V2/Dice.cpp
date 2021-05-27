/* 
 * File:   Dice.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 1:05 PM
 * Purpose: Dice class specification
 */

#include "Dice.h"

void Dice::setRoll() {
    roll = rand() % 6 + 1;
}

unsigned short Dice::getRoll() {
    return roll();
}