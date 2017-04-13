//File:  indexList.cpp
//Author: Eric Burgos
//Updated:
//Course:  CSC 136
//Date:    Spring 2015
//Purpose: contains a list of elements accessible by index
#include "indexList.h"
#include <iostream>
using namespace std;

#ifndef INDEXLIST_CPP
#define INDEXLIST_CPP

  //constuctor: takes size of array
template <class T>
indexList<T>::indexList(int size)
{
  numberOfElements = 0;
  maxSize = size;
  list = new T [maxSize];
}

// Copy Constructor
template<class T>
indexList<T>::indexList(const indexList &rhs)
{
 
  numberOfElements = rhs.numberOfElements;
  maxSize = rhs.maxSize;
  list = new T[maxSize];
  *this = rhs;
}



// Assignment Operator

template <class T>
indexList<T> &indexList<T>::operator=(const indexList &rhs)
{
  if (this != &rhs)
    {
      delete [] list;
      numberOfElements = rhs.numberOfElements;
      maxSize = rhs.maxSize;
      list = new T[maxSize];
      for (int i = 0; i < numberOfElements; i++)
      list[i] = rhs.list[i]; 
    }
  return *this;
}

// Destructor
// Deletes list
template<class T>
indexList<T>::~indexList()
{
  delete [] list;
}


  //Adds element to the end of the list
  //If array is full, returns false
template <class T>
bool indexList<T>::append(const T &value)
{
  if (maxSize > numberOfElements)
    {
      list[numberOfElements] = value;
      numberOfElements ++;
      return true;
    }
  else
    return false;
}


  //insert
  //Inserts an element at index indx, if indx valid
  //moves values up before inserting
  //If indx is invalid, returns false
template <class T>
bool indexList<T>::insert(int indx,const  T &value)
{
  if (indx >= 0 && indx < numberOfElements && numberOfElements < maxSize)
    {
      for (int i=numberOfElements; i>indx; i--)
	list[i] = list[i-1];
      list[indx] = value;

      numberOfElements ++;
      return true;
    }
  else
    return false;
}

//OrderedInsert
//Insert user value into correct spot in list

template <class T>
bool indexList<T>::orderedInsert(const T &value)
{
  int indx = 0;
  bool found = false;

  if (numberOfElements == maxSize) return false;
  while (indx < numberOfElements && !found)
    {
      if (list[indx] < value)
	indx ++;
      else
	found = true;
    }
  if (found )
    insert(indx, value);
  else
    append(value);
  return true;
}

  //replace
  //Replaces the value at indx if indx is valid
  //IF indx is not value, returns false
template <class T>
bool indexList<T>::replace(int indx, const T& newValue)
{
  if (indx >= 0 && indx <numberOfElements)
    {
      list[indx] = newValue;
      return true;
    }
  else
    return false;
}


  //retrieve
  //Retrieves the value at index indx, if indx valid
  //If indx is not valid, returns false
template <class T>
bool indexList<T>::retrieve(int indx, T &value) const
{
  if (indx >= 0 && indx < numberOfElements)
    {
      value = list[indx];
      return true;
    } 
  else
    return false;
}


  //remove
  //Removes a value from a specific indx, if indx valid
  //remaining values are moved down
  //IF indx not valid, return false
template <class T>
bool indexList<T>::remove(int indx)
{
  if (indx >= 0 && indx < numberOfElements)
    {
      for (int i= indx; i < numberOfElements-1; i++)
	  list[i] = list[i+1];

      numberOfElements --;
      return true;
    }
  else
    return false;
}

  //search
  //Searchs for the value in the array
  //Returns indx if found, -1 if not found
template <class T>
int indexList<T>::search(const T &value) const
{
  for (int i=0; i<numberOfElements; i++)
    {
      if (list[i] == value)
	return i;
    }
  return -1;
}


  //getSize
  //Returns the number of elements currently in
  //the array
template <class T>
int indexList<T>::getSize() const
{
  return numberOfElements;
}


//<< stream operator writes out entire list
template <class T>
ostream &operator<<(ostream &out, const indexList<T> &lst)
{
  T element;
  int count = lst.getSize();

  for (int j=0; j<count; j++)
    {
      lst.retrieve(j, element);
      out << "[" << j << "] " << element << endl;
    }
  return out;
}

#endif

