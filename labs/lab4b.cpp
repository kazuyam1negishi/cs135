/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 4B
* Description: Adds up even and odd numbers between 1 and a given number
* Input: Any given number between 2 and 10000
* Output: Sum of even and odd numbers between 1 and user's number
*/

#include <iostream>
using namespace std;

int main(){
    // Variable for number
    int count = 0;
    /* Asks user for a number between 2 and 10000
    If too small or big, fails and asks for new no.*/
    do{
        cout << "Enter a count between 2 and 10000\n**";
        cin >> count;
        // Clears cin and report fail to terminal
        if(cin.fail() || count < 2 || count > 10000){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError: Invalid entry, please retry\n";
        }
    // Keeps running until cin succeeds and no. is in range
    } while(cin.fail() || count < 2 || count > 10000);
    // Variable for even sum
    int sumEven = 0;
    // Adds any even number between 1 and count to sumEven
    for(int i = 0; i <= count; i++){
        if(i % 2 == 0){
            sumEven = i + sumEven;
        }
    }
    // Variables for odd sum
    int sumOdd = 0;
    int j = 0;
    // Add every odd number between 1 and count to sumOdd
    while(j <= count){
        if(j % 2 != 0){
            sumOdd = j + sumOdd;
        }
        j++;
    }
    // Reports sums to the terminal
    cout << "\nSum of even numbers: " << sumEven;
    cout << "\nSum of odd numbers:  " << sumOdd;
}