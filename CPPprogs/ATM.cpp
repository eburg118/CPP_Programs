#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void readFile(string &name, double &balance);
int menu();
void depositMoney(double &balance);
void withdrawMoney(double &balance);

void outputBalance(double balance);
void readIntoFile(string name, double balance);


int main()
{

  int choice;
  string name;
  double balance;

  readFile(name, balance);
  while ((choice = menu()) != 4)
    {
      switch(choice)
	{
	case 1: depositMoney(balance);
	  break;
	case 2: withdrawMoney(balance);
	  break;
	case 3: outputBalance(balance);
	  break;
	
	}
     
    } 
  readIntoFile(name, balance);

    return 0;
}
void readFile(string &name, double &balance)
{
  ifstream fp;


  fp.open("atm.dat");
  if(!fp)
    {
      cout << "Error opening file";
     
    }
  else 
    {
      while (fp.eof() == false)
	{
	  fp >> name;
	  fp >> balance;
	}
    }
  fp.close();
}

int menu()
{
  int choice;
  cout << endl;
  cout << "1. Deposit" << endl;
  cout << "2. Withdrawal" << endl;
  cout << "3. Check Balance" << endl;
  cout << "4. Exit" << endl;
  cout << "Choice: ";
  cin >> choice;
  cout << endl;
  return choice;
}
 
void depositMoney(double &balance)
{
  double amountDpst;
  cout << "How much would you like to deposit?: ";
  cin >> amountDpst;
  
  balance = amountDpst + balance;
}

void withdrawMoney(double &balance)
{
  double amountWith;
  cout << "How much would you like to withdraw?: ";
  cin >> amountWith;
  if (amountWith > balance)
    {
      cout << "Cannot withdraw more than whats on your account!" << endl;
     
    }
  else 
    balance = balance - amountWith;
}
void outputBalance(double balance)
{
  cout << "Your balance is: " << balance;
}
void readIntoFile(string name, double balance)
{
  ofstream fp ("atm.dat");
  if (fp.is_open())
    {
      fp << name << endl;
      fp << balance << endl;
      fp.close();
    }
  else
    cout << "Unable to open file";
}
