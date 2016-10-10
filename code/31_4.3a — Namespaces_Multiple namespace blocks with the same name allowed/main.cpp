#include <iostream>
#include "add.h"        // import BasicMath::add()
#include "subtract.h"   // import BasicMath::subtract()

using namespace std;

int main()
{
    cout << BasicMath::add(4, 3) << endl;
    cout << BasicMath::subtract(4, 3) << endl;

    return 0;
}
