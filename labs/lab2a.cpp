/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 2A
* Description: programs that converts degrees to radians and performs trig functions
* Input: one angle in degrees
* Output: degrees value in radians, along with sin, cos and tan of degrees
*/ 

#include <iostream>
#include <cmath>
using namespace std;

// constant value for pi
const double PI = 3.141592;
int main()
{
    // asks for value, which is then stored
    cout << "Enter an angle value, in degrees" << endl << "**";
    double degrees = 0.0;
    cin >> degrees;
    // converts degrees into radians
    double radians = 0.0;
    radians = (degrees * PI)/180;
    // reports radians and sin, cos and tan in console
    cout << endl << degrees << " degrees = " << radians << " radians" << endl;
    cout << "sin(" << degrees << ") = " << sin(radians) << endl;
    cout << "cos(" << degrees << ") = " << cos(radians) << endl;
    cout << "tan(" << degrees << ") = " << tan(radians) << endl;
}