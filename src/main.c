#include <stdio.h>

int main(int argc, char **argv) {
  printf("Hello, C!\n");

#ifndef BUILD_DEBUG
  printf("Release build...\n");
#else
  printf("Debug build...\n");
#endif

  return 0;
}
