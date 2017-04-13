/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 28, 2014                                               */
/* Due Date: November 3, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #13                                                                */
/* Filename: averageGrade_EricBurgos.cpp                                          */
/* Purpose: This program will use a loop to calculate average of numbers inputed  */
/**********************************************************************************/
#include <iostream>
using namespace std;


int main()
{

  // Initializing the variables

  int avrg, grade, total = 0, sum = 0;

  // First instance of asking the user for input

  cout << " Please Enter a grade, enter -1 to end: ";
  cin >> grade;

  // Loop that will run until grade is not equal to -1

  while (grade != -1)
    {
      sum += grade;
      cout << "Please Enter a grade, enter -1 to end: ";
      cin >> grade;
      total = total + 1;
    }

  // Will calculate the average using the variables in the loop

  avrg = sum/total;
  cout << "The class average is " << avrg << "."<< endl; 
}

