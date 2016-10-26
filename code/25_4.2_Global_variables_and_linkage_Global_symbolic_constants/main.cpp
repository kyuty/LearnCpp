#include <iostream>
#include "constants.h"

int main()
{
    double radius = 1.0;
    double circumference = 2 * radius * Constants::pi;
    std::cout << circumference << "\n";		// print 6.28318

    return 0;
}

/*
// Uninitialized definition:
int g_x;       // defines uninitialized global variable (external linkage)
const int g_x; // not allowed: const variables must be initialized

// Forward declaration via extern keyword:
extern int g_z;       // forward declaration for global variable defined elsewhere
extern const int g_z; // forward declaration for const global variable defined elsewhere

// Initialized definition:
int g_y(1);       // defines initialized global variable (external linkage)
const int g_y(1); // defines initialized static variable (internal linkage)

// Initialized definition w/extern keyword:
extern int g_w(1);       // defines initialized global variable (external linkage, extern keyword is redundant in this case)
extern const int g_w(1); // defines initialized const global variable (external linkage)

========================================================================

//未初始化的定义：
int g_x; 		//定义未初始化的全局变量（外部链接）
const int g_x; 	//不允许：const变量必须初始化

// 通过extern关键字转发声明：
extern int g_z; 		//在其他地方定义的全局变量的forward声明
extern const int g_z; 	//在其他地方定义的const全局变量的forward声明

//初始化定义：
int g_y（1）; 		//定义初始化的全局变量（外部链接）
const int g_y（1）; 	//定义初始化的静态变量（内部链接）

//初始化定义w / extern关键字：
extern int g_w（1）; 		//定义初始化的全局变量（外部链接，extern关键字在这种情况下是冗余的）
extern const int g_w（1）; 	//定义初始化的const全局变量（外部链接）
*/
