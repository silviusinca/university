#include <iostream>

class A {
public:
    A() = default;
    virtual void sayHello() {
        std::cout << "Hello, World! From class A" << std::endl;
    }
};

class B : public virtual A {
public:
    B(): A() {}
    void sayHello() override {
        std::cout << "Hello, World! From class B" << std::endl;
    }
};

class C : public virtual A {
public:
    C(): A() {}
    void sayHello() override {
        std::cout << "Hello, World! From class C" << std::endl;
    }
};

class D : public virtual A, public B, public C {
public:
    D(): A(), B(), C() {}
    void sayHello() override {
        std::cout << "Hello, World! From class D" << std::endl;
    }
};

int main() {
    A a;
    D d;
    d.sayHello();
    a.sayHello();
    return 0;
}

