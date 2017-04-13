/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: November 20, 2014                                               */
/* Due Date: December 2, 2014                                                     */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: Project 5                                                          */
/* Filename: loopDataFile_EricBurgos.cpp                                          */
/* Purpose: This program will read in a file and output name, average             */
/* and letter grade for the students in a file.                                   */
/**********************************************************************************/

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

// Prototypes

void displayHeader();
float processGrade(float &num1, float &num2, float &num3, float &num4, float &num5, float &num6, float &num7, float &num8, float &num9, float &num10);
char findLetterGrade(float avgGrade);

// Will display header

void displayHeader()
{
  cout << "Student grade Reports\n";
  cout << "==========================\n";
}

// Will calculate avg grade and return it

float processGrade(float &num1, float &num2, float &num3, float &num4, float &num5, float &num6, float &num7, float &num8, float &num9, float &num10)
{
  float avgGrade;
  avgGrade =  (num1+num2+num3+num4+num5+num6+num7+num8+num9+num10)/10.00;
  return avgGrade; 
}

// Will find letter grade and return it

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


int main()
{
  
  string name;
  float avgGrade;
  float num1, num2, num3, num4, num5, num6, num7, num8, num9, num10;
  ifstream fp;
  char letterGrade;
  fp.open("grades.dat");
  
  if(!fp) // If file does not open display error
    {
      cout << "Error opening file";
      return 0;
    }
  displayHeader();
  while (fp.eof() == false) // Loops while end of file is not reached
    {
      
      fp >> name;
      fp >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8 >> num9 >> num10;
      avgGrade = processGrade(num1, num2, num3, num4, num5, num6, num7, num8, num9, num10);
      cout << left << setw(15) << "Name: " << name << endl;
      cout << setw(15) << "Average: " << avgGrade << endl;
      letterGrade = findLetterGrade(avgGrade);
      cout << setw(15) << "Grade: " << letterGrade << endl << endl;     
    }
  cout << endl;
  fp.close();  
  
}
