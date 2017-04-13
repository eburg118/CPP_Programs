//File:      indexListApp.cpp
//Author:    Eric Burgos
//Updated:  
//Course:    CSC 136
//Date:      Spring 2012
//PUrpose:   Test the indexList Class with ints

#include "indexList.h"
#include "myDate.h"
#include "myTime.h"
#include <iostream>
#include <fstream>
using namespace std;

//FillList
//Description: opens a file and fills the list from the file
//Parameters:  indexList
//Return:      none
void FillList(indexList<myDate> &list);


//DisplayList
//Description: displays the list to the monitor
//Parameters: indexList
//Return:     none
void DisplayList(indexList<myDate> list);

//AddToList
//Description: adds to the list, either append or
//             insert based on user input
//Parameters: indexList
//Return:     none
void AddToList(indexList<myDate> &list);

//GetTodaysAppointments
//Description: displays time of appointment based on user input
//Parameters: indexList
//Return: none
void GetTodaysAppointments(indexList<myDate> list);

//ChangeAppointment
//Description: Lets user change appointment time
//Parameters: indexList
//Return: none

void ChangeAppointment(indexList<myDate> &list);

//Menu
int menu();

int main()
{
	int choice;
	int sizeOfList;
	

	cout << "Enter the size for the list: ";
	cin >> sizeOfList;
	

	indexList<myDate> L(sizeOfList);

	while ((choice = menu()) != 6)
	  {
	    switch (choice)
	      {
	      case 1: FillList(L); break;
	      case 2: AddToList(L); break;
	      case 3: GetTodaysAppointments(L); break;
	      case 4: ChangeAppointment(L); break;
	      case 5: DisplayList(L); break;
	      }
	  }


	return 0;
}


//menu
int menu()
{
	int ch;
	cout << endl;
	cout << "1. Fill from file" << endl;
	cout << "2. Add to the list" << endl;
	cout << "3. Get todays appointments" << endl;
	cout << "4. Change appointment" << endl;
	cout << "5. Display list" << endl;
	cout << "6. Quit" << endl << endl;
	cout << "Choice: ";
	cin >> ch;
	cout << endl;
	return ch;
}

//FillList
//Description: opens a file and fills the list from the file
//Parameters:  indexList
//Return:      none
void FillList(indexList<myDate> &list)
{
  bool ok = true;
  myDate value;
  myTime times;
  ifstream f;
  string fname;

  cout << "File: ";
  cin >> fname;
  f.open(fname.c_str());
  if (f.fail())
    {
      cout << "Failed to open" << endl;
      return;
    }
  
  f >> value;
  while (ok && !f.eof())
    {
      f >> times;
      value.setTime(times);

      ok  = list.orderedInsert(value);
      f >> value;

    }

  f.close();
      
}


//DisplayList
//Description: displays the list to the monitor
//Parameters: indexList
//Return:     none
void DisplayList(indexList<myDate> list)
{
  cout << endl;
  cout << list;
}

//AddToList
//Description: adds to the list, either append or
//             insert based on user input
//Parameters: indexList
//Return:     none
void AddToList(indexList<myDate> &list)
{
  myDate value;
  myTime timez;
  int index;
  bool result;

  cout << "Date to add to list: ";
  cin >> value;
  cout << "Time to add to list: ";
  cin >> timez;

  value.setTime(timez);
  result = list.orderedInsert(value);


  if (!result)
    cout << "addition failed" << endl;
}


//GetTodaysAppointments
//Description: displays time of appointment based on user input
//Parameters: indexList
//Return: none

void GetTodaysAppointments(indexList<myDate> list)
{
  myDate todaysDate;
  myDate datez;
  cout << "Whats today's date?(m/d/y): ";
  cin >> todaysDate;
  cout << endl;
  for(int i=0;i < list.getSize(); i++)
    {
      list.retrieve(i, datez);
      if (datez.compareDates(todaysDate) == 0)
	
	  cout << datez.getTime() << endl;
    
    }

}

//ChangeAppointment
//Description: Lets user change appointment time
//Parameters: indexList
//Return: none

void ChangeAppointment(indexList<myDate> &list)
{
  myDate datee;
  myTime tim;
  int result;
  myDate dateee;
  myTime timm;
  cout << "Please enter a date to change: ";
  cin >> datee;

  cout << "Enter time of the appointment: ";
  cin >> tim;
  cout << endl;

  datee.setTime(tim);
  result = list.search(datee);

  if(result != -1)
    {
      cout << "Enter a new date: ";
      cin >> dateee;
      cout << endl;
      cout << "Enter a new time: ";
      cin >> timm;
      cout << endl;

      dateee.setTime(timm);
      list.remove(result);
      list.orderedInsert(dateee);
    }
}




