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

double displayResults(double numberOfDays, double medicationCharges, double surgicalCharges, double labFees, double roomCharges, double miscellaneousCharges, double totalCharges)
{
  // displayResults
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // 
  // This funtion wil display the number of days, medication charges, lab fees, surgical charges, room charges, miscellaneous charges and total charges for the user.

  // Output 

  cout << "The number of days the patient stayed in the hospital: " << numberOfDays << endl;
  cout << "The amount of medication charges: " << "$" << medicationCharges << endl;
  cout << "The amount of surgical charges the patient has gotten: " << "$" << surgicalCharges << endl;
  cout << "The amount of lab fees the patient has gotten: " << "$" << labFees << endl;
  cout << "The room charges for the patient : " << "$" << roomCharges << endl;
  cout << "The miscellaneous charges for the patient : " << "$" << miscellaneousCharges << endl;
  cout << "The total charges for the patient: " << "$" << totalCharges << endl;

  // Prologue

  return 0.0;

}


int main()
{
  displayResults (10,150.00,250.00,350.00,4500.00,750.00,5250.00);
  return 0;
}
