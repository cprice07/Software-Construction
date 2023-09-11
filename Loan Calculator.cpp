#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstdlib>

using namespace std;

/* File name: project1_Price_czp0085.cpp
 * Author: Corah Price
 * Compile using g++
 * Utilized hints page provided by Dr Li
 * Utilized w3schools to learn initialization of variables in cpp
 * Utilized w3schools to learn proper if statement layout in cpp
 * Utilized stack overflow to learn how to create an exit error for invalid inputs
 * Worked with University tutor, Elliott, to fix problem in while loop
*/

int main() {
    //Variable Initialization
    double loan;
    double interestRate;
    double interestRateC;
    double monthlyPaid;
    int currentMonth;
    double interestTotal;
    double principal;
    currentMonth = 0;
    double userInputInterest;



    //Currency Formatting
    //Print set decimal amount
    cout.setf(ios::fixed);
    //Floating point number prints with decimal point
    cout.setf(ios::showpoint);
    //Number of integers after decimal point
    cout.precision(2);

    //User input
    //Print statement to user
    cout << "\nLoan Amount: ";
    //Input value
    cin >> loan;

    //Verify input value for loan is positive
    if (loan <= 0) {
        //Output if loan value is invalid
        cerr << "\nLoan amount entered must be positive and an integer.\n";
        return EXIT_FAILURE;
    }


    //Print statement to user
    cout << "Interest Rate (% per year): ";
    //Input value
    cin >> interestRate;

    //Verify input value for interest rate is a double
    if (cin.fail()) {
        //Output if interest rate invalid
        cerr << "\nInterest rate amount entered must be a number.\n";
        return EXIT_FAILURE;
    }

    //Verify input value for interest rate is positive
    if (interestRate < 0)  {
        //Output if interest rate invalid
        cerr << "\nInterest rate amount entered must be zero or greater.\n";
        return EXIT_FAILURE;
    }

    //Interest rates for calculating
    //Divides left operand (interestRate) with right operand (12) and assigns result to left operand (interestRate)
    //Calculates from yearly to monthly interest rate
    interestRate /= 12;
    userInputInterest = interestRate;
    //Calculates from percentage to decimal
    interestRateC = interestRate / 100;
    //Print statement to user
    cout << "Monthly Payments: ";
    //Input value
    cin >> monthlyPaid;

    //Verify monthly paid input is valid
    if (monthlyPaid <= 0) {
        //Output if monthlyPaid is invalid
        cerr << "\nMonthly payment amount is invalid.\n";
        return EXIT_FAILURE;
    }

    cout << endl;

    //Amortization Table
    cout << "*****************************************************************\n"
             << "\tAmortization Table\n"
             << "*****************************************************************\n"
             << "Month\tBalance\t\tPayment\t\tRate\t\tInterest\tPrincipal\n";




    //Loop to fill table
    while (loan > 0) {
        if (currentMonth == 0) {
            cout << currentMonth << "\t\t$" << loan;
            if (loan < 1000) cout << "\t"; // Formatting MAGIC
            cout << "\t" << "N/A\t\t\tN/A\t\t\tN/A\t\t\tN/A\n";
        }

            interestRate = interestRateC * loan;

            //Verify monthly paid is greater than interest rate
            if (monthlyPaid <= interestRate) {
                cerr << "\nMonthly payment entered is invalid, must be greater than monthly interest.\n";
                return EXIT_FAILURE;
            }

            //Test for when balance is less than monthly paid
            if (loan < monthlyPaid) {
                currentMonth++;
                double newMonthlyPaid = loan + interestRate;
                principal = newMonthlyPaid - interestRate;
                monthlyPaid = newMonthlyPaid;
                loan = loan - loan;
            }
                //When balance is greater than monthly paid
            else {
                principal = monthlyPaid - interestRate;
                loan = loan - principal;
                currentMonth++;
            }

            interestTotal += interestRate;

            if (loan <= 1000) {
                cout << currentMonth << "\t\t$" << loan << "\t\t$" << monthlyPaid << "\t\t" << userInputInterest
                     << "\t\t$"
                     << interestRate << "\t\t$" << principal << "\n";
            }
            if (loan > 1000) {
                cout << currentMonth << "\t\t$" << loan << "\t$" << monthlyPaid << "\t\t" << userInputInterest
                     << "\t\t$"
                     << interestRate << "\t\t$" << principal << "\n";
            }
        }


            cout << "****************************************************************\n";
            cout << "\nIt takes " << currentMonth << " months to pay off "
                 << "the loan.\n"
                 << "Total interest paid is: $" << interestTotal;
        cout << endl << endl;
        return 0;

    }


