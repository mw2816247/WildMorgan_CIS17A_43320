/* 
 * File:   Ctgries.h
 * Author: Morgan Wild
 * Created on May 31, 2021, 9:43 AM
 * Purpose: Ctgries class specification
 */

#ifndef CTGRIES_H
#define CTGRIES_H

#include "Array.h"

class Ctgries : public Array<short> {
    private:
        
    public:
        Ctgries();
        void newAry(); //Initialize the Ctgries array
        operator short(); //Used in calculating the user's final score. It iterates through each category and
        //returns the sum of the scores from each category
};

#endif /* CTGRIES_H */

