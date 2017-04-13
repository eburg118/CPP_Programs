#include<iostream>
using namespace std;
void menu();
void menuTwo();
int getChoice();

int main()
{
  
  menu();
  
  menuTwo();
  
}
void menu()
{
  
  cout << endl;
  cout << "1. Distance" << endl;
  cout << "2. Area" << endl;
  cout << "3. Volume" << endl;
  cout << "4. Weight" << endl;
  cout << "5. Temperature" << endl;
  getChoice();
}

void menuTwo()
{
  cout << endl;
  cout << "1. Standard" << endl;
  cout << "2. Metric" << endl;
  getChoice();
}
void menuForDistanceStandard()
{
  cout << endl;
  cout << "1. Inches" << endl;
  cout << "2. Miles" << endl;
  cout << "3. Yards" << endl;
  cout << "4. Feet" << endl;
  
}
void menuForDistanceMetric()
{
  cout << endl;
  cout << "1. Centimeters" << endl;
  cout << "2. Meters" << endl;
  cout << "3. kilometers" << endl;
  
}


int getChoice(int &choice)
{

  cout << "Please enter choice: ";
  cin >> choice;

}

