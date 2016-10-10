#include <iostream>

int main()
{
    // Pointer arithmetic
    {
        int value = 7;
        int *ptr = &value;

        std::cout << ptr << '\n';
        std::cout << ptr+1 << '\n';
        std::cout << ptr+2 << '\n';
        std::cout << ptr+3 << '\n';
    }
    {
        short value = 7;
        short *ptr = &value;

        std::cout << ptr << '\n';
        std::cout << ptr+1 << '\n';
        std::cout << ptr+2 << '\n';
        std::cout << ptr+3 << '\n';
    }

    // Arrays are laid out sequentially in memory
    {
        int array[] = { 9, 7, 5, 3, 1 };

        std::cout << "Element 0 is at address: " << &array[0] << '\n';
        std::cout << "Element 1 is at address: " << &array[1] << '\n';
        std::cout << "Element 2 is at address: " << &array[2] << '\n';
        std::cout << "Element 3 is at address: " << &array[3] << '\n';
    }

    // Pointer arithmetic, arrays, and the magic behind indexing
    {
         int array [5] = { 9, 7, 5, 3, 1 };

         std::cout << &array[1] << '\n'; // print memory address of array element 1
         std::cout << array+1 << '\n'; // print memory address of array pointer + 1

         std::cout << array[1] << '\n'; // prints 7
         std::cout << *(array+1) << '\n'; // prints 7 (note the parenthesis required here)
    }

    // Using a pointer to iterate through an array
    {
        const int arraySize = 7;
        char name[arraySize] = "Mollie";
        int numVowels(0);
        for (char *ptr = name; ptr < name + arraySize; ++ptr)
        {
            switch (*ptr)
            {
                case 'A':
                case 'a':
                case 'E':
                case 'e':
                case 'I':
                case 'i':
                case 'O':
                case 'o':
                case 'U':
                case 'u':
                    numVowels++;
            }
        }

        std::cout << name << " has " << numVowels << " vowels.\n";

    }
    return 0;
}
