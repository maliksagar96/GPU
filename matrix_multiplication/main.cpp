/**

**/


#include <iostream>
#include <openacc.h>
#include <cstdlib>

using namespace std;

int main() {

  const int N = 1000000000;
  
  double* a = new double[N];
  double* b = new double[N];

  srand(42);

  
  for (size_t i = 0; i < N; i++) {
    a[i] = static_cast<float>(rand()) / RAND_MAX;
    b[i] = static_cast<float>(rand()) / RAND_MAX;
    // a[i] = 1;
    // b[i] = 1;
  }

double sum = 0;


  #pragma acc parallel loop reduction(+:sum)
  for (int i = 0; i < N; i++) {
    sum += a[i] * b[i];
  }

  cout<<"Dot Product  = "<<sum<<endl;

  delete[] a;
  delete[] b;


  return 0;
}