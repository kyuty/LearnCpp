#include <iostream>
#include "foo.h"
#include "goo.h"

int main()
{
    {
        std::cout << Foo::doSomething(4, 3) << std::endl;
    }

    {
        std::cout << Goo::doSomething(4, 3) << std::endl;
    }

    {
        std::cout << Foo::doSomething(4, 3) << std::endl;
        std::cout << Goo::doSomething(4, 3) << std::endl;
    }

    {
        using namespace Foo; // look in namespace Foo
        std::cout << doSomething(4, 3) << std::endl; // calls Foo::doSomething()
    }

    {
        using Foo::doSomething; // Tell compiler that doSomething() means Foo::doSomething()
        std::cout << doSomething(4, 3) << std::endl; // will resolve to Foo::doSomething()
    }

    return 0;
}
