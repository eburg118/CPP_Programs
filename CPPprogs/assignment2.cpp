//CSC555 Assignment 2
//Major: Information Technology
//Author: Eric Burgos
//Course: CSC555
//Date: February 21, 2019
//Professor Name: Dr.Zhang
//Filename: Assignment2.cpp
//Purpose: This program simulates the encryption/decryption process
//of simplified DES.

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//functions used in key schedule
void p10(short a[]); //p10 permutation
void ls1(short a[]); //left shift 1
void ls2(short a[]); //left shift 2
void generate_roundKey(short a[], short k[]); //generate the round key
void permute(short a[], short p[], int size); //performs a given permutation  
void swap(short a[]);
void f_k(short data[], short round_key[]); //the f_k function

//helper functions
void printArray(short a[], int size); //print the given array a

//permutations and s-boxes used in the simplified DES
short IP[8]={2,6,3,1,4,8,5,7}; 
short IP_Inv[8]={4,1,3,5,7,2,8,6};  
short EP[8]={4,1,2,3,2,3,4,1}; 
short Sbox1[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
short Sbox2[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
short SW[8]={5,6,7,8,1,2,3,4};
short P4[4]={2,4,3,1};

int main()
{
  
  short key[10]; //10-bit master key
  short subkey1[8], subkey2[8]; //two 8-bit round keys
  void printArrayKey(short k[], int size);
  char a[10], b[10]; //for temperary use
  short data[8]; //8-bit data

  int choice; //user choice
  cout<< "1. Encryption 2. Decryption [1/2]: ";
  cin >> choice;

  switch(choice)
    {
    case 1:
      //read in the 10-bit master key
      cout<<"Enter 10-bit key:";
      for (int i=0; i<10;i++)
	{
	  cin>>a[i];
	  key[i]=(short)a[i]-48;
	}

      //read in 8-bit data
      cout<<"Enter 8-bit data:";
      for (int i=0; i<8; i++)
	{
	  cin>>b[i];
	  data[i]=(short)b[i]-48;
	}

      cout<<left;

      //key schedule
      p10(key);
      ls1(key);
      generate_roundKey(key, subkey1);
      ls2(key);
      generate_roundKey(key, subkey2);

  
      cout<<"\n\n";
      cout<<"Encryption:\n\n";
      //encrypt
      cout<<setw(25)<<"Round key 1: ";
      printArray(subkey1,8);
      cout<<setw(25)<<"Round key 2: ";
      printArray(subkey2,8);

      permute(data, IP, 8);
      cout<<setw(25)<<"After IP: ";
      printArray(data, 8);

      f_k(data, subkey1);
      cout<<setw(25)<<"After f_k: ";
      printArray(data, 8);

      swap(data);
      cout<<setw(25)<<"After SW: ";
      printArray(data, 8);
      
      f_k(data, subkey2);
      cout<<setw(25)<<"After f_k: ";
      printArray(data, 8);

      permute(data, IP_Inv, 8);
      cout<<setw(25)<<"Cipher text: ";
      printArray(data, 8);
      break;
    case 2:
      //TODO
      cout<<"Enter 10-bit key:";
      for (int i=0; i<10;i++)
        {
          cin>>a[i];
          key[i]=(short)a[i]-48;
        }

      //read in 8-bit data
      cout<<"Enter 8-bit data:";
      for (int i=0; i<8; i++)
        {
          cin>>b[i];
          data[i]=(short)b[i]-48;
        }

      cout<<left;
      p10(key);
      ls1(key);
      generate_roundKey(key, subkey1);
      ls2(key);
      generate_roundKey(key, subkey2);


      cout<<"\n\n";
      cout<<"Decryption:\n\n";
      //encrypt
      cout<<setw(25)<<"Round key 1: ";
      printArray(subkey1,8);
      cout<<setw(25)<<"Round key 2: ";
      printArray(subkey2,8);

      permute(data, IP, 8);
      cout<<setw(25)<<"After IP: ";
      printArray(data, 8);

      f_k(data, subkey2);
      cout<<setw(25)<<"After f_k: ";
      printArray(data, 8);

      swap(data);
      cout<<setw(25)<<"After SW: ";
      printArray(data, 8);

      f_k(data, subkey1);
      cout<<setw(25)<<"After f_k: ";
      printArray(data, 8);

      permute(data, IP_Inv, 8);
      cout<<setw(25)<<"Plain text: ";
      printArray(data, 8);



      break;
    }
}

//Function name: f_k
//Parameters: short data- data being passed, short round_key- key being user
//performs the f_k function on data with the given roundkey
void f_k(short data[], short round_key[])
{
  // Declare and initialize some variables for later user
  short leftBits[4]; 
  short rightBits[4];
  short rightBitsLater[4];
  char leftBitsAfterXor[4];
  char rightBitsAfterXor[4];
  short xOr[8];
  const char *bits[]={"00","01","10","11"};
  char lrow[3],lcol[3];
  char *SO;
  int i,lr,lc,b;
  SO = new char[3];  

  //Split the 8-bit array
    
  for(int i = 0; i < 4; i++)
    leftBits[i] = data[i];
  
  for(int j = 4; j < 8; j++)
    rightBits[j] = data[j];
    

  // EP operation for right side of 8-bit
  data[0] = rightBits[7];
  data[1] = rightBits[4];
  data[2] = rightBits[5];
  data[3] = rightBits[6];
  data[4] = rightBits[5];
  data[5] = rightBits[6];
  data[6] = rightBits[7];
  data[7] = rightBits[4];
  
  //XOr
  for(int x = 0; x < 8; x++)
    data[x] = data[x] ^ round_key[x];
    
  //Split bit array agin
  for(int a = 0; a < 4; a++)
    leftBitsAfterXor[a] = data[a] + '0';
  
  for(int b = 4; b < 8; b++)
    rightBitsAfterXor[b] = data[b] + '0';

  // Store left bits in columns and rows index
  lrow[0]= leftBitsAfterXor[0];
  lrow[1]=leftBitsAfterXor[3];
  lcol[0]=leftBitsAfterXor[1];
  lcol[1]=leftBitsAfterXor[2];
   
  lrow[2]='\0';
  lcol[2]='\0';

  // Mapping of Sbox 1 rows and columns based on bits
  for(i=0;i<4;i++)
    {
      if(strcmp(lrow,bits[i])==0)
	lr=i;
      if(strcmp(lcol,bits[i])==0)
	lc=i;
    }
  b=Sbox1[lr][lc];
  for(i=0;i<3;i++)
    {
    SO[i]=bits[b][i];
    }
  SO[3]='\0';
  
  // Variables for other Sbox mapping 
  const char *bitS[]={"00","01","10","11"};
  char lrowR[3],lcolR[3];
  char *SO1;
  int lR,lC,c;
  SO1 = new char[3];

  // Store right bits in columns and rows index
  lrowR[0]= rightBitsAfterXor[4];
  lrowR[1]=rightBitsAfterXor[7];
  lcolR[0]=rightBitsAfterXor[5];
  lcolR[1]=rightBitsAfterXor[6];

  lrowR[2]='\0';
  lcolR[2]='\0';

  // Mapping of Sbox 1 rows and columns based on bits
  for(i=0;i<4;i++)
    {
      if(strcmp(lrowR,bitS[i])==0)
        lR=i;
      if(strcmp(lcolR,bitS[i])==0)
        lC=i;
    }
  c=Sbox2[lR][lC];
  for(i=0;i<3;i++)
    {
      SO1[i]=bits[c][i];
    }
  SO1[3]='\0';

  // Combining the two sbox outputs
  short afterSbox[4];
  short p4Perm[4];
  short beforeSwap[8];
  for (int w = 0; w < 2; w++)
    {
      afterSbox[w] = SO[w] - '0';
      afterSbox[w+2] = SO1[w] - '0';
    }

  // P4 permutation
  p4Perm[0] = afterSbox[1];
  p4Perm[1] = afterSbox[3];
  p4Perm[2] = afterSbox[2];
  p4Perm[3] = afterSbox[0];

  // Xor after permutation with left bits
  for(int z = 0; z < 4; z++)
   p4Perm[z] = p4Perm[z] ^ leftBits[z];


  // Join two bit arrays
  for (int t = 0; t < 4; t++)
    {
      beforeSwap[t] = p4Perm[t];
      beforeSwap[t+4] = rightBits[t+4];
    }

  // Assign output to data variable
  for(int o = 0; o < 8; o++)
    data[o] = beforeSwap[o];
  
}


//Function name: permute
//Parameters: short a- bit data, short p- permutation table, int size- size of data
//permutate the given string a[] based on the permutation p[]
void permute(short a[], short p[], int size)
{
  // Pemutation algorithm that only works/is used for initial permutation
  int temp;
  short outputTemp[size];
  for(int i = 0; i < size; i++)
    {  
      temp = p[i];
      outputTemp[i] = a[temp-1];
    }
  for(int j = 0; j < 8; j++)
    a[j] = outputTemp[j];

}

//Function name: swap
//Parameters: short a- data being passed to swap
//Added function for swapping 8-bit int arrays
void swap(short a[])
{
  int x = a[0], i;
  int y = a[1];
  int b = a[2];
  int c = a[3];

  for (i = 0; i < 8; i++)
    a[i] = a[i + 4];

  a[4] = x;
  a[5] = y;
  a[6] = b;
  a[7] = c;

}

//Function name: printArray
//Parameters: short data- array to be printer, int size- size of data
//print the given array
void printArray(short a[], int size)
{
  for (int i=0; i<size; i++)
    cout<<a[i];
  cout <<endl;
}

//Function name: p10
//Parameters: short a- array that will be permutated
// P10 function
void p10(short a[])
{
  
  int perm10[10] = {3,5,2,7,4,10,1,9,8,6};
  int temp[10];

  // Manual permutation mapping
  temp[0] = a[2];
  temp[1] = a[4];
  temp[2] = a[1];
  temp[3] = a[6];
  temp[4] = a[3];
  temp[5] = a[9];
  temp[6] = a[0];
  temp[7] = a[8];
  temp[8] = a[7];
  temp[9] = a[5];
  // Assigning and storing permutated array in a variable
  for(int i = 0; i < 10; i++)
    a[i] = temp [i];
}

//Function name: ls1
//Parameters: short a- array to be swapped around
//ls1 function that clock-wise shift first element into end of array.
void ls1(short a[])
{
  int x = a[0], i;
  for (i = 0; i < 5; i++)
    a[i] = a[i + 1];
  
  a[4] = x;
  
  int temp = a[5], j;
  for (j = 5; j < 10; j++)
    a[j] = a[j + 1];

  a[9] = temp;

}

//Function name: ls2
//Parameters: short a- array to be swapped around
//function that will clock-wise shift first 2 elements of array to the end of array.
void ls2(short a[])
{
  int x = a[0], i;
  int y = a[1];
  for (i = 0; i < 5; i++)
    a[i] = a[i + 2];

  a[3] = x;
  a[4] = y;

  int temp = a[5], j;
  int temp1 = a[6];
  for (j = 5; j < 10; j++)
    a[j] = a[j + 2];

  a[8] = temp;
  a[9] = temp1;

}

//Function name: generate_roundKey
//Parameters: short a- data to be processed, short k- key to be processed
void generate_roundKey(short a[], short k[])
{
  //Run a manual permutation to create subkey
  k[0] = a[5];
  k[1] = a[2];
  k[2] = a[6];
  k[3] = a[3];
  k[4] = a[7];
  k[5] = a[4];
  k[6] = a[9];
  k[7] = a[8];

}

