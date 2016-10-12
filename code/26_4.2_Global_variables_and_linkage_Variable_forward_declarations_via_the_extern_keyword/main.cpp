#include <iostream>

extern int g_x; // forward declaration for g_x -- g_x can be used beyond this point in this file

int main()
{

    g_x = 5;
    std::cout << g_x << "\n";

    {
        extern int g_y; // forward declaration for g_y -- g_y can be used beyond this point in main()

        std::cout << g_y << "\n"; // should print 2
    }

    // std::cout << g_y; // was not declared in this scope

    return 0;
}
/*
extern
    在源文件A里定义的函数，在其它源文件里是看不见的（即不能访问）。为了在源文件B里能调用这个函数，应该在B的头部加上一个外部声明：

  extern   函数原型；
  这样，在源文件B里也可以调用那个函数了。
  注意这里的用词区别：在A里是定义，在B里是声明。
  一个函数只能（也必须）在一个源文件里被定义，但是可以在其它多个源文件里被声明。
  定义引起存储分配，是真正产生那个实体。而声明并不引起存储分配。

  打一个粗俗的比方：在源文件B里声明后，好比在B里开了一扇窗，让它可以看到A里的那个函数。


  declaration   声明  extern int x;   extern int add(int x, int y);
  define        定义  int x;          extern int add(int x, int y){return x+y;}
*/
