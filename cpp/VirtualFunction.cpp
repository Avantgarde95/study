#include <iostream>
#include <string>

class Base {
public:
    virtual void test1() {
        std::cout << m_name << "!\n";
    }

    virtual void test2() {
        std::cout << m_name << "!\n";
    }

    virtual void test3() {
        std::cout << m_name << "!\n";
    }

    void test4() {
        std::cout << m_name << "!\n";
    }

private:
    std::string m_name = "Base";
};

class Derived: public Base {
public:
    virtual void test1() {
        std::cout << m_name << "!\n";
    }

    virtual void test2(int x) {
        std::cout << m_name << "!\n";
    }

    // virtual void test3(int x) override { -> Compile error!
    virtual void test3() override {
        std::cout << m_name << "!\n";
    }

    void test4() {
        std::cout << m_name << "!\n";
    }

private:
    std::string m_name = "Derived";
};

int main() {
    auto x = Derived();
    x.test1();
    x.test2(3);
    x.test3();

    Base* y = &x;
    std::cout << "Virtual: ";
    y->test1();
    std::cout << "Non-virtual: ";
    y->test4();
    std::cout << "Parent's virtual: ";
    y->Base::test1();

    return 0;
}
