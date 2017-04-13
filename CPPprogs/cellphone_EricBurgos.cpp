/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 21, 2014                                                */
/* Due Date: Ocotber 32, 2014                                                     */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: Project #2                                                         */
/* Filename: cellphone_EricBurgos.cpp                                             */
/* Purpose: This program will ask user for account number, service number and     */
/* minutes used in order to calculate the amount due for a specific account.      */
/**********************************************************************************/
#include <iostream>
#include <iomanip>

using namespace std;

// Prototypes

void displayHeader();
int readAccountNum();
char readServiceCode();
int validateServiceCode(char serviceCode);
float calculateAmountDue(char serviceCode, int& nightMins, int& minsUsed, int& dayMins);
void displayResults(int accountNum, char serviceCode, int& minsUsed, float amountDue, int& nightMins, int& dayMins);

//Dsplays opening header

void displayHeader()
{
  
  cout << "Welcome to the phone bill calculator" << endl;
  cout << "--------------------------------------" << endl;
  
}

// Reads in users account number

int readAccountNum()
{
  int accountNum;
  
  cout << "Enter the account number: ";
  cin >> accountNum;
  return accountNum;
}

// Reads in users service code

char readServiceCode()
{
  char serviceCode;
  cout << "Enter the service code: ";
  cin >> serviceCode;
  return serviceCode;
}

// Validates that user typed in correct service code

int validateServiceCode(char serviceCode)
{
  switch (serviceCode)
    {
    case 'R':
      break;
    case 'r':
      break;
    case 'p':
      break;
    case 'P':
      break;
    default:
      cout << "ERROR: Invalid code" << endl;
    }
}

// Calculates the amount due for user based on service

float calculateAmountDue(char serviceCode, int& nightMins, int& minsUsed, int& dayMins)
{
  float amountDue;
   
  if (serviceCode == 'R' || serviceCode == 'r')
    {
      {
	cout << "Enter number of minutes used: ";
	cin >> minsUsed;
	cout << endl;
      }
      if (minsUsed <= 50)
	{
	  amountDue = 10.00;
	}
      if (minsUsed > 50)
	{
	  amountDue = 10.00 + ((minsUsed - 50) * .20);
	}
    }
  if (serviceCode == 'P' || serviceCode == 'p')
    {
      {
	cout << "Enter number of minutes used in day time (from 6AM to 6PM): ";
	cin >> dayMins;
	cout << "Enter number of minutes used in night time (from 6PM to 6AM): ";
	cin >> nightMins;
	cout << endl;      
      }
      if (dayMins <=75 && nightMins <=100)
	{
	  amountDue = 25.00;
	}
      if (dayMins > 75 &&  nightMins > 100)
	{
	  amountDue = 25.00 +(dayMins - 75) * .10 + (nightMins - 100) * .05;
	} 
      if (dayMins > 75 && nightMins <= 100)
	{
	  amountDue= 25.00 + (dayMins - 75) * .10;
	}
      if (dayMins <= 75 && nightMins > 100)
	{
	  amountDue = 25.00 + (nightMins-100) * .05;
	}
      
    }
  
  
  return amountDue;
}

// Displays results

void displayResults(int accountNum, char serviceCode, int& minsUsed, float amountDue, int& nightMins, int& dayMins)
{
  {
    cout << setprecision(2) << fixed << left << setw(25) << "Account number: " << accountNum << endl;
  }
  {
    switch(serviceCode)
      {
      case 'R':
      case 'r':
	cout << "Service:                 "  <<  "Regular" << endl;
	break;
      case 'p':
      case 'P':
	cout << "Service:                 " << "Premium" << endl;
	break;
      }
  }
  {
    switch (serviceCode)
      {
      case 'R':
      case 'r':
	cout << left << setw(25) << "Number of minutes used: " << minsUsed << endl;
	break;
      case 'p':
      case 'P':
	cout << left << setw(25) << "Number of minutes used: " << nightMins + dayMins << endl;
	break;
      }
  }
  {  
    
    cout << left << setw(25) << "Amount Due: " << "$" << amountDue << endl;
  }
  
} 


// Calls functions

int main()
 {
   int accountNum;
   char serviceCode;
   float amountDue;
   int dayMins;
   int nightMins;
   int minsUsed;
   
   displayHeader();
   accountNum = readAccountNum();
   serviceCode = readServiceCode();
   validateServiceCode(serviceCode);
   amountDue = calculateAmountDue(serviceCode, nightMins, minsUsed, dayMins);
   displayResults(accountNum, serviceCode, minsUsed, amountDue, nightMins, dayMins);
   return 0;
 }
 
