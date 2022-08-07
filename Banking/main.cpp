#include <iostream>
#include "Calculations.h"
#include "menu.h"

int shut_down();

using namespace std;


void main_menu() {
    // Take user input and initialize variables
    string userInput;
    char char_choice[3];
    int int_choice = 0;
    Calculations data = Calculations();

    // Create loop
    do {
        // Output menu
        data.displayMenu();

        // Get user input
        getline(cin, userInput);
        try {
            // Check user input is valid, and parse it if it is.
            if (userInput.size() == 1 && isdigit(userInput.at(0))) {
                int_choice = userInput.at(0) - 48;
                switch (int_choice) {
                    case 1:
                        data.getUserInput();
                        if (data.validateInput()) {
                            data.displayUserInput();
                        } else {
                            cout << "\nInvalid user input. Data must be greater than 0. Please try again." << endl;
                        }
                        break;
                    case 2:
                        data.displayInvestmentMenu(false);
                        // Enter the monthly deposit amount
                        break;
                    case 3:
                        data.displayInvestmentMenu(true);
                        // Enter the annual interest amount
                        break;
                    case 4:
                        shut_down();
                        break;
                    default:
                        printf("Wrong choice. Enter Again");
                        break;
                }
            } else {
                printf("\nInvalid user input. Data must be greater than 0. Please try again.");
            }
        }
        catch (std::ios_base::failure &fail) {
            cout << "Please select a valid  option, try again." << endl;
            cin.clear();
            std::string tmp;
            getline(cin, tmp);
        }
    } while (int_choice != 4);
}

int shut_down() {
    exit((0));
}


int main() {
    // Call main function
    main_menu();

    return 0;
}