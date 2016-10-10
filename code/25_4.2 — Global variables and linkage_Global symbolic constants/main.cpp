#include <iostream>
#include "constants.h"

int main()
{
    double radius = 1.0;
    double circumference = 2 * radius * Constants::pi;
    std::cout << circumference << "\n";

    return 0;
}

/*
// Uninitialized definition:
int g_x;       // defines uninitialized global variable (external linkage)
const int g_x; // not allowed: const variables must be initialized

// Forward declaration via extern keyword:
extern int g_z;       // forward declaration for global variable defined elsewhere
extern const int g_z; // forward declaration for const global variable defined elsewhere

// Initialized definition:
int g_y(1);       // defines initialized global variable (external linkage)
const int g_y(1); // defines initialized static variable (internal linkage)

// Initialized definition w/extern keyword:
extern int g_w(1);       // defines initialized global variable (external linkage, extern keyword is redundant in this case)
extern const int g_w(1); // defines initialized const global variable (external linkage)
*/
