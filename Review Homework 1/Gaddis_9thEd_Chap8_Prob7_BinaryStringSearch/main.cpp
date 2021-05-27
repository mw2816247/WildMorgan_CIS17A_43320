/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 12:30 PM
 * Purpose: Sort an array of names, allow the user to search for a name, and then display where the name is in the array, if it exists
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

void selectionSort(string[], int);
void swap(string &, string &);
int binarySearch(string[], int, string);

//Execution Begins Here
int main(int argc, char** argv) {
    const int SIZE = 20;
    string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
                    "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
                    "Taylor, Terri", "Johnson, Jill",
                    "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
                    "James, Jean", "Weaver, Jim", "Pore, Bob",
                    "Rutherford, Greg", "Javens, Renee",
                    "Harrison, Rose", "Setzer, Cathy",
                    "Pike, Gordon", "Holland, Beth"};
    string inName; //to store name input by user
    int pstn; //position in array
    
    selectionSort(names, SIZE);
    
    cout << "Enter a name to search for: ";
    getline(cin, inName);
    
    pstn = binarySearch(names, SIZE, inName);
    
    if (pstn != -1) {
        cout << names[pstn] << " was found at position " << pstn << "." << endl;
    } else {
        cout << inName << " was not found." << endl;
    }
    return 0;
}

void selectionSort(string array[], int SIZE) {
    int minI; //minimum index
    string minVal; //minimum value
    
    for (int startI = 0; startI < (SIZE - 1); startI++) {
        minI = startI;
        minVal = array[startI];
        for (int i = startI + 1; i < SIZE; i++) {
            if (array[i] < minVal) {
                minVal = array[i];
                minI = i;
            }
        }
        swap(array[minI], array[startI]);
    }
}

void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

int binarySearch(string array[], int SIZE, string inName) {
    int first,
            last = SIZE - 1,
            middle,
            pstn = -1;
    bool found = false;
    
    while (found != true && first <= last) {
        middle = (first + last) / 2;
        
        if (array[middle] == inName) {
            pstn = middle;
            found = true;
        } else if (array[middle] > inName) {
            last = middle - 1;
        } else {
            first = middle + 1;
        }
    }
    return pstn;
}