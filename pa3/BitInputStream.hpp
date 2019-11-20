/*
 * Filename: BitInputStream.hpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 15, 2013
 */

#ifndef BITINPUTSTREAM_HPP
#define BITINPUTSTREAM_HPP

#include <iostream>


using namespace std;

/*
 * A class, for bit input stream.
 */
class BitInputStream
{

private:
	char buf;		// one byte buffer of bits
	int nbits;		// how many bits have been written to buf
	std::istream & in;	// reference to the input steam to use

public:

	/*
	 * Initialize a BitInputStream that will use
	 * the given isteam for input.
	 */
	BitInputStream( std::istream & is ) : in(is)
	{
	  buf = 0;	// clear buffer
	  nbits = 8;	// initialize bit index
	}

	/*
	 * buffer is set to the first line in the input file, and clear it
	 */
	void fill()
	{
	  buf = in.get();
	  nbits = 0;
	}
  int readBit();
};

#endif	// BITINPUTSTREAM_HPP
