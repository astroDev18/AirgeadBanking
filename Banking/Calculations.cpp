//
// Created by Isa Ali on 7/30/2022.
//

#include <iostream>
#include "Calculations.h"

// Create investment data object
Calculations::Calculations() {
    m_principalInvestmentAmt = 0.0;
    m_monthlyDeposit = 0.0;
    m_totalYears = 0.0;
    m_annualInterestRate = 0.0;
}

// Destroy investment data object
Calculations::~Calculations() {
}


void Calculations::setInitialInvestment(double t_initInvestment) {
    m_principalInvestmentAmt = t_initInvestment;
}

void Calculations::setMonthlyDepositAmount(double t_MonthlyDepositAmount) {
    m_monthlyDeposit = t_MonthlyDepositAmount;
}

void Calculations::setAnnualInterestRate(double t_AnnualInterestRate) {
    m_annualInterestRate = t_AnnualInterestRate;
}

void Calculations::setInvestmentYears(int t_investmentYears) {
    m_totalYears = t_investmentYears;
}

double Calculations::getInitialInvestment() const {
    return m_principalInvestmentAmt;
}

double Calculations::getMonthlyDepositAmount() const {
    return m_monthlyDeposit;
}

double Calculations::getAnnualInterestRate() const {
    return m_annualInterestRate;
}

int Calculations::getInvestmentYears() const {
    return m_totalYears;
}

double Calculations::calcMonthlyInterest(double t_initInvestment) {

    double recurringMonthlyInterest = 0.0;
}


// Accept input from user and store in proper values
initializer_list<double> Calculations::getUserInput() {
    cout << "Initial Investment Amount: " << endl;
    cin >> m_principalInvestmentAmt;
    cout << "Monthly Deposit: " << endl;
    cin >> m_monthlyDeposit;
    cout << "Annual Interest: " << endl;
    cin >> m_annualInterestRate;
    cout << "Number of years: " << endl;
    cin >> m_totalYears;
}

// Ensure user input is validated
bool Calculations::validateInput() const {
    if (m_principalInvestmentAmt < 0 || m_monthlyDeposit < 0 || m_annualInterestRate < 0) {
        return false;
    }
    if (m_totalYears <= 0) {
        return false;
    }
    return true;
}

// Confirm user input by displaying it again.
void Calculations::displayUserInput() const {
    cout << "*********************** Data Input **********************" << endl;
    cout << "Initial Investment Amount:" << endl;
    cout << "$" << m_principalInvestmentAmt << endl;
    cout << "Monthly Deposit:" << endl;
    cout << "$" << m_monthlyDeposit << endl;
    cout << "Annual Interest:" << endl;
    cout << "$" << m_annualInterestRate << endl;
    cout << "Number of Years:" << endl;
    cout << m_totalYears << endl;
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

// display main selection menu
void Calculations::displayMenu() const {
    cout << "%*************************************************************%" << endl;
    cout << "%**                Airgead Banking App                      **%" << endl;
    cout << "%*************************************************************%" << endl;
    cout << "%** 1 - Enter Investment Data                               **%" << endl;
    cout << "%** 2 - View Investment Report without Monthly Deposit.     **%" << endl;
    cout << "%** 3 - View Investment Report with Monthly Deposit.        **%" << endl;
    cout << "%** 4 - Exit                                                **%" << endl;
    cout << "%*************************************************************%" << endl;
    cout << "Select your input choice:";
}

void Calculations::displayInvestmentMenu(bool t_monthlyDeposit) const {
    // Display the menu for the user depending on the investment type
    double monthlyDeposit = m_monthlyDeposit;
    if (!t_monthlyDeposit) {
        monthlyDeposit = 0;
        cout << "*********************** Investment Report **********************" << endl;
        cout << "%%==============================================================%%" << endl;
        cout << "#$# -> Balance and Interest Without Additional Monthly Deposits #$# <-" << endl;
    } else {
        cout << "*********************** Investment Report **********************" << endl;
        cout << "%%==============================================================%%" << endl;
        cout << "#$# -> Balance and Interest With Additional Monthly Deposits <- #$#" << endl;
    }
    // Create variables to hold values during calculations

    int monthsRemaining = m_totalYears * 12; // Num months remaining to invest
    int currentMonth = 1; // current month of investment
    double startingBalance = m_principalInvestmentAmt; // starting balance of investment
    double depositAmount = monthlyDeposit; // amount of monthly deposit
    double total = startingBalance + depositAmount; // total amount of investment
    double interest = total * ((m_annualInterestRate / 100) / 12); // interest amount
    double endBalance = total + interest; // balance after interest
    double previousBalance = startingBalance; // previous balance
    double yearEndEarnedInterest; // cumulative interest earned in a year


    // display header
    cout << "%============================================================%%" << endl;
    cout << "%$%--> Year\tYear End Balance: \tYear End Earned Interest: <--%$%" << endl;

    // loop each month and display year-end results.
    while (monthsRemaining > 0) {
        cout.precision(2);
        if (currentMonth % 12 == 0) {
            yearEndEarnedInterest = endBalance - previousBalance;
            cout << fixed << "\t\t" << currentMonth / 12 << "\t$" << endBalance << "\t\t\t\t$" << yearEndEarnedInterest
                 << endl;
            previousBalance = endBalance;
        }
        // decrease month counter
        monthsRemaining -= 1;
        // Increase counter for current month
        currentMonth += 1;
        // Update variable values
        startingBalance = endBalance;
        // add to total amount of investment
        total = startingBalance + depositAmount;
        // calculate interest amount
        interest = total * ((m_annualInterestRate / 100) / 12);
        // calculate end balance
        endBalance = total + interest;
    }

    if (!t_monthlyDeposit) {
        monthlyDeposit = 0;
        cout << "*********************** END OF INVESTMENT REPORT ***************" << endl;
    } else {
        cout << "*********************** END OF INVESTMENT REPORT ***************" << endl;
    }
}









