/*
 * Filename: boggleutil.cpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 24, 2013
 */

#include "boggleutil.h"

void MT::insert( string word )
{
  Node<char>* curr = root;
  for( unsigned int i = 0; i < word.length(); i++ )
  {
    int letter = (int)word[i] - (int)'a';
    if( curr->child[letter] == NULL )
    {
      curr->child[letter].push_back(letter);
      if( i == word.length() - 1 )
        break;
      else
        curr->child[letter] = new node();
    }
    curr = curr->child[letter];
  }
  curr->is_end = true;
}

bool MT::search( string word )
{
  Node<char>* curr = root;
  int i = 0;
  while( i < word.length() )
  {
    int letter = (int)word[i] - (int)'a';
    if( curr->child[letter] == word[i] )
    {
      if( (curr.is_end) && (i == word.length() - 1) )
        return true;
      else
      {
        curr = curr->child[letter];
        i++;
      }
    }
    else
    {
      return false;
    }
  }
  return false;
}
