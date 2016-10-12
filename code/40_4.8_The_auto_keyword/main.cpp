#include <iostream>

int add(int x, int y)
{
    return x + y;
}

// Automatic type deduction for functions in C++14
//auto add(int x, int y)
//{
//    return x + y;
//}

int main()
{
    {
        // auto int foo(5); // explicitly specify that foo should have automatic duration
    }

    // Automatic type deduction in C++11
    {
        auto d = 5.0; // 5.0 is a double literal, so d will be type double
        auto i = 1 + 2; // 1 + 2 evaluates to an integer, so i will be type int
        auto sum = add(5, 6); // add() returns an int, so sum will be type int
        std::cout << sum << "\n";
    }
    return 0;
}

/*
// Trailing return type syntax in C++11
    Consider the following function declaration:
        int add(int x, int y);
    In C++11, this could be equivalently written as:
        auto add(int x, int y) -> int;

    auto add(int x, int y) -> int;
    auto divide(double x, double y) -> double;
    void printSomething();
    auto calculateThis(int x, double d) -> std::string;

*/
