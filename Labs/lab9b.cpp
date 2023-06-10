/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 9B
* Description: Manipulates two strings and two ints in 5 different ways
* Input: Two numbers (integers) and two strings
* Output: Sum and product of two ints, two strings merged
* and a string multiplied by its corresponding integer
*/

#include <iostream> // duh
#include <string> // Used to get user input strings
#include <limits> // Used to clear failed input on getIntegerInputs
using namespace std;

// Function prototypes
void getIntegerInputs(int&, int&);
int getIntegerInput(string, int, int);
bool checkFailure(int, int, int);

// New overloaded functions for this lab
int add(int, int);
string add(string, string);
int multiply(int, int);
string multiply(string, int);

int main(){
    // Vars for storing numbers
    int num1 = 0;
    int num2 = 0;
    // Asks for numbers, check for error, etc.
    getIntegerInputs(num1, num2);
    // Vars for storing strings
    string firstWord = " ";
    string secondWord = " ";
    // Prompts and gets input (just done here to avoid having too many funcs.)
    cout << "\nEnter a string\n**";
    cin >> firstWord;
    cout << "\nEnter another string\n**";
    cin >> secondWord;
    // Var to store results of user-provided values
    int sum = add(num1, num2); // int add overloaded func. called
    string addedString = add(firstWord, secondWord); // string add func. called
    int product = multiply(num1, num2); // int multiply func. called
    string multiString1 = multiply(firstWord, num1); // string multiply called once
    string multiString2 = multiply(secondWord, num2); // string multiply called again
    // Reports all values to terminal
    cout << endl << num1 << " + " << num2 << " = " << sum << endl;
    cout << firstWord << " + " << secondWord << " = " << addedString << endl;
    cout << num1 << " * " << num2 << " = " << product << endl;
    cout << firstWord << " * " << num1 << " = " << multiString1 << endl;
    cout << secondWord << " * " << num2 << " = " << multiString2 << endl;
}

// Functions for integer checks
void getIntegerInputs(int& input1, int& input2){
    // Constants for biggest and smallest allowed numbers
    const int MIN = 1;
    const int MAX = 50;
    // Prompt for user to input number
    string prompt1 = "Enter an integer between "
        + to_string(MIN) + " and "
        + to_string(MAX) + "\n**";
    input1 = getIntegerInput(prompt1, MIN, MAX);
    cout << endl;
    string prompt2 = "Enter another integer between "
        + to_string(MIN) + " and "
        + to_string(MAX) + "\n**";
    input2 = getIntegerInput(prompt2, MIN, MAX);
}
int getIntegerInput(string prompt, int min, int max){
    // Variables for user input and if input valid
    int input = 0;
    bool validInput = false;
    do{
        cout << prompt;
        cin >> input;
        validInput = checkFailure(input, min, max);
    }while(validInput == false);
    return(input);
}
bool checkFailure(int input, int min, int max){
    // Checks if input failed, or if input too big or small
    if(cin.fail() || input > max || input < min){
        // If so, clears input and asks again.
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\nError: Invalid input!\n";
        // Returns false to run again
		return(false);
    }
    // If not, returns true to getDoubleInput
    return(true);
}

// New overloaded functions
int add(int num1, int num2){
    return(num1 + num2);
}
string add(string word1, string word2){
    string sum = word1 + word2;
    return(sum);
}
int multiply(int num1, int num2){
    return(num1 * num2);
}
string multiply(string word, int num){
    string mergedString = "";
    for(int i = 0; i < num; i++){
        mergedString += word;
    }
    return(mergedString);
}