/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 3B
* Description: Asks for a letter grade, and outputs range that grade falls in
* Input: A letter grade (character, upper or lower case)
* Output: A range that said letter grade falls in
*/

#include <iostream>
using namespace std;

int main ()
{
    // Asks user for letter grade (not case sensitive)
    cout << "Enter a letter grade" << endl << "**";
    // Variable used and initialized
    char letterGrade = 'a';
    cin >> letterGrade;
    cout << endl;
    switch(letterGrade)
    {
        /* If letter grade is valid (A, B, C, D, or F),
        message is output to terminal. */
        case 'A':
        case 'a':
            cout << "Grade range is 90 - 100" << endl;
            return(0);
        case 'B':
        case 'b':
            cout << "Grade range is 80 - 89.99" << endl;
            return(0);
        case 'C':
        case 'c':
            cout << "Grade range is 70 - 79.99" << endl;
            return(0);
        case 'D':
        case 'd':
            cout << "Grade range is 60 - 69.99" << endl;
            return(0);
        case 'F':
        case 'f':
            cout << "Grade range is 0 - 59.99" << endl;
            return(0);
        // Tells user that character input is invalid, and no range is shown.
        default:
            cout << "Error: \'" << letterGrade << "\' is not a valid letter grade" << endl;
            return(0);
    }
}