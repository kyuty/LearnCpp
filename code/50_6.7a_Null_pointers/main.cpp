#include <iostream>
//#include <cstddef> // for std::nullptr_t

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething()\n";
}

int main()
{
    // Null values and null pointers
    {
        int *ptr(0);  // ptr is now a null pointer

        int *ptr2; // ptr2 is uninitialized
        ptr2 = 0; // ptr2 is now a null pointer
    }
    {
        double *ptr(0);
        if (ptr)
            std::cout << "ptr is pointing to a double value.\n";
        else
            std::cout << "ptr is a null pointer.\n";    // print

        double *ptr_1;
        if (ptr_1)
            std::cout << "ptr_1 is pointing to a double value.\n";  // print
        else
            std::cout << "ptr_1 is a null pointer.\n";
    }

    // The NULL macro
    {
        int *ptr(NULL); // assign address 0 to ptr
    }

    // nullptr in C++11
    {
        int *ptr = nullptr; // note: ptr is still an integer pointer, just set to a null value (0)
    }

    // std::nullptr_t in C++11
    {
        doSomething(nullptr); // call doSomething with an argument of type std::nullptr_t
    }
    return 0;
}
