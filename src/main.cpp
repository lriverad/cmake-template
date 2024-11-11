#include <iostream>

int main(int argc, char *argv[]) {
  std::cout << "Hello, C++!\n";

#ifndef BUILD_DEBUG
  std::cout << "Release build...\n";
#else
  std::cout << "Debug build...\n";
#endif

  return 0;
}
