//File: myTimeTest.cpp
//Author: Eric Burgos
//Creation Date: February 11, 2015
//Due Date:February 12, 2015
//Course: CSC136
//Professor: Mrs. Day
//Purpose: User can view a clock and add and subtract hours and minutes

#include <iostream>
#include "myTime.h"
using namespace std;

//Name: menu
//Description: Prints the menu and reads the selection
//Parameters: none
//Return:     int the choice
int menu();
myTime  enterTime();
void displayAs12Hour(myTime tim);
void changeTimebyHours(myTime &tim);

int main()
{
  myTime clock;
  int choice;


  while ((choice = menu()) != 5)
    {
      switch(choice)
	{
	case 1: clock = enterTime(); break;
	case 2: displayAs12Hour(clock); break;
	case 3: changeTimebyHours(clock); break;
	case 4:/* changeTimebyMinutes(clock);*/ break;
	}
    }

  return 0;
}

myTime enterTime()

{
  myTime tim;
  cout << "Enter a time hours:minutes ";
  cin >> tim;
  return tim;
}

void displayAs12Hour(myTime tim)
{
  tim.showClock();
  cout << endl;
}

void changeTimebyHours(myTime &tim)
{
  char pick;
  int added;
  int subtracted;
  cout << "Would you like to add or subtract hours?('a=add, s=subtract'): ";
  cin >> pick;
  if (pick == 'a')
    {
      cout << "How many hours would you like to add?: ";
      cin >> added;
      cout << endl;
      tim.addHours(added);
      tim.showClock();
      cout << endl;
    }
  else if(pick == 's')
    {
      cout << "How many hours would you like to subtract?: ";
      cin >> subtracted;
      cout << endl;
      tim.subtractHours(subtracted);
      tim.showClock();
      cout << endl;
    }
}

//Name: menu
//Description: Prints the menu and reads the selection
//Parameters: none
//Return:     int the choice
int menu()
{
  int choice;
  cout << endl;
  cout << "1. Enter a time" << endl;
  cout << "2. Display the time" << endl;
  cout << "3. Change the time by hours" << endl;
  cout << "4. Change the time by minutes" << endl;
  cout << "5. Quit" << endl;
  cout << "Choice: ";
  cin >> choice;
  cout << endl;
  return choice;
}
