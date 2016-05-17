//Name: Sean Basler   Section: B
#include<iostream>

using namespace std;

template <typename T>
ArrayList<T>::~ArrayList()
{
	m_size = 0;
	m_max = 0;
	delete [] m_data;
	m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
	if(this != &rhs)
	{
		m_size = rhs.m_size;
		m_max = rhs.m_max;
		delete [] m_data;
		m_data = new T[m_max];
		for(int i = 0; i < m_max; i++)
			m_data[i] = rhs.m_data[i];
	}
	return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
	m_data = new T[cpy.m_max];
	*this = cpy; 
}

template <typename T>
int ArrayList<T>::size() const
{
	return m_size;
}

template <typename T>
const T& ArrayList<T>::first() const
{
	if(m_data != NULL)
		return m_data[0];
	else
	{
		cout<<"!-- ERROR : PANIC in ARRAYLIST.first()!!   (List is empty)"<<endl;
		return m_errobj;
	}
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
	if(i>=0 && i <= m_size)
	{
		return m_data[i];
	}
	else
	{
		cout<<"!-- ERROR : PANIC in ARRAYLIST!!.[]   (index out of bounds)"<<endl;
		return m_errobj;
	}
}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
	if(i>=0 && i <= m_size)
	{
		return m_data[i];
	}
	else
	{
		cout<<"!-- ERROR : PANIC in ARRAYLIST.[]!!   (index out of bounds)"<<endl;
		return m_errobj;
	}
}

template <typename T>
int ArrayList<T>::find(const T& x)
{
	int pos = -1;//returns the position or -1 if it is not found
	bool first = false;//makes sure only the first occurence is returned
	for(int j = 0; j < m_size; j++)
	{
		if(m_data[j] == x && first == false)
		{
			pos = j;
			first = true;
		}
	}
	
	return pos;
}

template <typename T>
void ArrayList<T>::clear()
{
	m_max = 0;
	m_size = 0;
	delete [] m_data;
	m_data = NULL;
	return;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{			
	if(m_size == m_max)
	{
		T* tmp;//temporary container
		
		if(m_max == 0)//starting case
		{
			m_max++;
			delete [] m_data;
			m_data = new T[m_max];
		}
		
		//transfer of data
		tmp = new T[m_max*2];
		for(int j = 0; j < m_max; j++)
			tmp[j] = m_data[j];
		
		delete [] m_data;
		//variables set and tmp destroyed
		m_data = tmp;
		
		//set new max
		m_max = m_max * 2;
	}
	
	m_data[m_size] = x;//puts x in back
	m_size++;//adds to the size
	
	return;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
	if(i>=0 && i<=m_size)
	{
		if(m_size != 0)//controls m_size for any but origin case
			m_size++;
		
		if(m_size == m_max)
		{
			T* tmp;//temporary container
		
			if(m_max == 0)//starting case
			{
				m_max++;
				delete [] m_data;
				m_data = new T[m_max];
			}
		
			//transfer of data
			tmp = new T[m_max*2];
			for(int j = 0; j < m_max; j++)
				tmp[j] = m_data[j];
		
			delete [] m_data;
			//variables set and tmp destroyed
			m_data = tmp;
		
			//set new max
			m_max = m_max * 2;
		}
		
		if(m_size == 0)//control for origin case
		{
			m_data[i] = x;
			m_size++;
		}
		else
		{
			for(int k = m_size; k > i; k--)
				m_data[k] = m_data[k-1];
			m_data[i] = x;
		}
	}
	else
		cout<<"!-- ERROR : PANIC in ARRAYLIST!!.insert()   (index out of bounds)"<<endl;
	
	return;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
	if(m_size != 0)//checks that there are things in the array
	{
		if(i>=0 && i<=m_size)
		{
			for(int k = i; k < m_size-1; k++)//shifts elements
				m_data[k] = m_data[k+1];
			
			m_size--;//decreases size
		
			if(m_size == (m_max/4))//shrinks max
			{
				T* tmp;
			
				m_max = m_max/2;//shrinks the max
			
				//transfers data
				tmp = new T[m_max];
				for(int j = 0; j<m_max; j++)
					tmp[j] = m_data[j];
			
				delete [] m_data;
			
				m_data = tmp;
			}
		}
		else
			cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()   (index out of bounds)"<<endl;
	}
	else
		cout<<"!-- ERROR : PANIC in ARRAYLIST!!.remove()   (List is Empty)"<<endl;
	
	return;
}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
	T tmp;//holds value for changed variable
	
	if(i>=0 && i<=m_max)
	{
		if(k>=0 && k<=m_max)
		{
			tmp = m_data[i];
			m_data[i] = m_data[k];
			m_data[k] = tmp;
		}
		else
			cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()   (index out of bounds)"<<endl;
	}
	else
		cout<<"!-- ERROR : PANIC in ARRAYLIST!!.swap()   (index out of bounds)"<<endl;
	return;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{	
	for(int k = 0; k < alist.size(); k++)
	{
		this->insert_back(alist[k]);
	}
	return;
}

template <typename T>
void ArrayList<T>::purge()
{
	for(int k = 0; k<m_size; k++)
	{
		for(int j = k+1; (j-1)<m_size; j++)
		{
			if(m_data[k] == m_data[j])
			{
				this->remove(j);
			}
		}
	}
	return;
}



