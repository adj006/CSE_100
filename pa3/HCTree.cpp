/*
 * Filename: HCTree.cpp
 * Author: Adrian Jimenez
 *         Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 3, 2013
 */

#include "HCTree.hpp"
#include <stack>

/** Use the Huffman algorithm to build a Huffman coding trie.
 *  PRECONDITION: freqs is a vector of ints, such that freqs[i] is
 *  the frequency of occurrence of byte i in the message.
 *  POSTCONDITION:  root points to the root of the trie,
 *  and leaves[i] points to the leaf node containing byte i.
 */
void HCTree::build(const vector<int>& freqs)
{
  int i;
  HCNode* min1;	// smallest count
  HCNode* min2;	// second smallest count
  HCNode* tree;
  // priority queue to store the forest
  std::priority_queue<HCNode*, std::vector<HCNode*>, HCNodePtrComp>  huff;
  for( i = 0; i < 256; i++ )
  {
    if( freqs[i] != 0 )
    {
      tree = new HCNode( freqs[i] , i );
      leaves[i] = tree;
      huff.push( tree ); 
    }
  }
  while( huff.size() > 1 )
  {
    min1 = huff.top();
    huff.pop();
    min2 = huff.top();
    huff.pop();
    min1->p = new HCNode( (min1->count+min2->count),
                          min1->symbol, min1, min2 );
    min2->p = min1->p;
    huff.push( min1->p );
  }
  root = huff.top();
}

HCNode* ptr;

/** Write to the given BitOutputStream
 *  the sequence of bits coding the given symbol.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
void HCTree::encode(byte symbol, BitOutputStream& out) const
{
  stack<int> s;
  ptr = leaves[symbol];
  while( ptr != root )
  {
    if( (ptr->p->c0) == ptr )
      s.push(0);
    else
      s.push(1);
    ptr = ptr->p;
  }
  while( !s.empty() )
  {
    out.writeBit(s.top());
    s.pop();
  }
}

/** Return symbol coded in the next sequence of bits from the stream.
 *  PRECONDITION: build() has been called, to create the coding
 *  tree, and initialize root pointer and leaves vector.
 */
int HCTree::decode(BitInputStream& in) const
{
  ptr = root;
  while( (ptr->c1) || (ptr->c0) )
  {
    if( in.readBit() == 1 )
      ptr = ptr->c1;
    else
      ptr = ptr->c0;
  }
  return ptr->symbol;
}
