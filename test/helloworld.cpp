#include <stdio.h>
#include <iostream>

/** This is the prototype of VectorAdd_f32, VectorAdd_f64 ... */
#include <helloworld.hpp>

/** This is the template of VectorAdd<T> */
#include <VectorAdd.hpp>

using namespace std;

int main()
{
  using T = double;

  int n = 100;

  vector<T> a( n, 0 );
  vector<T> b( n, 1 );

  /** Use VectorAdd<T> template */
  vector<T> c= helloworld::VectorAdd<T>( a, b ); 

  /** Use VectorAdd_f64 */
  vector<double> c_f64 = helloworld::VectorAdd_f64( a, b );

  cout << "Hello world! c[ 0 ] = " <<  c[ 0 ] << " C_f64[ 0 ] = " << c_f64[ 0 ] << endl;

  return 0;
};
