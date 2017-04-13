/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 14, 2014                                               */
/* Due Date: October 20, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #10                                                                 */
/* Filename: parameters_EricBurgos.cpp                                             */
/* Purpose: This program will use functions and function calls                   */
/**********************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std; 

// Prototypes

void displayInf();
void computeSumDiff();



// Function to take names as input and display them

void displayInf(string name, int age)
{
  cout << endl;
  cout << "Hello, " << name << endl;
  cout << "You are " << age << "years old." << endl << endl;
}

// Function to display user input after being calculated

void computeSumDiff(int sum, int diff)
{ cout << endl;
  cout <<"The sum of the two integers is " << sum << endl;
  cout <<"The difference of the two integers is " << diff << "." <<  endl;
  
}
int main()
{
  // Defining variables
  string name;
  int age;
  int num1;
  int num2;
  int sum;
  int diff;
  
  // Asking for user input
  
  cout << endl;
  cout << "What is your name? ";
  getline(cin,name);
  cout << "How old are you? ";
  cin >> age;
  
  // Calling function 
  
  displayInf(name, age);
  
  cout << "Enter two integers: ";
  cin >> num1 >> num2;
  
  // Calculations
  
  sum = num1 + num2;
  if (num1>num2)
    {
      diff = (num1-num2);
    }
  else if (num2>num1)
    {
      diff = (num2-num1);
    }
  else if (num1==num2)
    {
      diff = 0;
    }
  
  // Calling function
  
  computeSumDiff(sum, diff);


  return 0;

}
