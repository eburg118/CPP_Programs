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
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

// Prototypes

void displayHeader();


void displayHeader()
{
  cout << "Name" << "\t\t" << "Number" << "\t" << "Rating" << endl;
  cout << "-----------------------------------------------" << endl;
}

string calculateRating(ifstream &fp, string ratings[], int num1[], int count)
{
  string rating = ratings[0];

  while(fp.eof() == false)
    {
      for(int i=0; i<count; i++)
	{   
	  
	  if(num1[i] >= 500)
	    rating = "*****";
	  else if(num1[i] >= 300 && num1[i] < 500)
	    rating = "***";
	  else if(num1[i] >= 200 && num1[i] < 300)
	    rating = "*";
	  else if(num1[i] < 200)
	    rating = "-";
	 	  
	}
      return rating;
    }

}

int getTotalNumber(int num1[], int count)
{
  int sum=0;
  for(int i=0;i<count;i++)
    {
      sum+=num1[i];
    }
  return sum;
}
int main()
{
  string name[50];
  int num1[50]; 
  string ratings[50];
  int count = 0;
  ifstream fp;
  string rating;
  int sum;
  displayHeader();

  fp.open("elves.dat");
  if(!fp)
    {
      cout << "Error opening file";
      return 0;
    }
  else 
    {
      while(fp.eof() == false)
	{
	  fp >> name[49];
	  fp >> num1[49];
	  count++;
	}  
      //for(int i =0; i<count;i++)
	//	{
	  //cout << num1[i];
	  //cout << endl;
	  //	}
      sum = getTotalNumber(num1, count);
      cout << sum << endl;
      // rating =calculateRating(fp, ratings, num1, count);
      //cout << rating;
      fp.close();
    }
}
