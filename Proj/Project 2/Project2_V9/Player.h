/* 
 * File:   Player.h
 * Author: Morgan Wild
 * Created on May 26, 2021, 9:25 AM
 * Purpose: Player class specification
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Ctgries.h"

class Player;

ostream &operator << (ostream &, const Player &);

class Player {
    private:
        unsigned short score, //The player's score
                bonus; //Any bonus points scored by the player
        static const int MAX = 13; //Maximum number of categories
        string name; //The player's name
        Ctgries ctgries;
    public:
        Player(); //Constructor
        unsigned short getScr() const { //Retrieve the player's score
            return score;
        }
        unsigned short getBns() const { //Retrieve the player's bonus
            return bonus;
        }
        string getName() { //Retrieve the player's name
            return name;
        }
        static unsigned short getNAME(); //Retrieve NAME
        static unsigned short getMAX(); //Retrieve MAX
        //Since the last two functions are static, they can be retrieved before a Player is created
        //For instance, you can size a char array to hold the name of the Player
        //and then pass this array to the Player object when setting the name
        void setScr(unsigned short); //Set the player's score
        void setBns(unsigned short); //Set the player's bonus
        void setName(string n) { //Set the player's name
            name = n;
        }
        void newAry(short); //Override Array's newAry function
        operator short() { //Could be used when computing positions at the end
            return score;
        }
        friend ostream &operator << (ostream &, const Player &); //When the << operator is combined with a
        //Player object, the Player's name and scores in each category will be printed
        friend class Game; //Allow the Game class to access private members of Player
};

#endif /* PLAYER_H */