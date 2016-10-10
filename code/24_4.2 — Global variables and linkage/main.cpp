#include <iostream>

// Variables declared outside of a block are global variables
int g_x; // global variable g_x
const int g_y(2); // global variable g_y
int value(5); // global variable

static int g_x_1(1); // g_x_1 is static, and can only be used within this file
extern double g_y_1(9.8);   // g_y_1 is external, and can be used by other files
                            // ��û�������ļ�,�������ļ�û�ж���g_y_1����,��ô�������дextern double g_y_1(9.8);
                            // ����,�������д��extern double g_y_1;
                            // extern double g_y_1(9.8);--->���Ƕ���
                            // extern double g_y_1;--->��������;extern��˼���ڸ��ļ����һ�ȴ�,�����ҵ��ⲿ�ļ��е�g_y_1����

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
        std::cout << g_y << "\n";
    }

    {
        int value = 7; // hides the global variable value
        value++; // increments local value, not global value
        ::value--; // decrements global value, not local value

        std::cout << "local value: " << value << "\n";
        std::cout << "global value: " << ::value << "\n";
    }

    {
        std::cout << g_x_1 << "\n";
        g_x_1 = 2;
        std::cout << g_x_1 << "\n";

        std::cout << g_y_1 << "\n";
        g_y_1 = 3;
        std::cout << g_y_1 << "\n";
    }

    return 0;
}
