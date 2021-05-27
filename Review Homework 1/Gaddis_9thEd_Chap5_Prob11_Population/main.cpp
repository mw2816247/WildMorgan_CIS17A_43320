/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 10:07 AM
 * Purpose: Calculate population growth over a given number of days
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int pop, //population
            days;
    float avgInc; //average daily population increase
    
    cout << "Please enter the starting number of organisms: ";
    cin >> pop;
    
    while (pop < 2) {
        cout << "The starting number of organism cannot be less than 2. Please try again." << endl;
        cout << "Please enter the starting number of organisms: ";
        cin >> pop;
    }
    
    cout << "Please enter the average daily population increase (as a percentage): ";
    cin >> avgInc;
    
    while (avgInc < 0) {
        cout << "The average daily population increase cannot be negative. Please try again." << endl;
        cout << "Please enter the average daily population increase (as a percentage): ";
        cin >> avgInc;
    }
    
    cout << "Please enter the number of days the population will multiply for: ";
    cin >> days;
    
    while (days < 1) {
        cout << "The number of days cannot be less than 1. Please try again." << endl;
        cout << "Please enter the number of days the population will multiply for: ";
        cin >> days;
    }
    
    for (int i = 1; i <= days; i++) {
        pop = (pop * (avgInc / 100.0) + pop);
        
        cout << "The population after " << i << " day(s) is " << pop << "." << endl;
    }

    return 0;
}