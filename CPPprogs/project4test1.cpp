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
// This program will prompt user to enter their name
//
//


  // Declarations
  string name;
 
  //Input
 
  cout << "Please enter your name:";
  cin >> name ;
  cout << endl; 

  // Prologue

  return name;
}

int main()

{
  // Declarations

  string name;

  // Output

  name = readName();

  // Prologue

  return 0;
}





