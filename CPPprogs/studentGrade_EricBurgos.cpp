/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: November 13, 2014                                               */
/* Due Date: November 16, 2014                                                    */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #16                                                                */
/* Filename: studentGrade_EricBurgos.cpp                                          */
/* Purpose: This program will read in an input file using fp.open and it will     */
/*  use that data to calculate the final exam for each student in the data file.  */
/**********************************************************************************/
#include <iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

int main()
{

  // Declaring variables that will be used

  string name;
  float quizGrade1, quizGrade2, quizGrade3, exam1, exam2, final, quiz, finalEx, finalGrade, exam;
  ifstream fp; // Declaring variable for the file
  fp.open("student.dat"); // Will open the file specified
  
  // Will check if file opened correctly

  if (!fp)
    {
      cout << "Error opening file ";
      return 0;
    }
 
  // Will process a loop while the end of the file has not been reached and will stop once it does

  while (fp.eof() == false)
    {
      fp >> name;
      fp >> quizGrade1;
      fp >> quizGrade2;
      fp >> quizGrade3;
      fp >> exam1;
      fp >> exam2;
      fp >> final;
      quiz = (quizGrade1 + quizGrade2 + quizGrade3)/30 * .20 *100;
      exam = (exam1 + exam2)/200 * .50 * 100;
      finalEx = final/100 * .30 * 100;
      finalGrade = quiz + exam + finalEx;

      cout << setprecision(1) << fixed;
      cout << name <<"\t\t" <<finalGrade << endl;
    }    
  
}

