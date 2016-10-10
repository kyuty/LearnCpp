#include <iostream>

void printArray(const int *array, int length)
{
    // if user passed in a null pointer for array, bail out early!
    if (!array)
        return;
    for (int index=0; index < length; ++index)
        std::cout << array[index] << ' ';
    std::cout << std::endl;
}

void setToNull(int *tempPtr)
{
    // we're making tempPtr point at something else, not changing the value that tempPtr points to.
    tempPtr = nullptr; // use 0 instead if not C++11
}

void setToSix(int *tempPtr)
{
    *tempPtr = 6; // we're changing the value that tempPtr (and ptr) points to
}

// tempPtr is now a reference to a pointer, so any changes made to tempPtr will change the argument as well!
void setToNull_1(int *&tempPtr)
{
    tempPtr = nullptr; // use 0 instead if not C++11
}


int main()
{
    {
        int array[6] = { 6, 5, 4, 3, 2, 1 }; // remember, arrays decay into pointers
        printArray(array, 6); // so array evaluates to a pointer to the first element of the array here, no & needed
    }

    // Addresses are passed by value
    {
        // First we set ptr to the address of five, which means *ptr = 5
        int five = 5;
        int *ptr = &five;

        // This will print 5
        std::cout << *ptr << "\n";

        // tempPtr will receive a copy of ptr
        setToNull(ptr);

        // ptr is still set to the address of five!

        // This will print 5
        if (ptr)
            std::cout << *ptr << "\n";
        else
            std::cout << " ptr is null" << "\n";
    }
    {
        // First we set ptr to the address of five, which means *ptr = 5
        int five = 5;
        int *ptr = &five;

        // This will print 5
        std::cout << *ptr << "\n";

        // tempPtr will receive a copy of ptr
        setToSix(ptr);

        // tempPtr changed the value being pointed to to 6, so ptr is now pointing to the value 6

        // This will print 6
        if (ptr)
            std::cout << *ptr << "\n";
        else
            std::cout << " ptr is null" << "\n";

    }

    // Passing addresses by reference
    {
        // First we set ptr to the address of five, which means *ptr = 5
        int five = 5;
        int *ptr = &five;

        // This will print 5
        std::cout << *ptr << "\n";

        // tempPtr is set as a reference to ptr
        setToNull_1(ptr);

        // ptr has now been changed to nullptr!

        if (ptr)
            std::cout << *ptr << "\n";
        else
            std::cout << "ptr is null" << "\n";
    }
    return 0;
}
