/*
  Generating 2 gangs to do the same task.

*/

#include <stdio.h>
#include <openacc.h>

void main() {
  #pragma acc parallel num_gangs(2)
  {
    printf("How many times would a Hello be generated.\n");
  }

}


