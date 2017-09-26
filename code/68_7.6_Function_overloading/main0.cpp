#include <iostream>

void print(char *value)
{
    std::cout << "void print(char *value)" << std::endl;
}

void print(int value)
{
    std::cout << "void print(int value)" << std::endl; // print it
}

int main()
{
    print(0);
    return 0;
}

// Although 0 could technically match print(char*) (as a null pointer), it exactly matches print(int).
// Thus print(int) is the best match available.
