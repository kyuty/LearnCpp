#include <iostream>

enum Type
{
    INT,
    FLOAT,
    CSTRING,
};

void printValue(void *ptr, Type type)
{
    switch (type)
    {
        case INT:
            std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and dereference
            break;
        case FLOAT:
            std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and dereference
            break;
        case CSTRING:
            std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer and dereference
            break;
    }
}

int main()
{
    {
        struct Something
        {
            int n;
            float f;
        };
        int nValue;
        float fValue;
        Something sValue;

        void *ptr;
        ptr = &nValue; // valid
        ptr = &fValue; // valid
        ptr = &sValue; // valid
    }

    {
        int value = 5;
        void *voidPtr = &value;

        //cout << *voidPtr << endl; // illegal: cannot dereference a void pointer

        int *intPtr = static_cast<int*>(voidPtr); // however, if we cast our void pointer to an int pointer...

        std::cout << *intPtr << std::endl; // then we can dereference it like normal
    }

    {
        int nValue = 5;
        float fValue = 7.5;
        char szValue[] = "Mollie";

        printValue(&nValue, INT);
        printValue(&fValue, FLOAT);
        printValue(szValue, CSTRING);
    }
    return 0;
}
