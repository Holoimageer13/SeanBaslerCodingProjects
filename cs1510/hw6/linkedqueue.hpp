#include<iostream>
using namespace std;

template <class T>
bool LinkedQueue<T>::isEmpty() const
{
	if(m_next == NULL)
		return true;
	else
		return false;
}

template <class T>
const T& LinkedQueue<T>::front() const throw (Oops)
{
	Oops err("Error: Stack is Empty!");
	if(isEmpty())
		throw err;
		 
	return m_next->m_next->m_data;
}

template <class T>
void LinkedQueue<T>::enqueue(const T& x)
{
	LinkedQueue<T>* tmp = new LinkedQueue<T>;
	
	tmp->m_data = x;
	
	if(m_next != NULL)
	{
		tmp->m_next = m_next->m_next;
		m_next->m_next = tmp;
		m_next = tmp;
	}
	else
	{
		tmp->m_next = tmp;
		m_next = tmp;
	}
	return;
}

template <class T>
void LinkedQueue<T>::dequeue()
{
	if(m_next != NULL)
	{
		LinkedQueue<T>* tmp = m_next->m_next;
		m_next->m_next = tmp->m_next;
		delete tmp;	
		if(m_next == tmp)
			m_next = NULL;
	}
	return;
}

template <class T>
void LinkedQueue<T>::clear()
{	
	if(m_next != NULL)
	{
		while(!isEmpty())//run while it isn't empty
		{
			dequeue();
		}
	}
	return;	
}

template <class T>
int LinkedQueue<T>::QueueLength()
{
	int length = 0;// at first it is zero
	if(m_next != NULL)
	{
		length++;//if not empty add one
		const LinkedQueue<T>* r = m_next->m_next;
		const LinkedQueue<T>* tmp = m_next;
		while(r != tmp)//until all the way around count
		{
			length++;
			r = r->m_next;
		}
	}
	return length;	
}
