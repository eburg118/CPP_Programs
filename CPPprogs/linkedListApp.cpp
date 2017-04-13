//File:      linkedListApp.cpp
//Author:    Eric Burgos
//Updated:  
//Course:    CSC 136
//Date:      Spring 2012
//PUrpose:   Test the linkedList Class with ints

#include "linkedList.h"
#include "myDate.h"
#include "myTime.h"
#include <iostream>
#include <fstream>
using namespace std;

//FillList
//Description: opens a file and fills the list from the file
//Parameters:  linkedList
//Return:      none
void FillList(linkedList<myDate> &list);


//DisplayList
//Description: displays the list to the monitor
//Parameters: linkedList
//Return:     none
void DisplayList(linkedList<myDate> list);

//AddToList
//Description: adds to the list, either append or
//             insert based on user input
//Parameters: linkedList
//Return:     none
void AddToList(linkedList<myDate> &list);

//GetTodaysAppointments
//Description: displays time of appointment based on user input
//Parameters: linkedList
//Return: none
void GetTodaysAppointments(linkedList<myDate> list);

//ChangeAppointment
//Description: Lets user change appointment time
//Parameters: linkedList
//Return: none

void ChangeAppointment(linkedList<myDate> &list);


//clearList
//Description: lets user clear list
//Parameters: none
//Return: none

void clearList(linkedList<myDate> &list);

//Menu
int menu();

int main()
{
	int choice;
	int sizeOfList;
	

	//cout << "Enter the size for the list: ";
	//cin >> sizeOfList;
	

	linkedList<myDate> L;

	while ((choice = menu()) != 7)
	  {
	    switch (choice)
	      {
	      case 1: FillList(L); break;
	      case 2: AddToList(L); break;
	      case 3: GetTodaysAppointments(L); break;
	      case 4: ChangeAppointment(L); break;
	      case 5: DisplayList(L); break;
	      case 6: clearList(L); break;
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
	cout << "6. Clear List" << endl;
	cout << "7. Quit" << endl << endl;
	cout << "Choice: ";
	cin >> ch;
	cout << endl;
	return ch;
}

//FillList
//Description: opens a file and fills the list from the file
//Parameters:  linkedList
//Return:      none
void FillList(linkedList<myDate> &list)
{
  
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
  while (!f.eof())
    {
      f >> times;
      value.setTime(times);

      list.orderedInsert(value);
      f >> value;

    }

  f.close();
      
}


//DisplayList
//Description: displays the list to the monitor
//Parameters: linkedList
//Return:     none
void DisplayList(linkedList<myDate> list)
{
  cout << endl;
  cout << list;
}

//AddToList
//Description: adds to the list, either append or
//             insert based on user input
//Parameters: linkedList
//Return:     none
void AddToList(linkedList<myDate> &list)
{
  myDate value;
  myTime timez;
  int index;

  cout << "Date to add to list: ";
  cin >> value;
  cout << "Time to add to list: ";
  cin >> timez;

  value.setTime(timez);
  list.orderedInsert(value);

}


//GetTodaysAppointments
//Description: displays time of appointment based on user input
//Parameters: linkedList
//Return: none

void GetTodaysAppointments(linkedList<myDate> list)
{
  myDate todaysDate;
  myDate datez;
  cout << "Whats today's date?(m/d/y): ";
  cin >> todaysDate;
  cout << endl;

  list.begin();  
  while(list.retrieve(datez) != false)

    {
      
      if (datez.compareDates(todaysDate) == 0)
	{
	  cout << datez.getTime() << endl;
	}     
      list++; 
    }
}

//ChangeAppointment
//Description: Lets user change appointment time
//Parameters: linkedList
//Return: none

void ChangeAppointment(linkedList<myDate> &list)
{
  myDate datee;
  myTime tim;
  bool result;
  myDate dateee;
  myTime timm;
  cout << "Please enter a date to change: ";
  cin >> datee;

  cout << "Enter time of the appointment: ";
  cin >> tim;
  cout << endl;

  datee.setTime(tim);
  result = list.search(datee);

  if(result != false)
    {
      cout << "Enter a new date: ";
      cin >> dateee;
      cout << endl;
      cout << "Enter a new time: ";
      cin >> timm;
      cout << endl;

      dateee.setTime(timm);
      list.remove(datee);
      list.orderedInsert(dateee);
    }
}

//clearList
//Description: lets user clear list
//Parameters: none
//Return: none

void clearList(linkedList<myDate> &list)
{
  list.begin();
  list.clear();
}



