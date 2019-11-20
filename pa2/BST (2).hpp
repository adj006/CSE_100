#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

/**
 * Filename: BST.hpp
 * Name1: Derek Nguyen		htn047@ucsd.edu 	A10625099
 * Name2: Adrian Jimenez	adj006@ucsd.edu		A10748304
 *
 * Description: Construct a BST. 
 *
 *
 * Date: Oct 11, 2013
 */
 using namespace std;
template<typename Data>
class BST {

protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ 
  virtual ~BST() {
    deleteAll(root);
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */
  virtual bool insert(const Data& item) {
    //Verify the existence of a BST
    if( !root )
    {
      // Create the root for a new BST
      root = new BSTNode<Data>( item );
      isize++;
      return true;
    }
    else
    {
      BSTNode<Data> *curr = root;
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
            isize++;
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
            isize++;
            return true;
          }
        }
        else
          return false;
      }
    }
    return false;
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items.
   */
  iterator find(const Data& item) const {
    //Verify the existence of a BST
    if( !root )
    {
      return end();
    }
    else
    {
      BSTNode<Data> *curr = root;
      // Travel along the BST to search for the data item
      while( curr )
      {
        if( item < curr->data )
        { 
          curr = curr->left;
        }
        else if ( curr->data < item )
          curr = curr->right;
        else 
          return typename BST<Data>::iterator(curr);  
      } 
      return end();
    }     
  }

  
  /** Return the number of items currently in the BST.
   */ 
  unsigned int size() const {
    return isize;
  }

  /** Return true if the BST is empty, else false.
   */ 
  bool empty() const {
    if(isize==0)
      return true;
    else
      return false;
  }

  /** Return an iterator pointing to the first item in the BST.
   */ 
  iterator begin() const {
    return typename BST<Data>::iterator( first( root ) );
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */
  void inorder(BSTNode<Data>* n) const {
    if(n==0) return;
    inorder(n->left);
    std::cout << *n << std::endl;
    inorder(n->right);
  }

  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  // do a postorder traversal, deleting nodes
  static void deleteAll(BSTNode<Data>* n) {
    if (0 == n) return;
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }
  
  
 };


#endif //BST_HPP
