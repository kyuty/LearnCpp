#include <iostream>

// Variables declared outside of a block are global variables
int g_x; // global variable g_x
const int g_y(2); // global variable g_y
int value(5); // global variable

static int g_x_1(1); // g_x_1 is static, and can only be used within this file
extern double g_y_1(9.8);   // g_y_1 is external, and can be used by other files
                            // 若没有其他文件,或其他文件没有定义g_y_1变量,那么这里必须写extern double g_y_1(9.8);
                            // 否则,这里可以写成extern double g_y_1;
                            // 换句话说，extern的变量，必须有定义。
                            // extern double g_y_1(9.8);--->这是定义
                            // extern double g_y_1;--->这是声明;extern意思是在该文件里打开一扇窗,可以找到外部文件中的g_y_1变量

void doSomething()
{
    // global variables can be seen and used everywhere in program
    g_x = 3;
    std::cout << g_y << "\n";
}

// This function is declared as static, and can now be used only within this file
// Attempts to access it via a function prototype will fail
static int add(int x, int y)
{
    return x + y;
}

int main()
{
    {
        // global variables can be seen everywhere in program
        g_x = 5;
        std::cout << g_y << "\n";   // print 2
    }

    {
        int value = 7; // hides the global variable value
        value++; // increments local value, not global value
        ::value--; // decrements global value, not local value

        std::cout << "local value: " << value << "\n";      // print 8
        std::cout << "global value: " << ::value << "\n";   // print 4
    }

    {
        std::cout << g_x_1 << "\n";     // print 1
        g_x_1 = 2;
        std::cout << g_x_1 << "\n";     // print 2

        std::cout << g_y_1 << "\n";     // print 9.8
        g_y_1 = 3;
        std::cout << g_y_1 << "\n";     // print 3
    }

    return 0;
}
