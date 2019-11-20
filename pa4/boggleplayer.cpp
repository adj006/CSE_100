/*
 * Filename: boggleplayer.cpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 24, 2013
 */

#include "boggleplayer.h"
//#include "boggleboard.h"
#include <string.h>
#include <string>
#include "boggleutil.h"

BogglePlayer::BogglePlayer()
{

}

BogglePlayer::~BogglePlayer()
{
  clearBoard();
}

void BogglePlayer::setBoard(unsigned int rows, unsigned int cols, string** diceArray)
{
  if( isBoardSet )
    clearBoard();
  ROWS = rows;
  COLS = cols;
  for(int i = 0; i < ROWS; i++)
    for(int j = 0; j < COLS; j++)
    {
      board.push_back(toLowercase(diceArray[i][j]));
      isUsed.push_back(false);
    }
  isBoardSet = true;
}

vector<int> BogglePlayer::isOnBoard(const string& word_to_check)
{
  vector<int> path;
  string word = toLowercase(word_to_check);
  for(int i = 0; i < ROWS; i++)
    for(int j = 0; j < COLS; j++)
      if(traverseBoard(word, i, j, path))
        return path;
  return path;
}

bool BogglePlayer::traverseBoard(const string &word, int row, int col,
                                 vector<int> &path)
{
  int index = getIndex( row, col );
  if( index < 0 || index >= (int)board.size() )
    return false;
  if( isUsed[index] )
    return false;
  string curr = board[index];
  int currLen = (int)curr.length();
  int wordLen = (int)word.length();
  if( currLen > wordLen )
    return false;
  if( word.substr(0, currLen) != curr )
    return false;
  path.push_back(index);
  if( wordLen == currLen )
    return true;
  isUsed[index] = true;
  string restStr = word.substr(currLen);
  static int step[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
  for( int i = 0; i < 8; i++ )
  {
    bool res = traverseBoard(restStr, row + step[i][0], col + step[i][1], path);
    if( res )
    {
      isUsed[index] = false;
      return true;
    }
  }
  isUsed[index] = false;
  path.pop_back();
  return false;
}

int BogglePlayer::getIndex(int row, int col)
{
  if( row < 0 || col < 0 || row >= ROWS || col >= COLS )
    return -1;
  return row * COLS + col;
}

string BogglePlayer::toLowercase(string str)
{
  string result;
  int len = (int)str.length();
  for(int i = 0; i < len; i++)
    result += tolower(str[i]);
  return result;
}

void BogglePlayer::clearBoard()
{
  isBoardSet = false;
  board.clear();
  isUsed.clear();
}

void BogglePlayer::getCustomBoard(string** &new_board, unsigned int *rows,
				  unsigned int *cols)
{
  //setBoard( rows, cols, new_board );
}

bool BogglePlayer::getAllValidWords(unsigned int minimum_word_length,
				    set<string>* words)
{
  if(!isBoardSet || !isBuildLexicon )
    return false;
  else
  {
    for( int i = 0; i < ROWS; i++ )
    {
      for( int j = 0; i < COLS; j++ )
      {
        if( searchBoard( minimum_word_length, words, i, j, isVisited ) )
	  
      }
    }
  }
}
bool BogglePlayer::searchBoard( unsigned int min_len, set<string>& words,
                                int row, int col, vector<bool> isVisited, )
{
  int index = getIndex( row, col );
  if( index < 0 || index >= (int)board.size() )
    return false;
  if( isUsed[index] )
    return false;
  string curr = board[index];
  string word += curr;
  //int currLen = (int)curr.length();
  //int wordLen = (int)word.length();
  //if( currLen > wordLen )
    //return false;
  //if( word.substr(0, currLen) != curr )
    //return false;
  //if( wordLen == currLen )
    //return true;
  isUsed[index] = true;
  //string restStr = word.substr(currLen);
  static int step[8][2] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
  for( int i = 0; i < 8; i++ )
  {
    bool res = searchBoard(min_len, words, row + step[i][0], col + step[i][1],
                           isVisited);
    if( res )
    {
      isUsed[index] = false;
      return true;
    }
  }
  isUsed[index] = false;
  if( words.size() >= minimum_word_length && isInLexicon( it ) )
  {
  }
  return false;
}

bool BogglePlayer::isInLexicon(const string& word_to_check)
{
  MT t = new MT();
  bool val = false;
  val = t.search( word_to_check );
  //~MT();
  return val;
}

void BogglePlayer::buildLexicon(const set<string>& word_list)
{
  MT t = new MT();
  for( set<string>::iterator it = word_list.begin(); it != word_list.end(); 
       it++ )
    t.insert( *it );
  //~MT();
  isBuildLexicon = true;
}
