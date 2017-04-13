/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: November 20, 2014                                               */
/* Due Date: November 24, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #17                                                                 */
/* Filename: simpleArray_EricBurgos.cpp                                             */
/* Purpose: This program will take in user input and store in array.              */
/* and it will output different outputs based on the for loop                     */
/**********************************************************************************/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main()
{

  // Declarations

  int grades[10];
  int highest;
  int lowest;
  int average;
  int sum = 0;
  int count = 0;

  // Loop to ask user for input

  for(int i=0;i<10;i++)
    {
      cout << "Enter a number: ";
      cin >> grades[i];
    }
  cout << endl;
  cout << "You entered: "; 


  highest=lowest=grades[0];

  // Loop output the values in array

  for(int i = 0; i < 10; i++)
    {
      cout << grades[i] << " ";
    }
  cout << endl;
  cout << "Reversed order: ";
  
  // Loop to reverse the values in the array

  for(int i=10-1;i>=0;i--)
    {
      cout << grades[i] << " ";
    }
  cout << endl;
  cout << "The highest grade is ";

  // Loop to find the highest value in the array

  for(int i = 0; i < 10; i++)
    {
      if(grades[i] > highest)
	highest = grades[i];
    }
  cout << highest << endl;
  cout << "The lowest grade is ";

  // Loop to find the lowest values in the array

  for(int i = 0; i<10; i++)
    {
      if(grades[i] < lowest)
	lowest = grades[i];
    }
  cout << lowest << endl;
  cout << "The average grade is ";

  // Loop to find the average values of the array

  for(int i = 0; i < 10; i++)
    {
      sum += grades[i];
    }
  average = sum/10;
  cout << average << endl;
  cout << "There are "; 

  // Loop to find the number of grades above the average

  for(int i = 0; i < 10; i++)
    {
      if(grades[i] >= average)
	count++;
    }
  
  cout << count << " grades above average." << endl;

}
