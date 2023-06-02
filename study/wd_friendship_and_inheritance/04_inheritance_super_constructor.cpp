// constructors and derived classes
#include <iostream>
using namespace std;

class Mother {
  public:
    Mother ()
      { cout << "Mother: no parameters\n"; }
    Mother (int a)
      { cout << "Mother: int parameter\n"; }
    void method() {
      cout << "Mother: method()\n";
    };
    void call() {
      a();
      b();
    }
    void a() {
      cout << "Mother: a()\n";
    }
    virtual void b() {
      cout << "Mother: b()\n";
    }
};

class Daughter : public Mother {
  public:
    Daughter (int a)
      { cout << "Daughter: int parameter\n\n"; }
    void method() {
      cout << "Daughter: method()\n";
    };
    void a() {
      cout << "Daughter: a()\n";
    }
    virtual void b() {
      cout << "Daughter: b()\n";
    }
};

class Son : public Mother {
  public:
    Son (int a) : Mother (a)
      { cout << "Son: int parameter\n\n"; }
    void method() {
      Mother::method();
      cout << "Son: method()\n";
    };
};

int main () {
  Daughter kelly(0); // Mother: no parameters 
                     // Daughter: int parameter
  Son bud(0);        // Mother: int parameter
                     // Son: int parameter

  kelly.method();    // Daughter: method()
  bud.method();      // Mother: method()
                     // Son: method()
                     // 主动调用父类方法才会调，否则不调父类方法(void)

  // 只调用父类
  kelly.Mother::method(); // Mother: method()
  bud.Mother::method();   // Mother: method()

  kelly.call(); // Mother: a()    无 virtual 修饰符
                // Daughter: b()  有 virtual 修饰符
  return 0;
}
/*
Mother: no parameters
Daughter: int parameter

Mother: int parameter
Son: int parameter

Daughter: method()
Mother: method()
Son: method()
Mother: method()
Mother: method()
Mother: a()
Daughter: b()
*/
