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

void displayInstructions()
{
  // displayIntructions
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // This function will display intructions to the user in order to continue with program.

  // Delcarations
  // Initializations
  // Input
  // Processing
  // Output
  //
  cout << "This program will calculate the total hospital charges incurred gives" << endl;
  cout << "the number of days spent in the hospital, the medication charges, the surgical charges" << endl;
  cout << "and the lab fees. The program will produce as output the room charges and the total charges" << endl;
  cout << "Please follow the instructions to enter the necessary data" << endl; 
 
  // Prologue

  return;}

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

double readSurgicalCharges()
{ 
  // readsurgicalcharges
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // This function prompts the user to enter the surgical charges for the patient that stayed in the hospital.
  //
  //

  // Declarations 

  double input;

  // Initializations

  input = 0.0;

  // Input

  cout << "Please enter surgical charges for patient: " << "$";
  cin >> input;

  // Prologue

  return input;
}

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

double calculateMiscellaneousCharges(double medicationCharges, double surgicalCharges, double labFees)
{
  // calculateMiscellaneousCharges
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // This function will calculate the miscellaneous charges on the medication charges, surgical charges and lab fess that the user has entered.

  // Declarations

  double miscellaneousCharges;

  // Initializations

  miscellaneousCharges = 0.0;

  // Process

  miscellaneousCharges = medicationCharges + surgicalCharges + labFees;

  // Prologue

  return miscellaneousCharges;
}

double calculateTotalCharges(double roomCharges, double miscellaneousCharges)
{
  // calculateTotalCharges
  // Eric Burgos
  // CSC 135-010
  // Spetember 27,2013
  // part of project.cpp
  // This function calculates the total charge for the patient based on the room charges and the miscellaneous charges.

  // Declarations

  double totalCharges;

  // Initializations

  totalCharges = 0.0;

  // Process

  totalCharges = roomCharges + miscellaneousCharges;

  // Prologue

  return totalCharges;
}

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
  // Declarations

  double numberOfDays;
  double medicationCharges;
  double surgicalCharges;
  double labFees;
  double roomCharges;
  double miscellaneousCharges;
  double totalCharges;
 
  // Initializations
 
 numberOfDays = 0.0;
 medicationCharges = 0.0;
 surgicalCharges = 0.0;
 labFees = 0.0;
 roomCharges = 0.0;
 miscellaneousCharges = 0.0;
 totalCharges = 0.0;

  // Input

  displayInstructions();
  numberOfDays = readNumberOfDays();
  medicationCharges = readMedicationCharges();
  surgicalCharges = readSurgicalCharges();
  labFees = readLabFees();

  // Process/Calculations

  roomCharges = calculateRoomCharges(numberOfDays);
  miscellaneousCharges = calculateMiscellaneousCharges(medicationCharges, surgicalCharges, labFees);
  totalCharges = calculateTotalCharges(roomCharges, miscellaneousCharges);

  // Output

  displayResults (numberOfDays, medicationCharges, surgicalCharges, labFees, roomCharges, miscellaneousCharges, totalCharges);
 
 // Prologue

  return 0;
}
