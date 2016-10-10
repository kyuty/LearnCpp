#include <iostream>

int main()
{
    // std::cout
    {
        //1.
        std::cout << "Hello world!";

        //2.
        int x = 4;
        std::cout << "x is equal to:" << x;

        //3.
        std::cout << "Hi!";
        std::cout << "My name is Alex.";
    }

    // std::endl
    {
        std::cout << "Hi!" << std::endl;
        std::cout << "My name is Alex." << std::endl;
    }

    // std::cin
    {
        std::cout << "Enter a number:"; // ask user for a number
        int x = 0;
        std::cin >> x; // read number from console and store it in x
        std::cout << "You entered " << x << std::endl;
    }

    // The std namespace
    {
        using std::cout; // this using declaration tells the compiler that cout should resolve to std::cout
        cout << "Hello world!"; // so no std:: prefix is needed here!
    }

    // The using directive
    {
        using namespace std; // this using directive tells the compiler that we're using everything in the std namespace!
        cout << "Hello world!"; // so no std:: prefix is needed here!
    }

    // When executing a program from the IDE,
    // the console window blinks and then closes immediately.
    {
        std::cout << "Please press enter to close.";
        std::cin.clear(); // reset any error flags
        std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
        std::cin.get(); // get one more char from the user
    }

    return 0;
}
