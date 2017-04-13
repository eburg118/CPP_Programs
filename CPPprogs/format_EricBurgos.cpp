/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: Septemper 18, 2014                                               */
/* Due Date: September 22, 2014                                                   */
/* Course: CSC135 050                                                             */
/* Professor Name: Dr. Zhang                                                      */
/* Assignment: #5                                                                 */
/* Filename: variables_EricBurgos.cpp                                             */
/* Purpose: This program will calculate and display gross profit and net profit   */
/*   after reading user input of movie name, adult ticket and child tickets       */
/**********************************************************************************/
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
  string movieName;
  int adultTickets;
  int childTickets;
  double grossProfit;
  double netProfit;

  // Get the name of the movie

  cout << "Please enter the movie name: " << endl;
  getline (cin, movieName);

  // Gets the number of adult tickets sold

  cout << "Enter the number of adult tickets sold: " << endl;
  cin >> adultTickets;

  // Gets the number of child tickets sold

  cout << "Enter the number of child tickets sold: " << endl;
  cin >> childTickets;

  // Calculating the Gross and Net profits

  grossProfit = (9.50 * adultTickets) + (6.50 * childTickets);
  netProfit = .35 * grossProfit; 

  // Display
  cout << setprecision(2) << fixed;
  cout << left << setw(30) <<  "Movie Name:" <<  movieName << endl;
  cout << setw(30) <<  "Adult Tickets Sold:" <<  adultTickets << endl;
  cout << setw(30) << "Child Tickets sold:" <<  childTickets << endl;
  cout << setw(30) << "Gross Box Office Profit:" << "$" << grossProfit << endl;
  cout << setw(30) << "Net Box Office Profit:" << "$" << netProfit << endl;

  return 0;
}
