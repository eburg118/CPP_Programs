#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int counter;
  float numItems, price, subtotal = 0, salesTax, total ;
  cout << "How many items are in the order: ";
  cin >> numItems;
  cout << endl;

  for(counter = 1; counter <= numItems; counter++)
    {
      cout << "Enter the price of an item: ";
      cin >> price;
      subtotal+=price;
    }

  salesTax = subtotal * .08;
  total = salesTax + subtotal;

  cout << setprecision(2) << fixed;
  cout << left;
  cout << setw(20) << "Subtotal: " << "$" << subtotal << endl;
  cout << setw(20) <<  "Sales Tax: " << "$" << salesTax << endl;
  cout << setw(20) << "Total: " << "$" << total << endl;
}
