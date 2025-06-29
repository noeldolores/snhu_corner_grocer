/*
 * Corner Grocer
 * Date: 06/22/2025
 * Author: Noel Dolores
 */

using namespace std;

 // Investment class
#pragma once


class Investment {
public:
    /*
    * Prompts user to set initial values for the application
    */
    void setInitialValuesFromInput() {
        double initialInvestment;
        double monthlyDeposit;
        double interestRate;
        int numYears;

        cout << "**************************************************************************" << endl;
        cout << "*****************************  Data Input  *******************************" << endl;


        cout << "Enter Initial Investment Amount" << endl;
        cin >> initialInvestment;
        setInitialInvestment(initialInvestment);

        cout << "Enter Monthly Deposit Amount" << endl;
        cin >> monthlyDeposit;
        setMonthlyDeposit(monthlyDeposit);

        cout << "Enter Annual Interest Rate" << endl;
        cin >> interestRate;
        setInterestRate(interestRate);

        cout << "Enter Number of Years" << endl;
        cin >> numYears;
        setNumYears(numYears);
    }
	void printMenu();
	void menuFunctions(int menuNum);

	void setInitialInvestment(double i);
	void setMonthlyDeposit(double d);
	void setInterestRate(double r);
	void setNumYears(int y);

	double getInitialInvestment();
	double getMonthlyDeposit();
	double getInterestRate();
	int getNumYears();

	void balanceWithoutMonthlyDeposit();
	void balanceWithMonthlyDeposit();

private:
	double initialInvestment = 0.0;
	double monthlyDeposit = 0.0;
	double interestRate = 0.0;
	int numYears = 0;

	void printBalanceDetails(int yearIndex, double balance, double interestEarnedThisYear);
	void printReportHeader();
};