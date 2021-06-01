/* 
 * File:   Player.cpp
 * Author: Morgan Wild
 * Created on May 26, 2021, 9:25 AM
 * Purpose: Player class specification
 */

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

#include "Player.h"
#include "Ctgries.h"

Player::Player() {
    setScr(0);
    setBns(0);
}

void Player::setScr(unsigned short s) {
   score = s; 
}

void Player::setBns(unsigned short b) {
    bonus = b;
}

ostream &operator << (ostream &stream, const Player &obj) {
    stream << "--------------------" << endl << obj.name << endl;
    stream << left << setw(20) << "1. Aces" << setw(20) << "2. Twos" << setw(20) << "3. Threes" 
            << setw(20) << "4. Fours" << setw(20) << "5. Fives"
            << setw(20) << "6. Sixes" << endl;
    
    for (int i = 0; i < 6; i++) {
        if (obj.ctgries.getCont(i) == -1) {
            stream << setw(20) << "Empty";
        } else {
            stream << setw(20) << obj.ctgries.getCont(i);
        }
    }
    
    stream << endl;
    stream << setw(20) << "7. 3 of a kind" <<  setw(20) << "8. 4 of a kind" << endl;
    for (int i = 6; i < 8; i++) {
        if (obj.ctgries.getCont(i) == -1) {
            stream << setw(20) << "Empty";
        } else {
            stream << setw(20) << obj.ctgries.getCont(i);
        }
    }
    
    stream << endl << setw(20) << "9. Full house" << setw(20) << "10. SM Straight" << setw(20) << "11. LG Straight" << endl;
    for (int i = 8; i < 11; i++) {
        if (obj.ctgries.getCont(i) == -1) {
            stream << setw(20) << "Empty";
        } else {
            stream << setw(20) << obj.ctgries.getCont(i);
        }
    }
    stream << endl << setw(20) << "12. Yahtzee" << setw(20) << "13. Chance" << endl;
    for (int i = 11; i < 13; i++) {
        if (obj.ctgries.getCont(i) == -1) {
            stream << setw(20) << "Empty";
        } else {
            stream << setw(20) << obj.ctgries.getCont(i);
        }
    }
    stream << endl << "--------------------" << endl;
    return stream;
}

const short Player::MAX = 13;