/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Assignment 6
* Description: A crossword game using vectors for the game board
* Input: A number for the level, Y/N for questions and any letter when in-game
* Output: The game board, updated when a correct letter is guessed.
*/

#include <iostream> // duh
#include <fstream> // Used to read data into vectors
#include <iomanip> // Used for intro graphic and formatting for table
#include <vector> // Used for reading data and verifying user victory
#include <limits> // Used to erase failed input
#include <string> // Used to grab user input and use 1st char only
#include <cmath>
using namespace std;

// Function prototypes
vector<vector<char>> writeBoard(int); // Writes board
void printBoard(vector<vector<char>>); // Prints board
vector<vector<char>> wipeBoard(vector<vector<char>>); // Wipes user board to begin game
vector<vector<char>> checkGuess(vector<vector<char>>, // Checks for (and writes) correct guess.
    vector<vector<char>>, char);
bool checkUserGuess(vector<vector<char>>, // Checks if board changed after guess
    vector<vector<char>>, char);
bool checkIfGuessedBoard(vector<vector<char>>, // Checks if a letter is already guessed. 
    vector<char>, char);
bool checkGuessRepeat(vector<char>); // Checks vector for guesses for dupes.
bool checkBoardMatch(vector<vector<char>>, vector<vector<char>>); // Checks if boards match (win)

// Main body, in case you ever forget where or what it is.
int main(){
    // NOTE: FOR THE PURPOSES OF THIS PROGRAM,
    // gameBoard IS THE CPU'S COMPLETE BOARD,
    // AND userBoard IS THE USER'S GUESSING BOARD.
    // Intro graphic
    // For some reason, setw wouldn't work for some places, so I had to improv.
    cout << endl << "     Welcome to" << endl << endl
        << setw(10) << "W" << endl
        << "     C R O S S" << endl
        << setw(10) << "R" << endl
        << setw(10) << "D" << endl;
    // Bool used to determine if game is in play.
    bool gameRunning = true;
    cout << endl;
    while(gameRunning == true){
        // Asks user what level to play
        int level = 0;
        do{
            cout << "Enter level to play:\n";
            cin >> level;
            if(cin.fail() || level < 1){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry!\n";
                continue;
            }
            if(level > 3){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Level files could not be found!\n";
                continue;
            }
        }while(cin.fail() || level > 3 || level < 1);
        // 2D vectors for gameplay declared here
        vector<vector<char>> gameBoard;
        vector<vector<char>> userBoard;
        // Writes game and user boards.
        gameBoard = writeBoard(level);
        userBoard = writeBoard(level);
        // Wipes user board to start game.
        userBoard = wipeBoard(userBoard);
        // Integer for guess counter
        int guessCounter = 5;
        // Vector for storing user guesses.
        vector<char> userMadeGuesses;
        do{
            cout << endl;
            // Prints board
            printBoard(userBoard);
            // Bool to see if game is over
            bool gameEnded = false;
            bool validGuess = false;
            bool letterGuessed = false;
            // Runs check to see if boards match
            gameEnded = checkBoardMatch(gameBoard, userBoard);
            // If gameboards match or guesses run out, game exits.
            if(gameEnded == true || guessCounter == 0){
                gameRunning = false;
                break;
            }
            // Var used for user guess
            char guess = ' ';
            // Intermediary for user input
            string userGuess = "";
            // Resets user vars for use again
            userGuess = "";
            // Asks for input and only gets 1st letter
            cout << "\nEnter a letter:\n";
            cin >> userGuess;
            guess = userGuess.at(0);
            // Copies vector of userBoard here to do check later
            vector<vector<char>> changeCheck;
            changeCheck = userBoard;
            // Checks for changes (valid guess)
            bool letterRepeat = checkGuessRepeat(userMadeGuesses);
            // Makes changes if valid guess
            userBoard = checkGuess(gameBoard, userBoard, guess);
            // Checks if letter already guessed.
            // If so, skips over rest of function.
            letterGuessed = checkIfGuessedBoard(userBoard,
                userMadeGuesses, guess);
            if(letterGuessed == true){
                validGuess = checkUserGuess(changeCheck, userBoard, guess);
                if(validGuess == false){
                    cout << "The letter is already guessed, try again!\n";
                }
                if(letterRepeat == true){
                    cout << "The letter is already guessed, try again!\n";
                }
            }
            if(letterGuessed == false){
                // Checks for changes (valid guess)
                validGuess = checkUserGuess(changeCheck, userBoard, guess);
                // If wrong, guessCounter drops.
                if(validGuess == false){
                    cout << "The letter is not on the board\n";
                    guessCounter--;
                }
            }
            // Reports remaining number of guesses to terminal.
            cout << "Remaining incorrect guesses: " << guessCounter << endl;
        }while(gameRunning == true);
        // Victory reported to terminal
        if(guessCounter > 0){
            cout << "\nCongratulations! you solved the level!\n";
        }
        // Otherwise, loss reported
        else{
            cout << "\nBetter luck next time!\n";
        }
        char replay = 'a';
        do{
            // Asks user if they wish to replay
            cout << "Play again? (y/n)\n";
            cin >> replay;
            if(replay == 'Y' || replay == 'y'){
                gameRunning = true;
                break;
            }
            if(replay == 'N' || replay == 'n'){
                cout << "Thank you for playing CrossWord!";
                return(0);
            }
            if(cin.fail() || replay != 'Y' || replay != 'y' || replay != 'N' || replay != 'n'){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry!\n";
                continue;
            }
        }while(cin.fail() || replay != 'Y' || replay != 'y' || replay != 'N' || replay != 'n');
    }
}
// Function bodies

// Writes data from text file to an array
vector<vector<char>> writeBoard(int level){
    // Set up to allow file to open
    ifstream fileReader;
    // 2D vector used to store values
    vector<vector<char>> tempBoard;
    // Opens file to read in data
    /* For this, I found it easier to ask for the level number
    directly and then concatenate it with the rest of the file name.*/
    fileReader.open("level"+to_string(level)+".txt");
    // Writes data from file to game board
    while(fileReader.eof() == false){
        // String used to hold line from fileReader
        string lineHolder = "";
        // Gets line from fileReader
        getline(fileReader, lineHolder);
        // Temporary vector to allow individual chars to be placed inside
        // Note to self, don't put this inside the for loop. 
        vector<char> tempLine;
        // Used to loop between rows
        for(unsigned int i = 0; i < lineHolder.size(); i++){
            tempLine.push_back(lineHolder[i]);
        }
        tempBoard.push_back(tempLine);
    }
    return(tempBoard);
}
// Prints game board to terminal (or original board if desired, works w/ both.)
// NOTE: Used unsigned ints since these vars won't reach negative values.
void printBoard(vector<vector<char>> vectorName){
    // Loop for vector row, runs until end reached
    for(unsigned int i = 0; i < vectorName.size(); i++){
        // Loop for vector column, runs until end reached
        for(unsigned int j = 0; j < vectorName[i].size(); j++){
            // Prints out vector value
            cout << vectorName[i][j];
        }
        cout << endl;
    }
}
// Sets up (likely user) board to start game
vector<vector<char>> wipeBoard(vector<vector<char>> vectorName){
    // Loop for vector row, runs until end reached
    for(unsigned int i = 0; i < vectorName.size(); i++){
        // Loop for vector column, runs until end reached
        for(unsigned int j = 0; j < vectorName[i].size(); j++){
            // If a char is a letter, replaced with '_'
            if(isalpha(vectorName[i][j])){
                vectorName[i][j] = '_';
            }
        }
    }
    return(vectorName);
}
// Checks to see if a guessed letter matches with gameBoard.
vector<vector<char>> checkGuess(vector<vector<char>> board1,
    vector<vector<char>> board2, char guess){
    // Loop for vector row, runs until end reached
    for(unsigned int i = 0; i < board1.size(); i++){
        // Loop for vector column, runs until end reached
        for(unsigned int j = 0; j < board1[i].size(); j++){
            // Sees if guess is right, either upper or lowercase
            if(board1[i][j] == guess || board1[i][j] == (toupper(guess))){
                board2[i][j] = toupper(guess);
            }
        }
    }
    // Returns user board
    return(board2);
}
// Checks user guess. If wrong, return false, and guess counter
// is dropped in main.
bool checkUserGuess(vector<vector<char>> board1,
    vector<vector<char>> board2, char guess){
    for(unsigned int i = 0; i < board1.size(); i++){
        // Loop for vector column, runs until end reached
        for(unsigned int j = 0; j < board1[i].size(); j++){
            if(board1[i][j] != board2[i][j]){
                // Returns true if change found, meaning correct guess
                return(true);
            }
        }
    }
    // Returns false if boards match, meaning no change
    return(false);
}
// Checks to see if user guess is already on board.
// NOTE: This must be run after the checkGuess function.
bool checkIfGuessedBoard(vector<vector<char>> board,
    vector<char> guessChart, char guess){
    guessChart.push_back(guess);
    // Intermediary for any match in guesses
    bool repeatGuess = false;
    for(unsigned int i = 0; i < board.size(); i++){
        // Loop for vector column, runs until end reached
        for(unsigned int j = 0; j < board[i].size(); j++){
            if(board[i][j] == guess || board[i][j] == toupper(guess)){
                // Returns true
                return(true);
            }
        }
    }
    // Returns false if letter not guessed.
    return(repeatGuess);
}
// Checks to see if guess was repeated by
// seeing if it's in the guessChart vector.
bool checkGuessRepeat(vector<char> guessChart){
    for(unsigned int i = 0; i < guessChart.size(); i++){
        if(guessChart.at(guessChart.size()) == guessChart.at(i) ||
            toupper(guessChart.at(guessChart.size())) == guessChart.at(i)){
            return(true);
        }
    }
    return(false);
}
// Checks to see if boards match. If true, game is over, and user wins.
bool checkBoardMatch(vector<vector<char>> board1, vector<vector<char>> board2){
    // Placeholder bool to ensure boards match.
    bool boardMatch = false;
    /* Checks each character, and if any point boards do not match,
    else statement sets bool to false and continues game.*/
    for(unsigned int i = 0; i < board1.size(); i++){
        for(unsigned int j = 0; j < board2[i].size(); j++){
            if(board1[i][j] == board2[i][j]){
                boardMatch = true;
            }
            else{
                boardMatch = false;
                return(boardMatch);
            }
        }
    }
    // Return bool status.
    return(boardMatch);
}