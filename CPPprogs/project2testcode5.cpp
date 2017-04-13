// Project 2
//
// Eric Burgos
// CSC 135-010
// September 27, 2013
//
// This program calculates the total charges for a hospital visit based on cost
// per day and other charges included during a hospital stay.
//
#include <iostream>
#include <iomanip>

using namespace std;


double readLabFees()
{
  // readLabFees
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  //
  // This function prompts the user to enter the lab fess for the patient that stayed in the hospital.

  // Declarations

  double input;

  // Initializations

  input = 0.0;

  // Input

  cout << "Please enter the lab fees for patient: " << "$";
  cin >> input;

  // Prologue

  return input;
}



int main()
{
  readLabFees();
  return 0;
}
