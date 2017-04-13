/**********************************************************************************/
/* Author: Eric burgos                                                            */
/* Creating Date: February 5, 2015                                               */
/* Due Date: February 6, 2015                                                     */
/* Course: CSC136                                                             */
/* Professor Name: Mrs. Day                                                      */
/* Assignment: Program #1                                                         */
/* Filename: Program1_Ericburgos.cpp                                          */
/* Purpose:This program will use 2D/Parallel arrays to store and manipulate     */
/* data for a small theatre.                                    */
/**********************************************************************************/

#include<climits>
#include<cstdlib>
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

const char TAKEN = '*';
const char EMPTY = '#';
const int rows = 15;
const int columns = 30;
int total = 0;

int menu();
void readPricing(int rowPrice[], char seatingChart[][columns], int rows, int columns);
void showSeating(int rowPrice[], char seatingChart[][columns], int rows, int columns);
void processCustomer(int rowPrice[], char seatingChart[][columns], int rows, int columns);
void findSeats(int rowPrice[], char seatingChart[][columns], int rows, int columns);
void totals(int rowPrice[], char seatingChart[][columns], int rows, int columns);

 main()
{
  char seatingChart[rows][columns];
  int rowPrice[rows];
  int choice;

  readPricing(rowPrice, seatingChart, rows, columns);
  while ((choice = menu()) !=5)
    {
      switch(choice)
	{
	case 1: processCustomer(rowPrice, seatingChart, rows, columns) ;
	  break;
	case 2: findSeats(rowPrice, seatingChart, rows, columns);
	  break;
	case 3: showSeating(rowPrice, seatingChart, rows, columns);
	  break;
	case 4: totals(rowPrice, seatingChart, rows, columns);
	  break;
	}
    }
  return 0;
}

/**********************************************************************************/
/* Name: menu                                                                     */
/* Purpose: Prints options for the user                                           */
/* Parameters: none                                                               */
/* Return: Choice                                                                 */ 
/**********************************************************************************/

int menu()
{
  int choice;
  cout << endl;
  cout << "1. Process a customer" << endl;
  cout << "2. Find the number of seats available in a given row" << endl;
  cout << "3. Print the seating chart" << endl;
  cout << "4. Report total tickets sold and total price" << endl;
  cout << "5. Quit" << endl;
  cout << "Choice: ";
  cin >> choice;
  cout << endl;
  return choice;
}

/**********************************************************************************/
/* Name: readPricing                                                              */
/* Purpose: Reads price file into array                                           */
/* Parameters: rowPrice - array of prices                                         */
/*             seatingChart - matrix for seating                                  */
/*             rows - number of rows                                              */
/*             columns - number of columns                                        */
/* Return: none                                                                   */
/**********************************************************************************/

void readPricing(int rowPrice[], char seatingChart[][columns], int rows, int columns)
{
  ifstream fp;
  string fileName;
  
  cout << "Enter the name of the price file: ";
  cin >> fileName; // Filename: pricing.dat
  fp.open(fileName.c_str());
  if(!fp.good())
    {
      cout << "No data on file" << endl;
      exit(0);
    }
  for(int r=0; r<rows;r++)
    {
      fp >> rowPrice[r];
    }
  fp.close();

  // Initialization for seating chart matrix

  for(int i = 0; i<rows; i++)
    {
      for (int c = 0; c < columns; c++)
	seatingChart[i][c] = EMPTY; 
    }
  
}

/**********************************************************************************/
/* Name: showSeating                                                              */
/* Purpose: Displays theatre seating                                              */
/* Parameters: rowPrice - array of prices                                         */
/*             seatingChart - matrix for seating                                  */
/*             rows - number of rows                                              */
/*             columns - number of columns                                        */
/* Return: none                                                                   */
/**********************************************************************************/



void showSeating(int rowPrice[], char seatingChart[][columns], int rows, int columns)
{
  cout << "\t\tSeats" << endl;
  cout <<  "\t123456789012345678901234567890" << endl;
  
  for (int r=0; r<rows;r++)
    {
      cout << left << "Row" << setw(5) << (r + 1);
      
      for (int c=0; c<columns; c++)
	{
	  cout << seatingChart[r][c];

	}
      cout << endl;            
    }


}

/**********************************************************************************/
/* Name: processCustomer                                                          */
/* Purpose: Will allow customer to pick a seat and reserve it                     */
/* Parameters: rowPrice - array of prices                                         */
/*             seatingChart - matrix for seating                                  */
/*             rows - number of rows                                              */
/*             columns - number of columns                                        */
/* Return: none                                                                   */
/**********************************************************************************/


void processCustomer(int rowPrice[], char seatingChart[][columns], int rows, int columns)
{
  int row1, column1;
  char YorN;
  double total = 0.0;
  int ticket = 0;
 do
   {
     cout << "Enter the row and seat you want: ";
     cin >> row1 >> column1;
     cout << endl;
     if(seatingChart[row1][column1] == TAKEN)
       {
	 cout << "Cannot be reserved" << endl;
	 cout << "Do you need another seat? (y/n)" << endl;
	 cin >> YorN;
       }
     else if(seatingChart[row1][column1] == EMPTY)
       { 
	 for (int r=0; r<rows;r++)
	   for ( int c=0; c<columns; c++)
	     {
	       if(seatingChart[r][c] == TAKEN)
		 {
		   total+= seatingChart[r][c];
		 
		 }
	     }

	 ticket++;
	 seatingChart[row1-1][column1-1] = TAKEN;
	 cout << "Seat reserved" << endl;
	 cout << "Do you need another seat? (y/n)" << endl;
	 cin >> YorN;
	 
       }
   }
 while(YorN == 'y');
 
 
 cout << "Thank you" << endl;
 cout << "---------" << endl;
 cout << "You reserved " << ticket << " seats" << endl;
 cout << fixed <<  setprecision(2) <<  "You owe: $" << total  << endl;
 
} 

 

/**********************************************************************************/
/* Name: findSeats                                                                */
/* Purpose: Checks open seats with the use of user input                          */
/* Parameters: rowPrice - array of prices                                         */
/*             seatingChart - matrix for seating                                  */
/*             rows - number of rows                                              */
/*             columns - number of columns                                        */
/* Return: none                                                                   */
/**********************************************************************************/
void findSeats(int rowPrice[], char seatingChart[][columns], int rows, int columns)
{
  int rowz;
  int totalSeats = 0;

  cout << "Enter a row to check between 1 and 15: ";
  cin >> rowz;
  cout << endl;
  for (int c=0;c<columns;c++)
    {
      if (seatingChart[rowz-1][c] == EMPTY )
      totalSeats++;
    }
  cout << "There are " << totalSeats   << " seats available in row " << rowz << endl; 
}

/**********************************************************************************/
/* Name: totals                                                                   */
/* Purpose: Displays total tickets sold and total $ due                           */
/* Parameters: rowPrice - array of prices                                         */
/*             seatingChart - matrix for seating                                  */
/*             rows - number of rows                                              */
/*             columns - number of columns                                        */
/* Return: none                                                                   */
/**********************************************************************************/

void totals(int rowPrice[], char seatingChart[][columns], int rows, int columns)
{
  int r, c;
  int Ticketz = 0;
  double sum = 0.0;
 for ( r=0; r<rows;r++)
  for ( c=0; c<columns; c++)
    {	
      if(seatingChart[r][c] == TAKEN)
	{
	  sum+= seatingChart[r][c];
	    Ticketz++;
	}
    }
 
 
 cout << "Tickets Sold: " << Ticketz << endl;
 cout << "Total Collected: " << sum << "$" << endl;
}
