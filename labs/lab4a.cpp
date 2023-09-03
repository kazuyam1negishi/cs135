/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 4A
* Description: Counts from one number to another with a certain increment
* Input: 3 integers (Starting number, final number, and counting increment)
* Output: Any values between start and finish that fall in increment
*/

#include <iostream>
#include <limits>
using namespace std;

int main()
{
    // Asks user for a starting number, stored as an integer
    cout << "Enter a starting number\n**";
    int startingNumber = 0;
    cin >> startingNumber;
    /* Checks to see if value is an integer
    Fails if false, continues if true */
    if(cin.fail())
    {
        cout << "\nError: invalid entry.";
        return(0);
    }
    // Asks user for an ending number, stored as an integer
    cout << "\nEnter an ending number\n**";
    int endingNumber = 0;
    cin >> endingNumber;
    /* Checks if value is an integer larger than starting number
    Fails if false, continues if true */
    if(cin.fail())
        {
        cout << "\nError: invalid entry.";
        return(0);
        }
    if(startingNumber >= endingNumber)
        {
            cout << "\nError: end must be greater than start.";
            return(0);
        }
    // Asks user for an incrementing value
    cout << "\nEnter a value to increment by\n**";
    int increment = 0;
    cin >> increment;
    // Again, checks if value is an integer
    if(cin.fail())
    {
        cout << "\nError: invalid entry.";
        return(0);
    }
    cout << endl;
    /* Takes the starting number and adds the increment value
    until it reaches or passes the ending number. If and when
    reached, program stops before printing another value. */
    while(startingNumber <= endingNumber){
        cout << startingNumber << " ";
        startingNumber = startingNumber + increment;
    }
}