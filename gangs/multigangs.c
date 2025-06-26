/*
  This is nice simple code to understand some of the things. 

  1) The instructions in the pragma{} are sequential. They don't run in parallel. First a gang will print hello then it would print bye. 
  2) Bye from a different gang might get printed before hello from some other gang but it can print bye before printing the hello in the same gang.
  3) Host can't get printed before Hello. Every pragma inherently comes with a barrier by default.

*/

#include <stdio.h>
#include <openacc.h>

void main() {

  #pragma acc parallel num_gangs(10)
  {
    printf("Hello.\n");
    printf("Bye.\n");
  }
  printf("Host\n");

  #pragma acc parallel num_gangs(3) 
  {
    printf("One\n");
    printf("Two\n");
  }

}


