//Programmer: Adam Bowers and Sean Basler Date: 04/20/2014
//File: classmate.h				Class: CS53 b
//Purpose: This file contains the header file for the classmate class

#ifndef CLASSMATE_H
#define CLASSMATE_H
#include "structs.h"
#include "schoolyard.h"
using namespace std;

class classmate
{
  public:
    //Pre :none
    //Post:classmate string member is set to passed value
    //Desc:name member of classmate is set to n
    classmate(const string n="Bob"):m_name(n){setiq(randnum(MAXIQ,MINIQ));
		      m_score = 0; m_done = false; m_isBuild=false;}
    //Pre : none
    //Post: member x and y coor are set to a random number between 0 and 24
    //Desc: uses randnum function to generate random num on given interval
    //		and assign a two rand nums to x and y coor
    void go_to_school(schoolyard& theSchool);
    //Pre : iq is between acceptable bounds 50 and 75 inclusive
    //Post: iq member is set to iq parameter
    //Desc: if iq is in acceptable bounds m_iq is set to iq if not
    //		output error message
    void setiq(const int iq);
    //Pre : iq has been initialized
    //Post: current iq value is returned to caller
    //Desc: simply returns iq member to caller
    int getiq()const{return m_iq;}
    //Pre : members of pers are set otherwise junk data will be output
    //Post: outputs "name has iq of m_iq and is at (xcoor,ycoor)"
    //Desc: outputs earlier message to calling output stream and returns
    //		said stream
    friend ostream& operator<<(ostream& os, const classmate & pers);
    //Pre : m_xcoor and m_ycoor have a value to compare to
    //Post: x and y will randomly increment up or down one
    //Desc: generates random number from 0-99 and if less than chance to
    //		increment up will increment up otherwise down for x and y
    void move(schoolyard& theSchool);
    //Pre : none
    //Post: picks up trash
    //Desc: puts trash into the classmates pocket
    void pickuptrash(schoolyard& theSchool);
    //Pre : none
    //Post: returns score to calling function
    //Desc: Simply returns the current m_score
    int getscore()const{return m_score;}
    //Pre : m_trash is set to number of pieces of trash in collection
    //Post: returns the sum of all the values of trash in array
    //Desc: access the score from each piece of trash in collection and
    //		adds it to sum
    void setscore();
    //Pre : none
    //Post: returns m_done of calling object
    //Desc: simply returns m_done
    bool isdone()const{return m_done;}
	//Pre : x and y are valid in range for a point
	//Post: previous x and y are set to parameters
	//Desc: Simply sets m_xprev and m_yprev to parameters
	//void setprev(const int x, const int y){m_xprev=x;m_yprev=y;}
	//Pre : none
	//Post: returns true is the passed parameters are = to previous
	//Desc: compares parameters to m_prevx and y returning true if equal
	//bool isprev(const int x, const int y){return x==m_xprev&&y==m_yprev;}
	//Pre : the array isn't full(impossible given array size of schoolyard
	//Post: x and y are added to the elements of the array
	//Desc: sets each element at current element of m_prev to parameters and
    //      adds one to the index	
	//void setpoints(int x, int y){m_prevs[m_numpoints].x =x;
					//			m_prevs[m_numpoints].y =y;m_numpoints++;}
	//Pre : none
    //Post: returns true if x and y are correspond to a point in prevs array
    //		of points
	//Desc: increments through each point in array comparing it to parameters
	//bool beenthere(const int x, const int y);
  private:
    string m_name;
    int m_xcoor;
    int m_ycoor;
    int m_iq;
    int m_trash;
    int m_score;
	//int m_xprev;
	//int m_yprev;
    bool m_isBuild;
    bool m_done;
	//point m_prevs[MAXX*MAXX];
	//int m_numpoints;
    trash m_collection[MAXTRASH];
};

#endif
