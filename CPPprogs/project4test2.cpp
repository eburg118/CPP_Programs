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

double readHourlyRate()
{
// ReadHourlyRate
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will prompt user for their hourly rate.
//
//

  // Declarations

  double hourlyRate;

  // Input 

  cout << "Please enter hourly rate: ";
  cin >> hourlyRate;
  cout << endl; 

  // Prologue

  return hourlyRate;
}

int main()

{
  // Declarations

  double hourlyRate;

  // Output

  hourlyRate = readHourlyRate();

  // Prologue

  return 0;
}





