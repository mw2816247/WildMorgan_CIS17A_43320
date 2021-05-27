/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 12:30 PM
 * Purpose: Read in weather data from a given text file and then analyze and output the weather data
 */

//System Libraries
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void displayMonths(char[][30], int);
void displayDays(char[][30], int);
void displayHighest(char[][30]);

int main(int argc, char** argv) {
    ifstream inFile;
    string fName; //to store file name
    char weather[3][30];
    int month,
            day;
   
    cout << "Enter the file name: ";
    cin >> fName;
    cout << endl;
    
    inFile.open(fName);
    
    for (month = 0; month < 3; month++) {
        for (day = 0; day < 30; day++) {
            inFile >> weather[month][day];
        }
    }
    
    inFile.close();
    
    for (int i = 0; i < 3; i++) {
        displayDays(weather, i);
    }
    
    for (int i = 0; i < 3; i++) {
        displayMonths(weather, i);
    }
    
    displayHighest(weather);
    
    cout << endl;
    
    return 0;
}

void displayDays(char weather[][30], int i) {
    const char wNames[] = {'R', 'C', 'S'}; //The different weather names contained in the file
    const string wTypes[] = {"rainy", "cloudy", "sunny"}; //The three types of weather
    const string months[] = {"June", "July", "August"};
    int total; //The total number of days for the specified weather type in an specified month
    
    for (int month = 0; month < 3; month++) {
        total = 0;
        
        for (int day = 0; day < 30; day++) {
            if (weather[month][day] == wNames[i]) {
                total++;
            }
        }
        cout << "Total " << wTypes[i] << " days for " << months[month] << " = " << total << endl; 
    }
    cout << endl;
}

void displayMonths(char weather[][30], int i) {
    const char wNames[] = {'R', 'C', 'S'}; //The different weather names contained in the file
    const string wTypes[] = {"rainy", "cloudy", "sunny"}; //The three types of weather
    int total = 0; //The total number of days for the specified weather type in all months
    
    for (int month = 0; month < 3; month++) {
        for (int day = 0; day < 30; day++) {
            if (weather[month][day] == wNames[i]) {
                total++;
            }
        }
    }
    
    cout << "Total " << wTypes[i] << " days for all months = " << total << endl;
}

void displayHighest(char weather[][30]) {
    const string months[] = {"June", "July", "August"};
    int sum, //Sum of rainy days in a given month
            maxRain; //Maximum number of rainy days
    string maxMnth; //Month(s) with the maximum number of rainy days
    int totRny[3]; //Array to store total number of rainy days in each month
    
    for (int month = 0; month < 3; month++) {
        sum = 0;
        for (int day = 0; day < 30; day++) {
            if (weather[month][day] == 'R') {
                sum++;
            }
        }
        totRny[month] = sum;
    }
    
    cout << endl;
    
    maxRain = totRny[0];
    maxMnth = months[0];
    
    for (int month = 1; month < 3; month++) {
        if (totRny[month] > maxRain) {
            maxRain = totRny[month];
            maxMnth = months[month];
        } else if (totRny[month] == maxRain) {
            maxRain = totRny[month];
            maxMnth += ", ";
            maxMnth += months[month];
        }
    }
    
    cout << maxMnth << " had the most rainy days, with " << maxRain << " rainy days." << endl;
}