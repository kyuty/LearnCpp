// NOTE: this is not #include <iostream>, 
// because 'void doSomething()' already include.
// But, 'using namespace std;' 'std' use 'include <iostream>', 'int' is not use.
void doSomething(); // forward declaration for function doSomething()

int main()
{
#define PRINT
    doSomething();
    return 0;
}
