#include <iostream>

using namespace std;

int main()
{
    {
        int nValue = 5; // explicit initialization
        cout << nValue << endl;
    }
    {
        int nValue(5); // implicit initialization
        cout << nValue << endl;
    }
    {
        int value{5};   // uniform initialization
        cout << value << endl;
    }
    {
        int value{}; // default initialization to 0
        cout << value << endl;
    }

    {
        int a, b = 5; // bed (a is uninitialized!)
    }
    {
        int a= 5, b= 5; // correct
    }
    {
        int a, b(5);
        int c, d{5};
        cout << b << endl;
        cout << d << endl;
    }
}
/*
5
5
5
0
5
5
*/