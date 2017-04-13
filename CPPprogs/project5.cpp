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
#include <string>
#include <fstream>

using namespace std;

bool openFile(ifstream& inf, string& fileName, string name, double rate)

{

  // Input

  cout << "Please enter the name of the Data File: ";
  cin >> fileName;
  cout << endl;

  inf.open("textpayroll.dat");

  if (inf.fail())
    {

      cout << "Can't open file" << endl;
      return false;
    }
  else
    return true;
}


string readName(ifstream& inf, string name)
{
// ReadName
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will read name.
//

  inf >> name;
  return name;
}
 
double readHourlyRate(ifstream& inf, double rate)
{
  inf >> rate;
  return rate;
}


double readTotalHours(ifstream& inf,double day[4], double rate)
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
  double totalHours;

  inf>>day[0]>>day[1]>>day[2]>>day[3]>>day[4];

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

  // Initializations

  grossPay = 0.0;

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

  // Initializations

  withholding = 0.0;

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

  // Declarations

  double netpay;

  // Initializations

  netpay = 0.0;

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

  cout << "name         grossPay       withholding          netPay" <<endl;
}

double displayValues(string name, double grossPay, double withholding, double netPay)
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

  cout<<name<<"          "<<"$"<<grossPay<<"          "<<"$"<<withholding<<"            "<<"$"<<netPay<<endl;

  // Input/Output
}

int main()

{
 
 
  // Declarations
  string fileName;
  ifstream inf;
  double hourlyRate;
  string name;
  double totalHours = 0;
  double day[4];
  double grossPay;
  double withholding;
  double netPay;
  double values;

  // Initializations

  grossPay = 0.0;
  withholding = 0.0;
  netPay = 0.0;
  values = 0.0; 

  openFile (inf, fileName, name,hourlyRate);

  while (!inf.eof())
    {
       // Input

      name = readName(inf, name);
      hourlyRate = readHourlyRate(inf, hourlyRate);
      totalHours = readTotalHours(inf, day, totalHours);

	// Calculations

	grossPay = calculateGrossPay(totalHours, grossPay, hourlyRate);
	withholding = calculateWithholding(grossPay, withholding);
	netPay = calculateNetPay(netPay, grossPay, withholding);

	// Output
	displayHeader();

	displayValues(name, grossPay, withholding, netPay);
    }
 
  // Prologue

  return 0;
}





