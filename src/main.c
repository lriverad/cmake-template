#include <stdio.h>

int main(int argc, char **argv) {
  printf("Hello, C!\n");

#ifdef NDEBUG
  printf("Release build...\n");
#elif defined (DEBUG)
  printf("Debug build...\n");
#endif

  return 0;
}
