/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 1B
* Description: Asks for int's and doubles and solves equations
* Input: two integers and two doubles
* Output: each integer used in an equation and 1st double divided by 2nd
*/ 

#include <iostream>
using namespace std;

int main()
{
    //Variables for integers
    long firstInt = 0;
    long secondInt = 0;
    //Variable for doubles
    double firstDouble = 0.0;
    double secondDouble = 0.0;
    //Asks for two integers
    cout << "Enter an integer" << endl << "**";
    cin >> firstInt;
    cout << endl << "Enter another integer" << endl << "**";
    //Prints out equations using two provided integers
    cin >> secondInt;
    cout << endl << firstInt << " + " << secondInt << " = " << firstInt+secondInt << endl;
    cout << firstInt << " - " << secondInt << " = " << firstInt-secondInt << endl;
    cout << firstInt << " * " << secondInt << " = " << firstInt*secondInt << endl;
    cout << firstInt << " / " << secondInt << " = " << firstInt/secondInt << endl;
    cout << firstInt << " % " << secondInt << " = " << firstInt%secondInt << endl;
    //Asks for two doubles
    cout << endl << "Enter a double" << endl << "**";
    cin >> firstDouble;
    cout << endl << "Enter another double" << endl << "**";
    cin >> secondDouble;
    //Prints out solution of 1st double divided by 2nd double
    cout << endl << firstDouble << " / " << secondDouble << " = " << firstDouble / secondDouble << endl;
}