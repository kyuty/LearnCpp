#include <iostream>

// Case labels
bool isDigit(char c)
{
    switch (c)
    {
        case '0': // if c is 0
        case '1': // or if c is 1
        case '2': // or if c is 2
        case '3': // or if c is 3
        case '4': // or if c is 4
        case '5': // or if c is 5
        case '6': // or if c is 6
        case '7': // or if c is 7
        case '8': // or if c is 8
        case '9': // or if c is 9
            return true; // then return true
        default:
            return false;
    }
}

int main()
{
    // Switch execution and fall-through
    {
        switch (2)
        {
           case 1: // Does not match
               std::cout << 1 << '\n'; // skipped
           case 2: // Match!
               std::cout << 2 << '\n'; // Execution begins here
           case 3:
               std::cout << 3 << '\n'; // This is also executed
           case 4:
               std::cout << 4 << '\n'; // This is also executed
           default:
               std::cout << 5 << '\n'; // This is also executed
        }
    }

    // Break statements
    {
        switch (2)
        {
           case 1: // Does not match -- skipped
               std::cout << 1 << '\n';
               break;
           case 2: // Match!  Execution begins at the next statement
               std::cout << 2 << '\n'; // Execution begins here
               break; // Break terminates the switch statement
           case 3:
               std::cout << 3 << '\n';
               break;
           case 4:
               std::cout << 4 << '\n';
               break;
           default:
               std::cout << 5 << '\n';
               break;
        }
        // Execution resumes here
    }

    // Multiple statements inside a switch block
    {
        switch (1)
        {
            case 1:
                std::cout << 1 << "\n";
                //foo();
                std::cout << 2 << "\n";
                break;
            default:
                std::cout << "default case\n";
                break;
        }
    }

    // You can declare, but not initialize, variables inside the case statements
    {
        switch (1)
        {
            case 1:
                int y; // okay, declaration is allowed
                y = 4; // okay, this is an assignment
                break;

            case 2:
                y = 5; // okay, y was declared above, so we can use it here too
                break;

            case 3:
                //int z = 4; // illegal, you can't initialize new variables in the case statements

                            // However, initialization of variables directly underneath a case label is disallowed and will cause a compile error.
                            // This is because initializing a variable does require execution,
                            // and the case statement containing the initialization may not be executed!
                break;

            default:
                std::cout << "default case" << std::endl;
                break;
        }
    }

    // Rule: If defining variables used in a case statement,
    // do so in a block inside the case (or before the switch if appropriate)
    {
        switch (1)
        {
            case 1:
            { // note addition of block here
                int x = 4; // okay, variables can be initialized inside a block inside a case
                std::cout << x;
                break;
            }
            default:
                std::cout << "default case" << std::endl;
                break;
        }

    }
    return 0;
}
