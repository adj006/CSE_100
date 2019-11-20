/*
 * Filename: boggleplayer.h
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 24, 2013
 */

#ifndef BOGGLEPLAYER_H
#define BOGGLEPLAYER_H

#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <ctype.h>
//#include <bool.h>
#include "baseboggleplayer.h"
#include "boggleboard.h"

using std::vector;
using std::set;
using std::string;

/**
 *  The base class for any computer Boggle player.
 *  Subclass this, and provide definitions for all the
 *  public pure virtual member functions shown.
 *  See the README for detailed documentation on these functions.
 */
class BogglePlayer: public BaseBogglePlayer {

  private:
    bool isBuildLexicon;
    bool isBoardSet;
    vector<string> board;
    vector<bool> isUsed;
    vector<bool> isVisited; 
    int getIndex(int row, int col);
    void clearBoard();
    string toLowercase(string st);
    bool traverseBoard(const string &word, int row, int col, vector<int> &path);
    bool searchBoard(unsigned int min_len, set<string>& words,
                     vector<bool>& isVisited);
    int ROWS;
    int COLS;

  public:
    //static const int ALPHABET_SIZE = 26;
    BogglePlayer(); 
    ~BogglePlayer();
    void buildLexicon(const set<string>& word_list);
    void setBoard(unsigned int rows, unsigned int cols, string** diceArray);
    bool getAllValidWords(unsigned int minimum_word_length, set<string>* words);
    bool isInLexicon(const string& word_to_check);
    vector<int> isOnBoard(const string& word_to_check);
    void getCustomBoard(string** &new_board, unsigned int *rows,
                        unsigned int *cols);
};

#endif // BOGGLEPLAYER_H
