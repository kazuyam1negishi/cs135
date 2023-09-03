/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Assignment 5
* Description: Finds traffic violations with text input
* Input: Filename for text file with data of vehicles
* Output: All vehicles that were speeding in the form of a text file with date.
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    vector<string> plates, date, time;
    vector<int> weight, speed;
    ifstream(fileReader);
    do{
        // Asks user for a file to open.
        string filename = " ";
        cout << "Open file: ";
        getline(cin, filename);
        fileReader.open(filename);
        /* Checks to see if filename is
        valid. If not, the program asks
        for another file name. */
        if(fileReader.is_open() == false){
            cout << "Could not open " << filename << "\n";
            cin.clear();
        }
    } while(fileReader.is_open() == false);
    // Integer for number of writes
    int writes = 0;
    // Int for finding commas in input
    int comma = 0;
    while(fileReader.eof() == false){
        // Gets info from text input
        string input = " ";
        getline(fileReader, input);
        // Finds license plates and inputs as string
        comma = input.find(',');
        plates.push_back(input.substr(0, comma));
        input = input.substr(comma + 1, input.length());
        // Finds date and inputs as string
        comma = input.find(',');
        date.push_back(input.substr(0, comma));
        input = input.substr(comma + 1, input.length());
        // Finds time and inputs as string
        comma = input.find(',');
        time.push_back(input.substr(0, comma));
        input = input.substr(comma + 1, input.length());
        // Finds weight of car and inputs as int
        comma = input.find(',');
        weight.push_back(stoi(input.substr(0, comma)));
        input = input.substr(comma + 1, input.length());
        // Inputs speed of car as int
        speed.push_back(stoi(input));
        writes++;
    }
    // Closes file, now that we're done with it.
    fileReader.close();
    // Stream for output file
    ofstream(fileWriter);
    // Integer for number of violations
    int violations = 0;
    // Opens file with first date
    fileWriter.open("["+date.at(0)+"]"" Report.txt");
    // Variable for latest violation
    string lastViolation = date.at(0);
    for(int i = 0; i < writes; i++){
        // Checks if car is over 5k lbs and going > 30 mph
        if(weight.at(i) >= 5000 && speed.at(i) > 30){
            // Checks if date changed, if so, new file opens
            if(date.at(i) == lastViolation){
                fileWriter << "[" << time.at(i) << "] " << plates.at(i) << endl;
                violations++;
            }
            // Here, new file opens
            else{
                fileWriter.close();
                fileWriter.open("["+date.at(i)+"]"" Report.txt");
                fileWriter << "[" << time.at(i) << "] " << plates.at(i) << endl;
                violations++;
                lastViolation = date.at(i);
            }
        }
        // Checks if car is less than 5k lbs and going > 45 mph
        else if(weight.at(i) < 5000 && speed.at(i) > 45){
            // Checks if date changes, if so, new file opens
            if(date.at(i) == lastViolation){
                fileWriter << "[" << time.at(i) << "] " << plates.at(i) << endl;
                violations++;
            }
            // Here, new file opens
            else{
                fileWriter.close();
                fileWriter.open("["+date.at(i)+"]"" Report.txt");
                fileWriter << "[" << time.at(i) << "] " << plates.at(i) << endl;
                violations++;
                lastViolation = date.at(i);
            }
        }
    }
    // Reports total number of violations
    cout << violations << " violations logged.\n";
    // Closes writer for text file.
    fileWriter.close();
}