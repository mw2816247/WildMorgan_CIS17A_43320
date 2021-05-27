/* 
 * File:   Player.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 9:25 AM
 * Purpose: Player class specification
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Array.h"

class Player : public Array {
    private:
        unsigned short score, //The player's score
                bonus; //Any bonus points scored by the player
        static const int NAME = 80, //Will give them 80 characters for their name
                MAX = 13; //Maximum number of categories
        char name[NAME]; //The player's name
    public:
        Player(); //Constructor
        unsigned short getScr() const { //Retrieve the player's score
            return score;
        }
        unsigned short getBns() const { //Retrieve the player's bonus
            return bonus;
        }
        char *getName() { //Retrieve the player's name
            return name;
        }
        static unsigned short getNAME(); //Retrieve NAME
        static unsigned short getMAX(); //Retrieve MAX
        //Since the last two functions are static, they can be retrieved before a Player is created
        //For instance, you can size a char array to hold the name of the Player
        //and then pass this array to the Player object when setting the name
        void setScr(unsigned short); //Set the player's score
        void setBns(unsigned short); //Set the player's bonus
        void setName(char *); //Set the player's name
        void newAry(short); //Override Dice's newAry function
};

#endif /* PLAYER_H */