/*
  
*/

#include <stdio.h>
#include <openacc.h>

void main() {

  #pragma acc parallel if(3<2) num_gangs(10) 
  {
    printf("Hello.\n");    
  }

 

}


