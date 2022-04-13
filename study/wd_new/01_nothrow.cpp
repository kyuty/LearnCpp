// nothrow example
#include <iostream>     // std::cout
#include <new>          // std::nothrow

int main () {
  std::cout << "Attempting to allocate 1 MiB... ";
  char* p = new (std::nothrow) char [1048576]; // when nothrow is used as argument for new,
                                               // if throw exception, it returns a null pointer instead and not crash.

  if (!p) {             // null pointers are implicitly converted to false
    std::cout << "Failed!\n";
  } else {
    std::cout << "Succeeded!\n";
    delete[] p;
  }

  return 0;
}

/*
   Attempting to allocate 1 MiB... Succeeded!
*/
