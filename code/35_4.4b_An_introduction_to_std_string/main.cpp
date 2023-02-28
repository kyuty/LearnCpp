#include <iostream>
#include <string>
#include <sstream>

int main()
{
    // String input and output
    {
        std::string myName("Alex");
        std::cout << "My name is: " << myName << "\n";
    }

    {

        std::cout << "Enter your full name: ";
        std::string name;
        std::cin >> name;
        std::cin.ignore(32767, '\n');

        std::cout << "Enter your age: ";
        std::string age;
        std::cin >> age;
        std::cin.ignore(32767, '\n');

        std::cout << "Your name is " << name << " and your age is " << age << "\n";
        //Here��s the results from a sample run of this program:
        //    Enter your full name: John Doe
        //    Enter your age: 23
        //    Your name is John and your age is Doe
    }

    // Use std::getline() to input text
    {
        std::cout << "Enter your full name: ";
        std::string name;
        std::getline(std::cin, name); // read a full line of text into name

        std::cout << "Enter your age: ";
        std::string age;
        std::getline(std::cin, age); // read a full line of text into age

        std::cout << "Your name is " << name << " and your age is " << age << "\n";
    }

/*
    //Mixing std::cin and std::getline()
    {
        std::cout << "Pick 1 or 2: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(32767, '\n');

        std::cout << "Now enter your name: ";
        std::string name;
        std::getline(std::cin, name);

        std::cout << "Hello, " << name << ", you picked " << choice << '\n';
    }
*/

    // Appending strings
    {
        std::string a("45");
        std::string b("11");

        std::cout << a + b << "\n"; // a and b will be appended, not added // print 4511
        a += " volts";
        std::cout << a << "\n"; // print 45 volts
    }

    // String length
    {
        std::string myName("Alex");
        std::cout << myName << " has " << myName.length() << " characters\n"; // Alex has 4 characters
    }

/*
    // Write a program that asks the user to enter their full name and their age.
    // As output, tell the user how many years they��ve lived for each letter in their name
    // (for simplicity, count spaces as a letter).
    {
        std::cout << "Enter your full name: ";
        std::string name;
        std::getline(std::cin, name); // read a full line of text into name

        std::cout << "Enter your age: ";
        int age; // age needs to be an integer, not a string, so we can do math with it
        std::cin >> age;
        std::cin.ignore(32767,'\n');

        int letters = name.length(); // get number of letters in name (including spaces)
        double agePerLetter = static_cast<double>(age) / letters; // static cast age to double to avoid integer division
        std::cout << "You've lived " << agePerLetter << " years for each letter in your name.\n";
    }
*/

    {
        // https://blog.csdn.net/Nine_Yao/article/details/123706441

        // 1 初始化
        {
            std::string str("这是一个字符串");
            std::cout << str << "\n"; // print 这是一个字符串
        }

        // std::string 变量名称 { "字符串"， 要截取的长度}；
        // 1 个中文 == 3 个字符
        {
            // 1 乱码 2 乱码 3 这
            // 4 乱码 5 乱码 6 是
            // ...
            std::string str("这是一个字符串", 3);
            std::cout << str << "\n"; // print 这

            
            std::string str1("abcdefg", 3);
            std::cout << str1 << "\n"; // print abc
        }

        // std::string 变量名称 { "字符串"，起始位置， 要截取的长度}；
        {
            std::string str1("abcdefg", 1, 3);
            std::cout << str1 << "\n"; // print bcd
        }

        // std::string 变量名称 (要复制的个数，'字符')；
        {
            std::string str1(6, 'a');
            std::cout << str1 << "\n"; // print aaaaaa
        }

        // 2. 拼接
        // 使用 +
        {
            std::string str("123123");
            str = str + "456";
            std::cout << str << "\n"; // print 123123456
        }

        // 直接拼接
        {
            #define AAA "ABC"
            #define BBB "123"
            std::string str = AAA BBB;
            std::cout << str << "\n"; // print ABC123
        }

        // str.append()
        {
            std::string str("123");
            str.append("456");
            std::cout << str << "\n"; // print 123456

            str.append("ABC").append("123");
            std::cout << str << "\n"; // print 123456ABC123
        }
        
        // str.append("", int count)
        {
            std::string str("123");
            str.append("456", 1);
            std::cout << str << "\n"; // print 1234
        }

        // str.append("", int index, int count)
        {
            std::string str("123");
            str.append("456", 1, 2);
            std::cout << str << "\n"; // print 12356
        }

        // str.append(int repeatCount, '')
        {
            std::string str("123");
            str.append(6, 'a');
            std::cout << str << "\n"; // print 123aaaaaa
        }

        // number to string: to_string(number)
        {
            std::string str = std::to_string(123);
            std::cout << str << "\n"; // print 123
        }

        // char[] and string
        // 两个string能相加，是因为string类把运算符+和+=都重载过，+和+=是string的重载函数。也可以把string和字符串常量相加，但必须保证每个加法运算符+的两侧的运算对象至少有一个是string。
        // "123" 、"456"这两个常量在内存里是char类型的数组（const char[4]），char类型的数组无法相加，所以会报错。
        {
            std::string str("123");
            str = str + "456"; // is ok
            //str = "123" + "456"; // is error
            str = std::string("123") + "456"; // is ok
            //str = "123" + "456" + std::string("123"); // is error（加法的运算优先级是从左往右，"456" 和 "123"是不能做加法的）
            str = "123" + ("456" + std::string("123")); // is ok
            //str += "123" + "456"; // is error（运算优先级的问题，+=的优先级排在+的后面,所以同样是因为先进行"123" + "345"运算问题；）
        }

        // char and string
        // string和char是可以相加的（string重载的+运算符！可以对char类型进行相加！）
        // char 和char 可以相加， char[] 和char[] 不可以相加；
        {
            std::string str("123");
            str = str + 'a';
            str += 'b';
            str = str + 'c' + 'd';
            str += '1' + '2'; // '1' + '2' = 99 == 'c'
                              // char 和 char 也是可以相加的（char类型本质上是整数，只是通过ASCII表限定了，两个char相加就是通过ASCII码相加）
                              // 比如：str += '1' + '2'; 通过查ASCII表'1' = 49,'2' = 50, '1' + '2' = 99 == 'c'
            // str += 'w' + 'o'; // is warning
                                 // str += 'w' + 'o';打印出错是因为 'w' +'o' = 119 + 111 = 230, 230超出了ASCII范围
        }

        // substr(int startIndex, int length)
        {
            std::string str("123456");
            std::string str1(str.substr(1, 2));
            std::cout << str1 << "\n"; // print 23
        }

        // substr(int startIndex)
        {
            std::string str("123456");
            std::string str1(str.substr(1));
            std::cout << str1 << "\n"; // print 23456
        }

        // length
        // 中文因为编码格式的问题，会有差异
        {
            std::string str("123456");
            std::cout << str.length() << "\n"; // print 6
        }

        // 访问 string 字符串中的字符
        {
            std::string str("123456");
            str[0] = 'a';
            str[5] = 'b';
            std::cout << str << "\n"; // print a2345b
        }

        // == != > < >= <=
        {
            std::string str("123456");
            std::string str1("213456");
            if (str < str1) {
                std::cout << "case a" << "\n"; // print a
            } else {
                std::cout << "case b" << "\n"; // not print
            }
        }

        // compare("")
        {
            std::string str("abcd");
            std::cout << str.compare("abcd") << std::endl; // print 0
            std::cout << str.compare("ABCD") << std::endl; // print 32
            std::cout << str.compare("bcde") << std::endl; // print -1
        }

        // compare(int startIndex, int length, "", int startIndex, int length)
        {
            std::string str("abcd");
            std::cout << str.compare(1, 2, "dbca", 1, 2) << std::endl; // print 0
        }

        // find("") return startIndex or std::string::npos
        {
            std::string str("123456789");
            std::cout << str.find("567") << std::endl; // print 4
            if (str.find("21") == std::string::npos) {
                std::cout << "not find" << std::endl; // print it
            }
        }

        // rfind("") return startIndex or std::string::npos
        {
            std::string str("123456789");
            std::cout << str.rfind("7") << std::endl; // print 6
        }

        // find("", int startIndex)
        {
            std::string str("123456789");
            std::cout << str.find("567", 4) << std::endl; // print 4
            std::cout << str.find("567", 5) << std::endl; // print 18446744073709551615 // print std::string::npos
        }

        // A.find("B", int startIndex, int length)
        // startIndex: 从 A 的第 startIndex 开始搜索
        // length: 截取 B 的 length 位
        {
            std::string str("123456789");
            std::cout << str.find("56a", 4, 2) << std::endl; // print 4
            std::cout << str.find("56a", 4, 3) << std::endl; // print 18446744073709551615 // print std::string::npos
        }

        // insert(int startIndex, "")
        {
            std::string str("123");
            std::cout << str.insert(1, "aaa") << std::endl; // print 1aaa23
        }

        // insert(int startIndex, int repeatCount, '')
        {
            std::string str("123");
            std::cout << str.insert(1, 3, 'a') << std::endl; // print 1aaa23
        }

        // replace(int startIndexA, int lengthA, "")
        // replace(int startIndexA, int lengthA, int repeatCountB, '')
        // replace(int startIndexA, int lengthA, "", int lengthB)
        // replace(int startIndexA, int lengthA, "", int startIndexB, int lengthB)

        // erase(int startIndex, int length)
        // erase(int startIndex)
        // erase() same to clear()
        // clear()

        // string to number
        // int a = stoi("123");
        // long a = stol("123");
        // long long a = stoll("123");
        // unsigned long a = stoul("123");
        // unsigned long long a = stoull("123");
        // float a = stof("123");
        // double a = stod("123");
        // logn double a = stold("123");

        // stringstream
        // #include <sstream>
        {
            std::stringstream strStream;
            strStream << "123" << "456";
            std::string str = strStream.str();
            std::cout << str << std::endl; // print 123456
        }
    }

    return 0;
}
