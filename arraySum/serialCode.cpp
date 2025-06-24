#include <iostream>
#include <vector>
#include <cstdlib>
#include <openacc.h>

using namespace std;

int main() {

  size_t N = 5000000; // 500 million elements
  vector<float> a(N, 0), b(N, 0), c(N, 0);

  srand(42);  // fixed seed for reproducibility

  // CPU-side random initialization
  for (size_t i = 0; i < N; i++) {
    a[i] = static_cast<float>(rand()) / RAND_MAX;
    b[i] = static_cast<float>(rand()) / RAND_MAX;
  }

  // Explicitly manage GPU data movement
  #pragma acc data copyin(a[0:N], b[0:N]) copyout(c[0:N])
  {
    #pragma acc parallel loop
    for (size_t i = 0; i < N; i++) {
      c[i] = a[i] + b[i];
    }
  }

  // Print first 10 results
  // for (int i = 0; i < 10; i++) {
  //   cout << c[i] << endl;
  // }

  return 0;
}
