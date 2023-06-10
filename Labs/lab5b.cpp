/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 5B
* Description: Adds two numbers from a row in a file and adds total of all no.'s
* Input: Text file name (string)
* Output: Sums of both numbers in a row, and the total of all the sums
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    /* Sets up variable for strings
    incoming from text file. */
    ifstream(fileReader);
    do{
        // Asks user for a file to open.
        string filename = " ";
        cout << "Enter file name \n**";
        getline(cin, filename);
        fileReader.open(filename);
        /* Checks to see if filename is
        valid. If not, the program asks
        for another file name. */
        if(fileReader.is_open() == false){
            cout << "\nError: Invalid file name\n";
            cin.clear();
        }
    } while(fileReader.is_open() == false);
    cout << "\n";
    /* Variables used for holding running total,
    sum of two numbers at a given time, and the
    numbers input from the file. */
    int tempSum = 0;
    int runningTotal = 0;
    int num1 = 0; int num2 = 0;
    /* Uses numbers from opened file until
    the end of the file is reached. If any
    input fails, the row is skipped and
    the program continues.*/
    while(fileReader.eof() == false){
        fileReader >> num1 >> num2;
        if(fileReader.fail()){
            fileReader.clear();
            fileReader.ignore(100, '\n');
            cout << "Error in line\n";
            continue;
        }
        tempSum = num1 + num2;
        // Reports two number sum to terminal
        cout << num1 << " + " << num2 << " = " << tempSum << "\n";
        // Adds current sum to running total
        runningTotal = runningTotal + tempSum;
    }
    // Reports running total to terminal
    cout << "\nRunning total = " << runningTotal << "\n";
    return(0);
}