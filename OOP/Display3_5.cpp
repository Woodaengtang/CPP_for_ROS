//DISPLAY 3.5 Multiway if-else Statement
//Program to compute state income tax.
#include <iostream>
using namespace std;


//This program outputs the amount of state income tax due computed
//as follows: 
// no tax on income up to $15,000; 
// 5% on income betwee $15,001 and $25,000;
// 10% on income over $25,000.


int main( )
{
    int netIncome;
    double taxBill;

    // (1) Print "Enter net income (rounded to whole dollars) $" and receive netIncome as input.
    // Write code here
    cout << "Enter net income (rounded to whole dollars) $";
    cin >> netIncome;

    // (2) Write a program that can calculate state income tax due using an if-else statement.
    // Write code here 
    if (netIncome > 25000){
        taxBill = 0.1 * (netIncome - 25000) + 0.05 * (25000 - 15000);
    }
    else if (netIncome > 15000) {
        taxBill = 0.05 * (netIncome - 15000);
    }
    else {
        taxBill = 0;
    }

    // (3) Write code to print all results to two decimal places.
    // Write code here
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // (4) Print the netIncome received as input and the calculated taxBill as the result.
    // Write code here
    cout << "Net income = $" << (double)netIncome << "\n";
    cout << "Tax bill = $" << taxBill;

    return 0;
}