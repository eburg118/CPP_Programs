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
// This program will prompt the user for their hourly rate.
//
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
// This program will prompt the user for their total of hours worked for 5 days.
//
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
// This program will calculate the gross pay for user.
//
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
//

  // Output

  cout << "name         grossPay     " <<endl;

}

void displayValues(string name, double grossPay)
{
// DisplayValues
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will display values.
//
//

  // Output

  cout<<name<<"            "<<grossPay<<"            "<<endl;

}
int main()

{

  // Declarations

  string name;
  double hourlyRate;
  float totalHours;
  float day[4];
  double grossPay;
  double values;
  char printValues;

        // Input

        name = readName();
	hourlyRate = readHourlyRate();
	totalHours = readTotalHours();

	// Calculations

	grossPay = calculateGrossPay(totalHours, grossPay, hourlyRate);

	// Output

	displayHeader();
        displayValues(name, grossPay);
	
	// Prologue

	return 0;
}





