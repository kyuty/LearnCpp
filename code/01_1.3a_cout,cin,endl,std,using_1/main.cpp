#include <iostream>

//A collision example

int cout() // declares our own "cout" function
{
    return 5;
}

int main()
{
    using namespace std; // makes std::cout accessible as "cout"
    cout << "Hello, world!"; // uh oh!  Which cout do we want here?

    //the compiler is unable to determine
    // whether we meant std::cout or the cout function we've defined.
    //In this case, it will fail to compile with an "ambiguous symbol" error.
    return 0;
}
