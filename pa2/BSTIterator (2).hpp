#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

/**
 * Filename: BST.hpp
 * Name1: Derek Nguyen		htn047@ucsd.edu 	A10625099
 * Name2: Adrian Jimenez	adj006@ucsd.edu		A10748304
 *
 * Description: Construct a BSTIterator that traverses through the BST. 
 *
 * Date: Oct 11, 2013
 */

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ 
  BSTIterator(BSTNode<Data>* curr) : curr( curr ) {}

  /** Dereference operator. */
  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++() {
    curr = curr->successor();
    return *this;
  }

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /** Equality test operator. */ 
  bool operator==(BSTIterator<Data> const & other) const {
    return this->curr == other.curr;

  }

  /** Inequality test operator. */ 
  bool operator!=(BSTIterator<Data> const & other) const {
    return this->curr != other.curr;  
  }

};

#endif //BSTITERATOR_HPP
