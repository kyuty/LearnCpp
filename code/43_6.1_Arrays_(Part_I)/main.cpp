#include <iostream>

int main()
{
    // An example array program
    {
        int prime[5]; // hold the first 5 prime numbers
        prime[0] = 2;
        prime[1] = 3;
        prime[2] = 5;
        prime[3] = 7;
        prime[4] = 11;

        std::cout << "The lowest prime number is: " << prime[0] << "\n";    // print 2
        std::cout << "The sum of the first 5 primes is: " << prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << "\n";  // print 28
    }

    // Array data types
    {
        double array[3]; // allocate 3 doubles
        array[0] = 2.0;
        array[1] = 3.0;
        array[2] = 4.3;

        std::cout << "The average is " << (array[0] + array[1] + array[2]) / 3 << "\n";     // print 3.1
    }

    {
        struct Rectangle
        {
            int length;
            int width;
        };
        Rectangle rects[5]; // declare an array of 5 Rectangle
        rects[0].length = 24;
    }

    // Array subscripts
    {
        int array[5]; // declare an array of length 5

        // using a literal (constant) index:
        array[1] = 7; // ok

        // using an enum (constant) index
        enum Animals
        {
            ANIMAL_CAT = 2
        };
        array[ANIMAL_CAT] = 4; // ok

        // using a variable (non-constant) index:
        short index = 3;
        array[index] = 7; // ok
    }

    // Fixed array declarations
    {
        // using a literal constant
        int array[5]; // Ok

        // using a macro symbolic constant
        #define ARRAY_SIZE 5
        int array_1[ARRAY_SIZE]; // Syntactically okay, but don't do this

        // using a symbolic constant
        const int arraySize = 5;
        int array_2[arraySize]; // Ok

        // using an enumerator
        enum ArrayElements
        {
            MAX_ARRAY_SIZE = 5
        };
        int array_3[MAX_ARRAY_SIZE]; // Ok

        /*
        // using a non-const variable
        int size_1;
        std::cin >> size_1;
        int array_45[size_1]; // Not ok -- size is not a compile-time constant!

        // using a runtime const variable
        int temp = 5;
        const int size_2 = temp;
        int array_4[size_2]; // Not ok -- size is a runtime constant, not a compile-time constant!
        */

        std::cout << "dsfdsaf" << std::endl;
    }
    return 0;
}
