#include <iostream>

class Base1 {
public:
    ~Base1() {
        std::cout << "Delete Base1!\n";
    }
};

class Derived1: public Base1 {
public:
    ~Derived1() {
        std::cout << "Delete Derived1!\n";
    }
};

class Base2 {
public:
    virtual ~Base2() {
        std::cout << "Delete Base2!\n";
    }
};

class Derived2: public Base2 {
public:
    virtual ~Derived2() {
        std::cout << "Delete Derived2!\n";
    }
};

int main() {
    Base1* x = new Derived1();
    Base2* y = new Derived2();

    delete x;
    delete y;

    return 0;
}

