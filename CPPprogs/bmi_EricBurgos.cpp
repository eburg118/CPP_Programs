./**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: Septemper 11, 2014                                              */
/* Due Date: September 14, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #4                                                                 */
/* Filename: bmi_EricBurgos.cpp                                                   */
/* Purpose: This program will calculate the body mass index (BMI) of the user.    */
/**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;
int main()
{
  string name;
  float weight,height,bmi;

  // Get users name

  cout << "What is the users name?: ";
  getline(cin, name);
  
  // Get user weight

  cout << "What is the users weight(in pounds)?: ";
  cin >> weight;

  // Get users height

  cout << "What is the users height(in inches)?: ";
  cin >> height;

  // Calculate bmi

  bmi = 703 * weight / (height * height);

  // Display

  cout << "Hello, " << name << "." << endl;
  cout << "Your weight is: " << weight << " pounds." << endl;
  cout << "Your height is: " << height << " inches." << endl;
  cout << "Your body mass index is: " << bmi << endl;

  return 0;
}
