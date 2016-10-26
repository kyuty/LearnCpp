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

        /*
            int / int = 1
            double / int = 1.75
            int / double = 1.75
            double / double = 1.75
        */
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

        /*
            1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 
            21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 
            41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 
            61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 
            81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
        */
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

        /*
            Enter the base: 2
            Enter the exponent: 2
            2^2 = 4
        */
    }
    // Where¡¯s the exponent operator? === end

    return 0;
}
