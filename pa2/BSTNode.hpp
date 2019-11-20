#ifndef BSTNODE_HPP
#define BSTNODE_HPP
#include <iostream>
#include <iomanip>
#include <stdlib.h>

/**
 * Name1: Derek Nguyen		htn047@ucsd.edu 	A10625099
 * Name2: Adrian Jimenez	adj006@ucsd.edu		A10748304
 *
 * Description: BSTNode is used to contruct the BST. 
 *
 * Date: Oct 11, 2013
 */
 
template<typename Data>
class BSTNode {

public:

  /** Constructor.  Initialize a BSTNode with the given Data item,
   *  no parent, and no children.
   */
  BSTNode(const Data & d) : data(d) {
    left = right = parent = 0;
  }

  BSTNode<Data>* left;
  BSTNode<Data>* right;
  BSTNode<Data>* parent;
  Data const data;   // the const Data in this node.
  unsigned int priority;

  /** Return the successor of this BSTNode in a BST, or 0 if none.
   ** PRECONDITION: this BSTNode is a node in a BST.
   ** POSTCONDITION:  the BST is unchanged.
   ** RETURNS: the BSTNode that is the successor of this BSTNode,
   ** or 0 if there is none.
   */ 
  BSTNode<Data>* successor() {
    BSTNode<Data> *curr = this;
    // Verify the right child
    if( curr->right )
    {
      curr = curr->right;
      //Verify the left child
      while( curr->left )
      {
        curr = curr->left;
      }
      return curr;
    }
    
    // Verify the parent node
    while( curr->parent )
    {
      if( curr == curr->parent->left )
      {
        return curr->parent;
      }
      curr = curr->parent;
    }
    return 0;
  }
}; 

/** Overload operator<< to print a BSTNode's fields to an ostream. */
template <typename Data>
std::ostream & operator<<(std::ostream& stm, const BSTNode<Data> & n) {
  stm << '[';
  stm << std::setw(10) << &n;                 // address of the BSTNode
  stm << "; p:" << std::setw(10) << n.parent; // address of its parent
  stm << "; l:" << std::setw(10) << n.left;   // address of its left child
  stm << "; r:" << std::setw(10) << n.right;  // address of its right child
  stm << "; d:" << n.data;                    // its data field
  stm << ']';
  return stm;
}

#endif // BSTNODE_HPP
