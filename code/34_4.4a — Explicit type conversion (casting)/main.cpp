#include <iostream>

int main()
{
    {
        int i1 = 10;
        int i2 = 4;
        float f = i1 / i2;
        std::cout << f << "\n";
    }
    // Type casting === first
    {
        // C-style casts === first
        {
            int i1 = 10;
            int i2 = 4;
            float f = (float)i1 / i2;
            std::cout << f << "\n";
        }
        {
            int i1 = 10;
            int i2 = 4;
            float f = float(i1) / i2;
            std::cout << f << "\n";
        }
        // C-style casts === end

        // static_cast === first
        {
            char c = 97;
            std::cout << static_cast<int>(c) << std::endl; // prints 97, not 'a'
        }
        {
            int i1 = 10;
            int i2 = 4;
            float f = static_cast<float>(i1) / i2;
            std::cout << f << "\n";
        }
        // static_cast === end
    }
    // Type casting === end
    return 0;
}
