/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 19, 2014                                                */
/* Due Date: October 20, 2014                                                     */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #11                                                                */
/* Filename: returnValue_EricBurgos.cpp                                           */
/* Purpose: This program will use functions and return by value.                  */
/**********************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;



// Function to get input from user.

int getNumber()
{
  int tickets;
  cout << "How many tickets are sold? ";
  cin >> tickets;
  
  return tickets;
}

// Function to calculate the total amount of sale using input parameter

float calculateTotal(int tickets)
{
  float totalSales;
  
  totalSales = tickets * 10.99;
  return totalSales;
}

// Function to calculate total tax using input parameter

float calculateTax(float totalSales)
{
  float totalTax;
  totalTax = totalSales * .06;
  return totalTax; 

}

// Void function that uses three input parameters to display results

void displayResults(int tickets, float totalSales, float totalTax)
{
  cout << setprecision(2) << fixed;
  cout << left << setw(25) <<  "Tickets Sold: " <<  tickets << endl;
  cout << setw(25) << "Total Sales: " << "$" << totalSales << endl;
  cout << setw(25) << "Tax: " << "$" <<  totalTax << endl;
}

// Main function that calls other functions

int main()
{
  int tickets;
  float totalSales;
  float totalTax; 
  
  
  tickets =  getNumber();
  totalSales = calculateTotal(tickets);
  totalTax = calculateTax(totalSales);
  displayResults(tickets, totalSales, totalTax);
  return 0;
}




