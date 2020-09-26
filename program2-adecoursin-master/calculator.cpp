#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
/* This function takes 3 user-inputed variables and calculates the monthly
mortgage payment. It has no return but instead, output the value calculated
within the function.
*/
void MonthlyMortgagePayment(double yearlyInterestRate, double loanAmount, 
    double numberOfYears) {
    cout << "Interest rate: " << yearlyInterestRate << "%" << endl;
    cout << "Amount of loan: $" << loanAmount << endl;
    cout << "Number of years of loan: " << numberOfYears << endl;

    // converts annual interest rate and number of years to monthly uses
    double monthlyInterestRate = (yearlyInterestRate /100.0) / 12.0;
    double numberOfMonths = numberOfYears * 12;

    // calculates monthly payment and outputs this
    double monthlyPayment = (loanAmount * monthlyInterestRate) / 
    (1.0 - (pow((1.0 + monthlyInterestRate), -numberOfMonths)));
    cout << fixed << setprecision(2) << "Monthly Payment: $" << 
    monthlyPayment << endl;
}

/* This function takes 3 user-inputed variables and calculates the future value
of an investment. It uses one pass by reference variable, futureInvestmentValue, 
and alters the value of this variable to contain the future value. It has no return.
*/
void FutureInvestmentValue(double& futureInvestmentValue, double yearlyInterestRate, 
    double numOfYearsForInvestment, double originalInvestmentAmount) {
    cout << "Interest rate: " << yearlyInterestRate << "%" << endl;
    cout << "Number of years into future: " << numOfYearsForInvestment<< endl;
    cout << "Original investment amount: $" << originalInvestmentAmount << endl;

    futureInvestmentValue = originalInvestmentAmount * 
    (pow ((1.0 + (yearlyInterestRate / 100.0)), numOfYearsForInvestment));
    
}

/* This function takes 3 user-inputed variable and calculates the present amount needed
to reach a certain future value. It calculates this value within the function and 
returns the final value, which is a double.
*/
double PresentValueForFutureNeed(double yearlyInterestRate, double numYearsIntoFuture, 
    double amountOfFutureValue) {
    
    double presentValueForFuture = amountOfFutureValue / 
    (pow((1.0 + (yearlyInterestRate / 100.0)), numYearsIntoFuture));
    
    return presentValueForFuture;
}
