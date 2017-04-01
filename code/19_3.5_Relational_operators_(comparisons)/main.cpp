#include <iostream>
#include <iomanip> // for std::setprecision()
#include <cmath> // for fabs()

bool isAlmostEqual(double a, double b, double epsilon)
{
    // if the distance between a and b is less than epsilon, then a and b are "close enough"
    return fabs(a - b) <= epsilon;
}

// return true if the difference between a and b is within epsilon percent of the larger of a and b
bool approximatelyEqual(double a, double b, double epsilon)
{
    /*
    std::cout << std::setprecision(16); // show 16 digits (16精度,16个数字)
    std::cout << "fabs(a) = " << fabs(a) << "\n";
    std::cout << "fabs(b) = " << fabs(b) << "\n";
    std::cout << "fabs(a - b) = " << fabs(a - b) << "\n";
    if(fabs(a) < fabs(b)){
        std::cout << "return fabs(a - b) <= fabs(b) \n";
    } else {
        std::cout << "fabs(a) * epsilon = " << fabs(a) * epsilon << "\n";
        std::cout << "return fabs(a - b) <= fabs(a) * epsilon \n";
    }
    */
    return fabs(a - b) <= ((fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}

// return true if the difference between a and b is less than absEpsilon, or within relEpsilon percent of the larger of a and b
bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    double diff = fabs(a - b);
    if (diff <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return diff <= ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * relEpsilon);
}


int main()
{
    {
        double d1(100 - 99.99); // should equal 0.01
        double d2(10 - 9.99); // should equal 0.01

        std::cout << "d1 = " << d1 << "\n";
        std::cout << "d2 = " << d2 << "\n";

        if (d1 == d2)
            std::cout << "d1 == d2" << "\n";
        else if (d1 > d2)
            std::cout << "d1 > d2" << "\n";
        else if (d1 < d2)
            std::cout << "d1 < d2" << "\n";


        std::cout << std::setprecision(16); // show 16 digits (16精度,16个数字)
        std::cout << "d1 = " << d1 << "\n";
        std::cout << "d2 = " << d2 << "\n";

        if (d1 == d2)
            std::cout << "d1 == d2" << "\n";
        else if (d1 > d2)
            std::cout << "d1 > d2" << "\n";
        else if (d1 < d2)
            std::cout << "d1 < d2" << "\n";

        /*
            d1 = 0.01
            d2 = 0.01
            d1 > d2
            d1 = 0.01000000000000512
            d2 = 0.009999999999999787
            d1 > d2
        */

    }

    {
        // a is really close to 1.0, but has rounding errors, so it's slightly smaller than 1.0
        double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

        std::cout << std::setprecision(16); // show 16 digits (16精度,16个数字)
        std::cout << "a = " << a << "\n";

        // First, let's compare a (almost 1.0) to 1.0.
        std::cout << approximatelyEqual(a, 1.0, 1e-8) << "\n";

        // Second, let's compare a-1.0 (almost 0.0) to 0.0
        std::cout << approximatelyEqual(a-1.0, 0.0, 1e-8) << "\n";

        /*
            a = 0.9999999999999999
            1
            0
        */
    }

    {
        // a is really close to 1.0, but has rounding errors
        double a = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;

        std::cout << approximatelyEqual(a, 1.0, 1e-8) << "\n";     // compare "almost 1.0" to 1.0
        std::cout << approximatelyEqual(a-1.0, 0.0, 1e-8) << "\n"; // compare "almost 0.0" to 0.0
        std::cout << approximatelyEqualAbsRel(a-1.0, 0.0, 1e-12, 1e-8) << "\n"; // compare "almost 0.0" to 0.0

        /*
            1
            0
            1
        */
    }
    return 0;
}
