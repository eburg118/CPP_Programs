// Project3
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This program will calculate and print a bank's service fees for a month.
//
#include <iostream>
#include <iomanip>

using namespace std;

void displayResults (double accountNumber, double numberOfChecks, double serviceFee)
{
// DisplayResults
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This function will display the results (Account Number, Account Type, Number of Checks written and the fee you owe).
//

// Output

  cout << "Your account number is: " << accountNumber <<"." << endl;
  cout << "Your account type is: c." << endl;
  cout << "You have written " <<numberOfChecks<<" checks this month." << endl;
  cout << "Your service fee is:$" << serviceFee << endl;

}

int main()

{ 

  displayResults(1234, 34, 12.72);
  return 0;
}

