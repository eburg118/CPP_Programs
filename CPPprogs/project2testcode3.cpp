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


double readMedicationCharges()
{
  // readmedicationcharges
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // 
  // This function prompts the user to enter the medication cost for the patient.
  //
  //

  // Declarations

  double input;

  // Initializations

  input = 0.0;

  // input

  cout << "Please enter medication charges for patient: " << "$";
  cin >> input;

  // Prologue

  return input;
}

int main()
{
 readMedicationCharges();
  return 0;
}
