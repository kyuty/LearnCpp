#include <iostream>

int main()
{
    {
        bool myNameIsAlex = true; // true is a boolean literal constant
        int x = 5; // 5 is an integer literal constant
        unsigned int nValue = 5u; // unsigned int
        long nValue2 = 5L; // long
        float fValue = 5.0f; // float
        double d = 6.02e23; // double (by default)
        double pi = 3.14159; // 3.14159 is a double literal
        double avogadro = 6.02e23; // avogadro's number is 6.02 x 10^23
        double electron = 1.6e-19; // charge on an electron is 1.6 x 10^-19
    }

    {
        int x = 012; // 0 before the number means this is octal
        std::cout << x << std::endl;
    }

    {
        int x = 0xFF; // 0x before the number means this is hexadecimal
        std::cout << x << std::endl;
    }

    {
        int bin(0);
        bin = 0x01; // assign binary 0000 0001 to the variable
        bin = 0x02; // assign binary 0000 0010 to the variable
        bin = 0x04; // assign binary 0000 0100 to the variable
        bin = 0x08; // assign binary 0000 1000 to the variable
        bin = 0x10; // assign binary 0001 0000 to the variable
        bin = 0x20; // assign binary 0010 0000 to the variable
        bin = 0x40; // assign binary 0100 0000 to the variable
        bin = 0x80; // assign binary 1000 0000 to the variable
        bin = 0xFF; // assign binary 1111 1111 to the variable
        bin = 0xB3; // assign binary 1010 0011 to the variable
        bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable
    }

    {
        // c++14
        int bin(0);
        bin = 0b1;  // assign binary 0000 0001 to the variable
        bin = 0b11; // assign binary 0000 0011 to the variable
        bin = 0b1010; // assign binary 0000 1010 to the variable
        bin = 0b11110000; // assign binary 1111 0000 to the variable
    }

    {
        // c++14
        //int bin = 0b1011'0010;  // assign binary 1011 0010 to the variable
        //long value = 2'532'673'462; // much easier to read than 2532673462
    }

    return 0;
}
