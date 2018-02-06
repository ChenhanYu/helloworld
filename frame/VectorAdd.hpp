#ifndef VECTORADD_HPP
#define VECTORADD_HPP

#include <iostream>
#include <vector>

/** Use STL namespace */
using namespace std;


namespace helloword
{

template<typename T>
vector<T> VectorAdd( vector<T> &a, vector<T> &b )
{
  /** Assert that the lengths are the same */
  assert( a.size() == b.size() );

  /** Allocate vector<T> c */
  vector<T> c( a.size() );

  /** Version#1: index base */
  for ( int i = 0; i < c.size(); i ++ ) c[ i ] = a[ i ] + b[ i ];

  /** Version#2: iterator */
  for ( auto ita  = a.begin(), itb  = b.begin(), itc  = c.begin();
             ita != a.end(),   itb != c.end(),   itc != c.end();
             ita ++,           itb ++,           itc ++ )
  {
    (*c) = (*a) + (*b);
  }

  /** Return c and exit */
  return c;
};

}; /** end namespace helloword */

#endif /** define VECTORADD_HPP */
