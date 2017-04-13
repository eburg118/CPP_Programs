#include <iostream>
using namespace std;
void getNumbers(float &x, float &y);
float calcSum(float x, float y);
float calcDifference(float x, float y);
float calcMult(float x, float y);
float calcDiv(float x, float y);
void displayAnswers(float x, float y, float sum, float diff, float multi, float divv);

void getNumbers(float &x, float &y)
{
  cout << "Please enter two numbers: ";
  cin >> x;
  cin >> y;
  cout << endl;
}

float calcSum(float x, float y)
{
  float sum;
  sum=x+y;
  return sum;
}
float calcDifference(float x, float y)
{
  float diff;
  diff = x-y;
  return diff;
}
float calcMult(float x, float y)
{
  float multi;
  multi = x*y;
  return multi;
}
float calcDiv(float x, float y)
{
  float divv;
  divv = x/y;
  return divv;
}

void displayAnswers(float x, float y, float sum, float diff, float multi, float divv)
{
  cout << "The sum of these two numbers is: "<< x << "+" << y << "= " << sum; 
  cout << endl;
  cout << "The difference of these numbers is: " << x << "-" << y << "= " << diff;
  cout << endl;
  cout << "These numbers mulitplied equals: " << x << "*" << y << "= " << multi;
  cout << endl;
  cout << "These numbers divided equals:  " << x << "/" << y << "= " << divv;
  cout << endl;
}
int main()
{
  float diff;
  float sum;
  float multi;
  float divv;
  float x, y;
  
  getNumbers(x, y);
  sum = calcSum(x, y);
  diff = calcDifference(x, y);
  multi = calcMult(x, y);
  divv = calcDiv(x, y);
  displayAnswers(x, y, sum, diff, multi, divv);
  
  return 0;
}
