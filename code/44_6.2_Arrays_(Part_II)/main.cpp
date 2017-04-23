#include <iostream>

namespace StudentNames_1
{
    enum StudentNames_2
    {
        KENNY, // 0
        KYLE, // 1
        STAN, // 2
        BUTTERS, // 3
        CARTMAN, // 4
        WENDY, // 5
        MAX_STUDENTS // 6
    };
}

void passValue(int value) // value is a copy of the argument
{
    value = 99; // so changing it here won't change the value of the argument
}

void passArray(int prime[5]) // prime is the actual array
{
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

// even though prime is the actual array, within this function it should be treated as a constant
void passArray_1(const int prime[5])
{
    // so each of these lines will cause a compile error!
    //prime[0] = 11;
    //prime[1] = 7;
    //prime[2] = 5;
    //prime[3] = 3;
    //prime[4] = 2;
}

void printSize(int array[])
{
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

int main()
{
    // Initializing fixed arrays === first
    {
        int prime[5] = { 2, 3, 5, 7, 11 }; // use initializer list to initialize the fixed array
    }

    {
        // if there are less initializers in the list than the array can hold,
        // the remaining elements are initialized to 0
        int array[5] = { 7, 4, 5 }; // only initialize first 3 elements

        std::cout << array[0] << '\n';      // print 7
        std::cout << array[1] << '\n';      // print 4
        std::cout << array[2] << '\n';      // print 5
        std::cout << array[3] << '\n';      // print 0
        std::cout << array[4] << '\n';      // print 0
    }

    {
        // Initialize all elements to 0
        int array[5] = { };
    }

    {
        // In C++11, the uniform initialization syntax can be used instead:
        int prime[5] { 2, 3, 5, 7, 11 }; // use uniform initialization to initialize the fixed array
    }
    // Initializing fixed arrays === end

    // Omitted size
    {
        int array[5] = { 0, 1, 2, 3, 4 }; // explicitly define size of the array
        int array_1[] = { 0, 1, 2, 3, 4 }; // let initializer list set size of the array
    }

    // Arrays and enums === first
    {
        enum StudentNames
        {
            KENNY, // 0
            KYLE, // 1
            STAN, // 2
            BUTTERS, // 3
            CARTMAN, // 4
            MAX_STUDENTS // 5
        };
        int testScores[MAX_STUDENTS]; // allocate 5 integers
        testScores[STAN] = 76;
    }
    {
        enum StudentNames
        {
            KENNY, // 0
            KYLE, // 1
            STAN, // 2
            BUTTERS, // 3
            CARTMAN, // 4
            WENDY, // 5
            MAX_STUDENTS // 6
        };
        int testScores[MAX_STUDENTS]; // allocate 6 integers
        testScores[STAN] = 76; // still works
    }
    // Arrays and enums === end

    // Arrays and enum classes === first
    {
        enum class StudentNames
        {
            KENNY, // 0
            KYLE, // 1
            STAN, // 2
            BUTTERS, // 3
            CARTMAN, // 4
            WENDY, // 5
            MAX_STUDENTS // 6
        };
        int testScores[static_cast<int>(StudentNames::MAX_STUDENTS)]; // allocate 6 integers
        testScores[static_cast<int>(StudentNames::STAN)] = 76;
    }

    {
        int testScores[StudentNames_1::MAX_STUDENTS]; // allocate 6 integers
        testScores[StudentNames_1::STAN] = 76;
    }
    // Arrays and enum classes === end

    // Passing arrays to functions
    {
        int value = 1;
        std::cout << "before passValue: " << value << "\n";     // print 1
        passValue(value);
        std::cout << "after passValue: " << value << "\n";      // print 1

        int prime[5] = { 2, 3, 5, 7, 11 };
        // print before passArray: 2 3 5 7 11
        std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << "\n";
        passArray(prime);
        // print after passArray: 11 7 5 3 2
        std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " << prime[2] << " " << prime[3] << " " << prime[4] << "\n";
    }

    // sizeof and arrays
    {
        int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
        std::cout << sizeof(array) << '\n'; // will print the size of the array
                                            // print 32
        printSize(array);                   // print 8
    }

    // Indexing an array out of range
    {
        int prime[5]; // hold the first 5 prime numbers
        //prime[5] = 13;
    }
    return 0;
}
