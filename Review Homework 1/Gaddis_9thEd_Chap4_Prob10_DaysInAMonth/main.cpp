/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 10:07 AM
 * Purpose: Allow the user to enter a month and then display how many days are in that month
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    const unsigned char days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 29};
    unsigned char index;
    unsigned short month;
    int year;
    
    cout << "Enter the month (1-12): ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    
    while (month < 1 || month > 12) {
        cout << "The month you entered is invalid. Please enter a value in the range of 1-12: ";
        cin >> month;
    }
    
    if (month == 2) {
        if (year % 100 == 0 && year % 400 == 0) {
            index = 12;
        } else if (year % 4 == 0 && year % 100 != 0) {
            index = 12;
        } else {
            index = 1;
        }
    } else {
        index = month - 1;
    }
    
    cout << static_cast<int>(days[index]) << " days" << endl;
    
    return 0;
}