#include <iostream>
#include <cmath> // for sqrt() function

int main()
{
    double x;
tryAgain: // this is a statement label
    std::cout << "Enter a non-negative number:";
    std::cin >> x;
    std::cin.ignore(32767,'\n');

    if (x < 0.0)
        goto tryAgain; // this is the goto statement

    std::cout << "The sqrt of " << x << " is " << sqrt(x) << std::endl;
    return 0;
}
