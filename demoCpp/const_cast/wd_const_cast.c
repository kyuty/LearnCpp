#include <stdio.h>
void foo()
{
    const int a = 1;
    int *p = const_cast<int *>(&a);
    printf("p = %p, &a = %p\n", p, &a);
    *p = 2;
    const bool isEqual = &a == p;
    printf("a = %d, *p = %d, isEqual = %d\n", a, *p, isEqual?1:0);
}

int main() {
    foo();
    return 0;
}
/*
 使用const_cast<>(a)这个函数，会保存const a的值（保护现场，汇编的时候，const_cast把a压到栈中了），
 使用p来输出没有问题，但是使用a的时候会恢复现场，从栈中再取出a。

 即：*p和a的地址都一样，而且这个地址内的值也变化了，只是使用a的时候，会把栈中的a取出来使用。
 */
