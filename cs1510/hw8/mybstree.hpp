//Name: Sean Basler Section: B
#include<iostream>
#include<string>
using namespace std;

template <typename T>
TreeNode<T>::TreeNode(T data, TreeNode* right, TreeNode* left)
{
	m_data = data;
	m_right = right;
	m_left = left;
}

template <typename T>
TreeNode<T>* clone(const TreeNode<T>* t)
{
	if(t==NULL)
		return NULL;
	else
		return new TreeNode<T>(t->m_data, clone(t->m_right), clone(t->m_left));
}

template <typename T>
MyBSTree<T>::MyBSTree()
{
	m_root = NULL;
	m_size = 0;
}

template <typename T>
MyBSTree<T>::~MyBSTree()
{
	clear();
	m_size = 0;
}

template <typename T>
MyBSTree<T>& MyBSTree<T>::operator=(const MyBSTree<T>& rhs)
{
	if(this != &rhs)
	{
		clear();
		TreeNode<T>* tree;
		
		m_size = rhs.m_size;
		tree = clone(rhs.m_root);
		
		m_root = tree;
	}
	return *this;
}

template <typename T>
MyBSTree<T>::MyBSTree(MyBSTree<T>& rhs)
{
	m_root = NULL;//default constructor behavior
	m_size = 0;
	*this = rhs;//calls equal operator
}

template <typename T>
int MyBSTree<T>::size() const
{
	return m_size;
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
	if(m_root == NULL)
		return true;
	else 
		return false;
}

template <typename T>
int recursiveHeight(const TreeNode<T>* t)
{
	if(t == NULL)
	{
		return 0;
	}
	
	int left = recursiveHeight(t->m_left);
	int right = recursiveHeight(t->m_right);
	
	if(left > right)
		return 1 + left;
	else
		return 1 + right;	
}

template <typename T>
int MyBSTree<T>::height() const
{
	if(m_root == NULL)
		return 0;
	else
		return recursiveHeight(m_root);
}

template <typename T>
const T& recursiveMax(const TreeNode<T>* t)
{
	if(t->m_right == NULL)
		return t->m_data;
	else
		return recursiveMax(t->m_right);
}

template <typename T>
const T& MyBSTree<T>::findMax() const throw (Oops)
{
	Oops err("OOPS! : Tree is Empty!!");
	if(isEmpty())
		throw err;
	
	return recursiveMax(m_root);
}

template <typename T>
const T& recursiveMin(const TreeNode<T>* t)
{
	if(t->m_left == NULL)
		return t->m_data;
	else
		return recursiveMin(t->m_left);
}

template <typename T>
const T& MyBSTree<T>::findMin() const throw (Oops)
{
	Oops err("OOPS! : Tree is Empty!!");
	if(isEmpty())
		throw err;
	
	return recursiveMin(m_root);
}

template <typename T>
int recursiveFind(const TreeNode<T>* t, const T& x, int& level)
{	
	if(t == NULL)
	{
		return -level;
	}
	
	if(t->m_data > x)
	{
		level++;
		return recursiveFind(t->m_left, x, level);
	}
	else if(x > t->m_data)
	{
		level++;
		return recursiveFind(t->m_right, x, level);
	}
	else 
		return level;
}

template <typename T>
int MyBSTree<T>::find(const T& x) const
{
	//empty tree
	if(isEmpty())
		return 0;	
	
	int theLevel;
	int lvl = 1;//declare level at root
	
	theLevel = recursiveFind(m_root, x, lvl);
	return theLevel;
}

template <typename T>
void MyBSTree<T>::clear()
{
	while(!isEmpty())
	{
		remove(m_root->m_data);
	}
	return;
}

template <typename T>
void recursiveInsert(TreeNode<T>*& t, int& size, const T& x)
{
	if(t==NULL)
	{
		t = new TreeNode<T>;
		t->m_data = x;
		t->m_right = NULL;
		t->m_left = NULL;
		size++;
	}
	else if(x > t->m_data)
		recursiveInsert(t->m_right, size, x);
	else if(x < t->m_data)
		recursiveInsert(t->m_left, size, x);
	else//x already in tree
		return;
}

template <typename T>
void MyBSTree<T>::insert(const T& x)
{
	recursiveInsert(m_root, m_size, x);
	return;
}

//recursive remove
template <typename T>
void rcRemove(TreeNode<T>*& t, int& size, const T& x)
{
	if(t==NULL)
	{
		return;
	}
	
	if(x<t->m_data)
		rcRemove(t->m_left, size, x);
	else if(x>t->m_data)
		rcRemove(t->m_right, size, x);
	else//x found
	{
		if(t->m_right == NULL && t->m_left == NULL)
		{
			delete t;
			t = NULL;
			size--;
			return;
		}
		else if(t->m_right == NULL || t->m_left == NULL)
		{
			TreeNode<T>* tmp = t->m_right;
			if(tmp == NULL)
				tmp = t->m_left;
			delete t;
			t = tmp;
			size--;
			return;
		}
		else//two children
		{
			t->m_data = recursiveMax(t->m_left);
			rcRemove(t->m_left, size, t->m_data);
		}
	}
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
	rcRemove(m_root, m_size, x);
	return;
}

//recursive part of preorder
template <typename T>
void rcPreOrder(TreeNode<T>* t)
{
	cout<<t->m_data<<endl;
	if(t->m_left != NULL)
		rcPreOrder(t->m_left);
	if(t->m_right != NULL)
		rcPreOrder(t->m_right);
		
	return;
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
	rcPreOrder(m_root);
	return;
}

//recursive part of postorder
template <typename T>
void rcPostOrder(TreeNode<T>* t)
{
	if(t->m_left != NULL)
		rcPostOrder(t->m_left);
	if(t->m_right != NULL)
		rcPostOrder(t->m_right);
	
	cout<<t->m_data<<endl;
	return;
}

template <typename T>
void MyBSTree<T>::printPostOrder() const
{
	rcPostOrder(m_root);
	return;
}

//recursive part of print()
template <typename T>
void prettyPrint(const TreeNode<T>* t, int pad)
{
	string s(pad, ' ');
	if(t == NULL)
		cout<<endl;
	else
	{
		prettyPrint(t->m_right, pad+4);
		cout<<s<<t->m_data<<endl;
		prettyPrint(t->m_left, pad+4);
	}
	return;
}

template <typename T>
void MyBSTree<T>::print() const
{
	prettyPrint(m_root, 0);
	return;
}



