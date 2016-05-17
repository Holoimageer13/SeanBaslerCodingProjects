//-----------------------------------------------------------------------
// Programmer: Sean Basler           Student ID: 12366509 
// Lab: 9, "Aliens"                  Filename: Lab9.cpp
// Due Date: 03/18/14                 Class: CSc54, Section C
//------------------------------------------------------------------------

#include "lab9.h"

void greeting ()
{
  cout << endl << "Welcome! " << endl << endl;
  cout << "Aliens have arrived to earth"  << endl
       <<"This program gives information about an abducted family " << endl 
       << endl;

  return;
}

void signoff()
{
  cout << endl;
  cout << "Thank you for using the program! " << endl
       << "Have a good day!"  << endl ;
  return;
}

person readPerson()
{
  //declares variables
  person mom;
  
  //prompts for a name
  cout<<"\tName\t: ";
  cin>>mom.m_name;
  
  //prompts for an age
  cout<<"\tAge\t: ";
  cin>>mom.m_age;
  
  return mom;
}

float generateRandomNum()
{
  //local constants
  const int LOW_AGE = 1, HIGH_AGE = 3;
  
  //local variable
  float randNum;
  
  //generates random number
  randNum = LOW_AGE + static_cast<float>(rand())/
            (static_cast<float>(RAND_MAX/(HIGH_AGE-LOW_AGE)));
  return randNum;  
}
