#include <iostream>

// getValueFromUser will read a value in from the user, and return it to the caller
int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int a;
    std::cin >> a;
    return a;
}

void printA()
{
    std::cout << "A" << std::endl;
}

void printB()
{
    std::cout << "B" << std::endl;
}

// function printAB() calls both printA() and printB()
void printAB()
{
    printA();
    printB();
}


int main()
{
    {
        std::cout << "Starting main()" << std::endl;
        printAB();
        std::cout << "Ending main()" << std::endl;
    }

    {
        int x = getValueFromUser(); // first call to getValueFromUser
        int y = getValueFromUser(); // second call to getValueFromUser

        std::cout << x << " + " << y << " = " << x + y << std::endl;
    }

    return 0;
}
