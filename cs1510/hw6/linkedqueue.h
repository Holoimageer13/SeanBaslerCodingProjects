#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include<iostream>
#include"abstractqueue.h"

using namespace std;

template <typename T>
class LinkedQueue: public AbstractQueue<T>
{
	public:
  		T m_data;                  // Data to be stored
  		LinkedQueue<T>* m_next;     // Pointer to the next element in the list
		
		// Purpose: Default constructor
   		// Postconditions: next pointer set to NULL
    	// ---INLINE---
 		LinkedQueue() : m_next(NULL) {}
		
	  	 // Purpose: Checks if a queue is empty
 		 // Returns: 'true' if the queue is empty
 		 //     'false' otherwise
  		 bool isEmpty() const;

  		 // Purpose: looks at the front of the queue
 		 // Returns: a reference to the element currently in front of the queue
 		 // Exception: if the queue is empty, THROW a 'Oops' object with an error message!!!
 		 const T& front() const throw (Oops);

	 	 // Purpose: enqueue an element into the queue
 		 // Parameters: x is the item to add to the queue
  		// Postconditions: x is now the element at the end of the queue,
 		 void enqueue(const T& x);

  		// Purpose: dequeues
  		// Postconditions: the element formerly at the front of the queue has
  		//     been removed.
  		// Note: Dequeueing an empty queue results in an empty queue.
  		void dequeue();


  		// Purpose: clears the queue
  		// Postconditions: the queue is now empty
  		void clear();
  		
  		// Purpose: states the length of the Line
  		// Postconditions: number of items in the queue
  		// 		is returned
  		int QueueLength();
};
/*
template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedQueue<T>& xqueue)
{
  out << "[ ";
  int counter = 0;
  LinkedQueue<T>* tmp = m_next;
  LinkedQueue<T>* p = this;
  while (counter != xqueue.QueueLength() )
  {
    out << p->m_next->m_data;
    p = p->m_next;
    if(p->m_next != tmp)
    {
    	out<<", ";
    }
    else
    {
    	out<<" ";
    }
  } 
  out << "]"<<endl; 
  
  return out;
}
*/
#include "linkedqueue.hpp"

#endif
