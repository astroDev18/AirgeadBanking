//
// Created by Isa Ali on 7/30/2022.
//

#ifndef BANKING_CALCULATIONS_H
#define BANKING_CALCULATIONS_H

#include <vector>
#include <string>

using namespace std;

class Calculations {
    // Setup public methods
public:
    Calculations();

    virtual ~Calculations();

    // Get method values from user
    double getInitialInvestment() const;

    double getMonthlyDepositAmount() const;

    double getAnnualInterestRate() const;

    int getInvestmentYears() const;

    // Set method values for user
    void setInitialInvestment(double t_initInvestment);

    void setMonthlyDepositAmount(double t_MonthlyDepositAmount);

    void setAnnualInterestRate(double t_AnnualInterestRate);

    void setInvestmentYears(int t_investmentYears);


    // Returns monthly interest rate after calculation
    static double calcMonthlyInterest(double t_initInvestment);

    initializer_list<double> getUserInput();

    // Handle menu's output during system runtime
    void displayUserInput() const;

    bool validateInput() const;

    void displayMenu() const;

    void displayInvestmentMenu(bool monthlyDeposits) const;

private:
    // Private variables to store values. These are set by the user.
    double m_principalInvestmentAmt;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_totalYears;

};


#endif //BANKING_CALCULATIONS_H
