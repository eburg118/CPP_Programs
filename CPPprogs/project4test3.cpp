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

float readTotalHours()
{
// ReadTotalHours
//
// Eric Burgos
// CSC135-010
// November 14, 2013
//
// This program will prompt the user for their number of hours worked for 5 days.
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

int main()

{

  // Declarations

  float totalHours;
  float day[4];

  // Output

  totalHours = readTotalHours();

  // Prologue

  return 0;
}





