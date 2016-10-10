#include <iostream>
#include <array>
#include <algorithm> // for std::sort

void printSize(const std::array<double, 5> &myarray)
{
    std::cout << "size: " << myarray.size() << "\n";
}

int main()
{
    // An introduction to std::array in C++11
    {
        std::array<int, 5> myarray = { 9, 7, 5, 3, 1 }; // initialization list
        std::array<int, 5> myarray2 { 9, 7, 5, 3, 1 }; // uniform initialization

        //std::array<int, > myarray3 = { 9, 7, 5, 3, 1 }; // illegal, array size must be provided

        myarray = { 0, 1, 2, 3, 4 }; // okay
        myarray = { 9, 8, 7 }; // okay, elements 3 and 4 are set to zero!
        //myarray = { 0, 1, 2, 3, 4, 5 }; // not allowed, too many elements in initializer list!

        std::cout << myarray[1] << "\n";
        myarray[2] = 6;
    }
    {
        std::array<int, 5> myarray { 9, 7, 5, 3, 1 };
        myarray.at(1) = 6; // array element 1 valid, sets array element 1 to value 6
        //myarray.at(9) = 10; // array element 9 is invalid, will throw error
    }

    // Size and sorting
    {
        std::array<double, 5> myarray { 9.0, 7.2, 5.4, 3.6, 1.8 };
        std::cout << "size: " << myarray.size();
    }
    {
        std::array<double, 5> myarray { 9.0, 7.2, 5.4, 3.6, 1.8 };
        printSize(myarray);
    }
    {
        std::array<int, 5> myarray { 9, 7, 5, 3, 1 };

        for (auto &element : myarray)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
    {
        std::array<int, 5> myarray { 7, 3, 1, 9, 5 };
        std::cout << "ori_myarray:";
        for (const auto &element : myarray)
            std::cout << element << ' ';
        std::cout << std::endl;

        std::sort(myarray.begin(), myarray.end()); // sort the array forwards
        std::cout << "sort1_myarray:";
        for (const auto &element : myarray)
            std::cout << element << ' ';
        std::cout << std::endl;

        myarray = {7, 3, 1, 9, 5};
        std::sort(myarray.begin() + 1, myarray.end() -1);
        std::cout << "sort2_myarray:";
        for (const auto &element : myarray)
            std::cout << element << ' ';
        std::cout << std::endl;

        //myarray = {7, 3, 1, 9, 5};
        //std::sort(myarray.end(), myarray.begin());// ����ᱨ��

        myarray = {7, 3, 1, 9, 5};
        std::sort(myarray.rbegin(), myarray.rend()); // sort the array backwards
        std::cout << "sort3_myarray:";
        for (const auto &element : myarray)
            std::cout << element << ' ';
        std::cout << std::endl;

        myarray = {7, 3, 1, 9, 5};
        std::sort(myarray.rbegin() + 1, myarray.rend() - 1); // sort the array backwards
        std::cout << "sort4_myarray:";
        for (const auto &element : myarray)
            std::cout << element << ' ';
        std::cout << std::endl;
    }
    return 0;
}
