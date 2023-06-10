/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 7A
* Description: Reads in a series numbers into a multidimensional
* array, then outputs all the numbers along with the sum of the
* rows and columns.
* Input: Text file name (string)
* Output: All the numbers in the text file in rows and columns,
* along with the sum of each row and column.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    // File stream
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
            cout << "\nError: Invalid file name\n";
            cin.clear();
        }
    } while(fileReader.is_open() == false);
    // Variable used to declare array (with set values)
    double array[7][10];
    // Initializes array
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 10; j++){
            array[i][j] = 0;
        }
    }
    // Variable for sum of rows and columns
    double sum = 0.0;
    /* Prints out rows of numbers, then adds
    then together and reports all info to terminal. */
    cout << "\nROW SUMS: \n";
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 10; j++){
            // Writes value to array
            fileReader >> array[i][j];
            // Adds all values to sum
            sum += array[i][j];
            cout << fixed << left << setw(4) << setprecision(1) << array[i][j];
            // Only adds + up until the last number
            if(j < 9){
                cout << " + ";
            }
        }
        cout << " = " << sum;
        // Sets sum back to 0 for calculating next value
        sum = 0.0;
        cout << "\n";
    }
    /* Prints out columns of numbers, then adds
    then together and reports all info to terminal. */
    cout << "\nCOLUMN SUMS: \n";
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 7; j++){
            // Adds all values to sum
            sum += array[j][i];
            // Prints out values sideways
            cout << fixed << left << setw(4) << setprecision(1) << array[j][i];
            // Only adds + up until the last number
            if(j < 6){
                cout << " + ";
            }
        }
        // 
        cout << " = " << sum;
        // Sets sum back to 0 for calculating next value
        sum = 0.0;
        cout << "\n";
    }
}