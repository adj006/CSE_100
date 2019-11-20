/*
 * Filename: boggleutil.h
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 24, 2013
 */

#ifndef BOGGLEUTIL_H
#define BOGGLEUTIL_H

#include "baseboggleplayer.h"
#include "boggleboard.h"
#include <vector>


using namespace std;

//class BoggleUtil
//{


  /*class Die{
      string face;
      int row;
      int col;
      int loc;
      vector<Die*> neighbors;

  public:

      Die( )
      {

      }

      Die( string face ) {
          this->face = face;
      }*/
  //template<typename Data>
  class Node
  {
    public:
      /*Node( const string & s ) : s(s)
      {
        left = right = middle = parent = 0;
      }
      Node<Data>* left;
      Node<Data>* right;
      Node<Data>* middle;
      NOde<Data>* parent;
      string const data;
      bool is_end = false;
      Node<Data>* successor()
      {
        Node<Data>* curr = this;
        if( curr->right )
        {
          curr = curr->right;
          while( curr->left )
        }
      }*/
      Node() 
      {
        //child = NULL;
      }
      vector<Node> child(26, NULL);
      bool is_end = false;
  };
  class MT
  {
    public:
      Node<char>* root;

      MT() : root(0) { }

      virtual ~MT()
      {
        deleteAll(root);
      }
      void insert( string word );
      bool search( string word );
  };
//};

#endif // BOGGLEUTIL_H
