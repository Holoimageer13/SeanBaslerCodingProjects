//Programmer: Sean Basler   Class Section: B
//Program: "classmate.h"    Date: 4/19/14
//Desc: This declares the classmate class 
#ifndef CLASSMATE_H
#define CLASSMATE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global constants
const int TOP_PLACE = 24;//the largest coord a classmate can be placed

//the Class

//the class function conditions in order
//Desc: constructor for the classmate
// Pre: none
//Post: Will create a classmate object
//Desc: Puts the object somewhere between (0,0) and (24,24)
// Pre: none
//Post: Sets a random location to the object in the right range
//Desc: Sets an iq for the object in a certain range
// Pre: none
//Post: Sets the iq 
//Desc: Gets the value of the objects iq 
// Pre: none
//Post: Gets the iq value
//Desc: Increases or decreases an object coordinate by one
// Pre: none
//Post: Moves the object one space
//Desc: Outputs classmate in the correct format
// Pre: none
//Post: Outputs the classmate

class classmate
{
  public:
    classmate(const string name = "Bob");
    void place();
    void setIq();
    int getIq() {return m_iq;}
    void move();
    friend ostream& operator <<(ostream& out, classmate& person);
  private:
    string m_name;
    int m_xcord;
    int m_ycord;
    int m_iq;
};

#endif
