/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 3A
* Description: Determines which of two floats and two strings is the largest
* Input: Two floating point no's and two strings
* Output: The larger of the two floating point no's and strings
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Asks for two floating point no's, output as doubles
    cout << "Enter a floating point number" << endl << "**";
    double firstFloat = 0.0;
    cin >> firstFloat;
    cout << endl << "Enter another floating point number" << endl << "**";
    double secondFloat = 0.0;
    cin >> secondFloat;
    cout << endl << "You entered " << firstFloat << " and " << secondFloat
    << endl << "The largest is ";
    /* Determines if first or second float is larger,
    then outputs largest float to the terminal */
    if(firstFloat > secondFloat)
        cout << firstFloat << endl;
    else
        cout << secondFloat << endl;
    // Asks for two strings, output to terminal
    cout << endl << "Enter a string" << endl << "**";
    string firstString = "a";
    cin >> firstString;
    cout << endl << "Enter a second string" << endl << "**";
    string secondString = "b";
    cin >> secondString;
    cout << endl << "You entered \"" << firstString << "\" and \"" << secondString
    << "\"" << endl << "The largest is \"";
    /* Determines if first or second string is larger,
    then outputs largest string to the terminal */
    if(firstString > secondString)
        cout << firstString << "\"" << endl;
    else
        cout << secondString << "\"" << endl;
    return(0);
}