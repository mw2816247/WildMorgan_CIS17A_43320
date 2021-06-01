/* 
 * File:   Dice.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 12:56 PM
 * Purpose: Dice class specification
 */

#ifndef DICE_H
#define DICE_H

#include "Array.h"

class Dice : public Array<unsigned short> { //Make Dice inherit from Array so that it can use
    //the sorting functions found in Array
    private:
        unsigned short roll; //This will store the number rolled
    public:
        Dice() {}; //Constructor
        Dice(const Dice &); //Copy constructor
        void setRoll(int); //This will randomize a number and store it in roll
        unsigned short getRoll(int); //This will retrieve roll
        void newAry(short); //Take a specified number and create an array of that size
        //Using this will allow the program to later sort the dice using Array's built-in sort functions
};

#endif /* DICE_H */