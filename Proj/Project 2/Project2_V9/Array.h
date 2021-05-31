/* 
 * File:   Array.h
 * Author: Morgan Wild
 * Created on May 27, 2021, 9:21 AM
 * Purpose: Array class specification
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <string>
using namespace std;

class Array {
    private:
        unsigned short size;
        short *content;
    public:
        ~Array() { //Destructor
            delete []content;
        }
        void setSize(short n); //Set the size of the Array
        void prntAry(short); //Display the contents of the Array
        void ascSort(); //Sort the array into ascending order
        void dscSort(); //Sort the array into descending order
        virtual void newAry(short); //Classes that inherit can deal with initializing new Arrays
        void dupSort(); //This will take the array and move any duplicate entries to the end of the array
        void setCont(int, short); //Set the contents of the Array
        short getCont(int) const; //Retrieve the content at a specified index of the Array
        short getSize() { //Retrieve the size of the Array
            return size;
        }
};

#endif /* ARRAY_H */