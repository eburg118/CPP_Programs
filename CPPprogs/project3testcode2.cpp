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

char readAccountType()
{
// ReadAccountType
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This function will prompt the user for the account type.
//

// Declarations
 
  char accountType;

  // Input

  cout << "Please enter account type: ";
  cin >> accountType;

  // Prologue

  return accountType; 
}

int main()

{ 
  readAccountType();
  return 0;
}

