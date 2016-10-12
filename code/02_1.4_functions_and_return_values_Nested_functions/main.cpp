#include <iostream>

int foo() // no longer inside of main()
{
    std::cout << "foo!";
    return 0;
}

int main()
{
    /*
    int foo() // this function is nested inside main(), which is illegal.
    {
        std::cout << "foo!";
        return 0;
    }
    */

    foo();
    return 0;
}
