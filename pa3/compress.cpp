/*
 * FIlename: compress.cpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description: This file takes in an input file and compresses it into an
 *              output file.
 * Date: Nov. 3, 2013
 */

#include "HCTree.hpp"


/*
 * This is the main driver for the compress method
 */
int main( int argc, char* argv[] )
{
  ifstream theFile;	// input file
  ofstream out;		// output file
  unsigned char nextChar;
  theFile.open(argv[1], ios::binary);
  if(theFile.peek() == std::ifstream::traits_type::eof())
  {
    out.open(argv[2], ios::binary);
    theFile.close();
    out.close();
    return 0;
  }
  vector<int> freqs(256, 0);	// vector to store the count
  while ( 1 )
  {
    // To read in one character at a time
    nextChar = theFile.get();
    // breaks out if it reaches the end of the file
    if(!theFile.good())
      break;
    freqs[(int)nextChar]++;
  }
  theFile.close();
  HCTree tree;
  tree.build(freqs);
  out.open(argv[2], ios::binary);
  int i;
  for( i = 0; i < freqs.size(); i++ )
    out << freqs[i] << " ";
  out.flush();
  BitOutputStream out2 = BitOutputStream(out);
  theFile.open(argv[1], ios::binary);
  while( 1 )
  {
    nextChar = theFile.get();
    if(!theFile.good())
      break;
    tree.encode(nextChar, out2);
  }
  out2.flush();
  theFile.close();
  out.close();
  return 0;
}
