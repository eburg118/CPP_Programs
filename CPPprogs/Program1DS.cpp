#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

bool isVowel(string input);
void changeToPig(string input);


bool isVowel(char aChar)
{
  
  if (aChar == 'a' ||
      aChar == 'e' ||
      aChar == 'i' ||
      aChar == 'o' ||
      aChar == 'u' ||
      aChar == 'A' ||
      aChar == 'E' ||
      aChar == 'I' ||
      aChar == 'O' ||
      aChar == 'U'||

      aChar == 'y')
    return true; 
}

string changeToPig(string stringA)
{

  string stringP;
  if (isVowel(stringA.at(0)))
    {
      cout <<< stringA.at(0) << endl;
      stringP = stringA + "-way";
    }
  else
    {
      string nonVowelHead = "";
      int position = -1;
      for(int i=0; i < stringA.length();i++)
	{
	  if(isVowel(stringA.at(i)))
	    position = i;
	  break;
	}
      
    }
  if(position == -1)
    {
      stringP += stringA + "-way";
    }
else
  {
    stringP = stringA.substr(position)
  }
   

}


int main()
{


  string input;
  string outputPig;
  cout << "Please enter any word: " << endl;
  cin >> input;

  cout << "Text in pig Latin: " << outputPig << endl;



  isVowel(input);
  changeToPig(input);
  return 0;

}
