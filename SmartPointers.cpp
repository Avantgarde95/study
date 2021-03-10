#include <iostream>
#include <string>
#include <memory>

void printShared(const std::string& name, const std::shared_ptr<int>& v) {
    if (v == nullptr) {
        std::cout << name << ": nullptr\n";
    } else {
        std::cout << name << ": value = " << *v << ", count = " << v.use_count() << "\n";
    }
}

void printUnique(const std::string& name, const std::unique_ptr<int>& v) {
    if (v == nullptr) {
        std::cout << name << ": nullptr\n";
    } else {
        std::cout << name << ": value = " << *v << "\n";
    }
}

void testShared() {
    std::cout << "TestShared\n";

    auto x = std::make_shared<int>(5);
    printShared("x", x);

    auto a = x;
    printShared("x", x);
    printShared("a", a);

    auto b = a;
    printShared("x", x);
    printShared("a", a);
    printShared("b", b);
}

void testUnique() {
    std::cout << "TestUnique\n";

    auto x = std::make_unique<int>(5);
    printUnique("x", x);

    // auto a = x; -> Compile error!

    auto b = std::move(x);
    printUnique("x", x);
    printUnique("b", b);
}

int main() {
    testShared();
    testUnique();

    return 0;
}
