/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 7B
* Description: Finds hottest and coldest month of the year for city,
* along with the average low and high temp of the year.
* Input: Text file name, which inputs:
* city (string), year (int), and temp values (float).
* Output: Highest and lowest temp of the year and average over 12 months.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
    // Text input stream.
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
    // String to store city name
    string city = " ";
    // Integer for year in question 
    int year = 0;
    // Writes city and year to vars
    fileReader >> city >> year;
    // Array for monthly temp values
    float tempsArray[2][12];
    // Doubles for low and high averages
    double lowAverage = 0.0;
    double highAverage = 0.0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 2; j++){
            // Writes temp values to array
            fileReader >> tempsArray[j][i];
        }
        // Adds low temp values together
        lowAverage += tempsArray[0][i];
        // Adds high temp values together
        highAverage += tempsArray[1][i];
    }
    // Doubles for record lows and highs
    double lowestTemp = 100.0;
    double highestTemp = 0.0;
    // Finds them by comparing current value to array value
    for(int i = 0; i < 12; i++){
        if(tempsArray[0][i] < lowestTemp){
            lowestTemp = tempsArray[0][i];
        }
        if(tempsArray[1][i] > highestTemp){
            highestTemp = tempsArray[1][i];
        }
    }
    // Reports all the info to the terminal.
    cout << fixed << setprecision(2) << endl << city << " " << year << endl;
    cout << "Lowest temperature of the year was "
    << lowestTemp << "° F." << endl;
    cout << "Highest temperature of the year was "
    << highestTemp << "° F." << endl;
    cout << "Average low temperature of the year was "
    << lowAverage / 12 << "° F." << endl;
    cout << "Average high temperature of the year was "
    << highAverage / 12 << "° F." << endl;
}