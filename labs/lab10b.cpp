/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Lab 10B
* Description: Uses struct to store purchase info and report to terminal
* Input: A filename holding purchase data, like customer ID, item, cost,
* tax and quantity purchased.
* Output: A printout with all above info, total after tax and quantity
* number of unique customers and average total of all items.
*/

#include <iostream> // duh
#include <iomanip> // Used to manip. data for printout
#include <fstream> // Used to open and read in data
#include <limits> // Used for cin.clear()
using namespace std;

// Global constants
const int ARRAY_SIZE = 10;

// Struct that holds user data
struct PurchaseType{
    string customerID;
    string productName;
    double price;
    int qtyPurchased;
    double taxRate;
};

// Function prototypes
void openFile(ifstream&, string);
void readFile(ifstream&, PurchaseType[]);
void printPurchaseData(PurchaseType[], int);

// Main (don't forget where it is)
int main(){
    // File input stream
    ifstream fileReader;
    // String to store file name
    string filename = "";
    // Array of structs used in the program
    PurchaseType purchases[ARRAY_SIZE];
    // Opens file
    openFile(fileReader, filename);
    // Reads in data
    readFile(fileReader, purchases);
    // Prints out info to terminal
    printPurchaseData(purchases, ARRAY_SIZE);
}
// Function bodies
// Opens file with user prompt
void openFile(ifstream& fileReader, string prompt){
    do{
        cout << "Enter file name\n**";
        cin >> prompt;
        fileReader.open(prompt);
        // If file fails to open, user castigated
        // and asked to try again.
        if(fileReader.is_open() == false){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nError: Invalid File\n";
        }
    }while(fileReader.is_open() == false);
}

void readFile(ifstream& fileReader, PurchaseType purchases[]){
    // Int for successful writes
    int writes = 0;
    while(fileReader.eof() == false){
        // String for temporarily storing data
        string input = "";
        // Int for finding commas in input
        int comma = 0;
        getline(fileReader, input);
        // Preliminary check to see if eof
        // IF REMOVED, MAY CAUSE SEG. FAULT
        // OR INVALID ARGUMENT!
        if(fileReader.fail() || fileReader.eof()){
            continue;
        }
        // Finds place of comma, reads in data from start
        // to place of comma, then resets for next
        // piece of info to be read in.
        // stoi() and stod() used to convert
        // strings to ints and doubles.
        comma = input.find(',');
        purchases[writes].customerID = input.substr(0, comma);
        input = input.substr(comma + 1, input.length());
        comma = input.find(',');
        purchases[writes].productName = input.substr(0, comma);
        input = input.substr(comma + 1, input.length());
        comma = input.find(',');
        purchases[writes].price = stod(input.substr(0, comma));
        input = input.substr(comma + 1, input.length());
        comma = input.find(',');
        purchases[writes].qtyPurchased = stoi(input.substr(0, comma));
        input = input.substr(comma + 1, input.length());
        comma = input.find(',');
        purchases[writes].taxRate = stod(input.substr(0, input.length()));
        // Increases number of successful writes to allow
        // next line to be written.
        writes++;
    }
}

void printPurchaseData(PurchaseType purchases[], int size){
    // Int for total customers
    int totalCustomers = 0;
    // Double for grand total to be divided at the end
    double grandTotal = 0.0;
    // BIG STINKIN cout for the top 3 rows
    cout << endl << setfill('-')
    << "+" << setw(14) << "+" << setw(15) << "+" << setw(8)
    << "+" << setw(11) << "+" << setw(11) << "+" << setw(9)
    << "+" << endl
    << "| Customer ID | Product Name | Price | Quantity | Tax Rate |"
    << " Total  |" << endl
    << setfill('-')
    << "+" << setw(14) << "+" << setw(15) << "+" << setw(8)
    << "+" << setw(11) << "+" << setw(11) << "+" << setw(9)
    << "+" << endl;
    // Loop to print out purchases
    for(int i = 0; i < size; i++){
        // Checks if new customer.
        // If so, increases customer count.
        if(purchases[i].customerID != purchases[i+1].customerID){
            totalCustomers++;
        }
        // Double for product tax
        double tax = 0;
        tax = (purchases[i].price * purchases[i].taxRate);
        // Doubles for total after tax and quantity purchased
        double totalAfterTax = purchases[i].price + tax;
        double totalAfterQty = totalAfterTax * purchases[i].qtyPurchased;
        // Reports info to terminal
        cout << right << fixed << "|" << setfill(' ') << setprecision(2) << setw(12)
             << purchases[i].customerID << " | " << setw(12)
             << purchases[i].productName << " | " << setw(5)
             << purchases[i].price << " | " << setw(8)
             << purchases[i].qtyPurchased << " | " << setw(8)
             << (purchases[i].taxRate * 100) << " | "
             << setw(6) << totalAfterQty
             << " |" << endl;
        // Adds total after tax and qty. to grand total to be divided later
        grandTotal += totalAfterQty;
    }
    // Prints out last row
    cout << setfill('-')
    << "+" << setw(14) << "+" << setw(15) << "+" << setw(8)
    << "+" << setw(11) << "+" << setw(11) << "+" << setw(9)
    << "+" << endl;
    // Prints out number of unique customers
    cout << "Unique users:  " << totalCustomers << endl;
    // Prints out average spent on items
    cout << "Average total: $" << grandTotal / ARRAY_SIZE;
}