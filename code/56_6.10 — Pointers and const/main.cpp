#include <iostream>

/*
const int* ptr = &value; --> 不管value是int类型还是const int类型, 都不能通过 *ptr = ortherValue; 改变value的值.
int *const ptr = &value; --> ptr永远指向value的地址(
                                                    如果value是int类型,则可以通过 *ptr = ortherValue; 改变value的值.
                                                    如果value是const int类型,则不可以通过 *ptr = ortherValue; 改变value的值.
                                                    )
*/

int main()
{
    // Pointing to const variables === first
    {
        int value = 5;
        int *ptr = &value;
        *ptr = 6; // change value to 6
    }
    {
        const int value = 5; // value is const
        //int *ptr = &value; // compile error: cannot convert const int* to int*
        //*ptr = 6; // change value to 6
    }
    // Pointing to const variables === end

    // Pointer to const value === first
    {
        const int value = 5;
        const int *ptr = &value; // this is okay, ptr is pointing to a "const int"
        //*ptr = 6; // not allowed, we can't change a const value
    }
    {
        int value = 5; // value is not constant
        const int *ptr = &value; // this is still okay
    }
    {
        int value = 5;
        const int *ptr = &value; // ptr points to a "const int"
        value = 6; // the value is non-const when accessed through a non-const identifier
    }
    {
        int value = 5;
        const int *ptr = &value; // ptr points to a "const int"
        //*ptr = 6; // ptr treats its value as const, so changing the value through ptr is not legal
    }
    {
        int value1 = 5;
        const int *ptr = &value1; // ptr points to a const int

        int value2 = 6;
        ptr = &value2; // okay, ptr now points at some other const int
    }
    // Pointer to const value === end

    // Const pointers === first
    {
        int value = 5;
        int *const ptr = &value;
    }
    {
        int value1 = 5;
        int value2 = 6;

        int * const ptr = &value1; // okay, the const pointer is initialized to the address of value1
        //ptr = &value2; // not okay, once initialized, a const pointer can not be changed.
    }
    {
        int value = 5;
        int *const ptr = &value; // ptr will always point to value
        *ptr = 6; // allowed, since ptr points to a non-const int
    }
    // Const pointers === end

    // Const pointer to a const value
    {
        int value = 5;
        const int *const ptr = &value;
    }

    // Recappinguo
    {
        int value = 5;
        const int *ptr1 = &value; // ptr1 points to a "const int", so this is a pointer to a const value.
        int *const ptr2 = &value; // ptr2 points to an "int", so this is a const pointer to a non-const value.
    }
    return 0;
}
