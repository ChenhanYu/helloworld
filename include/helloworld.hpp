#ifndef HELLOWORLD_HPP
#define HELLOWORLD_HPP

#include <vector>

using namespace std;

namespace helloworld
{

vector<float> VectorAdd_f32( vector<float> &a, vector<float> &b );
vector<double> VectorAdd_f64( vector<double> &a, vector<double> &b );
vector<int> VectorAdd_d32( vector<int> &a, vector<int> &b );

}; /** end namespace helloworld */

#endif /** define HELLOWORLD_HPP */
