#include <bitset>
#include <iostream>

// Note that with std::bitset, our options correspond to bit numbers, not bit patterns
const int option_1 = 0;
const int option_2 = 1;
const int option_3 = 2;
const int option_4 = 3;
const int option_5 = 4;
const int option_6 = 5;
const int option_7 = 6;
const int option_8 = 7;

int main()
{
    // An introduction to std::bitset === first
    {
        std::bitset<8> bits(0x2);   // we need 8 bits, start with bit pattern 0000 0010
        bits.set(option_5);         // set bit 4 to 1 (now we have 0001 0010)
        std::cout << bits << "\n";
        bits.flip(option_6);        // flip bit 5 (now we have 0011 0010)
        std::cout << bits << "\n";
        bits.reset(option_6);       // set bit 5 back to 0 (now we have 0001 0010)
        std::cout << bits << "\n";

        std::cout << "Bit 4 has value: " << bits.test(option_5) << '\n';
        std::cout << "Bit 5 has value: " << bits.test(option_6) << '\n';
        std::cout << "All the bits: " << bits << '\n';

        /*
            00010010
            00110010
            00010010
            Bit 4 has value: 1
            Bit 5 has value: 0
            All the bits: 00010010
        */
    }
    // An introduction to std::bitset === end

    // Bit masks === first
    {
        const unsigned int lowMask = 0xF; // bit mask to keep low 4 bits (hex for 0000 0000 0000 1111)

        std::cout << "Enter an integer: ";
        int num;
        std::cin >> num;

        num &= lowMask; // remove the high bits to leave only the low bits
                        // 十进制的数字 与(&)操作 一个十六进制的数

        std::cout << "The 4 low bits have value: " << num<< '\n';

        /*
            Enter an integer: 17
            The 4 low bits have value: 1
        */
    }
    // Bit masks === end

    // An RGBA color example === first
    {
        const unsigned int redBits = 0xFF000000;    // 后面6个0; (1位对应4位 : F-->1111) 4*8
        const unsigned int greenBits = 0x00FF0000;  // 后面4个0; 
        const unsigned int blueBits = 0x0000FF00;   // 后面2个0; 
        const unsigned int alphaBits = 0x000000FF;

        std::cout << "unsigned int size's = " << sizeof(redBits) << "\n";
        std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): ";
        unsigned int pixel;
        std::cin >> std::hex >> pixel; // std::hex allows us to read in a hex value

        // use bitwise AND to isolate red pixels, then right shift the value into the range 0-255
        unsigned char red = (pixel & redBits) >> 24;
        unsigned char green = (pixel & greenBits) >> 16;
        unsigned char blue = (pixel & blueBits) >> 8;
        unsigned char alpha = pixel & alphaBits;

        std::cout << "\nYour color contains:\n";
        std::cout << static_cast<int>(red) << " of 255 red\n";
        std::cout << static_cast<int>(green) << " of 255 green\n";
        std::cout << static_cast<int>(blue) << " of 255 blue\n";
        std::cout << static_cast<int>(alpha) << " of 255 alpha\n";

        /*
            Enter a 32-bit RGBA color value in hexadecimal (e.g. FF7F3300): FF7F3300
            Your color contains:
            255 of 255 red
            127 of 255 green
            51 of 255 blue
            0 of 255 alpha
        */
    }
    // An RGBA color example === end

    return 0;
}

/*
b.any()         b中是否存在置为1的二进制位？

b.none()        b中不存在置为1的二进制位吗？

b.count()       b中置为1的二进制位的个数

b.size()        b中二进制位的个数

b[pos]          访问b中在pos处的二进制位

b.test(pos)     b中在pos处的二进制位是否为1？

b.set()         把b中所有二进制位都置为1

b.set(pos)      把b中在pos处的二进制位置为1

b.reset()       把b中所有二进制位都置为0

b.reset(pos)    把b中在pos处的二进制位置为0

b.flip()        把b中所有二进制位逐位取反

b.flip(pos)     把b中在pos处的二进制位取反

b.to_ulong()    用b中同样的二进制位返回一个unsigned long值

os << b         把b中的位集输出到os流
*/

/*
Summary
    Summarizing how to set, unset, toggle, and query bit flags:
    To query bit states, we use bitwise AND:
        if (myflags & option4) ... // if option4 is set, do something
    To turn bits on, we use bitwise OR:
        myflags |= option4; // turn option 4 on.
        myflags |= option4 | option5; // turn options 4 and 5 on.
    To turn bits off, we use bitwise AND with an inverse bit pattern:
        myflags &= ~option4; // turn option 4 off
        myflags &= ~option4 & ~option5; // turn option4 and 5 off.
    To toggle bit states, we use bitwise XOR:
        myflags ^= option4; // flip option4 from on to off, or vice versa
        myflags ^= option4 | option5; // flip options 4 and 5
*/

/*
    Quiz
        unsigned char option_viewed = 0x01;
        unsigned char option_edited = 0x02;
        unsigned char option_favorited = 0x04;
        unsigned char option_shared = 0x08;
        unsigned char option_deleted = 0x80;

        unsigned char myArticleFlags;
        ==========    ==========    ==========    ==========
        1a) Write a line of code to set the article as viewed.
        1b) Write a line of code to check if the article was deleted.
        1c) Write a line of code to unset the article as a favorite.
    Quiz answers
        1a) Hide Solution
        myArticleFlags |= option_viewed;
        1b) Hide Solution
        if (myArticleFlags & option_deleted) …
        1c) Hide Solution
        myArticleFlags &= ~option_favorited;
*/
