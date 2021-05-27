/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 10:07 AM
 * Purpose: Convert temperatures between 0 and 20 degrees Fahrenheit to degrees Celsius and display the conversions
 */

#include <iostream>
#include <iomanip>
using namespace std;

float celsius(unsigned short);

int main(int argc, char** argv) {
    unsigned short fTemp; //Temperature in Fahrenheit
    float cTemp; // Temperature in Celsius
    
    fTemp = 0;
    
    cout << setw(20) << "Fahrenheit" << setw(20) << "Celsius" << endl;
    
    for (unsigned short i = 0; i <= 20; i++){
        cTemp = celsius(fTemp);
        
        cout << setw(20) << fTemp << setw(20) << cTemp << endl;
        
        fTemp++;
    }

    return 0;
}

float celsius(unsigned short fTemp) {
    float cTemp; //Temperature in Celsius
    
    cTemp = ((fTemp-32) * 5.0 / 9.0);
    
    return cTemp;        
}