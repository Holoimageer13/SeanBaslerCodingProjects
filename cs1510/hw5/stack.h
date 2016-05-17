#ifndef STACK_H
#define STACK_H

#include<iostream>
#include"abstractstack.h"

using namespace std;

template <typename T>
class LinkedStack: public AbstractStack<T>
{
	public:
  		T m_data;                  // Data to be stored
  		LinkedStack<T>* m_next;     // Pointer to the next element in the list
		
		// Purpose: Default constructor
   		// Postconditions: next pointer set to NULL
    	// ---INLINE---
 		LinkedStack() : m_next(NULL) {}
		
	  	// Purpose: Checks if a stack is empty
	  	// Returns: 'true' if the stack is empty
	  	//     'false' otherwise
	  	bool isEmpty() const;
	
	  	// Purpose: looks at the top of the stack
	  	// Returns: a const reference to the element currently on top of the stack
	  	// Exception: if the stack is empty, THROW a 'Oops' object with an error message!!!
	  	const T& top() const throw ( Oops );
	
	  	// Purpose: push an element into the stack
	  	// Parameters: x is the value to push into the stack
	  	// Postconditions: x is now the element at the top of the stack,
		void push(const T& x);
	
	  	// Purpose: pop the stack
	  	// Postconditions: the element formerly at the top of the stack has
	  	// been removed
	  	// Note: Poping an empty stack results in an empty stack.
	  	void pop();
	
	  	// Purpose: clears the stack
	  	// Postconditions: the stack is now empty
	  	void clear();
};

template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedStack<T>& xstack)
{
  out << "[ ";
  const LinkedStack<T>* p = &xstack;
  while ( p->m_next != NULL )
  {
    out << p->m_data;
    if(p->m_next->m_next != NULL)
    {
    	out<<", ";
    }
    else
    {
    	out<<" ";
    }
    p = p->m_next;
  } 
  out << "]"<<endl; 
  
  return out;
}

#include "linkedstack.hpp"

#endif
