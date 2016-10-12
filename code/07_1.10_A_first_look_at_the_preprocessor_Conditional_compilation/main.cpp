#include <iostream>

using namespace std;

#define PRINT_JOE

int main()
{
    #ifdef PRINT_JOE
    cout << "ifdef Joe" << endl;
    #endif

    #ifndef PRINT_JOE
    cout << "ifndef Joe" << endl;
    #endif

    #ifdef PRINT_BOB
    cout << "ifdef Bob" << endl;
    #endif

    #ifndef PRINT_BOB
    cout << "ifndef Bob" << endl;
    #endif


    return 0;
}
