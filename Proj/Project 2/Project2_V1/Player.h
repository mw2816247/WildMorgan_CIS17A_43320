/* 
 * File:   Player.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 9:25 AM
 * Purpose: Player class specification
 */

#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        unsigned short score,
                bonus;
        static const int NAME = 80, //Will give them 80 characters for their name
                MAX = 13; //Maximum number of categories
        char name[NAME];
        short ctgries[MAX];
    public:
        Player();
        unsigned short getScr() const {
            return score;
        }
        unsigned short getBns() const {
            return bonus;
        }
        char *getName() {
            return name;
        }
        short getCtgry(int index) {
            return ctgries[index];
        }
        static unsigned short getNAME();
        static unsigned short getMAX();
        void setScr(unsigned short);
        void setBns(unsigned short);
        void setName(char *);
        void setCtgry(int, short);
};

#endif /* PLAYER_H */