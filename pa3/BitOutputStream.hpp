/*
 * Filename: BitOutputStream.hpp
 * Authors: Adrian Jimenez
 *          Ricardo Ambriz
 * Githubid: adj006
 *           rdambriz
 * Description:
 * Date: Nov. 15, 2013
 */

#ifndef BITOUTPUTSTREAM_HPP
#define BITOUTPUTSTREAM_HPP

#include <iostream>

using namespace std;

/*
 * A class, for bit output stream.
 */
class BitOutputStream
{

private:
	char buf;		// one byte buffer of bits
	int nbits;		// how many bits have been written to buf
	std::ostream & out;	// reference to the output steam to use

public:

	/*
	 * Initialize a BitOutputStream that will use
	 * the given osteam for output.
	 */
	BitOutputStream( std::ostream & os ) : out(os), buf(0), nbits(0)
	{
	  // clear buffer and bit counter
	}

	/*
	 * Send the buffer to the output, and clear it
	 */
	void flush()
	{
	  out.put(buf);
	  out.flush();
	  buf = nbits = 0;
	}
  void writeBit( int i );
};

#endif	// BITOUTPUTSTREAM_HPP
