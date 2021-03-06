#include <iostream>

using namespace std;

int add(int x, int y)
{
    return x + y;
}

int main()
{
    {
        int x = 5;
        int y = ++x; // x is now equal to 6, and 6 is assigned to y
    }

    {
        int x = 5;
        int y = x++; // x is now equal to 6, and 5 is assigned to y
    }

    {
        int x = 5, y = 5;
        cout << x << " " << y << endl;
        cout << ++x << " " << --y << endl; // prefix
        cout << x << " " << y << endl;
        cout << x++ << " " << y-- << endl; // postfix
        cout << x << " " << y << endl;

        /*
            5 5
            6 4
            6 4
            6 4
            7 3
        */
    }

    // Side effects
    {
        int x = 5;
        ++x;
        std::cout << x << "\n";

        /*
            6
        */
    }

    {
        int x = 5;
        int value = add(x, ++x); // is this 5 + 6, or 6 + 6?  
                                 // It depends on what order your compiler evaluates the function arguments in
        std::cout << value << "\n"; // value could be 11 or 12, depending on how the above line evaluates!

        /*
            11 or 12
        */
    }

    {
        int x = 1;
        x = x++;
        std::cout << x << "\n"; // it’s undefined. 
                                // If the ++ is applied to x before the assignment, the answer will be 1. 
                                // If the ++ is applied to x after the assignment, the answer will be 2.

        /*
            1 or 2
        */
    }

    return 0;
}
