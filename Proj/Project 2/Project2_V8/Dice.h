/* 
 * File:   Dice.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 12:56 PM
 * Purpose: Dice class specification
 */

#ifndef DICE_H
#define DICE_H

#include "Array.h"

class Dice : public Array { //Make Dice inherit from Array so that it can use
    //the sorting functions found in Array
    private:
        unsigned short roll; //This will store the number rolled
    public:
        void setRoll(int); //This will randomize a number and store it in roll
        unsigned short getRoll(int); //This will retrieve roll
        void newAry(short);
};

#endif /* DICE_H */