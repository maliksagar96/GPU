

#include <stdio.h>
#include <openacc.h>

void main() {

  #pragma acc kernels
  {
    printf("Hello.\n");    
  }

 

}


