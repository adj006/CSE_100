/**
 * Filename: benchtree.cpp
 * Name1: Derek Nguyen		htn047@ucsd.edu 	A10625099
 * Name2: Adrian Jimenez	adj006@ucsd.edu		A10748304
 *
 * Description: This program is to determine how efficient our implementaion
 *              of BST and RST where by calculating the average comparisons it
 *              takes to find an element in the tree. 
 *
 *
 * Date: Oct 22, 2013
 */
#include "BST.hpp"
#include "RST.hpp"
#include "countint.hpp"
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <string.h>

using namespace std;

/*
 * This is our main driver for this program. It determines what type of tree
 * it is. Once it knows what it is it then branches into the specified
 * instructions for the type.
 */
int 
main(int argc, char* argv[] )
{  
  vector<countint> v;

  
  BST<countint> *tree; 
  set<countint> *set; 

  int runs = 0;
  int size = 0;
  
  // Checks if user is using the program correctly
  if( argc != 5 )
  {
    cout << "Please inserts 4 arguments in the command prompt" << endl;
    return -1;
  } 
  else
  {
    runs = strtol(argv[4], NULL, 10);
    size = strtol(argv[3], NULL, 10);
  
    if( strcmp(argv[1], "bst") == 0) {
      tree =  new BST<countint>();
    }
    else if( strcmp(argv[1], "rst") == 0) {
      tree =  new RST<countint>();
    }
    else if( strcmp(argv[1], "set") == 0) {
      set = new std::set<countint>();
    }
    else
    {
      cout << "What tree you wanna execute? (bst, rst, or set)" << endl;
      return -1;
    }
   
    if(strcmp(argv[2], "sorted") == 0) 
    {
      // The tree already sorted
    }
    else if( strcmp(argv[2], "shuffled") == 0) 
    {
      random_shuffle( v.begin(), v.end() );
    }
    else
    {
      cout << "What do you want to do with the tree?" << endl;
      return -1;
    }
    
    if( size < 1 || runs  < 1 )
    {
      cout << "Please insert a positive number" << endl;
      return -1;
    }
    cout << 
  " # Benchmarking average number of comparisons for successful find\n"
  " # Data structure: " << argv[1] << "\n"
  " # Data: " << argv[2] << "\n"
  " # N is powers of 2, minus 1, from 1 to " << size << "\n"
  " # Averaging over " << runs << " runs for each N\n" 
  " #" << setw(10) << "N" << setw(20) << "Navgcomps" << setw(20) << "stdev" << endl;
  }

  for(int N = 1; N < size; N = N*2 + 1) 
  {
    double runtime = 0;
    double runtime_squr = 0;
    for( int i = 1; i <= runs; i++ ) {
      // Create  a vector for each trial.
      std::vector<countint> v;
      v.clear();
      for( int i = 0; i < N; ++i ) {
        v.push_back(i);
      }
    
      // Insert the keys in the vector in an empty structure of the appropriate kind:
      std::vector<countint>::iterator vit = v.begin();
      std::vector<countint>::iterator ven = v.end();
    
      for( vit = v.begin(); vit != ven; ++vit) {
        if( strcmp(argv[1], "bst") == 0 || strcmp(argv[1], "rst") == 0 )
          tree->insert( *vit );
        else
          set->insert( *vit );
      }
     
       // Find comparisons
       countint::clearcount();
       for( vit = v.begin(); vit != ven; ++vit ) {
         if( strcmp(argv[1], "bst") == 0 || strcmp(argv[1], "rst") == 0 )
          tree->find( *vit );
        else
          set->find( *vit );
       }
       double avgcomps = countint::getcount() / (double)N;
       runtime += avgcomps;
       runtime_squr += pow( avgcomps, 2 );  
    }
    runtime = runtime / runs;
    runtime_squr = runtime_squr / runs;
    double a = pow(runtime, 2);
    double b = abs(runtime_squr - a);
    double stdev = pow( b, 0.5);
    cout << setw(10) << N << setw(20) << runtime << setw(20) << stdev << endl;
  }
 
  return 0;
}
