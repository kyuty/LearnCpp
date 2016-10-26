#include <iostream>
#include <iomanip> // for std::setprecision()
#include <typeinfo> // for typeid()

int main()
{
    // Numeric conversions === first
    {
        int i = 30000;  //0111 0101 0011 0000
        char c = i;     //0011 0000

        std::cout << static_cast<int>(c) << std::endl;      // print 48
    }
    {
        int i = 2;
        short s = i; // convert from int to short
        std::cout << s << "\n";     // print 2

        double d = 0.1234;
        float f = d;
        std::cout << f << "\n";     // print 0.1234
    }
    {
        float f = 0.123456789; // double value 0.123456789 has 9 significant digits, but float can only support about 7
        std::cout << std::setprecision(9) << f << "\n";     // print 0.123456791
    }
    {
        int i = 10;
        float f = i;
        std::cout << f << "\n";     // print 10
    }
    {
        int i = 3.5;
        std::cout << i << "\n";     // print 3
    }
    // Numeric conversions === end

    // Evaluating arithmetic expressions === first
    {
        short a(4);
        short b(5);
        std::cout << typeid(a + b).name() << " " << a + b << std::endl; // show us the type of a + b
                                                                        // print i 9
    }
    {
        double d(4.0);
        short s(2);
        std::cout << typeid(d + s).name() << " " << d + s << std::endl; // show us the type of d + s
                                                                        // print d 6
    }
    {
        std::cout << 5u - 10 << "\n";   // 5u means treat 5 as an unsigned integer
                                        // print 4294967291
        /*
        In this case, the signed integer (10) is promoted to an unsigned integer (which has higher priority),
        and the expression is evaluated as an unsigned int.
        Overflow results, and we get an answer we don¡¯t expect.

        This is one of many good reasons to avoid unsigned integers in general.

        在这种情况下，有符号整数（10）被提升为无符号整数（具有较高优先级），
        并且表达式被计算为unsigned int。
        溢出结果，我们得到一个我们不期望的答案。

        这是避免使用无符号整数的许多好的原因之一。
        */
    }
    // Evaluating arithmetic expressions === end
    return 0;
}
