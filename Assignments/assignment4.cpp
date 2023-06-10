/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Assignment 4
* Description: Game of Nim with a "primitive" AI
* Input: Y/N for start, matches to remove at any time between 1 and 3
* and Y/N for replaying game.
* Output: Start message, matches at play, prompts, game over message
* and replay prompt.
*/

#include <iostream>
#include <string>
using namespace std;

int main(){
    /* Variables for entire program, like userStart
    userTurn for whose turn it is, and gameRunning
    to be able to replay at the end of the program. */
    string userStart = "a";
    bool userTurn = true;
    bool gameRunning = true;
    cout << "The game of Nim.  The player to remove the last match loses.\n";
    while(gameRunning == true){
        // Asks if player goes first.
        do{
            cout << "\nWould you like to go first? (Y/N): ";
            cin >> userStart;
            // If yes, user goes first.
            if(userStart == "Y" || userStart == "y"){
                userTurn = true;
                break;
            }
            // If no, user goes after computer.
            if(userStart == "N" || userStart == "n"){
                userTurn = false;
                break;
            }
            // If invalid input or not Y or N, fails and asks for input again.
            if(userStart != "Y" || userStart != "y" || userStart != "N" || userStart != "n"){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease, answer Y or N.\n";
            }
        }while(cin.fail() || userStart != "Y" || userStart != "y" || userStart != "N" || userStart != "n");

        // Variable for default number of matches
        int matches = 21;
        // Game logic found here, also checks if more than 1 match at play.
        while(matches >= 1){
            // Logic for player
            if(userTurn == true){
                // Reports no. of matches to terminal
                cout << "\nPlayer Turn - Matches: ";
                for(int i = 1; i <= matches; i++){
                    cout << "|";
                    if(i % 5 == 0){
                        cout << " ";
                    }
                }
                cout << "\n";
                /* Checks if only 1 match at play.
                If so, leaves loop to find winner. */
                if(matches == 1){
                    break;
                }
                // Variable for user matches.
                int userMatch = 0;
                do{
                    cout << "\nRemove (1 - 3): ";
                    cin >> userMatch;
                    // If invalid, asks for input again.
                    if(cin.fail()){
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "\nPlease, type 1, 2, or 3 as your response.\n";
                    }
                    // If less than 1, asks for bigger input.
                    else if(userMatch < 1){
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "\nMust remove at least one match.\n";
                    }
                    // If more than 3, asks for smaller input.
                    else if(userMatch > 3){
                        cin.clear();
                        cin.ignore(100, '\n');
                        cout << "\nCannot remove more than three matches.\n";
                    }
                }while(cin.fail() || userMatch < 1 || userMatch > 3);
                // Takes away matches from current pile
                matches = matches - userMatch;
                // Allows CPU to play.
                userTurn = false;
            }
            if(userTurn == false){
                // Reports no. of matches to terminal
                cout << "\nComputer turn - Matches: ";
                for(int i = 1; i <= matches; i++){
                    cout << "|";
                    if(i % 5 == 0){
                        cout << " ";
                    }
                }
                cout << "\n";
                /* Checks if only 1 match at play.
                If so, leaves loop to find winner. */
                if(matches == 1){
                    break;
                }
                /* Determines how many matches to take
                away based on this logic. */
                if(matches % 4 == 0){
                    matches = matches - 3;
                    cout << "\nComputer removes 3.\n";
                }
                else if(matches % 4 == 1){
                    matches = matches - 1;
                    cout << "\nComputer removes 1.\n";
                }
                else if(matches % 4 == 2){
                    matches = matches - 1;
                    cout << "\nComputer removes 1.\n";
                }
                else if(matches % 4 == 3){
                    matches = matches - 2;
                    cout << "\nComputer removes 2.\n";
                }
                // Allows player to play
                userTurn = true;
            }
        }
        // Reported if user loses.
        if(matches == 1 && userTurn == true){
            cout << "\nGame Over - Computer wins.\n";
        }
        // Reported if CPU loses.
        if(matches == 1 && userTurn == false){
            cout << "\nGame Over - Player wins.\n";
        }
        string playAgain = "a";
        do{
            // Asks to play again.
            cout << "\nWould you like to play again? (Y/N): ";
            cin >> playAgain;
            // If yes, game runs again.
            if(playAgain == "Y" || playAgain == "y"){
                gameRunning = true;
                break;
            }
            // If no, game run stays false and stops.
            if(playAgain == "N" || playAgain == "n"){
                gameRunning = false;
                break;
            }
            // If invalid, asks for input again.
            if(playAgain != "Y" || playAgain != "y" || playAgain != "N" || playAgain != "n"){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "\nPlease, answer Y or N.\n";
            }
        }while(cin.fail() || playAgain != "Y" || playAgain != "y" || playAgain != "N" || playAgain != "n");
    }
}