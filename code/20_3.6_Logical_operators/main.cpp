#include <iostream>

using namespace std;

int main()
{
    // Logical NOT === first
    {
        int x = 5;
        int y = 7;

        if (! x == y)
            cout << "x does not equal y" << "\n";
        else
            cout << "x equals y" << "\n";

        /*
        the expression ! x == y actually evaluates as (!x) == y.
        Since x is 5, !x evaluates to 0, and 0 == y is false,
        so the else statement executes!
        */

        /*
            x equals y
        */
    }
    {
        int x = 5;
        int y = 7;

        if (!(x == y))
            cout << "x does not equal y" << "\n";
        else
            cout << "x equals y" << "\n";

        /*
            x does not equal y
        */

    }
    // Logical NOT === end

    return 0;
}
