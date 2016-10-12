#include <iostream>

// This function has two integer parameters, one named x, and one named y
// The values of x and y are passed in by the caller
void printValues(int x, int y)
{
    std::cout << x << std::endl;
    std::cout << y << std::endl;
}

int main()
{
    printValues(6, 7); // This function call has two arguments, 6 and 7

    return 0;
}
/*
When printValues() is called with arguments 6 and 7,
printValues¡¯s parameter x is created and assigned the value of 6,
and printValues¡¯s parameter y is created and assigned the value of 7.

6,7 arguments
x,y parameter
*/
