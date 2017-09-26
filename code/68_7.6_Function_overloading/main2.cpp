#include <iostream>

void print(unsigned int value)
{
    std::cout << "void print(unsigned int value)" << std::endl;
}

void print(float value)
{
    std::cout << "void print(float value)" << std::endl;
}

int main()
{
    print('a');
    print(0);
    print(3.1415);
    return 0;
}
