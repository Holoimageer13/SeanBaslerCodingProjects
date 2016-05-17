//Programmer: Adam Bowers and Sean Basler  Date: 04/16/2014
//File: header.h		           Class: CS53 b
//Purpose: This file contains the header for all purpose functions and included
//		   libraries
#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
using namespace std;

//const for max dimensions used for classmate position as well as schoolyard
const int MINX =0;
const int MINY =0;
const int MAXIQ=150;
const int MINIQ=50;
const int THRESHOLDIQ = 100;
const int MAXTRASH = 10;
const int CHANCEUPX=50;
const int CHANCEUPY=50;
const int MAXINTV=100;
const int NUMOPT = 4;
const char POSITION = 'C';

//more school yard constants
const float PERC_TRASH = .25;
const float MAXYARTRASH = .5;
const int MAXX =25;
const int MAXY =25;
const char TRASH = 'T';
const char YAR= '_';
const char BUIL = 'S';
const char DOR= 'D';
const char TEACH = 'H';
const char STU = 'C';
const int YARMAX = 20;
const int YARMIN = 5;
const int YARTRASH = 365;

//Pre : Max is greater than 0 and min. Min is greater than or equal to 0
//Post: a random number between min and max not including max is generated
//Desc: uses the rand function to return a number between min and max inclusive
int randnum(const int max, const int min = 0);

//a structure for trash
struct trash
{
  string m_name;
  int m_val;
  trash();
};
//stucture for points to see if people have been there previously
struct point
{
  int m_x;
  int m_y;
};
#endif
