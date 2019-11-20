#ifndef RST_hpp
#define RST_hpp
#include "BST.hpp"
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <stdlib.h>
#include <ctime>
#include<iostream>
/**
 * FileName: RST.hpp
 * Name1: Derek Nguyen 		htn047@ucsd.edu		A10625099
 * Name2: Adrian Jimenez	adj006@ucsd.edu		A10748304
 *
 * Description: Construct a RST which contains inserted data as well as 
 * 		random priority (key).
 *
 * Date: Oct. 25, 2013.
 */

using namespace std;
template <typename Data>
class RST : public BST<Data> {

private:
 /** 
   * Function prototype:
   *    void
   *    leftRotation( BSTNode<Data> *curr ).
   * 
   * Description: This fucntion is used to rotate (exchange) the nodes in the
   * 		  RST so that it has descending order of priority. The funcion
   * 		  will perform left rotation if the parent has smaller priority
   * 		  than its right child.
   *
   * Parameter:
   * 	*curr -- pointer points to higher priority.
   *
   * Precondition:
   *    The parent's priority is smaller than the child's priority.
   *
   * Postcondition:
   *    The parent's priority is higher than its child's priority.
   */
  void leftRotation ( BSTNode<Data> *curr )
  {
    BSTNode<Data> *child = curr->right;
    child->parent = curr->parent;
    if( child->parent != NULL )   {
      if( child->parent->left == curr )   {
        child->parent->left = child;
      }
      else {
        child->parent->right = child;
      }
    }
    curr->right = child->left;
    
    if( curr->right != NULL )    {
      curr->right->parent = curr;
    }
    curr->parent = child;
    if( curr == BST<Data>::root )    {
      BST<Data>::root = curr;
      BST<Data>::root->parent = NULL;
    }
    child->left = curr;
  }
  
   /** 
   * Function prototype:
   *    void
   *    rightRotation( BSTNode<Data> *nodeBellow, BSTNode<Data> *nodeAbove ).
   * 
   * Description: This fucntion is used to rotate (exchange) the nodes in the
   * 		  RST so that it has descending order of priority. The funcion
   * 		  will perform right rotation if the parent has smaller priority
   * 		  than its left child.
   *
   * Parameter:
   * 	*nodeBelow  -- pointer points to higher priority.
   * 	*nodeAbove  -- pointer points to smaller priority.
   *
   * Precondition:
   *    The parent's priority is smaller than the child's priority.
   *
   * Postcondition:
   *    The parent's priority is higher than its child's priority.
   */  
  void right ( BSTNode<Data> *curr )
  {
    BSTNode<Data> *child = curr->left;
    child->parent = curr->parent;
    if( child->parent != NULL )    {
      if( child->parent->left == curr )      {
        child->parent->left = child;
      }
      else {
        child->parent->right = child;
      }
    }
    curr->left = child->right;
    if( curr->left != NULL )    {
      curr->left->parent = curr;
    }
    curr->parent = child;
    if( curr == BST<Data>::root )    {
      BST<Data>::root = child;
      BST<Data>::root->parent = NULL;
    }
    child->right = curr;
  }
  
  void bubble(BSTNode<Data> *curr )
  {
    while( curr->parent != NULL && curr->parent->priority > curr->priority )
    {
      if( curr->parent->right == curr )
        leftRotation(curr->parent);
      else 
        right(curr->parent);
    }
    if( curr->parent == NULL )
    {
      BST<Data>::root = curr;
    }
  }

public:

  /**
   * Function prototype:
   * 	virtual bool insert( const Data &item ).
   *
   * Description: Given a reference to a Data item, insert a copy of it 
   * 		  in the RST.
   *
   * Parameter:
   * 	&item -- reference copied data.
   *
   * Return:
   *  	true: if the item data was added to the RST.
   *  	false: if there is same data in the RST.
   *
   * Precondition: 
   * 	None
   *
   * Postcondition: 
   * 	the RST size is increased by 1. 
   *   
   */
  virtual bool insert(const Data& item) {
    //Verify the existence of a BST
    if( !BST<Data>::root )
    {
      // Create the root for a new BST
      srand(time(NULL));
      BST<Data>::root = new BSTNode<Data>( item );
      BST<Data>::root->priority = rand() % 30;
      BST<Data>::isize++;
      return true;
    }
    else
    {
      BSTNode<Data> *curr = BST<Data>::root;
      while( curr )
      {
        if( item < curr->data )
        {
          if( curr->left ) {
            curr = curr->left;            
          }
          else {
            curr->left = new BSTNode<Data>(item);
            curr->left->parent = curr;
            BST<Data>::isize++;
            curr = curr->left;
            curr->priority = rand();
            bubble( curr );
            return true;
          }
        }
        else if( curr->data < item ) {
          if( curr->right ) {
            curr = curr->right;
          }
          else {
            curr->right = new BSTNode<Data>(item);
            curr->right->parent = curr;
            BST<Data>::isize++;
            curr = curr->right;
            curr->priority = rand();
            bubble( curr );
            return true;
          }
        }
        else
          return false;
      }
    }
    return false;
  }
};

#endif // RST_HPP


