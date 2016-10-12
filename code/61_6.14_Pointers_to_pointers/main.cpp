#include <iostream>

using namespace std;

int main()
{
    // Pointers to pointers
    {
        int value = 5;

        int *ptr = &value;
        std::cout << *ptr << "\n"; // dereference pointer to int to get int value

        int **ptrptr = &ptr;
        std::cout << **ptrptr << "\n"; // first dereference to get pointer to int, second dereference to get int value
    }
    {
        int value = 5;
        //int **ptrptr = &&value; // not valid
        int **ptrptr = nullptr; // use 0 instead prior to C++11
    }

    // Two-dimensional dynamically allocated arrays
    {
        //int **array = new int[10][5]; // won¡¯t work!
        int (*array_0)[5] = new int[10][5];
        auto array_1 = new int[10][5]; // so much simpler!
    }
    {
        int **array_0 = new int*[10]; // allocate an array of 10 int pointers ¡ª these are our rows
        for (int count = 0; count < 10; ++count)
            array_0[count] = new int[5]; // these are our columns
    }
    {
        int **array_1 = new int*[10]; // allocate an array of 10 int pointers ¡ª these are our rows
        for (int count = 0; count < 10; ++count)
            array_1[count] = new int[count+1]; // these are our columns

        for (int count = 0; count < 10; ++count)
            delete[] array_1[count];
        delete[] array_1; // this needs to be done last
    }
    return 0;
}
