/*
What is pgcc compiler?

Compile with:
pgcc -acc hello.c

You'll have to tell the compiler to accelarate your code.

*/

#include <stdio.h>

int main() {

  #pragma acc parallel loop
  for(int i = 0;i < 100;i++) {
      printf("Hello World %d\n", i);
  }

  return 0;
}