/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 9A
* Description: Performs basic math with two numbers using two functions.
* Input: Two numbers (doubles)
* Output: The sum, difference, product and quotient of the two numbers.
*/

#include <iostream> // duh
#include <iomanip> // Used to set decimal precision to 2
#include <limits> // Used to clear invalid input
using namespace std;

// Function prototypes
void getDoubleInputs(double&, double&);
double getDoubleInput(string, double, double);
bool checkFailure(double, double, double);
void addSubtract(double&, double&);
void multiplyDivide(double&, double&);

int main(){
    // Initalizes variables
    double input1 = 0.0;
    double input2 = 0.0;
    // Calls function to ask for numbers
    getDoubleInputs(input1, input2);
    // Adds and subtracts given numbers
    addSubtract(input1, input2);
    // Multiplies and divides given numbers
    multiplyDivide(input1, input2);
    // Closes program (i seriously need to start doing this again...)
    return(0);
}

// Function bodies
void getDoubleInputs(double& input1, double& input2){
    // Constants for biggest and smallest allowed numbers
    const double MIN = 0.5;
    const double MAX = 20.5;
    // Prompt for user to input number
    string prompt1 = "Enter double between "
        + to_string(MIN) + " and "
        + to_string(MAX) + "\n**";
    input1 = getDoubleInput(prompt1, MIN, MAX);
    cout << endl;
    string prompt2 = "Enter another double between "
        + to_string(MIN) + " and "
        + to_string(MAX) + "\n**";
    input2 = getDoubleInput(prompt2, MIN, MAX);
    cout << endl;
}
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
		cout << "\nError: Invalid input!\n";
        // Returns false to run again
		return(false);
    }
    // If not, returns true to getDoubleInput
    return(true);
}
void addSubtract(double& num1, double& num2)
{
    // Temporarily copies values to these new vars
    double num1B = num1;
    double num2B = num2;
    // Adds num2 to num1
    num1 += num2;
    // Reports result to terminal
    cout << fixed << setprecision(2);
    cout << num1B << " + " << num2B << " = " << num1 << endl;
    // Subtracts num2 from num1, sets equal to num2
    num2 = num1B - num2B;
    // Reports result to terminal
    cout << num1B << " - " << num2B << " = " << num2 << endl;
    // Returns original value to variables
    num1 = num1B;
    num2 = num2B;
}
void multiplyDivide(double& num1, double& num2){
    // Again, temporarily copies values to vars
    double num1B = num1;
    double num2B = num2;
    // Multiplies num1 by num2
    num1 = num1 * num2;
    // Reports result to terminal
    cout << num1B << " * " << num2B << " = " << num1 << endl;
    // Divides num1 by num2
    num2 = num1B / num2B;
    // Reports result to terminal
    cout << num1B << " / " << num2B << " = " << num2 << endl;
}