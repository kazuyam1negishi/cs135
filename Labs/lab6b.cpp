/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 6B
* Description: Reads in names and scores from a text file
* into an array, then retrieves name and associated score
* Input: Text file name (string)
* Output: All names and scores, in forward and reverse order,
* the lowest and highest score in the class, the sum of all
* the scores, the class average and any students who have the
* name input in the terminal.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int ARRAY_SIZE = 100;

int main(){
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
    // Asks for a student name to be checked later
    string studentName = " ";
    cout << "\nEnter a name to search\n**";
    cin >> studentName;
    /* Variable used for no. of successful
    or failed writes and array indeces.*/ 
    int writes = 0;
    // Variables for arrays
    string names[ARRAY_SIZE];
    double scores[ARRAY_SIZE];
    // Reads in names and scores into arrays
    while(fileReader.eof() == false){
        fileReader >> names[writes] >> scores[writes];
        if(fileReader.fail() && fileReader.eof()){
            continue;
        }
        // Adds to successful write count
        writes++;
    }
    // Reports all names in standard order
    cout << "\nNames Forward: ";
    for(int i = 0; i < writes; i++){
        cout << names[i];
        if(i < writes - 1){
            cout << ", ";
        }
    }
    // Reports all scores in standard order
    cout << "\nScores Forward: ";
    for(int i = 0; i < writes; i++){
        cout << scores[i];
        if(i < writes - 1){
            cout << ", ";
        }
    }
    // Reports all names in reverse
    cout << "\nNames Reverse: ";
    for(int i = (writes - 1); i >= 0; i--){
        cout << names[i];
        if(i > 0){
            cout << ", ";
        }
    }
    // Reports all scores in reverse
    cout << "\nScores Reverse: ";
    for(int i = (writes - 1); i >= 0; i--){
        cout << scores[i];
        if(i > 0){
            cout << ", ";
        }
    }
    // Boolean for determining if a student is on the list
    bool studentFound = false;
    // Variable for no. of students with same name
    int studentCount = 0;
    // Determines how many students have the same name
    while(studentFound == false){
        for(int i = 0; i < writes; i++){
            if(names[i] == studentName){
                studentCount++;
                studentFound = true;
            }
        }
        /* Reports failure to terminal if no student exists with
        given name, then ends program.*/
        if(studentFound == false){
            cout << "\nError: " << studentName << " is not a student in the list";
            return(0);
        }
    }
    // Reports number of students with same name to terminal, if applicable.
    cout << endl << studentCount << " results for " << studentName;
    // Set output to two decimals for all values output from now.
    cout << fixed << setprecision(2);
    // Variables for biggest and smallest scores
    double maxNum = 0.0;
    double minNum = 100.0;
    /* Determines biggest and smallest score
    of the students with the same given name.*/
    for(int i = 0; i < writes; i++){
        if(scores[i] < minNum && studentName == names[i]){
            minNum = scores[i];
        }
        if(scores[i] > maxNum && studentName == names[i]){
            maxNum = scores[i];
        }
    }
    // Reports scores back to terminal
    cout << "\nMinimum: " << minNum;
    cout << "\nMaximum: " << maxNum;
    /* Variable for sum of scores
    of people with same given name.*/
    double sum = 0;
    for(int i = 0; i < writes; i++){
        if(studentName == names[i]){
            sum += scores[i];
        }
    }
    // Reports sum and average of scores to terminal.
    cout << "\nSum:     " << sum;
    cout << "\nAverage: " << sum/studentCount;
}