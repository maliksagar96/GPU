#include <stdio.h>
#include <cuda.h>

int main(void) {
  cudaDeviceProp prop;
  int count, devNum;
  cudaGetDeviceCount(&count);
  printf(" Number of devices = %d\n", count);
  cudaGetDevice(&devNum);
  printf(" Device Number = %d\n", devNum);

  for(int i = 0;i<count;i++) {
    cudaGetDeviceProperties(&prop, i);
    printf("\n Name:%s", prop.name);
    printf("\n Clock Rate = %d", prop.clockRate);
    printf("\n Device copy overlap:");
    if(prop.deviceOverlap) { printf("\t Enabled");}
    else{printf("\t Disabled");}
    printf("\n Kernel execution Timeout:");
    if(prop.kernelExecTimeoutEnabled) {printf("Enabled\n");}
    else{printf("Disabled\n");}
    printf("\n Global Memory: %ld", prop.totalGlobalMem);
    printf("\n Constant Memory: %ld", prop.totalConstMem);
    printf("\n Max Texture MemID: %d", prop.maxTexture1D);
  }


  return;
}