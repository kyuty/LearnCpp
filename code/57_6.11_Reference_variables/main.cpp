#include <iostream>

// ref is a reference to the argument passed in, not a copy
void changeN(int &ref)
{
	ref = 6;
}

// ref is a const reference to the argument passed in, not a copy
void changeN_1(const int &ref)
{
	// ref = 6; // not allowed, ref is const
}

int main()
{
    // References
    {
        int value = 5; // normal integer
        int &ref = value; // reference to variable value
        value = 6; // value is now 6
        ref = 7; // value is now 7

        std::cout << value << "\n"; // prints 7
        std::cout << ref << "\n"; // prints 7
        ++ref;
        std::cout << value << "\n"; // prints 8
        std::cout << ref << "\n"; // prints 8

        std::cout << &value << "\n"; // prints 0012FF7C
        std::cout << &ref << "\n"; // prints 0012FF7C
    }
    {
        const int x = 5;
        //int &ref = x; // invalid, non-const reference to const object
    }

    // References are implicitly const
    {
        int value = 5;
        int &ref = value; // valid reference

        //int &invalidRef; // invalid, needs to reference something
    }
    {
        int value1 = 5;
        int value2 = 6;
        int &ref = value1; // okay, ref is now an alias for value1

        std::cout << value1 << "\n";
        std::cout << value2 << "\n";
        std::cout << ref << "\n";

        ref = value2;   // assigns 6 (the value of value2) to value1 -- does NOT change the reference!
                        // ref还是value1的alias，不是value2的alias
                        // 对ref的理解就是：ref就是value1(初始化的时候是value1).后面遇到的ref都可以用value1来替代

        std::cout << "value1 = " << value1 << "\n";
        std::cout << "value2 = " << value2 << "\n";
        std::cout << "ref = " << ref << "\n";

        //----------------------------------------------

        int temp1 = 9;
        int temp2 = 8;
        int* ptr_temp1 = &temp1;

        std::cout << temp1 << "\n";
        std::cout << temp2 << "\n";
        std::cout << *ptr_temp1 << "\n";

        //ptr_temp1 = &temp2;
        *ptr_temp1 = temp2;

        std::cout << "temp1 = " << temp1 << "\n";
        std::cout << "temp2 = " << temp2 << "\n";
        std::cout << "*ptr_temp1 = " << *ptr_temp1 << "\n";
    }

    // Const references
    {
        const int value = 5;
        const int &ref = value; // ref is a const reference to value
    }

    // Const references to literal values
    {
        const int &rnRef = 6;
    }

    // References as function parameters
    {
        int n = 5;

        std::cout << n << '\n';

        changeN(n); // note that this is a non-reference argument

        std::cout << n << '\n';
    }

    // References as shortcuts
    {
        struct Something
        {
            int value1;
            float value2;
        };

        struct Other
        {
            Something something;
            int otherValue;
        };

        Other other;

        int &ref = other.something.value1;
        // ref can now be used in place of other.something.value1

        other.something.value1 = 5;
        ref = 5;
    }

    // References vs pointers
    {
        int value = 5;
        int *const ptr = &value;
        int &ref = value;

        *ptr = 5;
        ref = 5;
    }
    return 0;
}
