#include <iostream>
#include <math.h>    // for sin() and cos()

void foo(int &value)
{
    value = 6;
}

void getSinCos(double degrees, double &sinOut, double &cosOut)
{
    // sin() and cos() take radians, not degrees, so we need to convert
    static const double pi = 3.14159265358979323846; // the value of pi
    double radians = degrees * pi / 180.0;
    sinOut = sin(radians);
    cosOut = cos(radians);
}

int main()
{
    // Pass by reference
    {
        int value = 5;

        std::cout << "value = " << value << '\n';   // print value = 5
        foo(value);
        std::cout << "value = " << value << '\n';   // print value = 6
    }

    // Returning multiple values via out parameters
    {
        double sin(0.0);
        double cos(0.0);

        // getSinCos will return the sin and cos in variables sin and cos
        getSinCos(30.0, sin, cos);

        std::cout << "The sin is " << sin << '\n';  // print The sin is 0.5
        std::cout << "The cos is " << cos << '\n';  // print The cos is 0.866025
    }
    return 0;
}
