//File:     linkedList.h
//Author:   Prof. Day
//Course:   CSC 136
//Date:     Spring 2015
//Purpose:  Declaration of linked list class
#include <iostream>
#include "linkedList.h"
using namespace std;

#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP




  //The Big 3
  //copy constructor
  //Description: Copy constructor does a deep copy
  //Parameters: list to copy from
  //Return: none

template<class T>
linkedList<T>::linkedList(const linkedList &list)
{
  head = NULL; current = NULL; trailCurrent = NULL;
    *this = list;
}
  


//operator=
//Description: Assignment operator does a deep copy
//Parameter: list to copy form
//Return:    the instance of the lit
template<class T>
linkedList<T> &linkedList<T>::operator=(const linkedList &list)
{
  node *ok;
  if(this != &list)
    {
      clear();
      if(!list.empty())
	{
	  
	  head = new node(list.head -> data, NULL);
	  ok = list.head -> next;
	  current = head;
	}
      while(ok != NULL)
	{
	  current -> next = new node(ok -> data);
	  ok = ok -> next;
	  current = current -> next;
	}
      
      
    }
  return *this;
}

  //destructor
  //Description: Destructor deletes all the nodes in the list
  //Paramters:  none
  //Return :    none
template<class T>
linkedList<T>::~linkedList()   
{
  clear();
}
  //empty
  //Description: returns true if the list is empty, false otherwise
  //Paramters:  none
  //Return:     true if empty, false otherwise
template<class T>  
bool linkedList<T>::empty() const
{
  if (this -> head == NULL)
    return true;
  else
    return false;

}

  //clear
  //Description: clears out all the nodes in the list and sets head to NULL
  //Paramters:  none
  //Return:     none
template<class T>
void linkedList<T>::clear()
{
  current = head;
  while(current != NULL)
    {
      trailCurrent = current;
      current = current -> next;
      delete trailCurrent;

    }
  head = NULL;
  current = NULL;

}

  //search
  //Description: tries to locate value
  //    If found, returns true and current points to the value
  //    If not found, returns false and current cannot be trusted
  //Parameters: value to seach for
  //Return:  true if found, false othewise
template<class T>
bool linkedList<T>::search(const T &value)
{
  current = head;
  while(current != NULL && current -> data != value)
    {
      current = current -> next;
    }
  if (current == NULL)
    return false;
  else
    return true;

}


  //orderedInsert
  //Description: takes the value an inserts it in the linked list so that
  //             the values in the list are in ascending order
  //Parameters: value to insert
  //Return:   none
template<class T>
void linkedList<T>::orderedInsert(const T&value)
{
  current = head;
  trailCurrent = NULL;

  while(current != NULL && current -> data < value)
    {
      trailCurrent = current;
      current = current -> next;
    }
  if (trailCurrent != NULL)
    trailCurrent -> next = new node(value, current);
  else
    head = new node (value, current);

}

  //remove
  //Description:  removes the value from the list
  //              remove fails if there value is not found in the list
  //Paramter:   value to remove
  //Return:     true if removed, false otherwise
template<class T>
bool linkedList<T>::remove(const T &value)
{
  current = head;
  trailCurrent = NULL;
  while(current != NULL && current -> data != value)
    {
      trailCurrent = current;
      current = current -> next;
    }
  if(current == NULL)
    return false;
  if (trailCurrent != NULL)
    {
      trailCurrent -> next = current -> next;
      delete current;
      current = NULL;
    }
  else
    {
      head = current -> next;
      delete current;
      current = NULL;
    }
  return true;
}


  //replace
  //Description:  replaces the oldData with the newData
  //Parameters:   T oldData - IN data to find
  //              T newData - IN data to put
  //Return:      True if the oldData is found and false otherwise
template<class T>
bool linkedList<T>::replace(const T &oldData, const T &newData)
{
  if (current == NULL)
    return false;
  else
    {
      current ->oldData = newData;
      return true;
    }
}


  //insert 
  //Description: inserts value before the before current and after trailCurrent
  //  If trailCurrent is NULL, it inserts at the head of the list
  //  trailCurrent is set to point to the new node
  //Paramters: value to insert
  //Return:   none
template<class T>
void linkedList<T>::insert(const T &value)
{
  if (trailCurrent != NULL)
    trailCurrent -> next = new node(value, current);
  else
    head = new node(value, current);
}

  //retrieve
  //Description: retrieves the value at the current position
  //    value is returned through the parameter
  //Paramterss:  variable for value to retrieve
  //Return:    True if the position is valid and false otherwise
template<class T>
bool linkedList<T>::retrieve(T &value) const
{
  if (current != NULL)
    {
      value = current -> data;
      return true;
    }
  else
 return false;
}

  //The following routines are for traversing the list in an application

  //begin
  //Description: sets the current position to the beginning of the list
  //              It also sets the trailCurrent to NULL
  //Paramters:   none
  //Return:      none
template<class T>
void linkedList<T>::begin()
{
  current = head;
  trailCurrent = NULL;
}

  //operator ++
  // Description: as long as the current position is not NULL, it
  //              moves the current position (and trailCurrent) to next item
  //              Two prototypes are given so the operator can be used both prefix and postfix.
  //Parameters:   none (int i as a dummy)
  //Return:       the list
template<class T>
linkedList<T> linkedList<T>:: operator++()
{
  if (current != NULL)
    {
      trailCurrent = current;
      current = current -> next;
    }
  return *this;
}

template<class T>
linkedList<T> linkedList<T>::operator++(int i) // Dummy param
{
  linkedList<T> dummy (*this);
  if (current != NULL)
    {
      trailCurrent = current;
      current = current -> next;
    }
  return dummy;

} 



//ostream operator for printing the list
template <class T>
ostream &operator<<(ostream &output,   linkedList<T> list)
{
  T element;
 list.begin();
 if (!list.empty())
   {
 while (list.retrieve(element) != false)
   {
     output << "[" << element << "] " << endl;
     list++;
     
   }
   }
 else
   {
     output << "nothing here";
   }
 return output;
}



#endif
