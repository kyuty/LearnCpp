#include <iostream>

int main()
{
    using namespace std;
    // sizeof 是字节数，乘以 8 才是 bit 数
    cout << "bool:\t\t" << sizeof(bool) << " bytes\t" << sizeof(bool) * 8 << " bits" << endl;
    cout << "char:\t\t" << sizeof(char) << " bytes\t" << sizeof(char) * 8 << " bits" << endl;
    cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\t" << sizeof(wchar_t) * 8 << " bits" << endl;
    cout << "char16_t:\t" << sizeof(char16_t) << " bytes\t" << sizeof(char16_t) * 8 << " bits" << endl; // C++11, may not be supported by your compiler
    cout << "char32_t:\t" << sizeof(char32_t) << " bytes\t" << sizeof(char32_t) * 8 << " bits" << endl; // C++11, may not be supported by your compiler
    cout << "short:\t\t" << sizeof(short) << " bytes\t" << sizeof(short) * 8 << " bits" << endl;
    cout << "int:\t\t" << sizeof(int) << " bytes\t" << sizeof(int) * 8 << " bits" << endl;
    cout << "long:\t\t" << sizeof(long) << " bytes\t" << sizeof(long) * 8 << " bits" << endl;
    cout << "long long:\t" << sizeof(long long) << " bytes\t" << sizeof(long long) * 8 << " bits" << endl; // C++11, may not be supported by your compiler
    cout << "float:\t\t" << sizeof(float) << " bytes\t" << sizeof(float) * 8 << " bits" << endl;
    cout << "double:\t\t" << sizeof(double) << " bytes\t" << sizeof(double) * 8 << " bits" << endl;
    cout << "long double:\t" << sizeof(long double) << " bytes\t" << sizeof(long double) * 8 << " bits" << endl;

    int x;
    cout << "x is " << sizeof(x) << " bytes"<< endl;

    {
        float vTexCoors[] = {
            0.0f, 1.0f,
            1.0f, 1.0f,
            0.0f, 0.0f,
            1.0f, 0.0f,
            1.0f, 0.0f,
        };
        // sizeof(float) * 数组长度
        cout << "vTexCoors[] is " << sizeof(vTexCoors) << " bytes" << endl; // 32
        // 数组长度
        cout << "vTexCoors[] length is " << sizeof(vTexCoors) / sizeof(float) << " size" << endl; // 32
    }
    {
        float* vTexCoors = new float[10];
        vTexCoors[0] = 0.0f;
        vTexCoors[1] = 1.0f;
        vTexCoors[2] = 1.0f;
        vTexCoors[3] = 1.0f;
        vTexCoors[4] = 0.0f;
        vTexCoors[5] = 0.0f;
        vTexCoors[6] = 1.0f;
        vTexCoors[7] = 0.0f;
        // 指针，大小是 8
        cout << "vTexCoors* is " << sizeof(vTexCoors) << " bytes" << endl; // 8
        // float，大小是 4
        cout << "vTexCoors[0] is " << sizeof(vTexCoors[0]) << " bytes" << endl; // 4

        delete[] vTexCoors;
        vTexCoors = 0;
    }

    cout << "x is " << sizeof(x) << " bytes"<< endl;

    return 0;
}
/*
bool:		1 bytes	8 bits
char:		1 bytes	8 bits
wchar_t:	4 bytes	32 bits
char16_t:	2 bytes	16 bits
char32_t:	4 bytes	32 bits
short:		2 bytes	16 bits
int:		4 bytes	32 bits
long:		8 bytes	64 bits
long long:	8 bytes	64 bits
float:		4 bytes	32 bits
double:		8 bytes	64 bits
long double:	16 bytes	128 bits
x is 4 bytes
vTexCoors[] is 32 bytes
vTexCoors* is 8 bytes
vTexCoors[0] is 4 bytes
*/