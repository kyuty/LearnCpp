#include <iostream>
#include <vector>

int main()
{
    // An introduction to std::vector
    {
        // no need to specify size at initialization
        std::vector<int> array1;
        std::vector<int> array2 = { 9, 7, 5, 3, 1 }; // use initializer list to initialize array
        std::vector<int> array3 { 9, 7, 5, 3, 1 }; // use uniform initialization to initialize array (C++11 onward)

        array2[2] = 2;
        array2.at(3) = 3;

        array1 = { 0, 1, 2, 3, 4 }; // okay, array size is now 5
        array1 = { 9, 8, 7 }; // okay, array size is now 3
    }

    // Vectors remember their size
    {
        std::vector<int> array { 9, 7, 5, 3, 1 };
        std::cout << "The size is: " << array.size() << '\n';
    }

    // Resizing an array
    {
        std::vector<int> array1 { 0, 1, 2 };
        array1.resize(5); // set size to 5

        std::cout << "The size is: " << array1.size() << '\n';

        for (auto const &element: array1)
            std::cout << element << ' ';
        std::cout << "\n";
    }
    {
        std::vector<int> array { 0, 1, 2, 3, 4 };
        array.resize(3); // set size to 3

        std::cout << "The size is: " << array.size() << '\n';

        for (auto const &element: array)
            std::cout << element << ' ';
        std::cout << "\n";
    }

    // Compacting bools
    {
        std::vector<bool> array { true, false, false, true, true };
        std::cout << "The size is: " << array.size() << '\n';

        for (auto const &element: array)
            std::cout << element << ' ';
        std::cout << "\n";
    }
    return 0;
}
