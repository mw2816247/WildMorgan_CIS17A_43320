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

class Game;
ostream &operator << (ostream &, const Player &);
ostream &operator << (ostream &, const Game &);

class Player {
    private:
        unsigned short score, //The player's score
                bonus; //Any bonus points scored by the player
        static const short MAX; //Maximum number of categories
        string name; //The player's name
        Ctgries ctgries{MAX};
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
        static unsigned short getMAX(); //Retrieve MAX
        //Since the last function is static, it can be retrieved before a Player is created
        void setScr(unsigned short); //Set the player's score
        void setBns(unsigned short); //Set the player's bonus
        void setName(string n) { //Set the player's name
            name = n;
        }
        operator short() { //Used at the end to create an Array of the scores from the different players
            return score;
        }
        friend ostream &operator << (ostream &, const Player &); //When the << operator is combined with a
        //Player object, the Player's name and scores in each category will be printed
        friend class Game; //Allow the Game class to access private members of Player
        friend ostream &operator << (ostream &, const Game &);
};

#endif /* PLAYER_H */