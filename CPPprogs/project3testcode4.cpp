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

double readNumberOfChecks()
{
// ReadNumberOfChecks
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This function will prompt the user for the number of checks.
//

// Declarations

  double input;

// Initializations

  input = 0.0;

// Input

  cout << "Please enter the number of checks written: ";
  cin >> input;

// Prologue

  return input;
}

int main()

{ 
  readNumberOfChecks();
  return 0;
}

