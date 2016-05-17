//Programmer: Adam Bowers and Sean Basler Date: 04/20/2014
//File: classmate.h		          Class: CS53 b
//Purpose: This file contains the header file for the classmate class

#ifndef CLASSMATE_H
#define CLASSMATE_H
#include "structs.h"
#include "schoolyard.h"
using namespace std;
//Pre :none
//Post:classmate string member is set to passed value
//Desc:name member of classmate is set to n
//Pre : none
//Post: member x and y coor are set to a random number between 0 and 24
//Desc: uses randnum function to generate random num on given interval
//		and assign a two rand nums to x and y coor
//Pre : iq is between acceptable bounds 50 and 75 inclusive
//Post: iq member is set to iq parameter
//Desc: if iq is in acceptable bounds m_iq is set to iq if not
//		output error message
//Pre : iq has been initialized
//Post: current iq value is returned to caller
//Desc: simply returns iq member to caller
//Pre : members of pers are set otherwise junk data will be output
//Post: outputs "name has iq of m_iq and is at (xcoor,ycoor)"
//Desc: outputs earlier message to calling output stream and returns
//		said stream
//Pre : m_xcoor and m_ycoor have a value to compare to
//Post: x and y will randomly increment up or down one
//Desc: generates random number from 0-99 and if less than chance to
//		increment up will increment up otherwise down for x and y
//Pre : none
//Post: picks up trash
//Desc: puts trash into the classmates pocket
//Pre : none
//Post: returns score to calling function
//Desc: Simply returns the current m_score
//Pre : m_trash is set to number of pieces of trash in collection
//Post: returns the sum of all the values of trash in array
//Desc: access the score from each piece of trash in collection and
//		adds it to sum
//Pre : none
//Post: returns m_done of calling object
//Desc: simply returns m_done

class classmate
{
  public:
    classmate(const string n="Bob"):m_name(n){setiq(randnum(MAXIQ,MINIQ));
               m_score = 0; m_done = false; m_isBuild=false, m_trash = 0;}
    void go_to_school(schoolyard& theSchool);
    void setiq(const int iq);
    int getiq()const{return m_iq;}
    friend ostream& operator<<(ostream& os, const classmate & pers);
    void move(schoolyard& theSchool);
    void pickuptrash(schoolyard& theSchool);
    float getscore()const{return m_score;}
    void setscore();
    bool isdone()const{return m_done;}
  private:
    string m_name;
    int m_xcoor;
    int m_ycoor;
    int m_iq;
    int m_trash;
    float m_score;
    bool m_isBuild;
    bool m_done;
    trash m_collection[MAXTRASH];
};

#endif
