//Programmer: Adam Bowers and Sean Basler   Date: 04/20/2014
//File: classmatefunc.cpp		    Class: CS53 b
//Purpose: This file contains the function file for the classmate class

#include "classmate.h"
using namespace std;

void classmate::go_to_school(schoolyard& theSchool)
{
  m_trash = 0;
  m_xcoor = randnum(theSchool.getdim(), theSchool.getbuil());
  m_ycoor = randnum(theSchool.getdim(), theSchool.getbuil());
  //get another space if there's already a student there
  while(theSchool.getspace(m_xcoor, m_ycoor) == POSITION)
  {
    m_xcoor = randnum(theSchool.getdim(), theSchool.getbuil());
    m_ycoor = randnum(theSchool.getdim(), theSchool.getbuil());
  }
  pickuptrash(theSchool);
  theSchool.setspace(m_xcoor, m_ycoor, POSITION);
  return;
}

void classmate::setiq(const int iq)
{
  if((iq>=MINIQ)&&(iq<=MAXIQ))
    m_iq = iq;
  else
    cout<<"Tried to set invalid iq value so iq member isn't set"<<endl;
  return;
}

ostream& operator<<(ostream& os, const classmate & pers)
{
  os<<pers.m_name<<" has an iq of "<<pers.m_iq<<" and is at location(";
  os<<pers.m_xcoor<<","<<pers.m_ycoor<<")"<<endl;
  cout<<"This is the trash he has collected: "<<endl;
  for(int i=0;i<pers.m_trash;i++)
    os<<"\t"<<pers.m_collection[i].m_name<<endl;
  return os;
}

void classmate::move(schoolyard& theSchool)
{
  if(theSchool.gettrash() > 0)
  {
    int tempx = m_xcoor;
    int tempy = m_ycoor;
    int rannum, targetx, targety;
    
    //keeps track of if moving toward next trash in array is valid
    bool done1=false, done2=false, done3=false, done4=false;
    theSchool.setspace(m_xcoor,m_ycoor, YAR);	  
    //execute until a valid space is found
    while (m_xcoor==tempx && m_ycoor==tempy)
    {//moves intelligently to nearest piece of trash if smart 
	  if(m_iq>=THRESHOLDIQ)
	  {
	    point target;
	    target = theSchool.gettarget(m_xcoor,m_ycoor);
        targetx = target.m_x;
	    targety = target.m_y;
	  }
	  //if stupid move like this
	  else
	  {
	    targetx = theSchool.gettrshx();
        targety = theSchool.gettrshy();
	  }
      rannum=randnum(NUMOPT);
      //Checks if trash is around the character to be collected
      if(theSchool.getspace(m_xcoor-1, m_ycoor)==TRASH)
        tempx--;
      else if(theSchool.getspace(m_xcoor+1, m_ycoor)==TRASH)
        tempx++;
      else if(theSchool.getspace(m_xcoor, m_ycoor-1)==TRASH)
        tempy--;
      else if(theSchool.getspace(m_xcoor, m_ycoor+1)==TRASH)
        tempy++;
      else if(theSchool.getspace(m_xcoor+1, m_ycoor+1)==TRASH)
      {
        tempx++;
        tempy++;
      }
      else if(theSchool.getspace(m_xcoor-1, m_ycoor-1) == TRASH)	  
      {
        tempy--;
        tempx--;
      }
      else if(theSchool.getspace(m_xcoor+1, m_ycoor-1) == TRASH)
      {
        tempy--;
        tempx++;
      }
      else if(theSchool.getspace(m_xcoor-1, m_ycoor+1) == TRASH)
      {
        tempy++;
        tempx--;
      }
      //now go towards target
      else if (m_xcoor<targetx&&!done1)
      {
        tempx++;
        done1=true;
      }
      else if(m_xcoor>targetx&&!done2)
      {
        tempx--;
        done2=true;
      }
      else if(m_ycoor<targety&&!done3)
      {
        tempy++;
        done3=true;
      }
      else if(m_ycoor>targety&&!done4)
      {    
        tempy--;
        done4=true;
      }
      //now just move somewhere in case all else fails
      else if (rannum==0)
        tempx++;
      else if(rannum==1)
        tempy++;
      else if(rannum==2)
        tempx--;
      else
        tempy--;	  
      //make sure that there isn't a student at the space
      if(theSchool.getspace(tempx,tempy) == POSITION)
      {
        tempx = m_xcoor;
        tempy = m_ycoor;
      }
	  
      //redo if we moved into the school or out of bounds
      if (tempx < theSchool.getbuil() && tempy < theSchool.getbuil())
      {
        tempx = m_xcoor;
        tempy = m_ycoor;
      }
      if (tempx>=theSchool.getdim() || tempy >= theSchool.getdim())
      {
        tempy = m_ycoor;
        tempx= m_xcoor;
      }
    }
    m_xcoor = tempx;
    m_ycoor = tempy;
    pickuptrash(theSchool);
    theSchool.setspace(m_xcoor, m_ycoor, POSITION);
  }
  else 
  {
    //moves one square at a time to school
    if(!m_isBuild)
    {
      theSchool.setspace(m_xcoor,m_ycoor, YAR);
      bool don1=false, don2=false, don3=false, don4=false;
      int tempx = m_xcoor, tempy =m_ycoor, rannum;
      if(m_xcoor!= theSchool.getbuil()-1||m_ycoor!=theSchool.getbuil()-1)
      {  
        while (m_xcoor==tempx && m_ycoor==tempy)
        {
          rannum=randnum(NUMOPT);
          if(m_xcoor < theSchool.getbuil()-1&&!don1)
          {
            don1=true;
            tempx ++;     
          }  
          else if(m_xcoor > theSchool.getbuil()-1&&!don2)
          {  
            don2=true;
            tempx--;
          }
          else if(m_ycoor < theSchool.getbuil()-1&&!don3)
          {
            don3=true;
            tempy ++;
          }
          else if(m_ycoor > theSchool.getbuil()-1&&!don4)
          {
            don4=true;
            tempy--;
          }
	  //now just move somewhere in case all else fails
          else if (rannum==0)
          {
            tempx++;
          }
          else if(rannum==1)
          {
            tempy++;
          }
          else if(rannum==2)
          { 
            tempx--;
          }
          else
          {
            tempy--;
          }  
	  //make sure that there isn't a student at the space
          if(theSchool.getspace(tempx,tempy) == POSITION)
          {
            tempx = m_xcoor;
            tempy = m_ycoor;
          }
	   
          //redo if we didnt enter through the door
          if (tempx < theSchool.getbuil()-1 && tempy == theSchool.getbuil()-1)
          {
            tempx = m_xcoor;
            tempy = m_ycoor;
          }
	  if (tempy < theSchool.getbuil()-1 && tempx == theSchool.getbuil()-1)
          {
            tempx = m_xcoor;
            tempy = m_ycoor;
          }
          if (tempx>=theSchool.getdim() || tempy >= theSchool.getdim())
          {
            tempy = m_ycoor;
            tempx= m_xcoor;
          }
        }
        m_xcoor = tempx;
        m_ycoor = tempy;
      }
      else if(m_xcoor == theSchool.getbuil()-1 && 
	 m_ycoor == theSchool.getbuil()-1) 
      {
        m_isBuild = true;
      }
    
      theSchool.setspace(m_xcoor,m_ycoor, POSITION);
    }
    if(m_isBuild)
    {
      if( m_xcoor == theSchool.getbuil()-1 && m_ycoor == theSchool.getbuil()-1)
      {
        theSchool.setspace(m_xcoor,m_ycoor, DOR);
        m_xcoor--;
        m_ycoor--;
        theSchool.setspace(m_xcoor,m_ycoor, POSITION);
      }
      else
      {
        bool again=true;
        bool dne1=false, dne2=false, dne3=false, dne4=false;
        theSchool.setspace(m_xcoor, m_ycoor, BUIL);
        do
        {
          if(m_xcoor > theSchool.getteachx()&&!dne1)
          {
            m_xcoor --;
            dne1=true;
            if(theSchool.getspace(m_xcoor, m_ycoor) == POSITION ||
              m_xcoor<0)
            {
              again = true;
              m_xcoor ++;
            }
            else
              again = false;
          }
          else if(m_xcoor < theSchool.getteachx()&&!dne2)
          {
            m_xcoor ++;
            dne2=true;
            if(theSchool.getspace(m_xcoor, m_ycoor) == POSITION||
               m_xcoor==theSchool.getbuil())	
            {			   
              m_xcoor --;
              again = true;
            }
            else
              again = false;
          }
          else if(m_ycoor > theSchool.getteachy()&&!dne3)
          {
            m_ycoor --;
            dne3=true;
            if(theSchool.getspace(m_xcoor, m_ycoor) == POSITION||
              m_ycoor<0)
            {
              again = true;
              m_ycoor ++;
            }
            else
              again = false;
          }
          else if(m_ycoor < theSchool.getteachy()&&!dne4)
          {
            m_ycoor ++;
            dne4=true;
            if(theSchool.getspace(m_xcoor, m_ycoor) == POSITION||
               m_xcoor==theSchool.getbuil())		  
            {
              m_ycoor --;
              again = true;
            }
            else
              again = false;
          }
        } while(again);
        theSchool.setspace(m_xcoor, m_ycoor, POSITION);
      }
    }
    //now take care of when we finally get to the teacher
    if(m_xcoor == theSchool.getteachx()&& m_ycoor == theSchool.getteachy())
    {
      setscore();
      theSchool.setspace(m_xcoor, m_ycoor, TEACH);
    }
  }
  return;
}

void classmate::pickuptrash(schoolyard& theSchool)
{
  if(theSchool.getspace(m_xcoor, m_ycoor) == TRASH && m_trash != 10)
  {
    trash thePiece;
    if (thePiece.m_name == "glue")
      m_iq = m_iq - 2;
    else
    {
      m_collection[m_trash] = thePiece;
      m_trash ++;
    }
    theSchool.rmvtrsh(m_xcoor,m_ycoor);
  }
  else if(theSchool.getspace(m_xcoor, m_ycoor) == TRASH)
  {
    trash thePiece;
    if (thePiece.m_name == "glue")
      m_iq = m_iq - 2;
    else
    {
      int min_indx = 0;
      int min = m_collection[0].m_val;
      for(int i = 1; i < m_trash; i++)
      {
        if(min > m_collection[i].m_val)
        {
          min = m_collection[i].m_val;
          min_indx = i;
        }
      }
      if(min < thePiece.m_val)
      {
        m_collection[min_indx] = thePiece;
      }
    }
    theSchool.rmvtrsh(m_xcoor,m_ycoor);
  }
  return;
}	

void classmate::setscore()
{
  for( int i =0; i < m_trash; i++)
    m_score = m_score + m_collection[i].m_val;
  m_score = m_score/m_iq;
  m_done=true;
  return;
}
