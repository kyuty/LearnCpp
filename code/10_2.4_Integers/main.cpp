#include <iostream>

int main()
{
    {
        using namespace std;
        unsigned short x = 65535; // largest 16-bit unsigned value possible
        cout << "x was: " << x << endl;
        x = x + 1; // 65536 is out of our range -- we get overflow because x can't hold 17 bits
        cout << "x is now: " << x << endl;
    }

    {
        using namespace std;
        unsigned short x = 0; // smallest 2-byte unsigned value possible
        cout << "x was: " << x << endl;
        x = x - 1; // overflow!
        cout << "x is now: " << x << endl;
    }

    {
        std::cout << 20 / 4 << std::endl;
        std::cout << 8 / 5 << std::endl;
    }

    return 0;
}

/*
x was: 65535
x is now: 0
x was: 0
x is now: 65535
5
1
*/