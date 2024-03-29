#include <iostream> // for std::cout and std::endl

using namespace std;

#ifdef __cplusplus
#define ANDROID_NATIVE_UNSIGNED_CAST(x) static_cast<unsigned int>(x)
#else
#define ANDROID_NATIVE_UNSIGNED_CAST(x) ((unsigned int)(x))
#endif

#define ANDROID_NATIVE_MAKE_CONSTANT(a,b,c,d)  \
    ((ANDROID_NATIVE_UNSIGNED_CAST(a) << 24) | \
     (ANDROID_NATIVE_UNSIGNED_CAST(b) << 16) | \
     (ANDROID_NATIVE_UNSIGNED_CAST(c) <<  8) | \
     (ANDROID_NATIVE_UNSIGNED_CAST(d)))

#define ANDROID_NATIVE_BUFFER_MAGIC     ANDROID_NATIVE_MAKE_CONSTANT('_','b','f','r')

// Definition of function doPrint()
void doPrint() // doPrint() is the called function in this example
{
    std::cout << "In doPrint()" << std::endl;
    int a = ANDROID_NATIVE_BUFFER_MAGIC;
    std::cout << a << std::endl;
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()" << std::endl;
    doPrint(); // Interrupt main() by making a function call to doPrint().  main() is the caller.
    std::cout << "Ending main()" << std::endl;
    return 0;
}


//The function initiating the function call is called the caller,
//and the function being called is the callee or called function.
