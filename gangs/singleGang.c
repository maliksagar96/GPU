/*
  What this code is doing is that it generates a single Gang to do such a task. 
  Hence the output hello is generated only once. 

*/

#include <stdio.h>
#include <openacc.h>

void main() {
  #pragma acc parallel 
  {
    printf("Hello");
  }

}


