#include <iostream>
#include <iomanip> // for std::setprecision()

int main()
{
    // Precision and range
    {
        using namespace std;
        float f;
        f = 9.87654321f;
        cout << f << endl;
        f = 987.654321f;        // 小数点前后加起来，只打印6位数
        cout << f << endl;
        f = 987654.321f;
        cout << f << endl;
        f = 9876543.21f;        // e前面的数 依旧 只打印6位数
        cout << f << endl;
        f = 0.0000987654321f;   // e前面的数 依旧 只打印6位数
        cout << f << endl;

        /*
            9.87654
            987.654
            987654
            9.87654e+06
            9.87654e-05
        */
    }

    {
        std::cout << std::setprecision(16); // show 16 digits (16精度,16个数字)
        float f = 3.33333333333333333333333333333333333333f;
        std::cout << f << std::endl;
        double d = 3.3333333333333333333333333333333333333;
        std::cout << d << std::endl;

        /*
            3.333333253860474
            3.333333333333333
        */

//Because we set the precision to 16 digits, each of the above numbers is printed with 16 digits. 
//But, as you can see, the numbers certainly aren’t precise to 16 digits!
//
//The number of digits of precision a floating point variable has depends on 
// both the size (floats have less precision than doubles) 
// and the particular value being stored (some values have more precision than others).
// 
//Float values have between 6 and 9 digits of precision, 
// with most float values having at least 7 significant digits 
// (which is why everything after that many digits in our answer above is junk). 
//
//Double values have between 15 and 18 digits of precision, 
// with most double values having at least 16 significant digits. 
//
//Long double has a minimum precision of 15, 18, or 33 significant digits 
// depending on how many bytes it occupies.

    }

    {
        float f(123456789.0f); // f has 9 significant digits
        std::cout << f << std::endl;
        std::cout << std::setprecision(9); // because we want to show all 9 significant digits in f
        std::cout << f << std::endl;

        /*
            123456792
            123456792
        */
    }

    // Rounding errors === begin
    {
        double d(0.1);
        std::cout << d << std::endl; // use default cout precision of 6
        std::cout << std::setprecision(17);
        std::cout << d << std::endl;

        /*
            0.1
            0.10000000000000001
        */
        
//In binary, 0.1 is represented by the infinite sequence: 0.00011001100110011… 
//Because of this, when we assign 0.1 to a floating point number, we’ll run into precision problems.

// On the top line, cout prints 0.1, as we expect.
//
// On the bottom line, where we have cout show us 17 digits of precision, 
// we see that d is actually not quite 0.1! 
// This is because the double had to truncate the approximation due to its limited memory, 
// which resulted in a number that is not exactly 0.1. This is called a rounding error.
    }

    {
        std::cout << std::setprecision(17);

        double d1(1.0);
        std::cout << d1 << std::endl;

        double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1); // should equal 1.0
        std::cout << d2 << std::endl;

        /*
            1
            0.99999999999999989
        */

    }
    // Rounding errors === end

    // NaN and Inf
    {
        double zero = 0.0;
        double posinf = 5.0 / zero; // positive infinity
        std::cout << posinf << "\n";

        double neginf = -5.0 / zero; // negative infinity
        std::cout << neginf << "\n";

        double nan = zero / zero; // not a number (mathematically invalid)
        std::cout << nan << "\n";

        /*
            inf
            -inf
            -nan
        */
    }

    return 0;
}

/*

9.87654
987.654
987654
9.87654e+06
9.87654e-05

3.333333253860474
3.333333333333333

123456792
123456792

0.1
0.10000000000000001

1
0.99999999999999989

inf
-inf
-nan

*/

/*
Quiz
1) Convert the following numbers to C++ style scientific notation (using an e to represent the exponent) and determine how many significant digits each has:
a) 34.50
b) 0.004000
c) 123.005
d) 146000
e) 146000.001
f) 0.0000000008
g) 34500.0
Quiz Answers
1) Hide Solution
a) 3.450e1 (4 significant digits)
b) 4.000e-3 (4 significant digits)
c) 1.23005e2 (6 significant digits)
d) 1.46e5 (3 significant digits)
e) 1.46000001e5 (9 significant digits)
And now a couple of trickier ones:
f) 8e-10 (1 significant digit)
The correct significand is 8, not 8.0. 8.0 has two significant digits, but this number only has 1.
g) 3.45000e4 (6 significant digits)
*/
