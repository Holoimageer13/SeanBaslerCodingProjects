#include<iostream>

using namespace std;

template <class T>
bool LinkedStack<T>::isEmpty() const
{
	if(m_next == NULL)
		return true;
	else
		return false;
}

template <class T>
const T& LinkedStack<T>::top() const throw (Oops)
{
	Oops err("Error: Stack is Empty!");
	if(isEmpty())
		throw err;
		 
	return m_data;
}

template <class T>
void LinkedStack<T>::push(const T& x)
{
	LinkedStack<T>* tmp = new LinkedStack<T>;
	
	tmp -> m_data = m_data;
	tmp -> m_next = m_next;
	
	m_data = x;
	m_next = tmp;
	
	return;
}

template <class T>
void LinkedStack<T>::pop()
{
	if(m_next != NULL)
	{
		LinkedStack<T>* tmp = m_next;
		m_data = tmp->m_data;
		m_next = tmp->m_next;
		delete tmp;	
	}
	return;
}

template <class T>
void LinkedStack<T>::clear()
{	
	if(m_next != NULL)
	{
		const LinkedStack<T>* r = this;
		while(r->m_next != NULL)
		{
			pop();
		}
	}
	return;	
}
