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
        unsigned short roll;
    public:
        void setRoll();
        unsigned short getRoll();
};

#endif /* DICE_H */

