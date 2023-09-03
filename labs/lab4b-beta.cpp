/*
* Name: Jimmy
* Description:
* Input:
* Output:
*/

#include <iostream>
using namespace std;

int main(){
    int count = 0;
    do{
        cout << "Enter a count between 2 and 10000\n**";
        cin >> count;
        if(cin.fail() || count < 2 || count > 10000){
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\nError: Invalid entry, please retry\n";
        }
    } while(cin.fail() || count < 2 || count > 10000);
    cout << "\nFOR TESTING: You entered " << count << ".\n";
    int sumEven = 0;
    for(int i = 0; i <= count; i++){
        if(i % 2 == 0){
            sumEven = i + sumEven;
        }
    }
    int sumOdd = 0;
    int j = 0;
    while(j <= count){
        if(j % 2 != 0){
            sumOdd = j + sumOdd;
            cout << "FOR TESTING: J is currently " << j << ", and sumOdd is " << sumOdd << ".\n";
        }
        j++;
    }
    cout << "\nFOR TESTING: even sum is " << sumEven << ".";
    cout << "\nFOR TESTING: odd sum is " << sumOdd << ".\n";
}