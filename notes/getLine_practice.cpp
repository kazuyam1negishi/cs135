#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fileReader("names.txt");
    while(fileReader.eof() == false){
        string lastName = "";
        string firstName = "";
        string middleName = "";

        string newName = "";

        getline(fileReader,lastName,',');
        getline(fileReader,firstName,',');
        getline(fileReader,middleName);

        newName += firstName;
        newName += " ";
        newName += middleName[0];
        newName += ". ";
        newName += lastName;

        cout << newName << endl;
    }

}