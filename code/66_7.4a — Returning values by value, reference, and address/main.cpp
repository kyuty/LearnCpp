#include <iostream>
#include <array>

// Return by value
int doubleValue(int x)
{
    int value = x * 2;
    return value ; // A copy of value will be returned here
} // value goes out of scope here

int* allocateArray(int size)
{
    return new int[size];
}

// Returns a reference to the index element of array
int& getElement(std::array<int, 25> &array, int index)
{
    // we know that array[index] will not be destroyed when the function ends
    // so it's okay to return it by reference
    return array[index];
}

int returnByValue()
{
    return 5;
}

int& returnByReference()
{
     static int x = 5; // static ensures x isn't destroyed when it goes out of scope
     return x;
}

int main()
{
    // Return by address
    {
        int *array = allocateArray(25);

        // do stuff with array

        delete[] array;
    }

    // Return by reference
    {
        std::array<int, 25> array;

        // Set the element of array with index 10 to the value 5
        getElement(array, 10) = 5;

        std::cout << array[10] << '\n';
    }

    // Mixing return references and values
    {
        int value = returnByReference(); // case A -- ok, treated as return by value
        //int &ref = returnByValue(); // case B -- compile error
        const int &cref = returnByValue(); // case C -- ok, the lifetime of return value is extended to the lifetime of cref
    }
    return 0;
}
