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
    ��Դ�ļ�A�ﶨ��ĺ�����������Դ�ļ����ǿ������ģ������ܷ��ʣ���Ϊ����Դ�ļ�B���ܵ������������Ӧ����B��ͷ������һ���ⲿ������

  extern   ����ԭ�ͣ�
  ��������Դ�ļ�B��Ҳ���Ե����Ǹ������ˡ�
  ע��������ô�������A���Ƕ��壬��B����������
  һ������ֻ�ܣ�Ҳ���룩��һ��Դ�ļ��ﱻ���壬���ǿ������������Դ�ļ��ﱻ������
  ��������洢���䣬�����������Ǹ�ʵ�塣��������������洢���䡣

  ��һ�����׵ıȷ�����Դ�ļ�B�������󣬺ñ���B�￪��һ�ȴ����������Կ���A����Ǹ�������


  declaration   ����  extern int x;   extern int add(int x, int y);
  define        ����  int x;          extern int add(int x, int y){return x+y;}
*/
