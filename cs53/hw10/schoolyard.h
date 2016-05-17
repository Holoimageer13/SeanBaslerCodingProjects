//Programmer: Adam Bowers and Sean Basler  Date: 04/16/2014
//File: schoolyard.h			   Class: CS53 b
//Purpose: This file contains the header for the schoolyard class
#ifndef SCHOOLYARD_H
#define SCHOOLYARD_H

#include "structs.h"
using namespace std;

//Pre : yardsize is less than MAXX and builsiz less than yardsize
//		and both are positive
//Post: schoolyard is initialized with given parameters and chars are
//		set based on type of space
//Desc: uses parameters to set building and yard spaces then uses rand
//		function to set value for trash in 10% of yard space
//Pre : none
//Post: school is output to calling output stream
//Desc: irritates through each element in school char array with space
//		between different x vals and line between y vals
//Pre : none
//Post: the int value for schoolyard is returned
//Desc: Simply returns yard dimension to calling function
//Pre : none
//Post: the building size is returned to calling function
//Desc: adds one to m_builsiz since starts at 0 and return to calling function
//Pre : building size and yard dimension are set
//Post: The characater array of schoolyard is filled with building and random
//		trash. The rest of the spaces are spaces
//Desc: Uses dimensions, for loops and random numbers to fill character array
//Pre : m_numtrash >=0
//Post: The value of m_numtrash is decremented by one for schoolyard object
//Desc: Decrements m_numtrash by one
//Pre : m_numtrash is set
//Post: the amount of trash is returned to calling function
//Desc: Simply returns m_numtrash to calling function
//Pre : x and y are within acceptable bounds or >=builsiz and <actudimen
//Post: the character c is assigned to the calling object at x,y
//Desc: Checks that x and y are within bounds and if so assigns c to that index
//		if not outputs an error statement
//Pre : m_teachx is set
//Post: The x index in which the teacher is at is returned to calling object
//Desc: Returns current value of m_teachx
//Pre : m_teachy is set
//Post: The y index in which the teacher is at is returned to calling object
//Desc: Returns current value of m_teachy
//Pre : index at [x][y] isnt junk
//Post: the character at given index is returned
//Desc: Simply returns the character at index of parameters to calling object
//Pre : none
//Post: if x and y match a corresponding x and y in array of points
//      removes the point from the array
//Desc: increments through each item in the array and compares item
//      if a match is found then will remove that item
//Pre : there is at least one element of trash in yard
//Post: returns x index of first element of trash
//Desc: simply returns the x index of the point structure
//Pre : there is at least one element of trash in yard
//Post: returns y index of first element of trash
//Desc: simply returns the y index of the point structure
class schoolyard
{
  public:
    schoolyard(const int yarsiz=3, const int builsiz=1);
    friend ostream& operator<<(ostream& os, const schoolyard& school);
    int getdim()const{return m_actudimen;}
    int getbuil()const{return m_builsiz;}
    void picktrash(){m_numtrash--; return;}
    int gettrash()const{return m_numtrash;}
    void setspace(const int x, const int y, const char c);
    int getteachx()const{return m_teachx;}
    int getteachy()const{return m_teachy;}
    char getspace(const int x, const int y)const{return m_dimens[x][y];}
    void rmvtrsh(const int x, const int y);
    int gettrshx(){return trashlocs[0].m_x;}
    int gettrshy(){return trashlocs[0].m_y;}
	//Pre : the point array is initialized
	//Post: returns the point that is closest to passed parameters
	//Desc: increments through each item in the point array and compares
	//		to the parameter returning the closest point
	point gettarget(const int x, const int y)const;
  private:
    char m_dimens[MAXX][MAXY];
    int m_actudimen;
    int m_builsiz;
    int m_numtrash;
    int m_teachx;
    int m_teachy;
    point trashlocs[YARTRASH];//make an array of points for location of trash for searching algorithm
    void build_school();
};
#endif
