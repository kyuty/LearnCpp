#include <iostream>

namespace Foo
{
    namespace Goo
    {
        const int g_x = 5;
    }
}

namespace Boo = Foo::Goo; // Boo now refers to Foo::Goo

int main()
{
    {
        std::cout << Foo::Goo::g_x << "\n";     // print 5
    }

    {
        std::cout << Boo::g_x << "\n"; // This is really Foo::Goo::g_x      // print 5
    }

    return 0;
}
