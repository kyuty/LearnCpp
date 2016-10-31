#include <iostream>

inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    {
        std::cout << min(5, 6) << '\n';     // print 5
        std::cout << min(3, 2) << '\n';     // print 2

        // Now when the program compiles main(),
        // it will create machine code as if main() had been written like this:
        std::cout << (5 > 6 ? 6 : 5) << '\n';   // print 5
        std::cout << (3 > 2 ? 2 : 3) << '\n';   // print 2
    }
    return 0;
}
