#include <iostream>

void printSize(int *array)
{
    // array is treated as a pointer here
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

// C++ will implicitly convert parameter array[] to *array
void printSize_1(int array[])
{
    // array is treated as a pointer here, not a fixed array
    std::cout << sizeof(array) << '\n'; // prints the size of a pointer, not the size of the array!
}

// parameter ptr contains a copy of the array's address
void changeArray(int *ptr)
{
    *ptr = 5; // so changing an array element changes the _actual_ array
}

int main()
{
    // Similarities between pointers and fixed arrays === first
    {
        int array[5] = { 9, 7, 5, 3, 1 };

        // print the value of the array variable
        std::cout << "The array has address: " << array << '\n';

        // print address of the array elements
        std::cout << "Element 0 has address: " << &array[0] << '\n';
    }
    {
        int array[5] = { 9, 7, 5, 3, 1 };

        // dereferencing an array returns the first element (element 0)
        std::cout << *array << "\n"; // will print 9!

        char name[] = "Jason"; // C-style string (also an array)
        std::cout << *name << "\n"; // will print 'J'
    }
    {
        int array[5] = { 9, 7, 5, 3, 1 };
        std::cout << *array; // will print 9

        int *ptr = array;
        std::cout << *ptr; // will print 9
    }
    // Similarities between pointers and fixed arrays === end

    // Differences between pointers and fixed arrays
    {
        int array[5] = { 9, 7, 5, 3, 1 };

        std::cout << sizeof(array) << '\n'; // will print sizeof(int) * array length

        int *ptr = array;
        std::cout << sizeof(ptr) << '\n'; // will print the size of a pointer
    }

    // Revisiting passing fixed arrays to functions
    {
        int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
        std::cout << sizeof(array) << '\n';
        printSize(array); // the array argument decays into a pointer here
    }
    {
        int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
        std::cout << sizeof(array) << '\n';
        printSize_1(array); // the array argument decays into a pointer here
    }

    // An intro to pass by address
    {
        int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
        std::cout << "Element 0 has value: " << array[0] << '\n';

        changeArray(array);

        std::cout << "Element 0 has value: " << array[0] << '\n';
    }
    return 0;
}
