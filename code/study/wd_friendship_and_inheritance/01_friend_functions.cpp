// friend functions
#include <iostream>
using namespace std;

class Rectangle {
    int width, height;
  public:
    Rectangle() {}
    Rectangle (int x, int y) : width(x), height(y) {}
    int area() {return width * height;}
    friend Rectangle duplicate (const Rectangle&);
    //Rectangle duplicate (const Rectangle&);
};

Rectangle duplicate (const Rectangle& param)
{
  Rectangle res;
  res.width = param.width*2;
  res.height = param.height*2;
  return res;
}

int main () {
  Rectangle foo;
  Rectangle bar (2,3);
  foo = duplicate (bar);
  cout << foo.area() << '\n';
  return 0;
}
/*
In principle, private and protected members of a class cannot be accessed from outside the same class in which they are declared. However, this rule does not apply to "friend".

friend 能访问private和protected变量
作用于 返回的变量 和 参数的变量

----

if delete 'friend', will show the error and note below

01_friend_functions.cpp:18:7: error: 'width' is a private member of 'Rectangle'
  res.width = param.width*2;
      ^
01_friend_functions.cpp:6:9: note: implicitly declared private here
    int width, height;

01_friend_functions.cpp:18:21: error: 'width' is a private member of 'Rectangle'
  res.width = param.width*2;
                    ^
01_friend_functions.cpp:6:9: note: implicitly declared private here
    int width, height;

----

this is wrong.
Rectangle duplicate (friend const Rectangle&);

01_friend_functions.cpp:12:26: error: 'friend' used outside of class
    Rectangle duplicate (friend const Rectangle&);

*/
/*
24
*/
