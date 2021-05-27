/* 
 * File:   Dice.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 1:05 PM
 * Purpose: Dice class specification
 */

#include "Dice.h"
#include <ctime>
#include <cstdlib>
using namespace std;

void Dice::setRoll() {
    srand(static_cast<unsigned int>(time(0)));
    roll = rand() % 6 + 1;
}

unsigned short Dice::getRoll() {
    return roll;
}