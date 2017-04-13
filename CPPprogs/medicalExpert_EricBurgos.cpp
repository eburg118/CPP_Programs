/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: Septemper 9, 2014                                               */
/* Due Date: September 29, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #7                                                                 */
/* Filename: medicalExpert_EricBurgos.cpp                                          */
/* Purpose: This program will use nested if statements to display diagnosis of a patient  */

/**********************************************************************************/

#include<iostream>

using namespace std;

int main()
{
  
  char coughing;
  char breath;
  char headache;
  
  // Nested If statements
  cout << "Are you coughing Y/N?" << endl;
  cin >> coughing;

  if (coughing == 'Y' || coughing == 'y')
    {
      {
	cout << "Are you short of breath or wheezing Y/N?" << endl;
	cin >> breath;
      }
      if(breath == 'Y' || breath == 'y')
	{ 
	  cout << "Diagnosis: Pneumonia or infection of airways" << endl;
	}
      else 
	{
	  cout << "Diagnosis: Possible viral infection" << endl;
	}
    }
  else
    {
      { 
	cout << "Do you have a headache Y/N?" << endl;
	cin >> headache;
      }  
      if (headache == 'Y' || headache == 'y')
	{ 
	  cout << "Diagnosis: Possibilities include: meningitis" << endl;
	}
      else 
	{
	  cout << "You are healthy!" << endl; 
	}
    }
  
}
