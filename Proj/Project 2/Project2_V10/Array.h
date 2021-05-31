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

template <class T>
class Array {
    private:
        unsigned short size;
        T *content;
    public:
        ~Array() { //Destructor
            delete []content;
        }
        void setSize(short n); //Set the size of the Array
        void prntAry(T); //Display the contents of the Array
        void ascSort(); //Sort the array into ascending order
        void dscSort(); //Sort the array into descending order
        virtual void newAry(short); //Classes that inherit can deal with initializing new Arrays
        void dupSort(); //This will take the array and move any duplicate entries to the end of the array
        void setCont(int, T); //Set the contents of the Array
        short getCont(int) const; //Retrieve the content at a specified index of the Array
        short getSize() { //Retrieve the size of the Array
            return size;
        }
};

template <class T>
void Array<T>::setSize(short n) {
    if (n > 0) {
        size = n;
        content = new T[n];
    }
}

//setCont will only populate valid array indices
template <class T>
void Array<T>::setCont(int index, T value) {
    if (index >= 0 && index < size) {
        content[index] = value;
    }
}

//Like setCont, getCont will only return information for valid array indices
template <class T>
short Array<T>::getCont(int index) const {
    if (index >= 0 && index < size) {
        return content[index];
    }
    return 0;
}

template <class T>
void Array<T>::ascSort() {
    for (int i = 0; i < (size - 1); i++) {
        for (int j = (i + 1); j < size; j++) {
            if (content[i] > content[j]) {
                T temp = content[i];
                content[i] = content[j];
                content[j] = temp;
            }
        }
    }
}

template <class T>
void Array<T>::dscSort() {
    for (int i = 0; i < (size - 1); i++) {
        for (int j = (i + 1); j < size; j++) {
            if (content[i] < content[j]) {
                T temp = content[i];
                content[i] = content[j];
                content[j] = temp;
            }
        }
    }
}

template <class T>
void Array<T>::dupSort() {
    for (int i = 0; i < size; i++) {
        T temp;
        if (content[i] == content[(i + 1)]) {
            temp = content[i];
            
            for (int j = i; j < size; j++) {
                content[j] = content[(j + 1)];
            }
            content[(size-1)] = temp;
        }
    }
}

template <class T>
void Array<T>::newAry(short s) {
    setSize(s);
    for (int i = 0; i < size; i++) {
        setCont(i, 0);
    }
}

#endif /* ARRAY_H */