/* 
 * File:   Ctgries.cpp
 * Author: Morgan Wild
 * Created on May 31, 2021, 9:43 AM
 * Purpose: Ctgries class specification
 */

#include "Ctgries.h"
#include "Array.h"

Ctgries::Ctgries() {
    newAry(); //Initialize each element with a score of -1 to flag that it's currently unused
}

void Ctgries::newAry() {
    setSize(13);
    for (int i = 0; i < getSize(); i++) {
        setCont(i, -1);
    }
}