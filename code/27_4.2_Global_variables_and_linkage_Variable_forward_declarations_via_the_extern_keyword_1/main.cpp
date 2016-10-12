#include <iostream>

extern const double g_gravity;  // will not find g_gravity in constants.cpp
                                // because g_gravity has internal linkage.

int main()
{
    std:: cout << g_gravity;    // will cause compile error
                                // because g_gravity has not been defined as far as main.cpp knows
    return 0;
}
