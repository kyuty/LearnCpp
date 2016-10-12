#include <iostream>

int main()
{
    // C-style string symbolic constants
    {
        char myName[] = "Alex";
        std::cout << myName << "\n";
    }
    {
        const char *myName = "Alex";
        std::cout << myName << "\n";
    }

    // std::cout and char pointers
    {
        int nArray[5] = { 9, 7, 5, 3, 1 };
        char cArray[] = "Hello!";
        const char *name = "Alex";

        std::cout << nArray << '\n'; // nArray will decay to type int*
        std::cout << cArray << '\n'; // cArray will decay to type char*
        std::cout << name << '\n'; // name is already type char*
    }

    {
        char c = 'Q';
        std::cout << &c << "\n";
    }
    return 0;
}
