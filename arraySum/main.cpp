/**

This is my first code for parallel processing. There are some of the things we can learn form this simple code. 
1) When I am using vector<float> i am getting the error CUDA_ERROR_ILLEGAL_ADDRESS. I don't understand the reason fully yet. Hence I wil have to use raw pointers. 
2) Then I checked tried to push the limits of the the memeory. I increased the size N to 500 Million. A single float takes 4 bytes of memory. If i take 500 million such eelemts and then I use
3 arrays of such kind it is taking the memory of approximateyly 6 GB. My GPU is of 4GB. 
3) The conversion of serial to parallel code is very easy. But the performance is not that great. the increase in speed is not even 2 times. The performance is comapartively better for larger N. 
4) For smaller sized arrays the performance is worse as the memory trasnfer overhead becomes too large. 
5) Comparison with MPI and openMP is remaining. 
6) Also I would run this on larger system such as parambramha.  

*/

#include <iostream>
#include <cstdlib>
#include <openacc.h>
#include <vector>

using namespace std;

int main() {

//Increase te size 
 size_t N = 5000000; // 500 million elements
  
  float* a = new float[N];
  float* b = new float[N];
  float* c = new float[N];

  srand(42);
  for (size_t i = 0; i < N; i++) {
    a[i] = static_cast<float>(rand()) / RAND_MAX;
    b[i] = static_cast<float>(rand()) / RAND_MAX;
  }
  
  #pragma acc parallel loop
  for (size_t i = 0; i < N; i++) {
    c[i] = a[i] + b[i];
  }

  for (int i = 0; i < 10; i++) {
    cout << c[i] << endl;
  }

  return 0;
}
