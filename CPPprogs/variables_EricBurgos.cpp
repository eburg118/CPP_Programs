/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: Septemper 9, 2014                                               */
/* Due Date: September 14, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #3                                                                 */
/* Filename: variables_EricBurgos.cpp                                             */
/* Purpose: This program will let you practice variable declarations              */
/*  and using cout to output variable values, which are embedded in sentences.    */
/**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
  int number;
  number=23;
  cout << endl;
  cout << "There are " << number << " students in my class" << endl;
  
  int num1,num2,num3;
  num1=10;
  num2=15;
  num3=20;
  num1 += 20;
  num3=num1 + num2;
  
  cout << num1 << " "<<num2 << " " << num3 << endl;
  
  string name;
  name= "Eric Burgos";
  cout << "Hello, I am "<<name<<". It is nice to meet you."<<endl;
  
  char grade;
  grade='A';
  
  cout << "My grade for this class is " << grade << "." << endl;
  
  int random;
  
  cout << "The value of a random interger is: " << random << endl;
  cout << endl;

}

