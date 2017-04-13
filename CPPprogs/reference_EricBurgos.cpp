/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 21, 2014                                               */
/* Due Date: October 27, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #12                                                                 */
/* Filename: reference_EricBurgos.cpp                                             */
/* Purpose: This program will let you practice calling by reference              */
/**********************************************************************************/

#include <iostream>
#include<string>
using namespace std;

// Prototypes

void readInput(int &num1, int &num2, int &num3);
void findMedian(int num1, int num2, int num3, int &d);
 

// Reads user input, uses reference parameters

void readInput(int &num1, int &num2, int &num3)
{
  cout << "Please enter three integers: ";
  cin >> num1 >> num2 >> num3;
}

// Calculates the median by calling parameters by value, but then median by reference

void findMedian(int num1, int num2, int num3, int &d)
{
  if ((num1 > num2 && num1 < num3) || (num1 > num3 && num1 < num2))
    d = num1;
  else if ((num2 > num1 && num2 < num3) || (num2 > num3 && num2 < num1))
    d = num2;
  else if((num3 > num1 && num3 < num2) || (num3 > num2 && num3 < num1))
    d = num3;
}

// Call function and displays output

int main()
{
  int a, b, c, d;
  readInput(a, b, c);
  findMedian(a, b ,c, d);
  cout << "The median of the value is: " << d << endl;
}
