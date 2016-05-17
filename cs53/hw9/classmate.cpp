//Programmer: Sean Basler   Class Section: B
//Program: "classmate.cpp"  Date: 4/19/14
//Desc: This program Defines the member and friend functions of the classmate
//      class. 
#include "classmate.h"

classmate::classmate(const string name)
{ 
  //sets the name
  m_name = name;
  
  //setting the iq  
  setIq();
  place();
}

void classmate::place()
{  
  //setting the iq  
  m_xcord = (rand()%(TOP_PLACE+1));
  m_ycord = (rand()%(TOP_PLACE+1));
  return;  
}

void classmate::setIq()
{
  //local constants
  const int TOPIQ = 70, LOWIQ = 50;//the range of iq's
  
  //setting the iq  
  m_iq = ((rand()%((TOPIQ+1)-LOWIQ))+LOWIQ);
  return;
}

void classmate::move()
{
  //local constants 
  const int NUMOPT = 4; 
  
  //local variables
  int tempx, tempy, randnum;
  tempx = m_xcord;
  tempy = m_ycord;
  while (tempx == m_xcord && tempy == m_ycord)
  {
    randnum = (rand()%NUMOPT)+1;
    if (randnum == 1)
      tempx++;
    else if (randnum == 2)
      tempy++;
    else if (randnum == 3)
      tempx--;
    else
      tempy--;
    if (tempx < 0 || tempx > 24)
      tempx = m_xcord;
    if (tempy < 0 || tempy > 24)
      tempy = m_ycord;	
  }
  m_xcord = tempx;
  m_ycord = tempy;
  return;
}

ostream& operator <<(ostream& out, classmate& person)
{
  out<<person.m_name<<" has iq "<<person.m_iq<<" and is at ";
  out<<"("<<person.m_xcord<<", "<<person.m_ycord<<")."<<endl;
  return out;
}
