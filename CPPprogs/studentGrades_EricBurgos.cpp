/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: November 17, 2014                                               */
/* Due Date: November 21, 2014                                                    */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: Project #3                                                         */
/* Filename: studentGrade_EricBurgos.cpp                                          */
/* Purpose: This program will use user input to get student grades and name       */
/* and it will calculate the average. It will display Name, Avg, and letter grade */
/**********************************************************************************/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

// Prototypes

char findLetterGrade(float avgGrade);
void displayOutput(string studentName, float avgGrade, char letterGrade);

// Function that will display header

void displayHeader()
{
  cout << "*************************************************"  << endl;
  cout << "*\t" << "Welcome to Grade Calculator, Sir!" << "\t" << "*" << endl;
  cout << "*************************************************"  << endl;
}

// Function that will find the ltter grade based on avg grade of student

char findLetterGrade(float avgGrade)
{
  char letterGrade;

  if (avgGrade >= 90 && avgGrade <= 100)
    letterGrade = 'A';
  else if (avgGrade >= 80 && avgGrade <= 89)
    letterGrade = 'B';
  else if (avgGrade >= 70 && avgGrade <= 79)
    letterGrade = 'C';
  else if (avgGrade >= 60 && avgGrade <= 69)
    letterGrade = 'D'; 
  else if (avgGrade >= 0 && avgGrade <= 59)
    letterGrade = 'F';
  else
    letterGrade = '.';
  return letterGrade;
}

// Function that will display the output using studentName, avgGrade and letter grade as inputs

void displayOutput(string studentName, float avgGrade, char letterGrade)
{
  cout << setprecision(1) << fixed;
  cout << left << setw(15) <<  "Name: " << studentName << endl;
  cout << setw(15) << "Average: " << avgGrade << endl;
  cout << setw(15) << "Grade: " << letterGrade << endl;
  cout << endl;
}

// Main function that will use function calls to use other functions

int main()
{
  string studentName;
  float avgGrade;
  char letterGrade;
  displayHeader();
  cout << endl;
  cout << "Enter student name(Enter 'done' when done): ";
  cin >> studentName;
  cout << endl;
  
  // Loop that will run as long as user doesn't type "done"
  
  while(studentName != "done")
    {
      int grade;
      float avgGrade = 0.0;
      
      // Nested loop that will ask user to enter the students grade

      for(int i=1;i<=10;i++)
	{
	  cout << "Enter a grade: ";
	  cin >> grade;
	  avgGrade += grade;
	  
	}
      cout << endl;
      
      //Will calculate the avg grade based on users input
      
      avgGrade = avgGrade/10;
      
      // Function calls
      
      letterGrade =  findLetterGrade(avgGrade);   
      displayOutput(studentName, avgGrade, letterGrade);
      
      // Still in the loop and will ask the user for students name

      cout << "Enter student name(Enter 'done' when done): ";
      cin >> studentName;
      cout << endl;
    }
  cout << "Done" << endl;
  return 0;
}
