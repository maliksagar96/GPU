/**

This is my first code for parallel processing. There are some of the things we can learn form this simple code. 


*/



#include <iostream>
#include <cstdlib>
#include <openacc.h>
#include <vector>

using namespace std;

int main() {

 size_t N = 50000000; // 500 million elements
  
  // float* a = new float[N];
  // float* b = new float[N];
  // float* c = new float[N];

  vector<float> a(N,0), b(N,0), c(N,0);

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
