#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void readFile(string winningteam, string LosingTeam, int score)
{
  ifstream infile;
  infile.open("superbowl.dat");
}
string readWinningTeams(ifstream& infile, string winningTeams[47])
{
  infile >> winningTeams[47];
  return winningTeams;
}

string readLosingTeams(ifstream& infile, string losingTeams[47])
{
  infile >> losingTeams[47];
  return losingTeams;
}

int readScore(ifstream& infile, int score[47])
{
  infile >> score[47];
  return score;  
}
int calcAveragePoints(int score[47])
{
  int averagePoints;

  for(int i=0;i<47;i++)
    {
    averagePoints = score[i++]/i;
    }
  return 0;
}

int outputMoreThan40Points(int score[47])
{
  int MoreThan40Points;

  for( int i=0;i<47;i=i+1)
{
  if(score[47] > 40)
    {  MoreThan40Points = MoreThan40Points + 1;

	}
  }
  return 0;
}

 int findMostPoints( int score[47])
 {
   int mostPoints;
   for(int i=0;i<47;i++)
     {
       if(score[47]>MostPoints)
	 {
	   MostPoints = score[47];
	 }
     }
 }       
 int findLeastPoints(int score[47])
 {
  
   int leastPoints;
   for(int i=0;i<47;i++)
     {
       if(score[47]<leastPoints)
	 {
	   leastPoints = score[47];
	 }
     }
 }

 void displayValues()
 {
   cout << "Average points scored by winning team:" << averagePoints << endl;
   cout << "Number of wninning teams that scored more than 40 points:" << moreThan40Points << endl;
   cout << "Most Points scored:" << mostPoints << endl;
   cout << "Least Points score:" << leastPoints << endl;
 }
int main () 
{
  ifstream infile;
  string winningTeams[47];
  string losingTeams[47];
  int score[47];
  int averageScore;
  int MoreThan40Points;
  int mostPoints;
  int leastPoints;

  readFile(infile, winningTeams, losingTeams, score)
    while (!infile.eof())
      {
	winningTeams = readWinningTeams(infile, winningTeams)
	  losingTeams = readLosingTeams(infile, losingTeams)
	  score = readScore(infile, score)
	  averagePoints = calcAveragePoints(score, averagePoints)
	  moreThan40Points = outputMoreThan40Points(score, moreThan40Points)
          mostPoints = findMostPoints(score, mostPoints)
	  leastPoints = findLeastpoints(score, leastPoints)

					    
      }
}
