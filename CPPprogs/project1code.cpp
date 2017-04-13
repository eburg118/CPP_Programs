//
//
//
// Project1.cpp
// Eric Burgos
// CSC135-010
// September 13 2013
//
// Program will ask the user to enter the number of acres of property owned and the atual property value for those acres. Program will display the number of acres, the actual value, the assessment value, and the property tax.
//
//

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  //Declarations

double acresowned;
double actualvalue;
double assessmentvalue;
double propertytax;

 //Initialization

acresowned = 0.0;
actualvalue = 0.0;
assessmentvalue = 0.0;
propertytax = 0.0;
 
 //Input

cout << "Please enter the number of acres owned: ";
cin >> acresowned;
cout << endl;
cout << "Please enter the actual property value of the acres: ";
cin >> actualvalue;
cout << endl;

 //Process

assessmentvalue = actualvalue * 0.60;
 propertytax = (assessmentvalue / 100.00) * 0.064;

 //Output

 cout << "acres owned: " << setw(8) << acresowned << endl;
cout << "actual value: " << setw(6) << "$" << actualvalue << endl;
cout << "assessment value: " << setw(2) << "$" << assessmentvalue << endl;
cout << "property tax: " << setw(6) << "$" << propertytax << endl;

 //Prologue

 return 0; }


