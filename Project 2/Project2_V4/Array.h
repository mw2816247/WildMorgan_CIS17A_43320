/* 
 * File:   Array.h
 * Author: Morgan Wild
 * Created on May 27, 2021, 9:21 AM
 * Purpose: Array class specification
 */

#ifndef ARRAY_H
#define ARRAY_H

class Array {
    private:
        unsigned short size;
        short *content;
    public:
        ~Array() {
            delete []content;
        }
        void setSize(short n) {
            if (n > 0) {
                size = n;
                content = new short[n];
            }
        }
        void prntAry(short);
        void ascSort(); //Sort the array into ascending order
        void dscSort(); //Sort the array into descending order
        virtual void newAry(short) = 0; //Classes that inherit will deal with initializing new Arrays
        void dupSort(); //This will take the array and move any duplicate entries to the end of the array
        void setCont(int, short);
        short getCont(int) const;
        short getSize() {
            return size;
        }
};

#endif /* ARRAY_H */

