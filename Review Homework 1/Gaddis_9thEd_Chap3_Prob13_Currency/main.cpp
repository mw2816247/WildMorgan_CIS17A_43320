/* 
 * File:   main.cpp
 * Author: Morgan Wild
 * Created on February 19, 10:01 AM
 * Purpose: Convert dollars to yen and euros
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    const float YN_RATE = 98.93, //Yen conversion rate
            ER_RATE = 0.74; //Euro conversion rate
    float dollars,
            yen,
            euros;
    
    cout << "Enter the number of dollars: ";
    cin >> dollars;
    
    yen = dollars * YN_RATE;
    euros = dollars * ER_RATE;
    
    cout << setprecision(2) << fixed;
    cout << "Yen: " << yen << endl;
    cout << "Euros: " << euros << endl;
    
    return 0;
}