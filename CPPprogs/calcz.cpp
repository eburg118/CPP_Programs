#include <iostream>
using namespace std;
void numone(int x);
void numtwo(int y);
void getNums(int numone, int numtwo);
float calcsum(int numonw, int numtwo);
float calcsub();
float calcmult();
float calcdiv();
void displayinfo(int numone, int numtwo, float calcsum);

int main()
{
  float x, y;
  float sum;
  float sub;
  float mult;
  float div;
  numone(x);
  numtwo(y);
  sum = calcsum(x,y);
  //sub = calcsub(numone, numtwo);
  //mult = calcmult(numone, numtwo);
  //div = calcdiv(numone, numtwo);
  displayinfo(x, y, calcsum);
  return 0;
}

 numone(int x)
{
  cout << "Enter one number " ;
  cin >> x;
  return x;
}
void numtwo(int y)
{
  cout << "Enter a second number ";
  cin >> y;
  return y;
}
float calcsum(int numone, int numtwo)
{
  float sum;
  sum = numone+numtwo;
  return sum;
}
void displayinfo(int numone, int numtwo, float calcsum)
{
  cout << "The sum of" << numone << " and " << numtwo << " is " << calcsum << endl;
}
