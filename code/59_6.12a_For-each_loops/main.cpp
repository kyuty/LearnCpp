#include <iostream>
#include <vector>

int sumArray(int array[])
{
    int sum = 0;
    //for (const auto &number : array){ // compile error, the size of array isn't known
    //    sum += number;
    //}

    return sum;
}


int main()
{
    // For-each loops
    {
        int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
        for (int number : fibonacci) // iterate over array fibonacci
           std::cout << number << ' '; // we access the array element for this iteration through variable number
    }

    // For each loops and the auto keyword
    {
        int fibonacci[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 };
        for (auto number : fibonacci) // type is auto, so number has its type deduced from the fibonacci array
           std::cout << number << ' ';
        std::cout << std::endl;
    }

    // For-each loops and references
    {
        int array_0[5] = { 9, 7, 5, 3, 1 };
        for (auto element: array_0) // element will be a copy of the current array element
            std::cout << element << ' ';
        std::cout << std::endl;

        // This means each array element iterated over will be copied into variable element.
        // Copying array elements can be expensive,
        // and most of the time we really just want to refer to the original element.
        // Fortunately, we can use references for this:
        int array_1[5] = { 9, 7, 5, 3, 1 };
        for (auto &element: array_1) // The ampersand makes element a reference to the actual array element, preventing a copy from being made
            std::cout << element << ' ';
        std::cout << std::endl;

        // And, of course, it¡¯s a good idea to make your element const
        // if you¡¯re intending to use it in a read-only fashion:
        int array_2[5] = { 9, 7, 5, 3, 1 };
        for (const auto &element: array_2) // element is a const reference to the currently iterated array element
            std::cout << element << ' ';
        std::cout << std::endl;
    }

    // For-each loops and non-arrays
    {
        std::vector<int> fibonacci = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89 }; // note use of std::vector here rather than a fixed array
        for (const auto &number : fibonacci)
            std::cout << number << ' ';
        std::cout << std::endl;
    }

    // For-each doesn¡¯t work with pointers to an array
    {
        int array[5] = { 9, 7, 5, 3, 1 };
        std::cout << sumArray(array) << "\n";
    }

    // compare string
    {
        const std::string names[] = { "Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly" };
        std::string username = "Holly";
        bool found(false);
        for (const auto &name : names){
            if (name == username){
                found = true;
                break;
            }
        }
        if (found)
            std::cout << username << " was found.\n";
        else
            std::cout << username << " was not found.\n";

    }
    return 0;
}
