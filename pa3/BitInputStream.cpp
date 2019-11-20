/*
 * Filename: BitInputStream.cpp
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
#include "BitInputStream.hpp"

/*
 * Read the next bit from the bit buffer.
 * Fill the buffer from the input stream first if needed.
 * Return 1 if the bit read is 1;
 * Return 0 if the bit read is 0;
 */
int BitInputStream::readBit()
{
  // If all bits in the buffer are read, fill the buffer first
  if( nbits == 8 )
    fill();

  // Get the bit at the appropriate location in the bit buffer, and return the approptriate int
  int bit = ( (buf >> (7 - nbits)) & 1 );

  // Increment the index
  nbits++;

  return bit;
}
