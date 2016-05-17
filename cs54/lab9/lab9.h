//-----------------------------------------------------------------------
// Programmer: Sean Basler            Student ID: 12366509
// Lab: 9, "Aliens"                   Filename: Lab9.h
// Due Date: 03/18/14                 Class: CSc54, Section C
//------------------------------------------------------------------------

#ifndef LAB9_H
#define LAB9_H

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Structs
struct person
{
  string m_name;
  int m_age;
};


//functions

//Description: Stores values in a person
//        Pre: none
//       Post: Person is created
person readPerson();

//Description: Gives the user a greeting
//        Pre: none
//       Post: Outputs a greeting
void greeting ();

//Description: Generates a random number
//        Pre: None
//       Post: Returns a random number
float generateRandomNum();

//Description: Gives the user a farewell
//        Pre: none
//       Post: Outputs a farewell statement
void signoff();

//Template functions

//Description: Prints out two ages of any type
//        Pre: The insertion opperator must be defined for the type
//       Post: Outputs the two ages
template <typename T>
void printResults(T before, T after)
{
  cout<<"Age when Abduct\t: "<<before<<endl;
  cout<<"Age when return\t: "<<after<<endl;
}

#endif
