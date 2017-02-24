// NOTE: this is not #include <iostream>, 
// because 'void doSomething()' already include.
void doSomething(); // forward declaration for function doSomething()

int main()
{
#define PRINT
    doSomething();
    return 0;
}
