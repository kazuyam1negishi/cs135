/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 8B
* Description: Gives circumference and area of a circle using given radius.
* Input: A radius (double)
* Output: The circumference and area of a circle with given radius.
*/

#include <iostream>
#include <iomanip> // Used for 2 decimal precision on outputs
#include <cmath> // Used to raise radius to power in area function
#include <limits> // Used to clear failed input in checkFailure
using namespace std;

// Function prototypes
double getDoubleInput(string, double, double);
bool checkFailure(double, double, double);
double circumference(double);
double area(double);
// Global constant for pi for area function
const double PI = 3.14159;

// Main body
int main(){
    // Constants for biggest and smallest allowed numbers
    const double MIN = 0.5;
    const double MAX = 20.5;
    // Prompt for user to input number
    string prompt = "Enter a circle radius between "
        + to_string(MIN) + " and "
        + to_string(MAX) + "\n**";
    // Calls command to get input and set it equal to radius when successful
    double radius = getDoubleInput(prompt, MIN, MAX);
    // Calls command to get circumference and set it equal to userCircumference
    double userCircumference = circumference(radius);
    // Calls command to get area and sets it equl to uesrArea
    double userArea = area(radius);
    // Reports given radius, circumference and area to terminal.
    cout << endl << fixed << setprecision(2) << "Radius: " << radius << endl;
    cout << "Circumference: " << userCircumference << endl;
    cout << "Area: " << userArea << endl;
    // Closes program
    return(0);
} 

// Function bodies
double getDoubleInput(string prompt, double min, double max){
    // Variables for user input and if input valid
    double input = 0.0;
    bool validInput = false;
    do{
        cout << prompt;
        cin >> input;
        validInput = checkFailure(input, min, max);
    }while(validInput == false);
    return(input);
}
bool checkFailure(double input, double min, double max){
    // Checks if input failed, or if input too big or small
    if(cin.fail() || input > max || input < min){
        // If so, clears input and asks again.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nError: Invalid radius!\n";
        // Returns false to run again
		return(false);
    }
    // If not, returns true to getDoubleInput
    return(true);
}
double circumference(double radius){
    return(2 * PI * radius);
}
double area(double radius){
    return(PI * pow(radius, 2));
}