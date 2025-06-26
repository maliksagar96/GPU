/*
  Async usage

  The #pragma acc parallel kernel automatically comes with an implicit barrier command which is pragma acc wait. 
  When we write asynch command then the barrier is removed. In such a case the CPU doesn't wait for the GPU. 
  One interesting experiment is to see what will happen if you place async at the end of both the kernels and doesn't place acc wait anywhere in the code. 

*/

#include <stdio.h>
#include <openacc.h>

void main() {

  #pragma acc parallel num_gangs(10) async
  {
    printf("Hello.\n");
    printf("Bye.\n");
  }

  printf("Host\n");
  
  #pragma acc parallel num_gangs(3) async
  {
    printf("One\n");
    printf("Two\n");
  }

  printf("Last Command");

  

}


