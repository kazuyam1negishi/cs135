/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Assignment 7
* Description: A program that can view and manipulate .csv files
* Input: User and pass as arg's, and any 4 valid commands w/ syntax
* Output: table or command line messages
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <algorithm>
// Had to add this... smh
#include <sstream>

using namespace std;

const string USER = "meowmin";
const string PASS = "1w@ntch1cken";

const string COMMAND_PROMPT = ">";
const string COMMAND_DELIMITER = " ";

const string QUIT_CMD = "quit";
const string SHOW_CMD = "show";
const string CREATE_CMD = "create";
const string DELETE_CMD = "delete";

const string TABLE_FILETYPE = ".csv";
const string TABLE_FILE_DIRECTORY = "data/";
const string TABLES_TABLE = "data/tables.csv";

const string SHOW_ARG_1 = "tables";

const string USAGE_MSG = "Usage: ./a.out <username> <password>\n";
const string WELCOME_MSG = "Welcome ";

const string VALID_ARG_MSG = "";
const string QUIT_ARG_CNT_MSG = "QUIT Error: invalid argument count";
const string SHOW_ARG_CNT_MSG = "SHOW Error: invalid argument count";
const string CREATE_ARG_CNT_MSG = "CREATE Error: invalid argument count";
const string DELETE_ARG_CNT_MSG = "DELETE Error: invalid argument count";

const string TABLE_CREATE_SUCCESS_MSG = " table created successfully";
const string TABLE_DELETE_SUCCESS_MSG = " table removed successfully";
const string INVALID_CREDENTIALS_MSG = "Error: invalid credentials\n";
const string INV_CMD_MSG = "Error: invalid command name";
const string SHOW_INV_OPT_MSG = "SHOW Error: invalid option";
const string CREATE_INV_TABLE_NAME_MSG = "CREATE Error: table name should only contain"
" alpha numeric characters, '-', or '_'";
const string CREATE_EXISTS_MSG = "CREATE Error: table already exists";
const string CREATE_INV_HEADERS_MSG = "CREATE Error: column names should be separated"
" by delimiter and should only contain alpha numeric characters, '-', or '_'";
const string DELETE_UNDELETABLE_MSG = "DELETE Error: table cannot be deleted";
const string DELETE_INV_TABLE_NAME_MSG = "DELETE Error: invalid table name";

void header();
string toLower(string);
void getCredentials(int, char const *[], string&, string&);
bool validateCredentials(string, string);
// sections 2/3 add function prototypes

vector<string> getInput();
string validateArguments(vector<string>);
void executeCommand(vector<string>);
void commandLoop();


int main(int argc, char const *argv[]) {
	string user = "", pass = "";
	// Grabs arguments (user and pass in this case)
	getCredentials(argc, argv, user, pass);
	if(validateCredentials(user, pass)){
        // 1.2 call get header
	    // YOUR CODE HERE
		cout << WELCOME_MSG << USER << endl;
		header();
        // 2.1 call the loop to get commands from the user
	    // YOUR CODE HERE
		commandLoop();
    }
	return 0;
}

// used for section 1
// prints header
void header() 
{
	cout << "+---------------------------------------------------------------------+\n"
		 << "|   __   __  _______  _______  _     _    _______  _______  ___       |\n"
		 << "|  |  |_|  ||       ||       || | _ | |  |       ||       ||   |      |\n"
		 << "|  |       ||    ___||   _   || || || |  |  _____||   _   ||   |      |\n"
		 << "|  |       ||   |___ |  | |  ||       |  | |_____ |  | |  ||   |      |\n"
		 << "|  |       ||    ___||  |_|  ||       |  |_____  ||  |_|  ||   |___   |\n"
		 << "|  | ||_|| ||   |___ |       ||   _   |   _____| ||      | |       |  |\n"
		 << "|  |_|   |_||_______||_______||__| |__|  |_______||____||_||_______|  |\n"
		 << "|                                                               v1.0.0|\n"
		 << "+---------------------------------------------------------------------+\n";
}

// Used for section 2
// lowercases string and returns it
string toLower(string s) 
{
	for (char &x:s) x = static_cast<char>(tolower(x));
	return s;
}

// Used for section 3
// Prints the csv at the passed file path
bool printTable(string file) 
{
	string current = "", rest = "", delimiter = ",";
	int rowCnt = 0;
	ifstream toShow(file);
	getline(toShow, current);
	int colCnt = count(current.begin(), current.end(), delimiter[0]) + 1;
	toShow.seekg(0);
	vector<unsigned int> widths(colCnt, 0);
	while(getline(toShow, rest)) 
	{
		for (int i = 0; i < colCnt; i++)
		{
			current = rest.substr(0, rest.find(delimiter));
			rest = rest.erase(0, rest.find(delimiter) + 1);
			if (current.size() > widths[i])
				widths[i] = current.size();
		}
		rowCnt++;
	}
	if(rowCnt > 1) 
	{
		toShow.clear();
		toShow.seekg(0);
		cout << file.substr(file.find("data/") + 5, file.length() - 9) << " table:\n";
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++) cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		getline(toShow, current);
		vector<string> ret;
		string token = "";
		while(current.find(delimiter) != string::npos) 
		{
			token = current.substr(0, current.find(delimiter));
			current = current.erase(0, current.find(delimiter) + delimiter.length());
			ret.push_back(token);
		}
		ret.push_back(current);
		cout << setfill(' ') << left;
		for (unsigned int i = 0; i < widths.size(); i++)
			cout << "| " << setw(widths[i]) << ret[i] << " ";
		cout << "|" << endl;
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		while(getline(toShow, current)) 
		{
			ret.clear();
			while(current.find(delimiter) != string::npos) 
			{
				token = current.substr(0, current.find(delimiter));
				current = current.erase(0, current.find(delimiter) + delimiter.length());
				ret.push_back(token);
			}
			ret.push_back(current);
			cout << setfill(' ') << left;
			for (unsigned int i = 0; i < widths.size(); i++)
				cout << "| " << setw(widths[i]) << ret[i] << " ";
			cout << "|" << endl;
		}
		cout << setfill('-') << right;
		for (int i = 0; i < colCnt; i++)
			cout << "+" << setw(widths[i] + 3);
		cout << "+" << endl;
		cout << rowCnt - 1 << " row(s) in set.\n";
		return true;
	}
	return false;
}

// Fill this function out for section 1.1
void getCredentials(int argc, char const *argv[], string &user, string &pass){
	// 1.1 get username and password from cmd args
	// First checks if there are not enough arguments
	// If so, returns error and closes.
	if(argc < 3 || argc > 3){
		cout << USAGE_MSG;
		return;
	}
	// Grabs argument for username and places it in user string
	// Uses fixed values because of default usage
	user = argv[1];
	pass = argv[2];
}

// Fill this function out for section 1.2
bool validateCredentials(string u, string p){
	// 1.2 make sure proper user/pass
	// If user and pass valid, returns true.
	if(u == USER && p == PASS){
		return(true);
	}
	// Otherwise, returns false.
	cout << INVALID_CREDENTIALS_MSG;
	return(false);
}

// 2.1 add getInput() function
// YOUR CODE HERE
vector<string> getInput(){
	// Vector to be returned
	vector<string> userArguments;
	// String to store user input
	string userInput = "";
	// Asks for input
	do{
		cout << COMMAND_PROMPT;
		getline(cin, userInput);
		if(userInput == ""){
			cout << INV_CMD_MSG << endl;
		}
	}while(userInput == "");
	userInput = toLower(userInput);
	stringstream userInputStream(userInput);
	string userWord = "";
	while(getline(userInputStream, userWord, ' ')){
		userArguments.push_back(userWord);
	}
	/* Used to test if userArguments written properly
	for(unsigned int i = 0; i < userArguments.size(); i++){
		cout << userArguments[i] << endl;
	}
	*/
	
	/*
	RIP failed code
	12/3 1pm to 12/3 9pm

	do{
		int spaceLocal = 0;
		cout << "Before finding space\n";
		if(userInput.empty()){
			continue;
		}
		spaceLocal = userInput.find(' ');
		if(userInput.find(' ')){
			cout << "Space found!\n";
			userArguments.push_back(userInput.substr(0, spaceLocal));
			userInput = userInput.substr(spaceLocal + 1, userInput.length());
			continue;
		}
		if(!userInput.find(' ')){
			userArguments.push_back(userInput.substr(0, userInput.length()));
			continue;
		}
		if(userInput.length() == 0){
			continue;
		}
	}while(userInput.length() > 0);
	*/
	return(userArguments);
}

bool validFilename = true;
bool validAttribs = true;

// 2.1 add validateArguments(vector<string>) function
// YOUR CODE HERE
string validateArguments(vector<string> argVector){
	// Universal code for function
	string command = argVector[0];
	// Code for quit command
	if(command == QUIT_CMD && argVector.size() != 1){
		return(QUIT_ARG_CNT_MSG);
	}
	if(command == QUIT_CMD && argVector.size() == 1){
		return(VALID_ARG_MSG);
	}
	// Code for create table command
	if(command == CREATE_CMD && argVector.size() != 3){
		return(CREATE_ARG_CNT_MSG);
	}
	if(command == CREATE_CMD && argVector.size() == 3){
		string userFilename = argVector[1];
		// Checks if valid file name
		for(unsigned int i = 0; i < userFilename.length(); i++){
			// Checks if alphanumeric and/or -/_
			if(isalnum(userFilename.at(i))){
				validFilename = true;
			}
			if(userFilename.at(i) == '_' || userFilename.at(i) == '-'){
				validFilename = true;
			}
			// If invalid, error is output.
			if(validFilename == false){
				return(CREATE_INV_TABLE_NAME_MSG);
			}
		}
		// Tries file open if valid filename
		ifstream fileReader;
		fileReader.open(TABLE_FILE_DIRECTORY+userFilename+TABLE_FILETYPE);
		// If opens, error is output.
		if(fileReader.is_open() == true){
			fileReader.close();
			return(CREATE_EXISTS_MSG);
		}
		// Checks for valid attributes
		string attribs = argVector[2];
		if(attribs.at(0) == ',' || attribs.at(attribs.length() - 1) == ','){
			return(CREATE_INV_HEADERS_MSG);
		}
		for(unsigned int i = 0; i < attribs.length(); i++){
			// Checks if alphanumeric and/or -/_/,
			if(isalnum(attribs.at(i))){
				validAttribs = true;
			}
			if(attribs.at(i) == '_' || attribs.at(i) == '-'){
				validAttribs = true;
			}
			// Checks for empty attributes
			if(i >= 1 && attribs.at(i) == ',' && attribs.at(i-1) == ','){
				validAttribs = false;
			}
			// If invalid, error is output.
			if(validAttribs == false){
				return(CREATE_INV_HEADERS_MSG);
			}
		}
		// If all tests pass, command executed.
		if(validFilename == true && validAttribs == true){
			return(VALID_ARG_MSG);
		}
	}
	// Code for show table command
	if(command == SHOW_CMD && argVector.size() != 2){
		return(SHOW_ARG_CNT_MSG);
	}
	if(command == SHOW_CMD && argVector.size() == 2){
		if(argVector[1] != SHOW_ARG_1){
			return(SHOW_INV_OPT_MSG);
		}
		return(VALID_ARG_MSG);
	}
	// Code for delete table command
	if(command == DELETE_CMD && argVector.size() != 2){
		return(DELETE_ARG_CNT_MSG);
	}
	if(command == DELETE_CMD && argVector.size() == 2){
		// Sets file name used
		string filename = TABLE_FILE_DIRECTORY+argVector[1]+TABLE_FILETYPE;
		// If filename restricted, error reported.
		if(filename == TABLES_TABLE){
			return(DELETE_UNDELETABLE_MSG);
		}
		// Tries to open file
		ifstream fileReader;
		fileReader.open(filename);
		// If opens, error is output.
		if(fileReader.is_open() == false){
			return(DELETE_INV_TABLE_NAME_MSG);
		}
		// Reports valid if all tests pass
		fileReader.close();
		return(VALID_ARG_MSG);
	}
	// Code for delete table command
	/* Retired code
	string tempMessage = "inside validateArguments()\n";
	return(tempMessage);
	*/
	// Returns invalid command if all fails
	return(INV_CMD_MSG);
}

// 2.1 add executeCommand(vector<string>) function
// YOUR CODE HERE
void executeCommand(vector<string> argVector){
	// Code for quit command
	if(argVector[0] == QUIT_CMD && argVector.size() == 1){
		exit(0);
	}
	// Code for create table command
	if(argVector[0] == CREATE_CMD && argVector.size() == 3
		&& validFilename == true && validAttribs == true){
		if((TABLE_FILE_DIRECTORY+argVector[1]+TABLE_FILETYPE) != TABLES_TABLE){
			// Opens and writes to current file
			ofstream fileWriter;
			fileWriter.open(TABLE_FILE_DIRECTORY+argVector[1]+TABLE_FILETYPE);
			string userArgs = argVector[2];
			stringstream argStream(userArgs);
			string tableWrite = "";
			while(getline(argStream, tableWrite, ',')){
				fileWriter << tableWrite << endl;
			}
			// Closes current file and opens tables.csv
			fileWriter.close();
			fileWriter.open(TABLES_TABLE, ios_base::app);
			// Adds registry of new table to tables.csv
			fileWriter << argVector[1] << endl;
			fileWriter.close();
			// Reports success and table name
			cout << argVector[1] << TABLE_CREATE_SUCCESS_MSG << endl;
		}
	}
	// Code for show table command
	if(argVector[0] == SHOW_CMD && argVector[1] == SHOW_ARG_1){
		printTable(TABLES_TABLE);
	}
	// Code for delete table command
	if(argVector[0] == DELETE_CMD && argVector.size() == 2){
		string filename = TABLE_FILE_DIRECTORY+argVector[1]+TABLE_FILETYPE;
		ifstream fileReader;
		fileReader.open(filename);
		if(fileReader.is_open() == true && filename != TABLES_TABLE){
			// Reads in existing tables.csv
			
			fileReader.open(TABLES_TABLE);
			vector<string> tableHolder;
			string lineHolder = "";
			while(getline(fileReader, lineHolder)){
				tableHolder.push_back(lineHolder);
			}
			fileReader.close();
			// Erases old tables.csv
			remove(TABLES_TABLE.c_str());
			// Writes new tables.csv
			ofstream fileWriter;
			fileWriter.open(TABLES_TABLE);
			for(unsigned int i = 0; i < tableHolder.size(); i++){
				if(argVector[1] != tableHolder[i]){
					fileWriter << tableHolder[i] << endl;
				}
			}
			// Erases file mentioned by user
			remove(filename.c_str());
			cout << argVector[1] << TABLE_DELETE_SUCCESS_MSG << endl;
		}
	}
	/* Retired code
	cout << "inside executeCommand()\n";
	*/
}

// 2.1 add commandLoop() function
// YOUR CODE HERE
void commandLoop(){
	while(true){
		vector<string> userArguments;
		userArguments = getInput();
		cout << validateArguments(userArguments) << endl;
		executeCommand(userArguments);
	}
}

// NOTE: Because of the below statement, make sure
// not to share this with anyone. Just use it as a
// reference in the future or a way to review this
// concept. 
/*
	DO NOT REMOVE
	
	Copyright 2022 Alex St. Aubin. All Rights Reserved.

	Unauthorized reproductions of this handout and any accompanying code
	are strictly forbidden under Nevada State and US Federal law.
*/