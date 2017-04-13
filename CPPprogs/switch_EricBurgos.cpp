/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 7, 2014                                                 */
/* Due Date: October 13, 2014                                                     */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #8                                                                 */
/* Filename: switch_EricBurgos.cpp                                                */
/* Purpose: This program will ask the user to pick between 4 choices              */
/*and using the switch statement it will read input and find area of choice       */
/**********************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
  // Declarations 

  int choice;
  const float pi = 3.1415;
  float radius;
  float areaC;
  float lenght;
  float width;
  float areaR;
  float base;
  float height;
  float areaT;
  float major;
  float minor;
  float areaE;
  
  // Outputs a list of which the user can pick from and input a number

  cout << "What do you want to do?" << endl << endl;
  cout << "1. Computer area of a circle" << endl;
  cout << "2. Computer area of a rectangle" << endl;
  cout << "3. Computer area of a triangle" << endl;
  cout << "4. Computer area of a ellipse" << endl << endl;
  cout << "Please enter the number of your choice: ";
  cin >> choice;
  
  // Uses switch statement and its cases to get more user input and find/output area

  switch(choice)
    {
    case 1:
      cout << setprecision(2) << fixed;
      cout << "What is the radius of the circle: ";
      cin >> radius ;
      areaC = pi * pow(radius,2);
      cout << "Area of circle is: " << areaC << endl;
      break;
      
    case 2:
      cout << setprecision(2) << fixed;
      cout << "Whats is the lenght and width of the rectangle: ";
      cin >> lenght >> width;
      areaR = lenght * width;
      cout << "Area of rectangle is: " << areaR << endl;
      break;
      
    case 3:
      cout << setprecision(2) << fixed;
      cout << "What is the base and height of the rectangle: ";
      cin >> base >> height;
      areaT = .5 * base * height;
      cout << "Area of triangle is: " << areaT << endl;
      break;
      
    case 4:
      cout << setprecision(2) << fixed;
      cout << "Whats is the lenght of major and minor axis: ";
      cin >> major >> minor;
      areaE = pi * major * minor;
      cout << "Area of ellipse is: " << areaE << endl;
      break;
      
    default:
      choice = 0;
    }
  
  
  
}
