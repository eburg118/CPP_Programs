/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: October 24, 2014                                                */
/* Due Date: Novermber 6, 2014                                                    */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: Project #3                                                         */
/* Filename: shipping_EricBurgos.cpp                                              */
/* Purpose: This program will let the user input the amount of spools             */
/* that he or she wants to order and will output how much it will cost            */
/**********************************************************************************/
#include<iostream>
#include<iomanip>

using namespace std;

// Prototypes

void displayHeader();
int readNumberOfSpools();
float calculateSubtotal(int spools);
float calculateShipnHand(float subtotal);
float calculateTotalCost(float shipnHand, float subtotal);
void printResults(int spools, float subtotal, float shipnHnad, float totalCost);

// Will display header and what program will do

void displayHeader()
{
  cout << "Welcome to Shipping Charge Calculator" << endl;
  cout << "This program will calculate subtotal, shipping and hadling, and total charge" << endl;
  cout << "based on the number of spools ordered." << endl;
  cout << "-------------------------------------------------------------\n";
  cout << endl;
}

// Will read in the number of spools from the user

int readNumberOfSpools()
{
  int spools;
  cout << "Please enter the number of spools ordered: ";               ;
  cin >> spools;
  cout << endl;
  return spools;
}

// Will calculate the subtotal by taking in one parameter from previous function

float calculateSubtotal(int spools)
{
  float subtotal;
  
  subtotal = spools * 100;
  
  return subtotal;
}

// Will calculate the shipping and handling by taking in one parameter from previous function

float calculateShipnHand(float subtotal)
{
  float shipnHand;
  shipnHand = subtotal * .05;
  return shipnHand;
}

// Will calculate total cost by taking in 2 parameters 

float calculateTotalCost( float shipnHand, float subtotal)
{
  float totalCost;
  totalCost = subtotal + shipnHand;
  return totalCost;
}

// will display the results from all of the calculations

void printResults(int spools, float subtotal, float shipnHand, float totalCost)
{
  cout << setprecision(2) << fixed;
  cout << left  << setw(30) << "Number of spools ordered: " << spools << endl; 
  cout << setw(30) << "Subtotal: " << "$" << subtotal << endl;
  cout << setw(30) << "Shipping and handling: " << "$" << shipnHand << endl;
  cout << setw(30) << "Total charge: " << "$" << totalCost << endl;
}

// Main function that will call in the functions and execute them

int main ()
{
  int spools;
  float subtotal;
  float shipnHand;
  float totalCost;

  displayHeader();
  spools = readNumberOfSpools();
  subtotal = calculateSubtotal(spools);
  shipnHand = calculateShipnHand(subtotal);
  totalCost = calculateTotalCost(shipnHand, subtotal);
  printResults(spools, subtotal, shipnHand, totalCost);
  return 0;
}
