#include <iostream>
#include <cmath> // needed for pow()

int main()
{
    // Using static_cast<> to do floating point division with integers === first
    {
        int x = 7;
        int y = 4;

        std::cout << "int / int = " << x / y << "\n";
        std::cout << "double / int = " << static_cast<double>(x) / y << "\n";
        std::cout << "int / double = " << x / static_cast<double>(y) << "\n";
        std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << "\n";
    }
    // Using static_cast<> to do floating point division with integers === end

    // Modulus (remainder) === first
    {
        // count holds the current number to print
        int count = 1; // start at 1

        // Loop continually until we pass number 100
        while (count <= 100)
        {
            std::cout << count << " "; // print the current number

            // if count is evenly divisible by 20, print a new line
            if (count % 20 == 0)
                std::cout << "\n";

            count = count + 1; // go to next number
        } // end of while
    }
    // Modulus (remainder) === end


    // Where¡¯s the exponent operator? === first
    {
        std::cout << "Enter the base: ";
        double base;
        std::cin >> base;

        std::cout << "Enter the exponent: ";
        double exp;
        std::cin >> exp;

        std::cout << base << "^" << exp << " = " << pow(base, exp) << "\n";

    }
    // Where¡¯s the exponent operator? === end

    return 0;
}
