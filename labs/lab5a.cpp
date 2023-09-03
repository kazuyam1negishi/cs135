/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 5A
* Description: Makes a triangle with the size given to program
* Input: Any given number between 2 and 20
* Output: Two triangles (upside down and right side up)
* that are the size requested by the user
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    // Asks user for a value between 2 and 20
    int starCount = 0;
    /*Checks if the input succeeded and if the
    value is between 2 and 20. If not, the program
    clears the input and asks for another one.*/
    do{
        cout << "Enter a count between 2 and 20\n**";
        cin >> starCount;
        if(cin.fail() || starCount <= 1 || starCount > 20){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError: Invalid entry, please retry\n";
        }
    }while(cin.fail() || starCount <= 1 || starCount > 20);
    cout << endl;
    // Variable used for the for loop
    int count = 0;
    count = starCount;
    /* Draws upside down triangle
    by determining width of lines
    based on how close j is to i.*/
    for(int i = count; i > 0; i--){
        for(int j = 0; j < i; j++){
            cout << "*";
        }
        cout << endl;
    }
    // Variable used for while loop
    int row = 1;
    /*Draws right side up triangle
    by setting width to same value
    as row, which increments after
    each row is drawn.*/
    while(row < count + 1){
        row++;
        cout << setfill('*') << setw(row) << "*\n";
    }
}