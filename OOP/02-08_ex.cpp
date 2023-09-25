//DISPLAY 2.8 An if-else Statement
#include <iostream>
using namespace std;
int main( )
{
    int hours;
    double grossPay, rate;

    cout << "Enter the hourly rate of pay: $";
    cin >> rate;
    cout << "Enter the number of hours worked,\n"
         << "rounded to a whole number of hours: ";
    cin >> hours;

    // Write your code here using if-else loop
    if (hours < 40) grossPay = rate * hours;
    else grossPay = rate * 40 + 1.5 * rate * (hours - 40);
    // Write your code to specify the output of type double (two decimal places should be shown)
    
    cout << "Hours = " << hours << endl;
    cout << "Hourly pay rate = $" << rate << endl;
    cout << "Gross pay = $" << grossPay << endl;

    return 0;
}
