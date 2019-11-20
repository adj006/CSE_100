/*
 * Filename: BitOutputStream.cpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 15, 2013
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "BitOutputStream.hpp"

/*
 * Write the least significant bit of the argument to
 * the bit buffer, and increment the bit buffer index.
 * But flush the buffer first, if it is full.
 */
void BitOutputStream::writeBit( int i )
{
  // Is the bit buffer full? Then flush it
  if( nbits == 8 )
    flush();

  // Write the least significant bit of i into the buffer at the current index
  buf = buf | ( i << (7 - nbits) );
  
  // Increment the index
  nbits++;
}
