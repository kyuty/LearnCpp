#include <iostream>

using namespace std;

int main()
{
    // Sizeof operator === first
    {
        double d = 5.0;
        std::cout << sizeof(d) << "\n"; // will print the size of variable d in bytes
    }
    // Sizeof operator === end

    // Comma operator === first
    //Comma	operator : Evaluate x then y, returns value of y
    {
        int x = 0;
        int y = 2;
        int z = (++x, ++y); // increment x and y
        std::cout << x << "\n";
        std::cout << y << "\n";
        std::cout << z << "\n";

        //int sum = add(x, y); // this comma is not the comma operator
        //int x(3), y(5); // this comma is not the comma operator either
    }
    // Comma operator === end

    // conditional operators === first
    {
        int x = 21, y = 31;
        cout << ((x > y) ? x : y);
        cout << "\n";
        int a = cout << (x > y) ? x : y;
        cout << "\n" << a;
    }
    // conditional operators === end

    return 0;
}
