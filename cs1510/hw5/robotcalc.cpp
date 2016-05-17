//Name: Sean Basler  Section: B

#include "stack.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  string start;//
  LinkedStack<int> stack;//the stack
  
  while(start != "@")
  {
  	cin>>start;
  	
	if(start == "+")//adds number in stack
	{
		try
		{
			int x, y, z;//calculation variables
			x = stack.top();
			stack.pop();
			y = stack.top();
			stack.pop();
			z= x+y;
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "-")//subtracts top numbers in stack
	{
		try
		{
			int x, y, z;//calculation variables
			x = stack.top();
			stack.pop();
			y = stack.top();
			stack.pop();
			z= x-y;
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "*")//multiplys top numbers in stack
	{
		try
		{
			int x, y, z;//calculation variables
			x = stack.top();
			stack.pop();
			y = stack.top();
			stack.pop();
			z= x*y;
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "/")//divides two top numbers in stack
	{
		try
		{
			int x, y, z;//calculation variables
			x = stack.top();
			stack.pop();
			y = stack.top();
			stack.pop();
			z= y/x;
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "%")//returns remainder
	{
		try
		{
			int x, y, z;//calculation variables
			x = stack.top();
			stack.pop();
			y = stack.top();
			stack.pop();
			cout<<endl;
			cout<<x<<endl;
			cout<<y<<endl;
			z= y%x;
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "!")//makes top a negative number 
	{
		try
		{
			int x;//calculation variables
			
			x = stack.top();
			stack.pop();
			stack.push(-x);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "sum")//produces sum of stack
	{
		try
		{
			int x;
			int z=0;//calculation variables
			
			while(!stack.isEmpty() )
			{
				x = stack.top();
				stack.pop();
				z += x;
			}
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "prod")//produces product of stack
	{
		try
		{
			int x;
			int z=1;//calculation variables
			
			while(!stack.isEmpty() )
			{
				x = stack.top();
				stack.pop();
				z = x * z;
			}
			stack.push(z);
		}
		catch(Oops q)
		{
			cout<<q.m_errormsg<<endl;
			return 1;
		}
	}
	else if(start == "#")//displays stack
	{
		cout<<stack;
	}
	else if(start == "$")//clears stack
	{
		stack.clear();
	}
	else//adds number to stack
	{
		string tmp;
		tmp = start;
		int x;
		
		x = atoi(tmp.c_str());
		stack.push(x);
	}	
  }
  stack.clear();
  return 0;
}
