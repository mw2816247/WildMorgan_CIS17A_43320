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

void Dice::setRoll(int index) {
    roll = rand() % 6 + 1;
    setCont(index, roll);
}

unsigned short Dice::getRoll(int index) {
    short temp;
    temp = getCont(index);
    return temp;
}

void Dice::newAry(short numDice) {
    setSize(numDice);
    for (int i = 0; i < numDice; i++) {
        setRoll(i);
    }
}