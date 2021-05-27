/* 
 * File:   Dice.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 12:56 PM
 * Purpose: Dice class specification
 */

#ifndef DICE_H
#define DICE_H

class Dice {
    private:
        unsigned short roll; //This will store the number rolled
    public:
        void setRoll(); //This will randomize a number and store it in roll
        unsigned short getRoll(); //This will retrieve roll
};

#endif /* DICE_H */

