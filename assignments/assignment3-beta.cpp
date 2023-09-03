/*
Place your header comment here
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << endl
		 << ".@  @, (&           .(%(.               *#(,              .   \n"
		 << "(@  @( &@      .@@@@@@@@@@@@@#     @@@@@@@@@@@@@#        @@@. \n"
		 << "(@  @( &@    /@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@    .@@@@@,\n"
		 << "(@@@@@@@@   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@   .@@@@@,\n"
		 << "(@@@@@@@@   @@@@@@@@@@@@@@@@  .@@@@@@@@@@@@@@@@@@@@@(  .@@@@@,\n"
		 << " @@@@@@@#   @@@@@@@@@@@@@@      @@@@@@@@@@@@@@@@@@@@/  .@@@@@,\n"
		 << "    @@.     &@@@@@@@@@@@.   @@   @@@@@@@@@@@@@@@@@@@   .@@@@@,\n"
		 << "    @@.                   @@@@@   @@@@                 .@@@@@,\n"
		 << "    @@.       #@@@@@@@@@@@@@@@@@   &#  .@@@@@@@@@@     .@@@@@,\n"
		 << "    @@.         @@@@@@@@@@@@@@@@@.    %@@@@@@@@@#         ,@@,\n"
		 << "    @@.           @@@@@@@@@@@@@@@@,  @@@@@@@@@%           ,@@.\n"
		 << "    @@.             %@@@@@@@@@@@@@@@@@@@@@@@.             ,@@,\n"
		 << "    @@.                %@@@@@@@@@@@@@@@@@,                ,@@,\n"
		 << "    @@.                    &@@@@@@@@@,                    ,@@,\n"
		 << "    @@.                     &@@@@@,                       ,@@,\n"
		 << endl
		 << "             Welcome to the Calorie Calculator App\n";
    // Variable for user's age
	int age = 0;
	// Asks user for age in years
    cout << "To get started, enter your age in years:\n";
    cin >> age;
	/* Checks if age input is valid
	If not valid or within range, program
	fails and reports to terminal. */
	if(cin.fail()){
		cout << "\nInvalid Age!\n";
		return(0);
	}
	else if(age < 10 || age > 79){
        cout << "\nAge must be between 10 and 79 years!\n";
		return(0);
	}
	// Variable for user's weight
	int weight = 0;
	// Asks user for weight in pounds
    cout << "Enter weight in lbs:\n";
    cin >> weight;
	/* Checks if weight input is valid
	If not valid or within range, program
	fails and reports to terminal. */
	if(cin.fail() || weight < 50 || weight > 400){
        cout << "\nInvalid weight!\n";
		return(0);
	}
	else if(weight < 50 || weight > 400){
        cout << "\nWeight must be between 50 lbs and 400 lbs!\n";
		return(0);
    }
	// Variable for user's height
	int height = 0;
	// Asks for user's height in inches
	cout << "Enter height in inches:\n";
    cin >> height;
	/* Checks if height input is valid
	If not valid or within range, program
	fails and reports to terminal. */
    if(cin.fail()){
    	cout << "\nInvalid height!";
		return(0);
    }
	else if(height < 40 || height > 90){
		cout << "\nHeigh must be between 40\" and 90\"!";
		return(0);
	}
	cout << "FOR TESTING: age is " << age << ".\n";
	cout << "FOR TESTING: weight is " << weight << ".\n";
	cout << "FOR TESTING: height is " << height << ".\n";
	// Variable for user's gender
	char gender = 'a';
	// Variable for user's BMR
	double userBMR = 0.0;
	// Asks user for gender (male or female)
	cout << "Enter 'M' for male or 'F' for female:\n";
	cin >> gender;
	/*
	*/
	if(cin.fail()){
		cout << "\nFOR TESTING: Looks like the input failed. The program will now close.\n";
		return(0);
	}
	/*
	*/
	switch(gender){
		case 'M':
		case 'm':
			userBMR = 65 + (6.2 * weight) + (12.7 * height) - (6.8 * age);
			break;
		case 'F':
		case 'f':
			userBMR = 655 + (4.3 * weight) + (4.3 * height) - (4.7 * age);
			break;
	}
	cout << "FOR TESTING: TEST BMR FOR " << gender << " IS " << userBMR << ".\n";
	// Variable to define user's activity level (used later in switch)
	int activityLevel = 0;
	/* Asks user for activity level
	If not valid input, error reported
	to terminal, then ends program.*/
	cout << "Select activity level:\n"
		 << "1. Inactive: little to no exercise.\n"
		 << "2. Lightly active: Exercising 1 - 3 days/week\n"
		 << "3. Moderately active: Exercising 3 - 5 days/week\n"
		 << "4. Active: Exercising 6 - 7 days/week\n"
		 << "5. Very active: Exercising hard 6 - 7 days/week\n";
	cin >> activityLevel;
    if(cin.fail() || activityLevel < 1 || activityLevel > 5){
    	cout << "\nInvalid activity level!\n";
		return(0);
	}
	cout << "FOR TESTING: Activity level is " << activityLevel << ".\n";
	// Variable for user's AMR
	double userAMR = 0.0;
	// Switch used to multiply user BMR based on activity
	switch(activityLevel){
		case 1:
			userAMR = userBMR * 1.2;
			break;
		case 2:
			userAMR = userBMR * 1.375;
			break;
		case 3:
			userAMR = userBMR * 1.55;
			break;
		case 4:
			userAMR = userBMR * 1.725;
			break;
		case 5:
			userAMR = userBMR * 1.9;
			break;
	}
	cout << "FOR TESTING: TEST AMR FOR " << gender << " is " << userAMR << ".\n";
	double calorieDrop = 0.0;
	calorieDrop = userAMR * 0.8;
	double calorieGain = 0.0;
	calorieGain = userAMR * 1.2;
	// FINAL TEST TO SEE IF I CAN TURN THIS IN AND GO TO BED
	cout << "To maintain your current weight, you need to consume an average of "
	<< round(userAMR) << " calories/day.\n";
	cout << "To lose weight, you need to consume an average " << round(calorieDrop)
	<< " calories/day.\n";
	cout << "To gain weight, you need to consume an average " << round(calorieGain)
	<< " calories/day.\n";
	cout << "\n*Disclaimer: always consult your doctor before committing to a diet plan";
}