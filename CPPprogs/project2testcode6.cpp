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


double readNumberOfDays()

{
  // readnumberofdays
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // This function will prompt the user for the number of days the patient stayed at the hospital.
  // Declarations

  double input;

  // Initializations

  input = 0.0;

  // Input

  cout << "Please enter the number of days the patient stayed in the hospital: ";
  cin >> input;

  // Prologue

  return input;
}

double calculateRoomCharges(double numberOfDays)
{
  // calculateRoomCharges
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // This function will calculate the amount of room charge which is based in the number of days that the user entered.
  
  // Declarations 

  double roomCharges;

  // Initializations

  roomCharges = 0.0;
 
  // Calculations

  roomCharges = numberOfDays * 450.00;

  // Prologue

  return roomCharges;
}

int main()
{
  // Declarations

  double numberOfDays;
  double roomCharges;
  double results; 

 // Initializations
 
 numberOfDays = 0.0;
 roomCharges = 0.0;
 results = 0.0;
 // Input

 numberOfDays = readNumberOfDays();

 // Output

 results = calculateRoomCharges(numberOfDays);
 cout << "Room Charges are: " << "$" << results << endl;

 
 // Prologue

  return 0;
}
