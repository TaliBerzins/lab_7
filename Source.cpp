/**
 * @file Source.cpp
 * @author Tali Berzins
 * @date 2026-11-17
 * @brief   Demonstrates stack vs heap memory and the use of pointers and references.
 */
 
#include<iostream>
#include "SavingsAccount.h"

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;


/**
 * @brief Entry point for the banking application.
 * @return 0 to indicate success.
 */

int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account* account = new SavingsAccount("5423678409", 100.00, customer);
    account->printAccountInfo();

    int menuChoice = getMenuOption();
    while (menuChoice != QUIT)
    {
        switch (menuChoice)
        {
        case DEPOSIT:
        cout << "You selected to make a deposit. Enter the amount:" << endl;
        double depositAmount;
        cin >> depositAmount;
        if (isAmountValid(depositAmount)) {
            account->deposit(depositAmount);
            cout<< "Deposit of $" << depositAmount << " has been added to the account." << endl;
        } else {
            cout << "Invalid deposit amount. Please enter a positive value next time." << endl;
        }
            /*
            account.
            TODO: Gather the deposit amount input and validate it is > 0.
            Add the code that interacts with the account object to add
            a deposit to the account.
            */
            break;
        case WITHDRAWAL:
        cout << "You selected to make a withdrawal. Enter the amount:" << endl;
        double withdrawalAmount;
        cin >> withdrawalAmount;
        if (isAmountValid(withdrawalAmount)) {
            account->withdraw(withdrawalAmount);
            cout<< "Withdrawal of $" << withdrawalAmount << " has been removed from your account." << endl;
        } else {
            cout << "Invalid withdrawal amount. Please enter a positive value next time." << endl;
        }
            /*
            TODO: Gather the withdrawal amount input and validate it is > 0.
            Add the code that interacts with the account object to add
            a widthdrawal to the account.
            */
            break;
        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();
            /*
            TODO: Add the code that interacts with the account object to perform
            the close of business account balancing.
            */
            break;
        }

        menuChoice = getMenuOption();
    }
}

/**
 * @brief Prints the main menu.
 * @return Void.
 */
void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}
/**
 * @brief Takes user input for the menu option and validates it.
 * @return Return value for menu option.
 */
int getMenuOption()
{
    int choice = 0;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }
    } while (!isMenuChoiceValid(choice));

    return choice;
}
/**
 * @brief Evaluates if the menu choice is valid.
 * @param choice The menu choice to evaluate.
 * @return True if the choice is valid, false otherwise.
 */

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT and choice <= QUIT;
}
/**
 * @brief Evaluates if the amount entered is valid (greater than 0).
 * @param amount The amount to evaluate.
 * @return True if the amount is valid, false otherwise.
 */
bool isAmountValid(double amount)
{
    return amount > 0;
}
/**
 * @brief Prints a message indicating that the menu choice entered is invalid.
 * @return Void.
 */
void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option selected. Please try again." << endl;
}