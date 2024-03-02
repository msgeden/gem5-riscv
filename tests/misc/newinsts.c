#include <stdio.h>
#include <stdlib.h>
int main(){
  long a=7;
  asm volatile("mov   x0, 112");
  asm volatile("mov   x1, 133");
  asm volatile("mod   x1, x0, x1");
  asm volatile("str x1, [sp, 24]");
  printf("Hello from AArch64 with ASM %ld\n",a);
  return 0;
}
