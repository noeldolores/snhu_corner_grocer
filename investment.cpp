/*
 * Corner Grocer
 * Date: 06/22/2025
 * Author: Noel Dolores
 */

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "investment.h"

using namespace std;

/*
* Prints the main navigation menu to screen and accepts input.
*/
void Investment::printMenu() {
    int menuNum = 0;

    cout << "**************************************************************************" << endl;
    cout << "*****************************  Data Input  *******************************" << endl;

    while (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4) {
        cout << "--------------------------------------------------------------------------" << endl;
        cout << "Enter 1 to Search" << endl;
        cout << "Enter 2 to Print Item Volume" << endl;
        cout << "Enter 3 to Print Histogram" << endl;
        cout << "Enter 4 to exit" << endl;

        cin >> menuNum;
        menuFunctions(menuNum);
    }
}

/*
* Takes action based on user input on the main navigation menu
*/
void Investment::menuFunctions(int menuNum) {
    string continueValidation;

    switch (menuNum) {
    case 1:
        balanceWithoutMonthlyDeposit();
        balanceWithMonthlyDeposit();

        cout << "Enter any key to continue..." << endl;
        cin >> continueValidation;

        printMenu();

        break;
    case 2:
        setInitialValuesFromInput();
        printMenu();
        break;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }
}

/*
* Setters for investment class private variables
*/
void Investment::setInitialInvestment(double i) {
    initialInvestment = i;
}

void Investment::setMonthlyDeposit(double d) {
    monthlyDeposit = d;
}

void Investment::setInterestRate(double r) {
    interestRate = r;
}

void Investment::setNumYears(int y) {
    numYears = y;
}

/*
* Getters for investment class private variables
*/
double Investment::getInitialInvestment() {
    return initialInvestment;
}

double Investment::getMonthlyDeposit() {
    return monthlyDeposit;
}

double Investment::getInterestRate() {
    return interestRate;
}

int Investment::getNumYears() {
    return numYears;
}

/**
 * Calculates and prints an end of year balance report for a given number of years
 */
void Investment::balanceWithoutMonthlyDeposit() {
    cout << "         Balance and Interest Without Additional Monthly Deposits" << endl;
    printReportHeader();

    double balance = getInitialInvestment();
    double interestRate = getInterestRate();
    int numYears = getNumYears();

    double totalInterestEarned = 0.0;

    double monthlyInterestRate = (interestRate / 100.0) / 12.0;
    int monthsInYear = 12;

    // Simulate numYears of interest accrual
    for (int i = 0; i < numYears; ++i) {
        // Simulate 12 months of interest accrual
        for (int j = 0; j < monthsInYear; ++j) {
            double interestEarnedThisMonth = balance * monthlyInterestRate;
            balance += interestEarnedThisMonth;
            totalInterestEarned += interestEarnedThisMonth;
        }

        printBalanceDetails(i + 1, balance, totalInterestEarned);
    }
}


/*
 * Calculates and prints an end of year balance report for a given number of years
 */
void Investment::balanceWithMonthlyDeposit() {
    cout << "          Balance and Interest With Additional Monthly Deposits" << endl;
    printReportHeader();

    double balance = getInitialInvestment();
    double monthlyDeposit = getMonthlyDeposit();
    double interestRate = getInterestRate();
    int numYears = getNumYears();

    double totalInterestEarned = 0.0;

    double monthlyInterestRate = (interestRate / 100.0) / 12.0;
    int monthsInYear = 12;

    // Simulate numYears of interest accrual
    for (int i = 0; i < numYears; ++i) {
        // Simulate 12 months of interest accrual
        for (int j = 0; j < monthsInYear; ++j) {
            double interestEarnedThisMonth = balance * monthlyInterestRate;
            balance += interestEarnedThisMonth;
            totalInterestEarned += interestEarnedThisMonth;
            balance += monthlyDeposit;
        }

        printBalanceDetails(i + 1, balance, totalInterestEarned);
    }
}

/*
* Prints the header to the balance reports
*/
void Investment::printReportHeader() {
    cout << "==========================================================================" << endl;
    cout << right << setw(6) << "Year" << setw(30) << "Year End Balance" << setw(35) << "Year End Earned Interest" << endl;
    cout << "--------------------------------------------------------------------------" << endl;
}


/**
* Prints the calculated results of each years investment details in 3 separate fields
* @param year year number
* @param yearEndBalance the current dollar value of the investment
* @param interestEarned dollar amount of how much earned in that year
*/
void Investment::printBalanceDetails(int yearIndex, double balance, double interestEarnedThisYear) {
    cout << right << fixed << setprecision(2) << setw(6) << yearIndex << setw(30) << balance << setw(35) << interestEarnedThisYear << endl;
}