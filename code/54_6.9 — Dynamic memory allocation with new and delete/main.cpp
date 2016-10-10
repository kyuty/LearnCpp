#include <iostream>

int main()
{
    // Dynamically allocating single variables
    {
        new int; // dynamically allocate an integer (and discard the result)

        int *ptr = new int; // dynamically allocate an integer and assign the address to ptr
                            // so we can access it later
        *ptr = 7; // assign value of 7 to allocated memory
    }

    // Initializing a dynamically allocated variable
    {
        int *ptr1 = new int (5); // use direct initialization
        int *ptr2 = new int { 6 }; // use uniform initialization
    }

    // Deleting single variables
    {
        int *ptr = nullptr;
        // assume ptr has previously been allocated with operator new
        delete ptr; // return the memory pointed to by ptr to the operating system
        ptr = 0; // set ptr to be a null pointer (use nullptr instead of 0 in C++11)
    }

    // Dangling pointers
    {
        int *ptr = new int; // dynamically allocate an integer
        *ptr = 7; // put a value in that memory location

        delete ptr; // return the memory to the operating system.  ptr is now a dangling pointer.

        std::cout << *ptr << "\n"; // Dereferencing a dangling pointer will cause undefined behavior
        delete ptr; // trying to deallocate the memory again will also lead to undefined behavior.
    }
    {
        int *ptr = new int; // dynamically allocate an integer
        int *otherPtr = ptr; // otherPtr is now pointed at that same memory location

        delete ptr; // return the memory to the operating system.  ptr and otherPtr are now dangling pointers.
        ptr = 0; // ptr is now a nullptr

        // however, otherPtr is still a dangling pointer!
    }

    // Operator new can fail
    {
        int *value = new (std::nothrow) int; // value will be set to a null pointer if the integer allocation fails
    }
    {
        int *value = new (std::nothrow) int; // ask for an integer's worth of memory
        if (!value) // handle case where new returned null
        {
            std::cout << "Could not allocate memory";
            return 1;
        }
    }

    // Null pointers and dynamic memory allocation
    {
        int *ptr;
        // If ptr isn't already allocated, allocate it
        if (!ptr)
            ptr = new int;
        if (ptr)
            delete ptr;
    }

    // Memory leaks
    {
        int value = 5;
        int *ptr = new int; // allocate memory
        ptr = &value; // old address lost, memory leak results
    }
    {
        int *ptr = new int;
        ptr = new int; // old address lost, memory leak results
    }
    return 0;
}
