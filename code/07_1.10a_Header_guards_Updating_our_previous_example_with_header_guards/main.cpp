#include "math.h"
#include "geometry.h"

int main()
{
    return 0;
}

//Now, when main.cpp #includes “math.h”, 
// the preprocessor will see that MATH_H hasn’t been defined yet. 
// The contents of math.h are copied into main.cpp, and MATH_H is defined. 
// main.cpp then #includes “geometry.h”, which #includes “math.h”. 
// The preprocessor sees that MATH_H has previously been defined, 
// and the contents between the header guards are skipped.
//
//Thus, by adding the header guards, 
// we’ve ensured that the contents of math.h are only included once in main.cpp.
//
//For good form, we should also add header guards to geometry.h.
