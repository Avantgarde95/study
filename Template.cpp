#include <iostream>

namespace CompileTimeComputation {

template <int N>
constexpr int fibonacci() {
    return fibonacci<N - 1>() + fibonacci<N - 2>();
}

template <>
constexpr int fibonacci<1>() {
    return 1;
}

template <>
constexpr int fibonacci<0>() {
    return 0;
}

void run() {
    constexpr int n = 10;
    std::cout << n << "th fibonacci number: " << fibonacci<n>() << "\n";
}

};

int main() {
    CompileTimeComputation::run();

    return 0;
}
