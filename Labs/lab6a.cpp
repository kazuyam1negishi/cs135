/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 6A
* Description: Reads numbers from text file into an array,
* then performs arithmetic with all values in said array.
* Input: Text file name (string)
* Output: All values in increasing and decreasing value, the largest
* and smallest values of the array, the sum and the average of all the values.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 100;

int main(){
    /* Sets up variable for strings
    incoming from text file. */
    ifstream(fileReader);
    do{
        // Asks user for a file to open.
        string filename = " ";
        cout << "Enter a file name \n**";
        getline(cin, filename);
        fileReader.open(filename);
        /* Checks to see if filename is
        valid. If not, the program asks
        for another file name. */
        if(fileReader.is_open() == false){
            cout << "\nError: Invalid file name.\n";
            cin.clear();
        }
    } while(fileReader.is_open() == false);
    cout << "\n";
    // Variables to determine no. of successful and failed writes
    int writes = 0;
    int errorCount = 0;
    // Variable for array (Kudos if you get the reference!)
    double arraySeven[ARRAY_SIZE];
    // Writes input from file to array index in question.
    while(fileReader.eof() == false){
        fileReader >> arraySeven[writes];
        // If failed and at EOF, then continues
        if(fileReader.fail() && fileReader.eof()){
            continue;
        }
        // If failed and not at EOF, clears input and adds to err. count
        if(fileReader.fail() && fileReader.eof() == false){
            fileReader.clear();
            fileReader.ignore(256, '\n');
            cout << "Error: Invalid input in file.\n";
            errorCount++;
            continue;
        }
        // Only added if write successful
        writes++;
    }
    // Used to allow 2 decimal precision with all outputs.
    cout << fixed << setprecision(2);
    // Reports successful writes to terminal.
    cout << "\nAmount of Elements Read In: " << writes << endl;
    // Reports all numbers in order to terminal.
    cout << "Forwards: ";
    for(int i = 0; i < writes; i++){
        cout << arraySeven[i];
        if(i < writes - 1){
            cout << ", ";
        }
    }
    // Reports numbers to terminal backwards.
    cout << "\nBackwards: ";
    for(int i = (writes - 1); i >= 0; i--){
        cout << arraySeven[i];
        if(i > 0){
            cout << ", ";
        }
    }
    // Variables for biggest and smallest number
    double maxNum = 0.0;
    double minNum = 5.0;
    // Determines smallest and biggest number by comparing next no. in array
    for(int i = 0; i < writes; i++){
        if(arraySeven[i] < minNum){
            minNum = arraySeven[i];
        }
        if(arraySeven[i] > maxNum){
            maxNum = arraySeven[i];
        }
    }
    // Reports totals back to terminal
    cout << "\nMinimum: " << minNum;
    cout << "\nMaximum: " << maxNum;
    // Finds out the sum of all the numbers from array.
    double sum = 0;
    for(int i = 0; i < writes; i++){
        sum += arraySeven[i];
    }
    // Reports total sum to terminal
    cout << "\nSum: " << sum;
    // Reports average of all numbers to terminal
    cout << "\nAverage: " << sum/writes;
}