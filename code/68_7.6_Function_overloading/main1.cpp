#include <iostream>

void print(char *value)
{
    std::cout << "void print(char *value)" << std::endl;
}

void print(int value)
{
    std::cout << "void print(int value)" << std::endl; // print it.
}

int main()
{
    print('a');
    return 0;
}

// In this case, because there is no print(char), the char ‘a’ is promoted to an integer, which then matches print(int).
