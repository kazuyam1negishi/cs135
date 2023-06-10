/*
* Name: Jimmy Soto Agustin, 5008099390, 1006 & 1023, Assignment 2
* Description: Asks user for number of animals and age,
* then outputs lbs of food needed for zebras and rabbits
* Input: Number of zebras, rabbits and how old they are
* Output: Total lbs of food for each animal,
* growth rate for each group, and how much total
* food is needed for each group.
*/

//include required libraries
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Define constants here
const double BABY_ZEBRA = 5.0;
const double BABY_RABBIT = 0.5;
const double ZEBRA_GROWTH_RATE = .05;
const double RABBIT_GROWTH_RATE = .10;

int main()
{
	//Print Zoo Banner
	cout << "+---------------------------------------------------------------------------+ \n"
		 << "|    UU     UU  NNNN     NN  LL       VV      VV         CCCCCC    SSSSSSSS | \n"
		 << "|   /UU    /UU /NN/NN   /NN /LL      /VV     /VV        CC////CC  SS//////  | \n"
		 << "|   /UU    /UU /NN//NN  /NN /LL      /VV     /VV       CC    //  /SS        | \n"
		 << "|   /UU    /UU /NN //NN /NN /LL      //VV    VV       /CC        /SSSSSSSSS | \n"
		 << "|   /UU    /UU /NN  //NN/NN /LL       //VV  VV        /CC        ////////SS | \n"
		 << "|   /UU    /UU /NN   //NNNN /LL        //VVVV         //CC    CC        /SS | \n"
		 << "|   //UUUUUUU  /NN    //NNN /LLLLLLLL   //VV           //CCCCCC   SSSSSSSS  | \n"
		 << "|    ///////   //      ///  ////////     //              //////   ////////  | \n"
		 << "|                                                                           | \n"
		 << "|             ZZZZZZZZ           OOOOOOO         OOOOOOO                    | \n"
		 << "|                 /ZZ           OO/////OO       OO/////OO                   | \n"
		 << "|                /ZZ           OO     //OO     OO     //OO                  | \n"
		 << "|               /ZZ           /OO      /OO    /OO      /OO                  | \n"
		 << "|              /ZZ            /OO      /OO    /OO      /OO                  | \n"
		 << "|             /ZZ             //OO     OO     //OO     OO                   | \n"
		 << "|           //ZZZZZZZZZZ       //OOOOOOO       //OOOOOOO                    | \n"
		 << "|           ///////////         ///////         ///////                     | \n"
		 << "+---------------------------------------------------------------------------+ \n\n";

    cout << "\n*****************************************************************************" <<endl;
    cout << "             Welcome to the UNLV Zoo - Food Supply Department!" <<endl;
    cout << "*****************************************************************************\n" <<endl;

	//Ask the user for the number of months of growth to calculate
	cout << "The food/day for a baby zebra is constant (lbs): "
	<< BABY_ZEBRA << endl;
	cout << "The food/day for a baby rabbit is constant (lbs): "
	<< BABY_RABBIT << endl;
	cout << "After growing the number of months:" << endl << "**";
	int months = 0; // How many months the animals have been alive
	cin >> months;
	//Calculate and report the updated food requirements for zebras and rabbits as well as the zebra to rabbit ratio
	double grownZebra = 0.0; // Food supply for grown zebra
	double grownRabbit = 0.0; // Food supply for grown rabbit
	grownZebra = BABY_ZEBRA * pow ((1 + ZEBRA_GROWTH_RATE), months);
	grownRabbit = BABY_RABBIT * pow ((1 + RABBIT_GROWTH_RATE), months);
	cout << fixed << setprecision(2);
	cout << "The food/day for a bigger zebra is: " << grownZebra << endl;
	cout << "The food/day for a bigger rabbit is: " << grownRabbit << endl;
	cout << "Zebra eats " << static_cast<int>(grownZebra / grownRabbit)
	<< " times as much as rabbits" << endl << endl;
	//Ask the user for the number of zebras and rabbits to feed
    cout << "The number of Zebra:" << endl << "**";
	int zebraTotal = 0; // Total number of zebras
	cin >> zebraTotal;
	cout << "The number of Rabbit:" << endl << "**";
	int rabbitTotal = 0; // Total number of rabbits
	cin >> rabbitTotal;
	// Variables used for total food after n months, and equations
	double grownZebraFood = 0.0; // Food for zebras in pounds
	grownZebraFood = grownZebra * zebraTotal;
	double grownRabbitFood = 0.0; // Food for rabbits in pounds
	grownRabbitFood = grownRabbit * rabbitTotal;
	cout << "For Zebras, total food/day in " << months << " months is: "
	<< grownZebraFood << endl;
	cout << "For Rabbits, total food/day in " << months << " months is: "
	<< grownRabbitFood << endl;
	double totalFood = 0.0; // Combined total of food for both animal groups
	totalFood = grownZebraFood + grownRabbitFood;
	cout << "Overall, total food/day in " << months << " months is: "
	<< totalFood << endl;
	// Rounding up totalFood so food in lbs is shown on receipt
	totalFood = 1 + totalFood;
	double totalFoodReceipt = static_cast<int>(totalFood);
	//Print formatted results
    cout << setfill(' ') << fixed << setprecision(2)
	     << "\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\\n"
		 << "|" << setw(40) << "|\n"
		 << "|             UNLV CS Zoo              |\n"
		 << "|         4505 S Maryland Pkwy         |\n"
		 << "|          Las Vegas,NV 89154          |\n"
		 << "|            (702) 895-3011            |\n"
		 << "|" << setw(40) << "|\n"
		 << "|" << setw(40) << "|\n"
		 << "| Baby Zebra(lbs/d):" << right << setw(18) << BABY_ZEBRA << " |\n"
		 << "| Growth Rate(month):" << setw(16) << ZEBRA_GROWTH_RATE * 100 << "% |\n"
		 << "| Baby Rabbit(lbs/d):" << setw(17) << BABY_RABBIT<< " |\n"
		 << "| Growth Rate(month):" << setw(16) << RABBIT_GROWTH_RATE * 100 << "% |\n"
		 << "|" << setw(40) << "|\n"
		 << "| Growth Month:" << setw(23) << months << " |\n"
		 << "| Grown Zebra(lbs/d):" << setw(17) << grownZebra << " |\n"
		 << "| Grown Rabbit(lbs/d):" << setw(16) << grownRabbit << " |\n"
		 << "|" << setw(40) << "|\n"
		 << "| Zebra amount:" << setw(23) << zebraTotal << " |\n"
		 << "| Rabbit amount:" << setw(22) << rabbitTotal << " |\n"
		 << "| Total Food(lbs/d):" << setfill('*') << setw(18)
		 << totalFoodReceipt << " |\n"
		 << "|" << setfill(' ') << setw(40) << "|\n"
         << "\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/"<<endl;

    return 0;
 }