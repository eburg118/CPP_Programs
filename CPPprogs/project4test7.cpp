// Project4.cpp
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will process employess and their pay.
//
//
#include <iostream>
#include <iomanip>

using namespace std;

string readName()
{
// ReadName
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will prompt the user for their name.
//

  // Declarations

  string name;

  // Input

  cout << "Please enter your name:";
  cin >> name ;
  cout << endl;
 
  // Prologue

  return name;
}

double readHourlyRate()
{
// ReadHourlyRate
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will prompt the hourly rate for the user.
//

  // Declarations

  double hourlyRate;
 
  // Input

  cout << "Please enter hourly rate: ";
  cin >> hourlyRate;
  cout << endl; 

  if(hourlyRate <=0)
    {
      readHourlyRate();
      return 0;
}
  else if(hourlyRate > 0)
    {
      return hourlyRate;
    }
}
float readTotalHours()
{
// ReadTotalHours
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will prompt the user for their total hours worked for 5 days.
//

  // Declarations

  float day[4];
  float totalHours;
 
  // Input

 cout<<"Please enter the number of hours you worked for each day separated by a space: ";
  cin >> day[0] >> day[1] >> day[2] >> day[3] >> day[4];

  for(int i = 0;i<=4;i++)
    {
     
      totalHours += day[i];
    }

  // Prologue

  return totalHours;
}

double calculateGrossPay(double totalHours, double grossPay, double hourlyRate)
{
// CalculateGrossPay
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will calculate gross pay for the user.
//

  // Calculations

  if(totalHours <=40)
    {
      grossPay = totalHours * hourlyRate;
    }
  if(totalHours > 40)
    {
      grossPay = ((totalHours - 40)*(hourlyRate*1.5))+(40 * hourlyRate);
      
	}

  // Prologue

  return grossPay;
}

double calculateWithholding(double grossPay, double withholding)
{
// CalculateWithholding
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will calculate the withholding for the user.
//

  // Calculations

  if(grossPay <= 500)
    {
      withholding = (grossPay*.0125)+(grossPay*.0765)+(grossPay*.15);
    }
  if(grossPay > 500)
    {
      withholding = (grossPay*.0125)+(grossPay*.0765)+(grossPay*.25);
    }
 
  // Prologue

  return withholding;
}

double calculateNetPay(double netPay, double grossPay, double withholding)
{
// CalculateNetPay
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will calculate net pay for the user.
//

  // Calculations

  netPay = grossPay - withholding;

  // Prologue

  return netPay;
}

void displayHeader()
{
// DisplayHeader
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will display header.
//
 
  // Output

  cout << "name         grossPay       withholding        netPay" <<endl;
}

char displayValues(string name, double grossPay, double withholding, double netPay, char exit)
{
// DisplayValues
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will display values.
//

  // Output

  cout<<name<<"            "<<grossPay<<"            "<<withholding<<"            "<<netPay<<endl;

  // Input/Output

  cout << "Run program again?(y/n): ";
  cin >> exit;

  // Prologue

  return exit;
}
int main()

{
  // Declarations

  string name;
  double hourlyRate;
  float totalHours;
  float day[4];
  double grossPay;
  double withholding;
  double netPay;
  double values;
  char exit;
  char printValues;

 

  do    {

        // Input

        name = readName();
	hourlyRate = readHourlyRate();
	totalHours = readTotalHours();

	// Calculations

	grossPay = calculateGrossPay(totalHours, grossPay, hourlyRate);
	withholding = calculateWithholding(grossPay, withholding);
	netPay = calculateNetPay(netPay, grossPay, withholding);

	// Output

	displayHeader();
	exit = displayValues(name, grossPay, withholding, netPay, exit);
    }
  while(exit !='n');
 
  // Prologue

  return 0;
}





