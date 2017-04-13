// File: myDate.cpp
// Author: Eric Burgos
// Course: CSC 136
// Date: Spring 2015
// Purpose: Implementation on myDate.h file

#include "myDate.h"
#include <iostream>
#include <iomanip>
using namespace std;

//Default constructor
//Description: sets month to 1, day to 1, year to 2015
//Parameters: none
myDate::myDate()
{
  month = 1;
  day = 1;
  year = 2015;
}

// gets and sets

int myDate::getMonth() const
{
  return month;
}
int myDate::getDay() const
{
  return day;
}
int myDate::getYear() const
{
  return year;
}
myTime myDate::getTime() const
{
  return theTime;
}

void myDate::setMonth(int mnth)
{
  month = mnth;
}

void myDate::setDay(int dy)
{
  day = dy;
}

void myDate::setYear(int yr)
{
  year = yr;
}

void myDate::setTime(const myTime &tm)
{
  theTime = tm;
}

//relational operators: compare full date and time
//A later date/time is "greater" than an earlier one
bool myDate::operator==(const myDate &date) const
{
  if (year == date.getYear() && month == date.getMonth() && day == date.getDay() && theTime == date.getTime())
    return true;

  else 
    return false;

}
bool myDate::operator<(const myDate &date) const
{
  if (year < date.getYear())
    return true;
  else if(year > date.getYear())
    return false;
  if (month < date.getMonth())
    return true;
  else if (month > date.getMonth())
    return false;
   if (day < date.getDay())
    return true;
   else if (day > date.getDay())
     return false;
   if (theTime < date.getTime())
     return true;
 else
    return false;

}
bool myDate::operator>(const myDate &date) const
{
  if (year > date.getYear())
    return true;
  else if (year < date.getYear())
    return false;
   if (month > date.getMonth())
    return true;
  else if (month < date.getMonth())
    return false;
  if (day > date.getDay())
    return true;
  else if(day < date.getDay())
    return false;
  if (theTime > date.getTime())
    return true;  
else
    return false;

}
bool myDate::operator<=(const myDate &date) const
{
  if (year <= date.getYear())
    return true;
  else
    return false;
  if (month <= date.getMonth())
    return true;
  else 
    return false;
  if (day <= date.getDay())
    return true;
  else 
    return false;
  if(theTime <= date.getTime())
    return true;
  else 
    return false;
}
bool myDate::operator>=(const myDate &date) const
{
  if (year >= date.getYear())
    return true;
  else
    return false;
  if (month >= date.getMonth())
    return true;
  else
    return false;
  if (day >= date.getDay())
    return true;
  else
    return false;
  if(theTime >= date.getTime())
    return true;
  else
    return false;

}
bool myDate::operator!=(const myDate &date) const
{
  if (year != date.getYear())
    return true;
  else
    return false;
  if (month != date.getMonth())
    return true;
  else
    return false;
  if (day != date.getDay())
    return true;
  else
    return false;
  if(theTime != date.getTime())
    return true;
  else
    return false;

}

//Name: compareDates
//Description: It will compare two dates, not including the times
//Parameters:  myDate secondDate - IN - the date to compare
//Return: -1 if the instance is ealier than secondDate
//         0 if the instance is the same date as secondDate
//         1 if the instance is later than the secondDate
int myDate:: compareDates(const myDate &secondDate) const
{
  if(year < secondDate.getYear())
    return -1;
  else if (year > secondDate.getYear())
    return 1;

  if (month < secondDate.getMonth())
    return -1;
  else if(month > secondDate.getMonth())
    return 1;

  if (day < secondDate.getDay())
    return -1;
  else if (day > secondDate.getDay())
    return 1;

  return 0;
}

//Name: operator+=
//Description: Moves the date a head days days
//Parameters:  days, the number of days to advance the date
//Return: the instance of the object
myDate &myDate::operator+=(int days)
{
  day += days;
  if (days > daysInMonth())
    {
      day -= daysInMonth();
      if (month > 12)
	{
	  month =1;
	  year++;
	}
      else
	month++;
    }
  return *this;
}

//Name: toLongDate
//Description: creates a string for the date using the actual month name
//             for example 1/2/2012 would return January 2, 2012
//Return: the long version of the date
string myDate::toLongDate()
{
  string longDate, currentMonth, intConverted;
  if (month == 1)
    currentMonth = "January";
  else if(month == 2)
    currentMonth = "February";
  else if(month == 3)
    currentMonth = "March";
  else if (month == 4)
    currentMonth = "April";
  else if(month == 5)
    currentMonth = "May";
  else if (month == 6)
    currentMonth = "June";
  else if (month == 7)
    currentMonth = "July";
  else if(month == 8)
   currentMonth = "August";
  else if(month == 9)
    currentMonth = "September";
  else if(month == 10)
    currentMonth = "October";
  else if(month == 11)
    currentMonth = "November";
  else if (month == 12)
    currentMonth = "December";
  
  longDate += currentMonth;
  longDate += " ";
  intConverted = convertIntToString(day);
  longDate += intConverted;
  longDate += ", ";
  intConverted = convertIntToString(year);
  longDate += intConverted;
  
  return longDate;
}

//Name: isLeapYear
//Description: Determines if the year is a leap year
//A year is a leap year under the following rules:
//if not divisible by 4, it is not a leap year
//if divisible by 4 and not 100, it is a leap year
//if divisible by 4 and 100, it must be be divisible by
//400 to be a leap year
//Parameters: none
//Return: true if leap year, false otherwise
bool myDate:: isLeapYear() const
{
  if (year % 4 == 0)
    {
      if (year % 100 == 0)
	{
	  if (year % 400 == 0)
	    return true;
	  else
	    return false;
	}
      
      else 
	return true;
    }
  else 
    return false;
}

//Name: daysInMonth
//Description: uses the month and year to determine the total days
//Paraemters: none
//Return: the number of days in the month of the instance
//remember that February depends on if it is a leap year
int myDate:: daysInMonth() const
{
  switch(month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return 31;
      break;
    case 2:
      if (isLeapYear())
	return 29;
      else return 28;
      break;
    default:
      return 30;
      break;
    }
}

//Name: operator<<
//Description: writes out the date in the form month/day/year hours:minutes
//Parameters:  ostream output - IN/OUT the stream written to
//             myDate date - IN - the date to write
//Return:     ostream - the stream written to
ostream &operator<<(ostream &output, const myDate &date)
{
  output << date.getMonth() << "/" << date.getDay() << "/" << date.getYear() << " " << date.getTime();
  return output;
}

//Name: operator>>
//Description: Expects the user to enter a date in the form month/day/year
//             reads ONLY the date part not the time
//Parameters:  istream input - IN/OUT the stream read from
//             myDate date - OUT the date to fill
//Return:     istream - the stream read from
istream &operator>>(istream &input, myDate &date)
{
  int mnth, dy, yr;
  char slash;
  input >> mnth >> slash >> dy >> slash >> yr;
  date.setMonth(mnth);
  date.setDay(dy);
  date.setYear(yr);
  return input;
}

