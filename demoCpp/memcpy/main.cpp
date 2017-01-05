#include <iostream>
#include <vector>

struct Data
{
    int a;
    std::vector<int> vector;
    Data(int x)
    {
        a = x;
    }
};

int main()
{
    Data* ori = new Data(1);
    std::cout << sizeof(ori->vector) << std::endl;
    ori->vector.push_back(100);
    ori->vector.push_back(111);
    std::cout << sizeof(ori->vector) << std::endl;
    ori->vector.push_back(222);
    ori->vector.push_back(333);
    std::cout << sizeof(ori) << std::endl;
    std::cout << ori->vector.size() << std::endl;
    std::cout << sizeof(ori->vector) << std::endl;

    Data* copy = new Data(2);
    std::cout << copy->a << std::endl;
    memcpy(copy, ori, 4);
    std::cout << copy->a << std::endl;

    std::cout << "================\n";
    memcpy(copy, ori, 8);
    std::cout << copy->a << std::endl;
    std::cout << copy->vector.size() << std::endl;
    //std::cout << copy->vector[0] << std::endl;
    //memcpy(&(copy->vector), &(ori->vector), 24);
    //std::cout << copy->vector.size() << std::end;

    return 0;
}
/*
 * g++ main.cpp -o main.o && ./main.o
 * 24
 * 24
 * 8
 * 4
 * 24
 * 2
 * 1
 * ================
 * 1
 * 0
 */
