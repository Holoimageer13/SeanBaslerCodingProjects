// Programmer: Sean Basler    Date:04/09/14
// File: RalphSays_funct.cpp        Class Section: b
// Purpose: This file defines the functions used in RalphSays.cpp
#include "RalphSays.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

void greet()
{
  cout<<"Welcome to Ralph Answers.";
  cout<<" Where we guarentee you an answer every time."<<endl<<endl;
  return;
}

void bye()
{
  cout<<"Thank you for heeding the great wisdom of our founder...";
  cout<<" THE ALL KNOWING RALPH!"<<endl;
  return;
}

void ask(char question[])
{
  cout<<"What is your question for our generous benefactor?: ";
  cin.getline(question, MAXINPUT, '\n');
  cout<<endl;
  cout<<"Ralph says:"<<endl;
  cout<<"\t";  
  return;
}

char again()
{
  //declares local constants
  const int MAXTRYS = 3;
  
  //declares local variables
  char again, redo[MAXINPUT];
  int cnt = 0;
  
  //checks for more questions
  cout<<"Do you have any more question's for "; 
  cout<<"the Great and powerful Ralph?!(y/n): ";
  cin.getline(redo, MAXINPUT);
  again = redo[0];
  while(again != 'y' && again != 'Y' && again != 'n' && again != 'N') 
  {
    cout<<"Fool, answer with a y or an n: ";
    cin.getline(redo, MAXINPUT);
    again = redo[0]; 
    if (cnt == MAXTRYS)
    {
      again = 'n';
    }
    cnt++;
  }
  cout<<endl;
  return again;
}

int chance()
{
  //declares local variables
  int randNum;
  
  //randomizes the return number
  randNum = ((rand()%100)+1);
  return randNum;
}

int chance(const int up)
{
  //declares local variables
  int randNum;
  
  //randomizes the return number
  randNum = ((rand()%(up))+1);
  return randNum; 
}

void longword(char word[], const char question[])
{
  //local variables
  char longWord[MAXINPUT] =" ";
  int currentLength = 0, theLength, j = 0, maxLength = 0;//counters
  
  //finds longest word
  for (unsigned int i = 0; question[i] != '\0' ; i++)
  {
    if (isspace(question[i]) || (i==strlen(question)-1))
    {
      if (maxLength < currentLength)
      {
        theLength = i - currentLength;
        for(j = 0; j <= currentLength; j++)
        {
          
          if(!isspace(question[theLength]))
	    longWord[j] = question[theLength];
	  else
	    j = currentLength - 1;
	  theLength++; 

	  //create null at the end of the array
	  if (j == (currentLength - 1))
	    longWord[j+1] = '\0';
	  if (longWord[j] == '?')
	  {
	    longWord[j] = '\0';
	  }   
        }
        maxLength = currentLength;   
      }
      currentLength = 0;      
    }
    else
    {
      currentLength++;
    }
  }
  strcpy(word, longWord);
  return;
} 

void anyword(char word[], ifstream& fin, const int size)
{
  //local variables
  int randnum; 
  randnum = chance(size);
  //selects the word
  for (int i = 0; i <= randnum; i++)
  { 
    fin >> word;
  }
  fin.clear();
  fin.close();
  return;
}

int datasize(ifstream& fin)
{
  //local variables
  char allwords[MAXDATA];
  int cnt = 0;
  
  //reads the size
  while(fin >> allwords)
  {
    cnt++;
  }
  fin.close();
  fin.clear();
  return cnt;
}

void anyphrase(char phrase[], ifstream& fin, const int size, const bool isNoun)
{
  //local constants
  const int LEADNUM = 2;
  
  //local variables
  int randnum;
  
  //chooses one of the phrases at random
  randnum = chance(size);
  for (int i = 0; i <= randnum; i++)
  {
    if (isNoun == false)
    {
      fin.ignore(LEADNUM, ' ');
    }
    fin.getline(phrase, MAXPHRASE, '\n');
  }
  fin.clear();
  fin.close();
  return;  
}

int numlines(ifstream& fin)
{
  //local variables
  char line[MAXPHRASE];
  int cnt = 0;
      
  //reads the size
  fin.ignore(MAXPHRASE, '\n');
  while(fin.getline(line, (MAXPHRASE-1), '\n'))
  {
    cnt++;
    fin.ignore(MAXPHRASE, '\n');
  }
  fin.close();
  fin.clear();
  return cnt;  
}
