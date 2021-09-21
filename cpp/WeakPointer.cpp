#include <iostream>
#include <memory>

class Node1 {
public:
    std::shared_ptr<Node1> m_parent = nullptr;
    std::shared_ptr<Node1> m_child = nullptr;
};

class Node2 {
public:
    std::weak_ptr<Node2> m_parent;
    std::shared_ptr<Node2> m_child = nullptr;
};

void test1() {
    auto a1 = std::make_shared<Node1>();
    auto a2 = std::make_shared<Node1>();

    a1->m_child = a2;
}

void test2() {
    auto a1 = std::make_shared<Node1>();
    auto a2 = std::make_shared<Node1>();

    a1->m_child = a2;
    a2->m_parent = a1;
}

void test3() {
    auto a1 = std::make_shared<Node2>();
    auto a2 = std::make_shared<Node2>();

    a1->m_child = a2;
}

void test4() {
    auto a1 = std::make_shared<Node2>();
    auto a2 = std::make_shared<Node2>();

    a1->m_child = a2;
    a2->m_parent = a1;
}

int main() {
    // No leaks.
    test1();

    // Leak.
    test2();

    // No leaks.
    test3();

    // No leaks.
    test4();

    return 0;
}
