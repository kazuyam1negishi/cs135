/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 2B
* Description: Finds the area and circumference of a circle with a given radius
* Input: 1 double (radius)
* Output: 2 doubles (circum and area)
*/ 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Sets up constant double for pi
const double PI = 3.141592;

// Initializes and defines doubles to be used
double radius = 0.0;
double circum = 0.0;
double area = 0.0;
int main()
{
    // Asks user for a radius to be used later
    cout << "Enter the radius of a circle" << endl << "**";
    cin >> radius;
    // Calculates circumference and radius
    circum = 2.0 * PI * radius;
    area = PI * pow (radius, 2.0);
    // Starts printout to terminal
    cout << endl << setfill('-') << "+" << setw(9) << "+" << setw(16) << "+" <<
    setw(10) << "+" << endl;
    cout << "| radius | circumference | area    |" << endl;
    cout << setfill('-') << "+" << setw(9) << "+" << setw(16) << "+" <<
    setw(10) << "+" << endl;
    cout << fixed << setprecision(2) << setfill(' ');
    cout << "| " << left << setw(6) << radius << " | " << left << setw(13) <<
    circum << " | " << left << setw(7) << area << " |" << endl;
    cout << right << setfill('-') << "+" << setw(9) << "+" << setw(16) << "+" <<
    setw(10) << "+" << endl;
}