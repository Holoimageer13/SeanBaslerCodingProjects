//Name: Sean Basler		Section: B
#include<iostream>

using namespace std;

template <class T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs)
{
	if(this != &rhs)
	{
		clear();//deallocates LinkedList 
		const LinkedList<T>* tmp = &rhs;
		int counter = 0;
		while(tmp->m_next != NULL)
		{
			insert(tmp->m_data, this->getAtPtr(counter));
			tmp = tmp->m_next;
			counter++;
		}
		
	}
	
	return *this;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
	m_next = NULL;//default constructor behavior
	*this = rhs;//calls equal operator
}

template <class T>
int LinkedList<T>::size() const
{
	int theSize = 0;
	const LinkedList<T>* r = this;
	
	while(r->m_next != NULL)//counts elements in list
	{
		theSize++;
		r=r->m_next;
	}
	
	return theSize;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
	const LinkedList<T>* r = this;
	bool empty = false;
	
	if(r->m_next == NULL)
		empty = true;
	
	return empty;
}

template <class T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
	if(m_next != NULL)
		return this;
	else
	{
		cout<<"!!-- ERROR : PANIC in LINKEDLIST.getFirstPtr() - empty list"<<endl;
		return NULL;
	}
}

template <class T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{	
	if(m_next != NULL)
	{
		LinkedList<T>* r = this;
		for(int j = 0; j < size()-1; j++)
		{
			r=r->m_next;
		}
		return r;
	}
	else
	{
		cout<<"!!-- ERROR : PANIC in LINKEDLIST.getLastPtr() - empty list"<<endl;
		return NULL;
	}
}

template <class T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
	if(i>=0 && i<=size())
	{
		LinkedList<T>* r = this;
		
		for(int j = 0; j < i; j++)
		{
			r=r->m_next;
		}
		return r;
	}
	else
	{
		cout<<"!!-- ERROR : PANIC in LINKEDLIST.getAtPtr() - empty list"<<endl;
		return NULL;
	}
}

template <class T>
void LinkedList<T>::clear()
{	
	if(m_next != NULL)
	{
		while(m_next != NULL)
		{
			LinkedList<T>* tmp = m_next;
		
			m_data = tmp->m_data;
			m_next = tmp->m_next;
			
			delete tmp;
		}
	}
	return;	
}

template <class T>
void LinkedList<T>::insert_front(const T& x)
{	
	if(isEmpty())
	{
		m_next = new LinkedList<T>;//new list for empty ones
		m_data = x;
	}
	else
	{
		LinkedList<T>* tmp = new LinkedList<T>;
		
		tmp->m_data = m_data;
		tmp->m_next = m_next;
		
		m_data = x;
		m_next = tmp;
	}
	
	return;
}

template <class T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
	LinkedList<T>* tmp = new LinkedList;//new list to transfer pos to
	
	tmp->m_data = pos->m_data;
	tmp->m_next = pos->m_next;
	
	pos->m_data = x;
	
	pos->m_next = tmp;
}

template <class T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
	LinkedList<T>* tmp = pos->m_next;//tmp is now the member next to pos
	
	pos->m_data = tmp->m_data;
	pos->m_next = tmp->m_next;
	
	delete tmp;
}


template <class T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
	bool equal = true;
	const LinkedList<T>* r = rhs.m_next;//data on in the rhs
	const LinkedList<T>* l = this->m_next;//data in the lhs
	
	if(size() == rhs.size())
	{	
		if(this->m_data != rhs.m_data)
			equal = false;
			
		while (r->m_next != NULL)
		{
			if(r->m_data != l->m_data)
			{
				equal = false;
			}
			r=r->m_next;
			l=l->m_next;
		}
	}
	else
		equal = false;
	
	return equal;
} 

template <class T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
	LinkedList<T>* r = this;//running pointer
	while(r->m_data != x && r->m_next != NULL)
	{
		r = r->m_next;
	}
	
	if(r->m_data == x)
		return r;
	else
		return NULL;
}

template <class T>
void LinkedList<T>::reverse()
{
	LinkedList<T>* tmp = new LinkedList<T>;
	LinkedList<T>* r = this;
	
	while(r->m_next != NULL)
	{
		tmp->insert_front(r->m_data);
		r = r->m_next;
	}
	
	m_data = tmp->m_data;
	m_next = tmp->m_next;
	
	return;
}

template <class T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
	LinkedList<T> tmp ( xlist );
	LinkedList<T>* ap = new LinkedList<T>;
	
	ap->m_next = tmp.m_next;
	ap->m_data = tmp.m_data;
	
	getLastPtr()->m_next = ap;//connect lists
	return;
}

