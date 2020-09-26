/*
Author: Abby DeCoursin
Date: 9-15-2019
Description: This program displays a menu that then takes user input for one of
the menu options, dealing with investments. The user input then leads to the 
execution of an if statement which prompts the user for data regarding 
investments, interest rates, etc. A function is then called using the data input 
by the user and then, depending on the function, the data is manipulated and the 
output value is determined. The program outputs a display of the data the
user inputed and calculates the value selected. The menu continues to display 
until the user inputs the exit case, which for this program is "D", and then
the program ends.
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "calculator.h"

using namespace std;

int main() {
    string userInput;

    while (userInput != "D"){
        // The data entered for the first user input option should be one of
        // the specified options, otherwise the user is prompted again.
        cout << "MENU" << endl;
        cout << "A. Monthly Mortgage Payment" << endl;
        cout << "B. Future Investment Value" << endl;
        cout << "C. Present Value for Future Need" << endl;
        cout << "D. Quit" << endl;
        cout << "Type A, B, C, D to display contents of choice: ";
        cin >> userInput;

        // This section uses a function to calculate the monthly mortgage 
        // payment. It takes
        // the interest rate, loan amount, and number of years into the future
        // to output the monthly payment.
        // Data entered should be a number (int or double) and will be 
        // converted to a double regardless. If the user enters a invalid
        // character, the input is ignored and the value is set to 0. 
        // If the user doesn't give any input, the default value of 0 is used.        
        if (userInput == "A") {
            cout << "Monthly Mortgage Payment" << endl;

            double yearlyInterestRate;
            double loanAmount;
            double numberOfYears;

            cout << "Enter the yearly interest rate as xx.xx: ";
            cin >> yearlyInterestRate;
            cin.clear(); // ignores invalid inputs
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Enter the loan amount: $";
            cin >> loanAmount;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Enter the number of years of the loan: ";
            cin >> numberOfYears;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            MonthlyMortgagePayment(yearlyInterestRate, loanAmount, numberOfYears);
        }

        // This section uses a function to calculate
        // the value of an investment made now.
        // It takes into account the interest rate, number of years into
        // the future, and the present investment made. The futureInvestmentValue
        // variable is passed by reference and altered within the function.
        // Data entered should be a number (int or double) and will be 
        // converted to a double regardless. If the user enters a invalid
        // character, the input is ignored and the value is set to 0. If the 
        // user doesn't give any input, the default value of 0 is used.
        else if (userInput == "B") {
            cout << "Future Investment Value" << endl;

            double yearlyInterestRate;
            double numOfYearsForInvestment;
            double originalInvestmentAmount;
            double futureInvestmentValue = 0;

            cout << "Enter the yearly interest rate as xx.xx: ";
            cin >> yearlyInterestRate;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Enter the number of years for investment: ";
            cin >> numOfYearsForInvestment;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Enter the amount of the original investment: $";
            cin >> originalInvestmentAmount;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            FutureInvestmentValue(futureInvestmentValue, yearlyInterestRate, 
                numOfYearsForInvestment, originalInvestmentAmount);

            cout << fixed << setprecision(2) << "Future value will be: $" << 
            futureInvestmentValue << endl;
        }

        // This section uses a function to calculate the value the user 
        // needs now to have a
        // certain amount in the future. It takes into account the interest
        // rate, number of years into the future, and the amount desired in the
        // future and calls a function to return the present amount needed.
        // Data entered should be a number (int or double) and will be 
        // converted to a double regardless. If the user enters a invalid
        // character, the input is ignored and the value is set to 0. If the user
        // doesn't give any input, the default value of 0 is used.
        // The function outputs a double.
        else if (userInput == "C") {
            cout << "Present Value for Future Need" << endl;

            double yearlyInterestRate;
            double numYearsIntoFuture;
            double amountOfFutureValue;

            cout << "Enter the yearly interest rate as xx.xx: ";
            cin >> yearlyInterestRate;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Enter the number of years into the future: ";
            cin >> numYearsIntoFuture;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl << "Enter the amount of the future value: $";
            cin >> amountOfFutureValue;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;

            cout << "Interest rate: " << yearlyInterestRate << "%" << endl;
            cout << "Number of years into future: " << numYearsIntoFuture << endl;
            cout << "Desired future value: $" << amountOfFutureValue << endl;

            cout << fixed << setprecision(2) << "Present value needed: $" << 
            PresentValueForFutureNeed(yearlyInterestRate, numYearsIntoFuture, 
                amountOfFutureValue)
            << endl;
        }

        // If the user does not enter one of the 4 options, the output message
        // is displayed until a valid character is inputed.
        else if (userInput != "D") {
            cout << "Please enter a valid character." << endl;
        }
    }
    cout << "Goodbye!" << endl; // displays after user enters "D"
}