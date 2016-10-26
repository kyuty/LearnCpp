#include <iostream>

void incrementAndPrint()
{
    using namespace std;
    int value = 1; // automatic duration by default
    ++value;
    cout << value << endl;
} // value is destroyed here

void incrementAndPrint_1()
{
    using namespace std;
    static int s_value = 1; // static duration via static keyword.  This line is only executed once.
    ++s_value;
    cout << s_value << endl;
} // s_value is not destroyed here, but becomes inaccessible

int main()
{
    incrementAndPrint();    // print 2
    incrementAndPrint();    // print 2
    incrementAndPrint();    // print 2

    incrementAndPrint_1();  // print 2
    incrementAndPrint_1();  // print 3
    incrementAndPrint_1();  // print 4
}
