#include<iostream>
#include<math.h>
using namespace std;

const double gallonPrice = 25.83;
const double quartPrice = 6.79;

void getArea(int &sqrFeet);
void calculateQrts(int sqrFeet, int &numOfQrts);
void calculateGallons(int numOfQrts, int &numOfGallons);
void calculateQrtsDisplayed(int numOfQrts, int numOfGallons, int &numberOfQrts);
void displayGallonsandQrts(int numOfGallons, int numOfQrts, int numberOfQrts);
void calculatePrice(int numOfGallons, int numberOfQrts, double &price);
void displayPrice(double price);
void getAmountTendered(double &amtTend);
void getChange(double price, double amtTend, double &change);
void displayChange(double change);
void calculateDenominations(double change);

int main()
{
  int sqrFeet ;
  int numOfGallons;
  int numOfQrts;
  int numberOfQrts;
  double price;
  double amtTend;
  double change;

  getArea(sqrFeet);
  calculateQrts(sqrFeet, numOfQrts);
  calculateGallons(numOfQrts, numOfGallons);
  calculateQrtsDisplayed(numOfQrts, numOfGallons, numberOfQrts);
  displayGallonsandQrts(numOfGallons, numOfQrts, numberOfQrts);
  calculatePrice(numOfGallons, numberOfQrts, price);
  displayPrice(price);
  getAmountTendered(amtTend);
  getChange(price, amtTend, change);
  displayChange(change);
  calculateDenominations(change);
}

void getArea(int &sqrFeet)
{
 cout << "Enter the area in square feet: ";
 cin >> sqrFeet;
 cout << endl;

}
void calculateQrts(int sqrFeet, int &numOfQrts)
{
  sqrFeet -= 1;
  numOfQrts = sqrFeet / 50;
  numOfQrts += 1;
}

void calculateGallons(int numOfQrts, int &numOfGallons)
{

  numOfGallons = numOfQrts / 4;

}

void calculateQrtsDisplayed(int numOfQrts, int numOfGallons, int &numberOfQrts)
{
  numberOfQrts = numOfQrts % 4;
}
void displayGallonsandQrts(int numOfGallons, int numOfQrts, int numberOfQrts)
{

  cout << "Customer needs: " << numOfGallons << " gallons and "<<numberOfQrts  <<  " quarts" << endl << endl;
 
}
void calculatePrice(int numOfGallons, int numberOfQrts, double &price)
{
  price = (numOfGallons * gallonPrice) + (numberOfQrts * quartPrice); 
}
void displayPrice(double price)
{
  cout << "Total Price is: " << "$" << price << endl << endl << endl;
}

void getAmountTendered(double &amtTend)
{
  cout << "Amount Tendered: " << "$";
  cin >> amtTend;
  cout << endl;
}
void getChange(double price, double amtTend, double &change)
{
  change = amtTend - price;
}
void displayChange(double change)
{
  cout << "Change: " << "$" << change << " in the following denominations: " << endl << endl;
}
void calculateDenominations(double change)
{
  int twenties, tens, fives, ones, quarters, dimes, nickels, pennies;
  change = change * 100;
  twenties = change/2000;
  change = fmod(change, 2000);
  tens = change/1000;
  change = fmod(change, 1000);
  fives = change/500;
  change = fmod(change, 500);
  ones = change/100;
  change = fmod(change, 100);
  quarters = change/25;
  change = fmod(change, 25);
  dimes = change/10;
  change = fmod(change, 10);
  nickels = change/5;
  change = fmod(change, 5);
  pennies = change/1;

  cout << "Twenties: " << twenties << endl;
  cout << "Tens: " << tens << endl;
  cout << "Fives: " << fives << endl;
  cout << "Ones: " << ones << endl;
  cout << "Quarters: " << quarters << endl;
  cout << "Dimes: " << dimes << endl;
  cout << "Nickels: " << nickels << endl;
  cout << "Pennies: " << pennies << endl;
}





