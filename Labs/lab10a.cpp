/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 10A
* Description: Uses struct to store student information and report to terminal
* Input: A student's full name and a grade as a number
* Output: A student's full name, grade and letter frade
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Struct used in the program
struct studentType{
    string firstName;
    string lastName;
    int grade;
    char letterGrade;
};

// Function prototypes
void getStudentData(studentType&);
void getLetterGrade(studentType&);
void printStudentData(studentType);

// Main, in case you forget where or what it is
int main(){
    // New student declared here
    studentType student;
    // Allows student data to be obtained
    getStudentData(student);
    getLetterGrade(student);
    // Reports info to terminal
    printStudentData(student);
}

// Function bodies
// Gets student's first and last name,
// and grade as a number from 0 to 4.
void getStudentData(studentType& student){
    cout << "Enter a first name\n**";
    cin >> student.firstName;
    cout << "\nEnter a last name\n**";
    cin >> student.lastName;
    // Bool for checking if valid entry
    bool validNum = false;
    // Runs while false
    while(validNum == false){
        cout << "\nEnter a grade\n**";
        cin >> student.grade;
        // If the input fails or is < 0 or > 4, fails and continues
        // without changing validNum.
        if(cin.fail() || student.grade < 0 || student.grade > 4){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError: Invalid grade";
            continue;
        }
        // If the statement above does not run, the bool becomes true.
        validNum = true;
    }
}
void getLetterGrade(studentType& student){
    // Matches number with
    // appropriate letter.
    if(student.grade == 4)
        student.letterGrade = 'A';
    if(student.grade == 3)
        student.letterGrade = 'B';
    if(student.grade == 2)
        student.letterGrade = 'C';
    if(student.grade == 1)
        student.letterGrade = 'D';
    if(student.grade == 0)
        student.letterGrade = 'F';
}
void printStudentData(studentType student){
    // Reports all info to terminal.
    cout << "\nData Entered\n" << fixed << right
         << "  student.firstName" << setw(5) << " = " << student.firstName << endl
         << "  student.lastName" << setw(6) << " = " << student.lastName << endl
         << "  student.grade" << setw(9) << " = " << student.grade << endl
         << "  student.letterGrade = " << student.letterGrade << endl;
}