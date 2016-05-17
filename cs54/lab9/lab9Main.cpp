//-----------------------------------------------------------------------
// Programmer: Sean Basler            Student ID: 12366509
// Lab: 9, "Aliens"                   Filename: Lab9Main.cpp
// Due Date: 03/18/14                 Class: CSc54, Section C
//------------------------------------------------------------------------

#include "lab9.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
  srand(time(NULL));
  int const ABDUCT_M=3, ABDUCT_C = 5;
  person mother;
  float child;

  int motherNew;
  float childNew;
  
  greeting();

  //read mothers age from user
  cout<< "Reading mother's information" <<endl;
  mother =readPerson();
  //generating childs (an random number between 1 to 12)
  cout<< "Generating child' information (a toddler: 1y-3y)" <<endl;
  
  child = generateRandomNum();
  cout << "\tchild's age = "   << child;
  cout << endl << endl;
  
  cout << "Aliens abduct the family" << endl
       << "\tMother for " << ABDUCT_M << endl
       << "\tChild for " << ABDUCT_C << endl ;
  
  motherNew = mother.m_age+ABDUCT_M;
  childNew = child + ABDUCT_C;

  //print results
 
  cout << "mother's age information "<< endl ;
  //call printResuls to print mother's  information
  printResults(mother.m_age, motherNew); 
  cout << "Child's age information "<< endl ;
  //call printResuls to print child's  information
  printResults(child, childNew);
  signoff();
  
  return 0;
}

