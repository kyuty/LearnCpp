#include <iostream>
#include <cstdint> // for fixed-width integers
#include <vector>

int main()
{
    {
        typedef double distance_t; // define distance_t as an alias for type double
        // The following two statements are equivalent:
        double howFar;
        distance_t howFar_1;
    }
    {
        typedef long miles_t;
        typedef long speed_t;

        miles_t distance = 5;
        speed_t mhz = 3200;

        // The following is valid, because distance and mhz are both actually type long
        distance = mhz;
    }

    // Using typedefs for legibility
    {
        int GradeTest();

        typedef int testScore_t;
        testScore_t GradeTest();
    }

    // Platform independent coding
    {
        #ifdef INT_2_BYTES
        typedef char int8_t;
        typedef int int16_t;
        typedef long int32_t;
        #else
        typedef char int8_t;
        typedef short int16_t;
        typedef int int32_t;
        #endif
    }

    {
        int8_t i(97); // int8_t is actually a typedef for char
        std::cout << i << "\n";
    }

    // Using typedefs to make complex types simple
    {
        typedef std::vector<std::pair<std::string, int> > pairlist_t;
        pairlist_t pairlist;
        //boolean hasDuplicates(pairlist_t pairlist)
        //{
        //    // some code here
        //}
    }

    // Typedefs via the using keyword in C++11
    {
        typedef double distance_t; // define distance_t as an alias for type double
        using distance_t_1 = double; // define distance_t as an alias for type double
    }
    return 0;
}
