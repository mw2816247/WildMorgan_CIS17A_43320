/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 9:48 AM
 * Purpose: Convert temperature in degrees Celsius to degrees Fahrenheit
 */

#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    float celsius, //Temperature in degrees Celsius
            fhrnht; //Temperature in degrees Fahrenheit
    
    cout << "Please enter the temperature in degrees Celsius" << endl;
    cin >> celsius;
    
    fhrnht = ((9.0 / 5.0) * celsius) + 32;
    
    cout << "The temperature is " << fhrnht << " degrees Fahrenheit." << endl;
    
    return 0;
}