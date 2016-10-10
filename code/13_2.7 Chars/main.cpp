#include <iostream>

int main()
{
    {
        char ch1(97); // initialize with integer 97
        char ch2('a'); // initialize with code point for 'a' (97)
    }

    {
        char ch(5); // initialize with integer 5
        char ch1('5'); // initialize with code point for '5' (53)
    }

    {
        char ch(97); // even though we're initializing ch with an integer
        std::cout << ch << "\n"; // cout prints a character
    }

    // Printing chars as integers via type casting === first
    {
        char ch(97);
        int i(ch); // assign the value of ch to an integer
        std::cout << i << "\n"; // print the integer value
    }

    {
        char ch(97);
        std::cout << ch << std::endl;
        std::cout << static_cast<int>(ch) << std::endl;
        std::cout << ch << std::endl;
    }
    // Printing chars as integers via type casting === end

    // Inputting chars == first
    {
        std::cout << "Input a keyboard character: ";
        char ch;
        std::cin >> ch;
        std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;
    }

    {
        std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)
        char ch;
        std::cin >> ch; // ch = 'a', "bcd" is left queued.
        std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;

        // Note: The following cin doesn't ask the user for input, it grabs queued input!
        std::cin >> ch; // ch = 'b', "cd" is left queued.
        std::cout << ch << " has ASCII code " << static_cast<int>(ch) << std::endl;
    }
    // Inputting chars == end

    // Escape sequences === first
    {
        std::cout << "First part\tSecond part\n";
    }
    {
        std::cout << "\"This is quoted text\"\n";
        std::cout << "This string contains a single backslash \\" << std::endl;
        std::cout << "6F in hex is char \'\x6F\'" << std::endl; //将16进制的数打印成字符
        std::cout << "77 in hex is char \'\77\'" << std::endl;  //将8进制的数打印成字符
    }
    // Escape sequences === end

    return 0;
}
