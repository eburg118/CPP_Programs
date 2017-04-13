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

double  readAccountNumber()

{
// ReadAccountNumber
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This function will prompt the user for an account number.
//

  // Declarations

  double input;

  // Initializations

  input = 0.0;

  //Input

  cout << "Please enter account number: ";
  cin >> input;

  // Prologue

  return input;
}


int main()

{ 
  readAccountNumber();
  return 0;
}

