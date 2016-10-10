#include <iostream>

int add(int x, int y) // add's x is created here
{
    return x + y;
} // add's x goes out of scope and is destroyed here

int main()
{
    int x = 5; // main's x is created here
    int y = 6;
    std::cout << add(x, y) << std::endl; // the value from main's x is copied into add's x
    return 0;
} // main's x goes out of scope and is destroyed here
