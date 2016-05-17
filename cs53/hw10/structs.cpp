//Programmer: Adam Bowers and Sean Basler  Date: 04/16/2014
//File: funct.cpp			   Class: CS53 b
//Purpose: This file contains the function definitions for all the global
//		   functions
#include "structs.h"
using namespace std;

int randnum(const int max, const int min)
{
  return rand()%(max-min) + min;
}

trash::trash()
{
  //open our text file
  ifstream fin;
  fin.open("trash.dat");
  int num_lines;
  fin>>num_lines;
  for(int i =0; i<randnum(num_lines,1);i++)
  {
    fin>>m_val;
    fin.ignore();
    getline(fin,m_name);
  }
  fin.close();
}
