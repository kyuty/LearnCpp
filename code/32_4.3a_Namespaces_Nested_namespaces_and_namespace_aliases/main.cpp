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
        std::cout << Foo::Goo::g_x << "\n";
    }

    {
        std::cout << Boo::g_x << "\n"; // This is really Foo::Goo::g_x
    }

    return 0;
}
