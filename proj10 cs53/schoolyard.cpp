//Programmer: Sean Basler   Class Section: B
//Program: "schoolyard.cpp" Date: 4/19/14
//Desc: This program Defines the member and friend functions of the schoolyard
//      class. 
#include "schoolyard.h"

schoolyard::schoolyard(const short yard, const short building)
{
  if (yard <= MAXDIST && building < yard)
  {
    m_yard = yard;
	m_building = building;
	build_school();
  }
  else
    cout<<"Error, invalid entry!"<<endl;
}

void schoolyard::build_school()
{
  //local constants
  const float AMT_TRASH = 0.1;
  const int CHANCE_TRASH = 10;
  //local variables
  short theSchool = getbuilding(), outside = getyard();
  short trash = static_cast<int>(((outside*outside) - 
                (theSchool*theSchool))*AMT_TRASH);
  bool randnum;
  
  //building the outer yard
  for (int i = 0; i <= outside; i++)
  {
    for (int j = 0; j <= outside; j++)
    {
	  m_theYard[i][j] = ' ';
	  if ((i > theSchool || j > theSchool) && trash != 0)
      {
		randnum = rand()%CHANCE_TRASH;
        if (randnum == 0)
        {
		  m_theYard[i][j] = 'T';
	      trash--;
        }		  
      }
	}
	if (i == outside && trash != 0)
	{
	  i = i-(outside-theSchool);
	}
  }	
  
  //building the school 
  for (int i = 0; i <= theSchool; i++)
  {
    for (int j = 0; j <= theSchool; j++)
	{
	  m_theYard[i][j] = 'S';
	}
  }
  m_theYard[theSchool][theSchool] = 'D';
}

ostream& operator <<(ostream& out, const schoolyard& yard)
{
  int theGrid = yard.m_yard; 
  for (int i = 0; i <= theGrid; i++)
  {
    for (int j = 0; j <= theGrid; j++)
	{
	  out<<yard.m_theYard[i][j];
	}
	out<<endl;
  }
  return(out);
}
