#include <iostream>
#include <typeinfo>//use typeid

int main()
{
    // The address-of operator (&)
    {
        int x = 5;
        std::cout << x << '\n';     // print the value of variable x
        std::cout << &x << '\n';    // print the memory address of variable x
    }

    // The dereference operator (*)
    {
        int x = 5;
        std::cout << x << '\n';     // print the value of variable x
        std::cout << &x << '\n';    // print the memory address of variable x
        std::cout << *&x << '\n';   // print the value at the memory address of variable x
    }

    // Declaring a pointer
    {
        int *iPtr;      // a pointer to an integer value
        double *dPtr;   // a pointer to a double value

        int* iPtr2;     // also valid syntax (acceptable, but not favored)
        int * iPtr3;    // also valid syntax (but don't do this)

        int *iPtr4, *iPtr5;     // declare two pointers to integer variables

        int* iPtr6, iPtr7;      // iPtr6 is a pointer to an int, but iPtr7 is just a plain int!
        iPtr7 = 3;
        iPtr6 = &iPtr7;
    }

    // Assigning a value to a pointer
    {
        int value = 5;
        int *ptr = &value;  // initialize ptr with address of variable value

        std::cout << &value << '\n';    // print the address of variable value
        std::cout << ptr << '\n';       // print the address that ptr is holding
    }
    {
        int iValue = 5;
        double dValue = 7.0;

        int *iPtr = &iValue; // ok
        double *dPtr = &dValue; // ok
        //iPtr = &dValue; // wrong -- int pointer cannot point to the address of a double variable
        //dPtr = &iValue; // wrong -- double pointer cannot point to the address of an int variable

        //int *ptr = 5;
        //double *dPtr = 0012FF7C; // not okay, treated as assigning an integer literal
    }

    // The address-of operator returns a pointer
    {
        int x(4);
        std::cout << typeid(&x).name() << "\n";     // print Pi
        
        float y(1.0);
        std::cout << typeid(&y).name() << "\n";     // print Pf

        /*
            On Visual Studio 2013, this printed: int *
            With gcc, this prints “pi” (pointer to integer) instead
        */
    }

    // Dereferencing pointers
    {
        int value = 5;
        std::cout << &value << "\n"; // prints address of value
        std::cout << value << "\n"; // prints contents of value

        int *ptr = &value; // ptr points to value
        std::cout << ptr << "\n"; // prints address held in ptr, which is &value
        std::cout << *ptr << "\n"; // dereference ptr (get the value that ptr is pointing to)
    }
    {
        int value = 5;
        int *ptr = &value; // ptr points to value

        *ptr = 7; // *ptr is the same as value, which is assigned 7
        std::cout << value << "\n"; // prints 7
    }

    // The size of pointers
    {
        char *chPtr; // chars are 1 byte
        int *iPtr; // ints are usually 4 bytes
        struct Something
        {
            int nX, nY, nZ;
        };
        Something *somethingPtr; // Something is probably 12 bytes

        std::cout << sizeof(chPtr) << '\n';         // prints 8
        std::cout << sizeof(iPtr) << '\n';          // prints 8
        std::cout << sizeof(somethingPtr) << '\n';  // prints 8
    }
    return 0;
}
