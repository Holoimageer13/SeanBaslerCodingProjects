//Name: Sean Basler Section: B
#ifndef MYBSTREE_H
#define MYBSTREE_H

#include<iostream>
#include<string>
#include "abstractbstree.h"

using namespace std;

template <typename T>
struct TreeNode
{
	T m_data;
	TreeNode<T>* m_right;
	TreeNode<T>* m_left;
	
	//constructor
	TreeNode() : m_right(NULL), m_left(NULL) {};
	
	//parametered constructor
	TreeNode(T data, TreeNode* right, TreeNode* left);
};

template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
	TreeNode<T>* m_root;
	int m_size;
	
	public:
		//constructor
		MyBSTree();
		
		//destructor
		~MyBSTree();
		
		//operator equals
		MyBSTree<T>& operator=(const MyBSTree<T>& rhs);
		
		//copy constructor
		MyBSTree(MyBSTree<T>& rhs);
		
		// Purpose: Accessor function for the number of elements in the tree
		// Returns: number of elements in the tree
		int size() const;
		
		// Purpose: Checks if a tree is empty
		// Returns: 'true' if the tree is empty
		//     'false' otherwise  
		bool isEmpty() const;
		
		// Purpose: Returns the height of the tree
		// Returns: height the tree
		//int recursiveHeight(const TreeNode<T>* t); 
		int height() const;
		
		// Purpose: finds the maximum element in the Tree
		// Returns: a const reference to the maximum element
		// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
		//const T& recursiveMax(const TreeNode<T>* t);
		const T& findMax() const throw (Oops);
		
		// Purpose: finds the minimum element in the Tree
		// Returns: a const reference to the minimum element
		// Exception: if the tree is empty, THROW a 'Oops' object with an error message!!!
		//const T& recursiveMin(const TreeNode<T>* t);
		const T& findMin() const throw (Oops);
		
		// Purpose: finds an element in the Tree
		// Parameters: x is value to be found 
		// Returns: 
		//     If The tree contains x then  
		//         return N, the level of the node containing x
		//         (the root is considered level 1)
		//     If The tree does not contains x then  
		//         return -N, where N is the level of the tree reached in the search 
		//int recursiveFind(const TreeNode<T>* t, const T& x, int& level);
		int find(const T& x) const;
		
		
			
		  /*** ---- Mutator Operations ---- */
		  
		// Purpose: Clears the Tree
		// Postconditions: an empty Tree
		void clear();
		
		// Purpose: Inserts an element into a tree
		// Parameters: x is value to be added to the tree
		// Postconditions: The tree now contains x
		//     if the tree already contains x, ignore insertion
		//void recursiveInsert(TreeNode<T>* t, int& size, const T& x);
		void insert(const T& x);
			
		// Purpose: Removes an element from the tree
		// Parameters: x, the element to remove
		// Postconditions: the tree does not contains x
		//void rcRemove(TreeNode<T>* t, int& size, const T& x);
		void remove(const T& x);
				  
			 
		  /*** ---- Output Operations ---- */
		
		// Purpose: Prints the Tree in Pre-Order 
		//void rcPreOrder(TreeNode<T>* t);   
		void printPreOrder() const;
		
		// Purpose: Prints the Tree in Pre-Order    
		//void rcPostOrder(TreeNode<T>* t);
		void printPostOrder() const; 
		
		
		// Purpose: Prints the Tree In-Order with formatting
		//     each level indented 4 spaces, one element per line   
		//void prettyPrint(const TreeNode<T>* t, int pad); 
		void print() const;
};

#include "mybstree.hpp"

#endif
