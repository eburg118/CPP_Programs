/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 9, 2014                                                 */
/* Due Date: October 13, 2014                                                     */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #9                                                                 */
/* Filename: simpleFigure_EricBurgos.cpp                                          */
/* Purpose:This program will use functions to create a simple figure              */
/**********************************************************************************/
#include<iostream>
using namespace std;

// Prototypes

void drawCircle();
void drawIntersect();
void drawBase();

// Function to draw circle

void drawCircle()
{
  cout << "   *  " <<endl;
  cout << " *   *"<< endl;
  cout << "  * *" << endl;
}

// Function to draw intersect

void drawIntersect()
{
  cout << "  / \\" << endl;
  cout << " /   \\" << endl;
  cout << "/     \\" << endl;
  cout << "-------" << endl;
}

// Function to draw base

void drawBase() 
{
  cout << "  / \\" << endl;
  cout << " /   \\" << endl;
  cout << "/     \\" << endl;
}
// Calling to the functions
 int main()
{
  drawCircle();
  drawIntersect();
  drawBase();
  return 0;
}
