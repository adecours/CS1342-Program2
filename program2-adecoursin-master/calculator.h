#ifndef CALCULATOR_H
#define CALCULATOR_H

void MonthlyMortgagePayment(double yearlyInterestRate = 0, double loanAmount = 0,
    double numberOfYears = 0);

void FutureInvestmentValue(double& futureInvestmentValue, double yearlyInterest = 0,
    double numOfYearsForInvestment = 0, double originalInvestmentAmount = 0);

double PresentValueForFutureNeed(double yearlyInterestRate = 0,
    double numYearsIntoFuture = 0, double amountOfFutureValue = 0);

#endif