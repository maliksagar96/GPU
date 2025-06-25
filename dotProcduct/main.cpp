#include <iostream>
#include <openacc.h>
#include <cstdlib>

using namespace std;

int main() {

  const int N = 100000000;
  
  float* a = new float[N];
  float* b = new float[N];

  srand(42);

  
  for (size_t i = 0; i < N; i++) {
    a[i] = static_cast<float>(rand()) / RAND_MAX;
    b[i] = static_cast<float>(rand()) / RAND_MAX;
  }

  float sum = 0;

#pragma acc data copyin(a[0:N], b[0:N])
{
  #pragma acc parallel loop reduction(+:sum)
  for (int i = 0; i < N; i++) {
    sum += a[i] * b[i];
  }
}


  cout<<"Dot Product  = "<<sum<<endl;

  delete[] a;
  delete[] b;


  return 0;
}