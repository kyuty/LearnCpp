#include <iostream>
#include "constants.h"

int main()
{
    // const === first
    {
        const double gravity { 9.8 }; // preferred use of const before type
        int const sidesInSquare { 4 }; // okay, but not preferred
        //const int a;// is wrong
    }

    {
        // Note that const variables can be initialized from non-const values:
        std::cout << "Enter your age: ";
        int age;
        std::cin >> age;
        const int usersAge (age); // usersAge can not be changed
    }
    // const === end

    // Constexpr === first
    {
        constexpr double gravity (9.8); // ok, the value of 9.8 can be resolved at compile-time
        constexpr int sum = 4 + 5; // ok, the value of 4 + 5 can be resolved at compile-time

        //std::cout << "Enter your age: ";
        //int age;
        //std::cin >> age;
        //constexpr int myAge = age; // not okay, age can not be resolved at compile-time
    }
    // Constexpr === end

    // Using symbolic constants throughout a program
    {
        double radius = 1.0;
        double circumference = 2 * radius * constants::pi;
    }

    return 0;
}
