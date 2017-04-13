/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: November 11, 2014                                               */
/* Due Date: November 15, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #15                                                                */
/* Filename: multipleOrders_EricBurgos.cpp                                        */
/* Purpose: This program will take in multiple orders and calculate the subtotal  */
/* using loops                                                                    */
/**********************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Declares variables

  int pplNum;
  float price;

  // Asks user for number of people at table and takes in input
 
 cout << "How many people are at the table: ";
 cin >> pplNum;

 // Loop that will run while people at the table does not equal to 0

  while(pplNum != 0)
    {
      float sum=0;
      int i;
      for (i=1;i<=pplNum;i++) // Nested loop inside while loop

	{
	  cout << "Enter the price of the meal: ";
	  cin >> price;
     	  sum += price;
	}
      
      cout << endl;
      cout << setprecision(2) << fixed << "The subtotal is " << "$" << sum << "." << endl << endl;
      
      cout << "How many people are at the table: ";
      cin >> pplNum;
    }
  
  // If people at the table = 0 then loop will stop and this will be displayed

  cout << "Bye!" << endl;
  
}
