//Name: Sean Basler  Section: B
#include <iostream>
#include "IntBox.h"

IntBox::IntBox(int s, int a)
{

	if(s > 0)
	{	
		//dynamically allocates specified array
		m_ints = new int[s];
		for(int k = 0; k<s; k++)
			m_ints[k] = a;
		
		//sets box size
		m_boxsize = s;
	}
}

IntBox::~IntBox()
{
	delete [] m_ints;
}

const IntBox& IntBox::operator=(const IntBox& rhs)
{
	if(this != &rhs)
	{
		m_boxsize = rhs.m_boxsize;
		delete [] m_ints;//deallocates previously stored array
		m_ints = new int[m_boxsize];//allocates new array 
		for(int i = 0; i < m_boxsize; i++)
			m_ints[i] = rhs.m_ints[i]; //fills new array
	}
	return *this;
}

IntBox::IntBox(const IntBox& rhs)
{
	m_ints = new int[rhs.m_boxsize];
	*this = rhs;
}

void IntBox::set(int i, int x)
{
	if( i >= 0 && i <= m_boxsize)
	{
		m_ints[i] = x;
	} 
	return;
}

std:: ostream& operator<< (std::ostream& out, const IntBox& box)
{
	out<<"[ ";
	for(int j = 0; j < box.m_boxsize; j++)
		out<<box.m_ints[j]<<", ";
	out<<"]";
	
	return out;
}
