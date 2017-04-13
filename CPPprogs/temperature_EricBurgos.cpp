/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: Septemper 15, 2014                                               */
/* Due Date: September 29, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #6                                                                 */
/* Filename: temperature_EricBurgos.cpp                                           */
/* Purpose: This program will use else if statements and will convert celsiu to farenheit   */

/**********************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

  float tempCels; 
  float tempFar;
  
  // Will instruct user to input temperature in Celsius

  cout << "Please enter the temperature today in Celsius: " << endl;
  cin >> tempCels;

  // Calculations to make Celsius into Farenheit

  tempFar = (tempCels * 1.8) + 32;

  // Display temprature in farenheit

  cout << "The temperature today is " << tempFar << "\xB0" << "F" << endl;

  // Will display message according to temperature.

    if(tempFar >= 86)
      cout << "It is hot today." << endl;
    else if(tempFar >= 59)
      cout << "It is warm today." << endl;
    else if(tempFar >= 32)
      cout << "It is cold today." << endl;
    else
      cout << "It is freezing today" << endl; 

}
