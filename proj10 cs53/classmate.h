//Programmer: Sean Basler   Class Section: B
//Program: "classmate.h"    Date: 4/19/14
//Desc: This declares the classmate class 
#ifndef CLASSMATE_H
#define CLASSMATE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
//the Class
class classmate
{
  public:
    classmate();
    classmate(const string name);
	void place();
	void setIq();
	int getIq() {return m_iq;}
	void move();
	friend ostream& operator <<(ostream& out, classmate& person);
  private:
    string m_name;
	int m_xcord;
	int m_ycord;
	int m_iq;
};

#endif
