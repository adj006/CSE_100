/*
 * Filename: uncompress.cpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description: This file takes in an input file and uncompresses it into
 *              an output file.
 * Date: Nov. 3, 2013
 */

#include "HCTree.hpp"

/*
 * This is the main driver for the uncompress method
 */
int main( int argc, char* argv[] )
{
  ifstream theFile;	// input file
  ofstream out;		// output file
  vector<int> freqs(256, 0);	// vector to store the count
  HCTree tree;
  theFile.open( argv[1], ios::binary );
  int i = 0;
  int count = 0;
  int outSize = 0;
  if(theFile.peek() == std::ifstream::traits_type::eof())
  {
    out.open(argv[2], ios::binary);
    theFile.close();
    out.close();
    return 0;
  }
  if( theFile.good() && theFile.is_open() )
    for( i = 0; i < freqs.size(); i++ )
    {
      theFile >> count;	// reads the bytes from input file
      freqs[i] = count;	
      outSize += count;	// calculates the size of the output file
    }
  tree.build(freqs);
  theFile.get();
  BitInputStream in1 = BitInputStream(theFile);
  out.open(argv[2], ios::binary);
  for( i = 0; i < outSize; i++ )
    out << (unsigned char)tree.decode( in1 );
  theFile.close();
  out.close();
  return 0;
}
