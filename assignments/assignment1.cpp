/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Assignment 1
* Description: Calculates ticket total and tax, leftover cash and how many buses
* needed for a zoo trip
* Input: 1 double (money) and 1 int (people)
* Output: Number of buses, total before tax, tax, and money leftover for each person
*/ 

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


// Variables to be used in the program
int people = 0;
int buses = 0;
double money = 0.0;
double spare_cash = 0.0;
double ticket_subtotal = 0.0;
double ticket_taxes = 0.0;
const double TICKET_PRICE = 7.95;

int main()
{
    // Asks for values (how many people and how much cash available)
    cout << "How many people are in the class? ";
    cin >> people;
    cout << "How much money is in the pool? $";
    cin >> money;
    // Calculates subtotal, taxes, how many buses are needed and leftover cash for food
    ticket_subtotal = TICKET_PRICE * people;
    ticket_taxes = (int)(ticket_subtotal * 6.85) / 100.0;
    // Buses equation set up like this to allow for rounding up
    buses = (people + 11) / 12.0;
    spare_cash = (money - (ticket_subtotal + ticket_taxes)) / people;
    spare_cash = static_cast<int>(spare_cash*100)/100.0;
    // Reports needed info to the terminal
    cout << buses << " Buses need to be reserved." << endl;
    cout << "Tickets will cost $" << ticket_subtotal << endl;
    cout << "Tax will be $" << ticket_taxes << endl;
    cout << "Each person will have $" << spare_cash << " for food." << endl;
}