/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 8A
* Description: Makes a triangle with given size and character
* Input: A number between 2 and 20 and any character
* Output: Two triangles (upside down and right side up) with
* the size and character requested by user.
*/

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function prototypes
int getIntegerInput(string, int, int);
char getCharacterInput(string);
void writeUpsideDownTriangle(int, char);
void writeRightsideUpTriangle(int, char);

int main() {
	// Minimums/maximums
	const int MIN = 2;
	const int MAX = 20;
	// Prompt for integer input
	string prompt1 = "Enter a count between " +
		to_string(MIN) + " and " +
		to_string(MAX) + "\n**";
	// Prompt for character input
	string prompt2 = "\nEnter a character\n**";
	// Get size of triangle
	int size = getIntegerInput(prompt1, MIN, MAX);
	// Get character to use when printing triangle
	char character = getCharacterInput(prompt2);
	// Write both triangles
	writeUpsideDownTriangle(size, character);
	writeRightsideUpTriangle(size, character);
	cout << endl; // ffs
	// Terminate the program
	return (0);
}

// Function definitions
int getIntegerInput(string prompt, int min, int max){
	// Variable to get triangle size (returned at end)
	int size = 0;
	do{
		// Asks user for size
		cout << prompt;
		cin >> size;
		// If invalid or too large or small, retries
		if(cin.fail() || size > max || size < min){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nError: Invalid input!\n";
			continue;
		}
	}while(cin.fail() || size > max || size < min);
	// Returns accepted value to main
	return(size);
}
char getCharacterInput(string prompt){
	// Asks user for character
	cout << prompt;
	char character = ' ';
	cin >> character;
	// Returns character to main
	return(character);
}
void writeUpsideDownTriangle(int size, char character){
	cout << endl;
	// Prints out upside down triangle to terminal
	for(int i = size; i > 0; i--){
        for(int j = 0; j < i; j++){
            cout << character;
        }
        cout << endl;
    }
}
void writeRightsideUpTriangle(int size, char character){
	// Prints out right side up triangle to terminal
	int row = 0;
	while(row < size){
		row++;
        cout << setfill(character) << setw(row) << character << endl;
	}
}