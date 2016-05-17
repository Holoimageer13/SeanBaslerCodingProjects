//Programmer: Sean Basler   Class Section: B
//Program: "schoolyard.h"   Date: 4/19/14
//Desc: This declares the schoolyard class
#ifndef SCHOOLYARD_H
#define SCHOOLYARD_H 
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//global constant
const int MAXDIST = 25;

//the Class

//the class functions conditions in order
//Desc: Constructor for the schoolyard class;
// Pre: must have two positive numbers and the first number must be larger
//Post: creates a schoolyard
//Desc: Retrives the size of the yard without the building
// Pre: none
//Post: Returns the size of the non-building schoolyard
//Desc: Gets the size of the school building
// Pre: none
//Post: Returns the size of the building
//Desc: Outputs the schoolyard character map
// Pre: none
//Post: Outputs the schoolyard
//Desc: Builds the schoolyard character map 
// Pre: Must have valid private variables
//Post: Builds the schoolyard character map

class schoolyard
{
  public:
    schoolyard(const short yard, const short building);
    short getyard() {return m_yard;}
    short getbuilding() {return m_building;}
    friend ostream& operator <<(ostream& out, const schoolyard& yard);
  private:
    void build_school();
    char m_theYard[MAXDIST][MAXDIST];
    short m_yard;
    short m_building;
};
#endif
