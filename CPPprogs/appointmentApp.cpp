//Author: Eric Burgos  
//Creation Date: February 24, 2015 
//Due Date: March 5, 2015
//Course:  CSC 136
//Professor: Prof. Day
//Assignment Number: #2
//Purpose:  Allows a user to keep track of appointments by using the myDate class
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "myDate.h"
#include "myTime.h"
using namespace std;

//Name: readAppointments
//Description: opens a file and reals all appoinments until
//             the end  of the file.  Then calls sort.
//Parameters:  dates - an array of myDate objects
//             size - updated when a values are added
//Return:      none
void readAppointments(myDate dates[], int &size);

//Name: sort
//Description: does a selection sort in ascending order
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void sort(myDate dates[], int size);

//Name: menu
//Description: does a selection sort in ascending order
//Parameters:  none
//             
//Return:      none
int menu();

//Name: viewAppointments
//Description: displays appointments
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void viewAppointments(myDate dates[], int size);

//Name: addAppointments
//Description: ability to add appointments to array
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void addAppointment(myDate dates[], int &size);

//Name: viewLongNames
//Description: displays appointments in long name form
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void viewLongNames(myDate dates[], int size);

//Name: showMissedAppoinments
//Description: displays missed appointments
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void showMissedAppointments(myDate dates[], int size);

//Name: moveAllAppointments
//Description: moves appointment days according to user input
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void moveAllAppointments(myDate dates[], int size);

//Name: viewAllTodaysAppointments
//Description: shows appointments taking in user input as to what the date is
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void viewAllTodaysAppointments(myDate dates[], int size);

int main()
{
  myDate dates[50];
  int size;
  int choice;

  readAppointments(dates, size); 
  sort(dates, size);
  while ((choice = menu()) != 7)
    {
      switch(choice)
	{
	case 1: addAppointment(dates, size); break;
	case 2: viewAppointments(dates, size); break;
	case 3: viewLongNames(dates, size); break;
	case 4: showMissedAppointments(dates, size); break;
	case 5: moveAllAppointments(dates,size); break;
	case 6: viewAllTodaysAppointments(dates, size); break;
	}
    }
						    
  
  return 0;
}


//Name: readAppointments
//Description: opens a file and reals all appoinments until
//             the end  of the file.  Then calls sort.
//Parameters:  dates - an array of myDate objects
//             size - updated when a values are added
//Return:      none
void readAppointments(myDate dates[], int &size)
{
  ifstream f;
  string fname;
  size = 0;
  myDate aDate;
  myTime aTime;

  cout << "File: ";
  cin >> fname;
  f.open(fname.c_str());
  if (f.fail())
    {
      cout << "file failed to open" << endl;
      exit (0);
    }
  
  f >> aDate;
  while (!f.eof())
    {
      f >> aTime;
      aDate.setTime(aTime);
      dates[size] = aDate;
      size ++;
      f >> aDate;
    }
  sort(dates, size);
  f.close();
}

//Name: sort
//Description: does a selection sort in ascending order
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void sort(myDate dates[], int size)
{
  int first, min;
  myDate date;

  for (int i=0; i<size-1; i++)
    {
      min = i;
      for (int j=i+1; j<size; j++)
	if (dates[j] < dates[min])
	  min = j;

      date = dates[i];
      dates[i] = dates[min];
      dates[min] = date;
    }
}

//Name: addAppointments
//Description: ability to add appointments to array
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void addAppointment(myDate dates[], int &size)
{
  myDate datez;
  myTime timez;
  cout << "Enter the date of appointment(m/d/y): ";
  cin >> datez;
  cout << "Enter the time(Hours:Minutes):" ;
  cin >> timez;

  datez.setTime(timez);
  dates[size] = datez;
  size ++;
  sort(dates, size);

}

//Name: viewAppointments
//Description: displays appointments
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void viewAppointments(myDate dates[], int size)
{
  for (int i = 0; i < size; i++)
    cout << dates[i] << endl;
}

//Name: viewLongNames
//Description: displays appointments in long name form
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void viewLongNames(myDate dates[], int size)
{
  
  for (int i = 0; i < size; i++)
    {
      cout << dates[i].toLongDate() << " ";
      dates[i].getTime().showClock();
      cout << endl;
    }
}

//Name: showMissedAppoinments
//Description: displays missed appointments
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void showMissedAppointments(myDate dates[], int size)
{
  myDate dateToday;
  myTime timeToday;
  cout << "What is todays date(m/d/y)?: ";
  cin >> dateToday;
  cout << endl;
  cout << "Current time(Hours:Minutes): ";
  cin >> timeToday;
  cout << endl;

  dateToday.setTime(timeToday);
  for(int i = 0; i < size; i++)
    {
      if (dateToday>dates[i])
	{
	  cout << dates[i];
	  cout << endl;
	} 
   }
}

//Name: moveAllAppointments
//Description: moves appointment days according to user input
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void moveAllAppointments(myDate dates[], int size)
{
  int howMany;

  cout << "How many days?: ";
  cin >> howMany;
  for(int i = 0; i < size; i++)
    dates[i] += howMany;
}

//Name: viewAllTodaysAppointments
//Description: shows appointments taking in user input as to what the date is
//Parameters:  dates - an array of myDate objects
//             size - updated when a value added
//Return:      none
void viewAllTodaysAppointments(myDate dates[], int size)
{
  myDate todaysDate;
  cout << "Todays date(m/d/y)?: ";
  cin >> todaysDate;
  cout << "The time(s) for todays appointments is/are: " << endl;
  for (int i = 0; i < size; i++)
    {
      if (todaysDate.compareDates(dates[i]) == 0)
	{
	  dates[i].getTime().showClock();
	  cout << endl;
	}
    }
}

//Name: menu
//Description: does a selection sort in ascending order
//Parameters:  none
//
//Return:      none
int menu()
{
  int choice;
  cout << endl;
  cout << "1. Add an appointment" << endl;
  cout << "2. Show all appointments" << endl;
  cout << "3. Show long names" << endl;
  cout << "4. Show missed appointments" << endl;
  cout << "5. Move all appointments" << endl;
  cout << "6. View today's appointments" << endl;
  cout << "7. Quit" << endl;

  cin >> choice;
  return choice;
}


