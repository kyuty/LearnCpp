#include <iostream>

int add(int x, int y) // x and y are created here
{
    // x and y are visible/usable within this function only
    return x + y;
} // x and y go out of scope and are destroyed here

int main()
{
    int a = 5; // a is created and initialized here
    int b = 6; // b is created and initialized here
    // a and b are usable within this function only
    std::cout << add(a, b) << std::endl; // calls function add() with x=a and y=b
    return 0;
} // a and b go out of scope and are destroyed here
