#include <iostream>

inline int min(int x, int y)
{
    return x > y ? y : x;
}

int main()
{
    {
        std::cout << min(5, 6) << '\n';
        std::cout << min(3, 2) << '\n';

        // Now when the program compiles main(),
        // it will create machine code as if main() had been written like this:
        std::cout << (5 > 6 ? 6 : 5) << '\n';
        std::cout << (3 > 2 ? 2 : 3) << '\n';
    }
    return 0;
}
