//Programmer: Adam Bowers and Sean Basler  Date: 04/16/2014
//File: header.h		           Class: CS53 b
//Purpose: This file defines the functions in class schoolyard

#include "schoolyard.h"
using namespace std;
schoolyard::schoolyard(const int yarsiz, const int builsiz)
{
  //get actual dimension if in acceptable bound
  if(yarsiz>=0&&yarsiz<MAXX)
    m_actudimen = yarsiz;
  else
    cout<<"Invalid yard size so value was not set"<<endl;
  
  //get building size and assign our array
  if(yarsiz>=builsiz)
  {
    m_builsiz = builsiz;
    build_school();
  }
  else
  {
    cout<<"Building size is invalid with respect to yard";
    cout<<" size so value not set"<<endl;
  }
}

void schoolyard::build_school()
{	
  int numspace = 0;
  
  //set S for every block of school based on build
  for(int i = 0; i<m_builsiz; i++)
    for(int k = 0; k<m_builsiz; k++)
    {
      if(i==m_builsiz-1&& k==m_builsiz-1)
        m_dimens[k][i]=DOR;
      else
        m_dimens[k][i]=BUIL;
    }
  // put the teach in a random school building spot that isn't the door
  do
  {
    m_teachx = randnum(m_builsiz);
    m_teachy = randnum(m_builsiz);
  } while(m_teachx == m_builsiz-1 && m_teachy== m_builsiz-1);
  m_dimens[m_teachx][m_teachy]=TEACH;
  //now set spaces for yard
  for(int i = 0; i<m_actudimen; i++)
    for(int k = 0; k<m_actudimen; k++)
      if(i>m_builsiz-1||k>m_builsiz-1)//make sure not to overwrite building
      {
        m_dimens[k][i]= YAR;
        numspace++;
      }
  if (PERC_TRASH > MAXYARTRASH)
  {
    cout<<"Error, above allowed amount of trash";
    exit(3);//exit condition if trash is above allowed amount 
  }
  m_numtrash = static_cast<int>(numspace*PERC_TRASH);
   
    
  //put trash in a random space in yard
  int indxy= 0;
  int indxx= 0;
  bool valid = false;
  for(int i = 0; i<m_numtrash; i++)
  {
    do
    {
      indxy=randnum(m_actudimen,0);
      indxx=randnum(m_actudimen,0);
      //make sure that index for trash is valid
      if((m_dimens[indxx][indxy]!=TRASH)&&(indxy>=m_builsiz||indxx>=m_builsiz))
      {
        m_dimens[indxx][indxy]=TRASH;
        valid = true;
        trashlocs[i].m_x=indxx;
        trashlocs[i].m_y=indxy;
      }
      else
        valid = false;
    } while(!valid);	  
  }
  return;
}

ostream& operator<<(ostream& os, const schoolyard& school)
{
  //increment through every index in array and output
  cout<<"The school yard is"<<endl;
  int size = school.m_actudimen;
  for(int j = 0; j < size; j++)
    os<<"----";
  os<<"-"<<endl;
  for(int i=0; i < size; i++)
  {
    for(int k = 0; k < size; k++)
      os<<"| "<<school.m_dimens[i][k]<<" ";
    os<<"|"<<endl;
    for(int j = 0; j < size; j++)
      os<<"----";
    os<<"-"<<endl;
  }
  return os;
}

void schoolyard::setspace(const int x, const int y, const char c)
{//make sure not trying to assign an array in the building or outside school
  if(x>=0 || y>=m_builsiz)
    m_dimens[x][y]=c;
  else
    cout<<"You can't write to that index, assignment failed"<<endl;
  return;
}

void schoolyard::rmvtrsh(const int x, const int y)
{
  bool isthere=false;
  int count = 0;
  while(count<m_numtrash&&!isthere)
  {
    if(trashlocs[count].m_x==x&&trashlocs[count].m_y==y)
      isthere=true;
    
    //remove trash point if there
    if(isthere)
      for(int i=count; i<m_numtrash; i++)
      {
        //assigns junk data at lower index but irrelevant when m_numtra updated
        trashlocs[i].m_x=trashlocs[i+1].m_x;
        trashlocs[i].m_y=trashlocs[i+1].m_y;
      }
      count ++;
  }
  picktrash();
  return;
}
  
point schoolyard::gettarget(const int x, const int y)const
{
  point temp;
  int mindis, curdis;
  temp = trashlocs[0];
  if(temp.m_x> x)
    mindis = temp.m_x - x;
  else
    mindis = x - temp.m_x;
  if(temp.m_y>y)
    mindis = mindis+ temp.m_y-y;
  else
    mindis= mindis + y-temp.m_y;
  for(int i =1; i<m_numtrash; i++)
  {
	if(trashlocs[i].m_x> x)
      curdis = trashlocs[i].m_x - x;
    else
      curdis = x - trashlocs[i].m_x;
    if(trashlocs[i].m_y>y)
      curdis = curdis+ trashlocs[i].m_y-y;
    else
      curdis= curdis + y-trashlocs[i].m_y;
	if(curdis<mindis)
	{
	  temp = trashlocs[i];
	  mindis = curdis;
	}
  }
  return temp;
}
