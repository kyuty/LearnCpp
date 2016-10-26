#include <iostream>

using namespace std;

// declare global variable
int g_mode;

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
    g_mode = 1; // note: this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething();

    // Programmer still expects g_mode to be 1
    // But doSomething changed it to 2!

    if (g_mode == 1)
        cout << "No threat detected." << endl;
    else
        cout << "Launching nuclear missiles..." << endl;    // print this

    return 0;
}

/*
// 变量名改成 g_ 开头的
For example, instead of:
    double gravity (9.8); // unclear if this is a local or global variable from the name

    int main()
    {
        return 0;
    }
Do this:
    double g_gravity (9.8); // now clear this is a global variable from the name

    int main()
    {
        return 0;
    }
*/

/*
// 使用static将变量限定在当前文件中
For example, instead of:
    double g_gravity (9.8); // can be exported and used directly in any file
Do this:
    static double g_gravity (9.8); // restrict direct access to this file only
    double getGravity() // this function can be exported to other files to access the global outside of this file
                        // 此函数可以导出到其他文件以访问此文件的全局外部
    {
        // We could add logic here if needed later
        return g_gravity;
    }
*/
