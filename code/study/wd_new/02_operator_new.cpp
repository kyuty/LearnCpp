// operator new example
#include <iostream>     // std::cout
#include <new>          // ::operator new

struct MyClass {
  int data[100];
  MyClass() {
    std::cout << "constructed [" << this << "]\n";
  }
};

int main () {

  std::cout << "1: ";
  MyClass * p1 = new MyClass;
      // allocates memory by calling: operator new (sizeof(MyClass))
      // and then constructs an object at the newly allocated space

  std::cout << "2: ";
  MyClass * p2 = new (std::nothrow) MyClass;
      // allocates memory by calling: operator new (sizeof(MyClass),std::nothrow)
      // and then constructs an object at the newly allocated space

  std::cout << "3: ";
  new (p2) MyClass;
      // does not allocate memory -- calls: operator new (sizeof(MyClass),p2)
      // but constructs an object at p2

  // Notice though that calling this function directly does not construct an object:
  std::cout << "4: ";
  MyClass * p3 = (MyClass*) ::operator new (sizeof(MyClass));
      // allocates memory by calling: operator new (sizeof(MyClass))
      // but does not call MyClass's constructor

  std::cout << "\n5:";
  std::cout << p3->data[0];
  delete p1;
  delete p2;
  delete p3;

  return 0;
}
/*
1: constructed [0x8f0f70]
2: constructed [0x8f23a8]
3: constructed [0x8f23a8]
4:
5:0
*/
