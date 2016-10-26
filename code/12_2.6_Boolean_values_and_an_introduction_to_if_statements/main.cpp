#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y)
{
    return (x == y); // operator== returns true if x equals y, and false otherwise
}

int main()
{

    {
        bool b1 = true; // explicit initialization
        bool b2(false); // implicit initialization
        bool b3 { true }; // uniform initialization (C++11)
    }

    {
        bool b1 = !true; // b1 will have the value false
        bool b2(!false); // b2 will have the value true
    }

    {
        bool b(true);
        std::cout << b << std::endl;
        std::cout << !b << std::endl;

        bool b2(false);
        std::cout << b2 << std::endl;
        std::cout << !b2 << std::endl;

        /*
            1
            0
            0
            1
        */
    }

    {
        std::cout << true << std::endl;
        std::cout << false << std::endl;
        std::cout << std::boolalpha; // print bools as true or false
        std::cout << true << std::endl;
        std::cout << false << std::endl;

        /*
            1
            0
            true
            false
        */
    }

    {
        std::cout << "Enter an integer: ";
        int x;
        std::cin >> x;

        std::cout << "Enter another integer: ";
        int y;
        std::cin >> y;

        bool equal = isEqual(x, y);
        if (equal)
            std::cout << x << " and " << y << " are equal" << std::endl;
        else
            std::cout << x << " and " << y << " are not equal" << std::endl;

        /*
            Enter an integer: 1
            Enter another integer: 2
            1 and 2 are not equal
        */
    }

    return 0;
}

/*
1
0
0
1

1
0
true
false
Enter an integer: 1
Enter another integer: 2
1 and 2 are not equal
*/