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

double validateAccountType( char accountType)
{
// ValidateAccountType
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This function will validate account type.
//

// Process

  switch(accountType)
    {

    case 'C':
      break;
    case 'c':
      break;
    case 'P':
      break;
    case 'p':
      break;
    default:

      // Output
 
cout << "Invalid account type. Program will not calculate fees." << endl;   
 exit(EXIT_FAILURE);
 }
}

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

double calculateServiceFee(double numberOfChecks, double servicefee, char accountType)
{
// CalculateServiceFee
//
// Eric Burgos
// CSC135-010
// November 8,2013
//
// This function will calculate the monthly serivce fee for the user.
//

  // Declarations

  double serviceFee;

  // Process
 
  if(accountType == 'C' || accountType == 'c')
    {
      if(numberOfChecks < 20)
	{
	  serviceFee = numberOfChecks * .10 + 10.00;
	}
      if(numberOfChecks >= 20 && numberOfChecks <= 39)
	{
	  serviceFee = numberOfChecks * .08 + 10.00;
	}
      if(numberOfChecks >= 40 && numberOfChecks <= 59)
	{
	  serviceFee = numberOfChecks * .04 + 10.00;
	}
    }
  if(accountType == 'P' || accountType == 'p')
    {
      if(numberOfChecks < 20)
	{
	  serviceFee = 10.00;
	}
      if(numberOfChecks >= 20 && numberOfChecks <= 50)
	{
	  serviceFee = numberOfChecks * .07 + 10.00;
	}
      if(numberOfChecks > 51)
	{
	  serviceFee = numberOfChecks * .10 + 10.00;
	}
    }
  // Prologue 

 return serviceFee;

}

void displayResults (double accountNumber, char accountType, double numberOfChecks, double serviceFee)
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
  cout << "Your account type is: " << accountType <<"." << endl;
  cout << "You have written " <<numberOfChecks<<" checks this month." << endl;
  cout << "Your Service fee is:$" << serviceFee << endl;

}

int main()

{ 

  // Declarations

  double accountNumber;
  char accountType;
  double numberOfChecks;
  double serviceFee;

  // Initializations 

  accountNumber = 0.0;
  numberOfChecks = 0.0;
  serviceFee = 0.0;

  // Input

  accountNumber = readAccountNumber();
  accountType = readAccountType();
  numberOfChecks = readNumberOfChecks();

  // Process

  validateAccountType(accountType);
  serviceFee = calculateServiceFee(numberOfChecks, serviceFee,accountType);

  // Output

  displayResults(accountNumber, accountType, numberOfChecks, serviceFee);

  // Prologue

  return 0;
}

