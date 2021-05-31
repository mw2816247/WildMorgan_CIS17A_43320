/* 
 * File:   Array.h
 * Author: Morgan Wild
 * Created on May 27, 2021, 9:38 AM
 * Purpose: Array class specification
 */

#include "Array.h"
#include <cstdlib>
#include <string>
using namespace std;


void Array::setSize(short n) {
    if (n > 0) {
        size = n;
        content = new short[n];
    }
}

//setCont will only populate valid array indices
void Array::setCont(int index, short value) {
    if (index >= 0 && index < size) {
        content[index] = value;
    }
}

//Like setCont, getCont will only return information for valid array indices
short Array::getCont(int index) const {
    if (index >= 0 && index < size) {
        return content[index];
    }
    return 0;
}

void Array::ascSort() {
    for (int i = 0; i < (size - 1); i++) {
        for (int j = (i + 1); j < size; j++) {
            if (content[i] > content[j]) {
                int temp = content[i];
                content[i] = content[j];
                content[j] = temp;
            }
        }
    }
}

void Array::dscSort() {
    for (int i = 0; i < (size - 1); i++) {
        for (int j = (i + 1); j < size; j++) {
            if (content[i] < content[j]) {
                int temp = content[i];
                content[i] = content[j];
                content[j] = temp;
            }
        }
    }
}

void Array::dupSort() {
    for (int i = 0; i < size; i++) {
        int temp;
        if (content[i] == content[(i + 1)]) {
            temp = content[i];
            
            for (int j = i; j < size; j++) {
                content[j] = content[(j + 1)];
            }
            content[(size-1)] = temp;
        }
    }
}

void Array::newAry(short s) {
    setSize(s);
    for (int i = 0; i < size; i++) {
        setCont(i, 0);
    }
}